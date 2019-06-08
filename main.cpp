#include <iostream>
#include <exception>
#include <algorithm>
#include <string>

#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;

int main() try {
	// Initialize SDL library
	SDL sdl(SDL_INIT_VIDEO);

	if((SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur d'initialisaton de la SDL : %s\n", SDL_GetError() );
		exit(EXIT_FAILURE);
	}
	// Initialize SDL_ttf library
	SDLTTF ttf;

	// Create main window: 640x480 dimensions, resizable, "SDL2pp demo" title
	Window window("SDL2pp demo",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Load sprites image as a new texture; since there's no alpha channel
	// but we need transparency, use helper surface for which set color key
	// to color index 0 -> black background on image will be transparent on our
	// texture
	Texture sprites(renderer, Surface(DATA_PATH "/M484SpaceSoldier.png")
			.SetColorKey(true, 0));

	// Enable alpha blending for the sprites
	sprites.SetBlendMode(SDL_BLENDMODE_BLEND);

	// Gradient texture to be generated
	Texture gradient(renderer, SDL_PIXELFORMAT_BGR888, SDL_TEXTUREACCESS_STATIC, 1, 256);
	{
		// Array holding RGB values for 256 pixels
		unsigned char grad[256 * 3];
		int n = 0; // counter

		// Fill array with fading gray values from white to black; its contents will be
		// 255,255,255, 254,254,254, 253,253,253 ... 1,1,1, 0,0,0
		std::generate(grad, grad + sizeof(grad), [&](){ return 255 - n++ / 3; });

		// Update texture with our raw color data, enable blending and set color
		// and alpha modulation, so when rendered our texture will be dark cyan
		gradient.Update(NullOpt, grad, 3)
			.SetBlendMode(SDL_BLENDMODE_BLEND)
			.SetColorMod(0, 255, 255)
			.SetAlphaMod(85);
	}

	// Load font, 12pt size
	Font font(DATA_PATH "/Vera.ttf", 12);

	// Game state
	bool is_running = false; // whether the character is currently running
	bool is_shooting[10] = {false};
	int bullet = 0;
	int direction = 0; // whether the character is currently running
	int run_phase = -1;      // run animation phase
	float position = 0.0;    // player position
	float bullet_position[10] = {0.0};
	int bullet_x, bullet_y;
	int bullet_direction[10] = {6};
	int cpt = 0;

	unsigned int prev_ticks = SDL_GetTicks();
	// Main loop
	while (1) { //************************************************************
		// Timing: calculate difference between this and previous frame
		// in milliseconds
		unsigned int frame_ticks = SDL_GetTicks();
		unsigned int frame_delta = frame_ticks - prev_ticks;
		prev_ticks = frame_ticks;

		// Event processing:
		// - If window is closed, or Q or Escape buttons are pressed,
		//   quit the application
		// - If Right key is pressed, character would run
		// - If Right key is released, character would stop
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return 0;
			} else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
					case SDLK_q:
						return 0;
					case SDLK_RIGHT:
						is_running = true;
						direction = 6;
						break;
					case SDLK_LEFT:
						is_running = true;
						direction = 4;
						break;
					case SDLK_f:
						for (size_t i = 0; i <= cpt; i++) {
							if (is_shooting[i]==false)
								is_shooting[i] = true;
								if(direction == 4)
									bullet_direction[i] = 4;
								if (direction == 6)
									bullet_direction[i] = 6;
							if(is_shooting[i]==true)
							cpt++;
						}
				}
			} else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
					case SDLK_RIGHT:
					case SDLK_LEFT:
						is_running = false;
						break;
				}
			}
		}

		// Update game state for this frame:
		// if character is runnung, move it in the right direction
		if (is_running) {
			position += frame_delta * 0.2 * (direction == 4) ? -1 : 1;
			run_phase = (frame_ticks / 100) % 8;
		} else {
			run_phase = 0;
		}
		for (size_t i = 0; i <= cpt ; i++) {
			if(is_shooting[i]) {
				bullet_position[i] += frame_delta * 0.6 * (bullet_direction[i] == 4) ? -1 : 1;
				if (bullet_position[i] > renderer.GetOutputWidth()) {
					is_shooting[i] = false;
					cpt --;
				}
				if (bullet_position[i] < -50) {
					is_shooting[i] = false;
					cpt --;
				}
			}
		}


		// If player passes past the right side of the window, wrap him
		// to the left side
		if (position > renderer.GetOutputWidth())
			position = 0;
		if (position < 0)
			position = renderer.GetOutputWidth()-50;

		int vcenter = renderer.GetOutputHeight() / 2; // Y coordinate of window center

		// Clear screen
		renderer.Clear();

		// Copy our gradient texture, stretching it to the whole window
		renderer.Copy(
				gradient,
				NullOpt,
				Rect(0, vcenter, renderer.GetOutputWidth(), renderer.GetOutputHeight() / 2)
			);

		// Pick sprite from sprite atlas based on whether
		// player is running and run animation phase
		int src_x = 8, src_y = 11; // by default, standing sprite turned right
		if (direction == 4) // if turned left
			src_x = 59;

		if (is_running) {
			// one of 8 run animation sprites
			src_x = 8 + 51 * run_phase;

			if (direction == 6)
				src_y = 67;
			else if (direction == 4)
				src_y = 123;
		}

		for (size_t i = 0; i <= cpt; i++) {
			if (is_shooting[i]) {
				 bullet_x = 180 , bullet_y = 245;
			}
		}

		// Draw player sprite
		sprites.SetAlphaMod(255); // sprite is fully opaque
		renderer.Copy(
				sprites,
				Rect(src_x, src_y, 50, 50),
				Rect((int)position, vcenter - 50, 50, 50)
			);

			for (size_t i = 0; i <= cpt; i++) {
				if(is_shooting[i]) {
					sprites.SetAlphaMod(255); // sprite is fully opaque
					renderer.Copy(
							sprites,
							Rect(bullet_x, bullet_y, 20, 20),
							Rect((int)bullet_position[i] +10, vcenter - 45, 50, 50)
						);
					}
			}


		// Draw the same sprite, below the first one, 50% transparent and
		// vertically flipped. It'll look like reflection in the mirror
		sprites.SetAlphaMod(127); // 50% transparent
		renderer.Copy(
				sprites,
				Rect(src_x, src_y, 50, 50),
				Rect((int)position, vcenter, 50, 50),
				0.0,              // don't rotate
				NullOpt,          // rotation center - not needed
				SDL_FLIP_VERTICAL // vertical flip
			);

		// Create text string to render
		std::string text =
			"Position: "
			+ std::to_string((int)position)
			+ ", running: "
			+ (is_running ? "true" : "false")
			+ ", shooting: "
			+ (is_shooting[0] ? "true" : "false")
			+ ", check: "
			+ std::to_string((int)bullet_position[0])
			+ ", cpt: "
			+ std::to_string((int)cpt);

		// Render the text into new texture. Note that SDL_ttf render
		// text into Surface, which is converted into texture on the fly
		Texture text_sprite(
			renderer,
			font.RenderText_Blended(text, SDL_Color{255, 255, 255, 255})
		);

		// Copy texture into top-left corner of the window
		renderer.Copy(text_sprite, NullOpt, Rect(0, 0, text_sprite.GetWidth(), text_sprite.GetHeight()));
		// Show rendered frame
		renderer.Present();

		// Frame limiter: sleep for a little bit to not eat 100% of CPU
		SDL_Delay(1); //************************************************************
	}

	// Here all resources are automatically released and libraries deinitialized
	return 0;
} catch (std::exception& e) {
	// If case of error, print it and exit with error
	std::cerr << e.what() << std::endl;

	return EXIT_SUCCESS;
}
