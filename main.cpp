#include <iostream>
#include <exception>
#include <algorithm>
#include <string>

#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;

int main() try
{
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
			1920, 1080,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

//***********************************************************************************
	// Load sprites image as a new texture; since there's no alpha channel
	// but we need transparency, use helper surface for which set color key
	// to color index 0 -> black background on image will be transparent on our
	// texture
	Texture sprites_idle_1 (renderer, Surface(DATA_PATH "/rogue like character/rogue like idle_Animation 1_0.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_idle_1.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_idle_2 (renderer, Surface(DATA_PATH "/rogue like character/rogue like idle_Animation 1_1.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_idle_2.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_idle_3 (renderer, Surface(DATA_PATH "/rogue like character/rogue like idle_Animation 1_2.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_idle_3.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_1 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_0.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_1.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_2 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_1.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_2.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_3 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_2.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_3.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_4 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_3.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_4.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_5 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_4.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_5.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_6 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run_Animation 1_5.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_6.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_down_1 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run down_Animation 1_0.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_down_1.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_down_2 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run down_Animation 1_1.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_down_2.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_down_3 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run down_Animation 1_2.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_down_3.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_down_4 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run down_Animation 1_3.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_down_4.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_up_1 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run up_Animation 1_0.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_up_1.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_up_2 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run up_Animation 1_1.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_up_2.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_up_3 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run up_Animation 1_2.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_up_3.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_run_up_4 (renderer, Surface(DATA_PATH "/rogue like character/rogue like run up_Animation 1_3.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_run_up_4.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_1 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_0.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_1.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_2 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_1.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_2.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_3 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_2.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_3.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_4 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_3.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_4.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_5 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_4.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_5.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_6 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_5.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_6.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_7 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_6.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_7.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_spell_8 (renderer, Surface(DATA_PATH "/rogue like character/rogue like attack_Animation 1_7.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_spell_8.SetBlendMode(SDL_BLENDMODE_BLEND);

	Texture sprites_projectil (renderer, Surface(DATA_PATH "/M484SpaceSoldier.png")
			.SetColorKey(true, 0));
	// Enable alpha blending for the sprites
	sprites_projectil.SetBlendMode(SDL_BLENDMODE_BLEND);

	// Load font, 12pt size
	Font font(DATA_PATH "/Vera.ttf", 12);
	//***********************************************************************************

	// Game state
	bool is_running = false; // whether the character is currently running
	int direction = 0; // whether the character is currently running
	int run_phase_x = -1;// run animation phase
	int run_phase_y = -1;
	float position_x = 100.0;
	float position_y = 100.0;    // player position
	int run_x = 10, run_y = 10;

	bool is_shooting[10] = {false};
	int bullet = 0;
	int cpt = 0;
	int bullet_direction[100] = {6};
	float bullet_position_x[100] = {0.0};
	float bullet_position_y[100] = {0.0};
	int bullet_x = 150, bullet_y = 270;

	bool is_idle = true;
	int idle_phase = -1;
	int idle_x = 10, idle_y = 10;

	bool is_spell = false;
	int spell_direction = 0;
	int spell_phase = -1;
	int spell_x = 10 , spell_y = 10;

	unsigned int prev_ticks = SDL_GetTicks();
	//***********************************************************************************

	// Main loop
	//***********************************************************************************
	while (1) {
		// Timing: calculate difference between this and previous frame
		// in milliseconds
		unsigned int frame_ticks = SDL_GetTicks();
		unsigned int frame_delta = frame_ticks - prev_ticks;
		prev_ticks = frame_ticks;
		//***********************************************************************************
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
						run_phase_x = 0;
						is_running = true;
						is_idle = false;
						direction = 6;
						break;
					case SDLK_LEFT:
						run_phase_x = 0;
						is_running = true;
						is_idle = false;
						direction = 4;
						break;
					case SDLK_UP:
						run_phase_y = 0;
						is_running = true;
						is_idle = false;
						direction = 8;
						break;
					case SDLK_DOWN:
						run_phase_y = 0;
						is_running = true;
						is_idle = false;
						direction = 2;
						break;
					case SDLK_r:
						spell_phase = 0;
						is_spell = true;
						is_running = false;
						is_idle = false;
						if(direction == 4)
						{
							spell_direction = 4;
						}
						if (direction == 6 || direction == 8 || direction == 2)
						{
							spell_direction = 6;
						}
						break;
					case SDLK_f:
						for (size_t i = 0; i <= bullet; i++) {
							if (is_shooting[i]==false)
							{
								is_shooting[i] = true;
								bullet_position_x[i] = position_x;
								bullet_position_y[i] = position_y;
								cpt ++;
								if(direction == 4)
								{
									bullet_direction[i] = 4;
								}
								if (direction == 6)
								{
									bullet_direction[i] = 6;
								}
								if(direction == 8)
								{
									bullet_direction[i] = 8;
								}
								if (direction == 2)
								{
									bullet_direction[i] = 2;
								}
							}
						}
				}
				break;
			} else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
					case SDLK_RIGHT:
					is_running = false;
					is_idle = true;
					break;
					case SDLK_LEFT:
						is_running = false;
						is_idle = true;
						break;
					case SDLK_UP:
						is_running = false;
						is_idle = true;
						break;
					case SDLK_DOWN:
						is_running = false;
						is_idle = true;
						break;
					case SDLK_r:
						is_running = false;
						is_spell = false;
						is_idle = true;
						break;
				}
			}
		}
		bullet = cpt;
		//***********************************************************************************
		// Update game state for this frame:
		// if character is runnung, move it in the right direction
		if(is_idle)
		{
				idle_phase = (frame_ticks / 100) % 3;
		}
		else
		{
			idle_phase = 0;
		}
		if (is_running)
		{
			if(direction == 4 || direction == 6)
			{
				position_x += frame_delta * 0.1 * (direction == 4) ? -1 : 1;
				run_phase_x = (frame_ticks / 100) % 6;
			}
			if(direction == 8 || direction == 2)
			{
				position_y += frame_delta * 0.1 * (direction == 8) ? -1 : 1;
				run_phase_y = (frame_ticks / 100) % 4;
			}
		} else {
			run_phase_x = 0;
			run_phase_y = 0;
		}
		if (is_spell)
		{
			spell_phase = (frame_ticks / 100) % 8;
			position_x = position_x;
			position_y = position_y;
		}
		else
		{
			spell_phase = 0;
		}
		for (size_t i = 0; i <= bullet ; i++)
		{
			if(is_shooting[i])
			{
				if(bullet_direction[i] == 6 || bullet_direction[i] == 4)
				{
					bullet_position_x[i] += frame_delta * 0.6 * (bullet_direction[i] == 4) ? -1 : 1;
					if (bullet_position_x[i] > renderer.GetOutputWidth())
					{
						is_shooting[i] = false;
						cpt --;
					}
					if (bullet_position_x[i] < -50)
					{
						is_shooting[i] = false;
						cpt --;
					}
				}
				if(bullet_direction[i] == 8 || bullet_direction[i] == 2)
				{
					bullet_position_y[i] += frame_delta * 0.6 * (bullet_direction[i] == 8) ? -1 : 1;
					if (bullet_position_y[i] > renderer.GetOutputHeight())
					{
						is_shooting[i] = false;
						cpt --;
					}
					if (bullet_position_y[i] < 0)
					{
						is_shooting[i] = false;
						cpt --;
					}
				}
			}
		}
		bullet = cpt;
		// If player passes past the right side of the window, wrap him
		// to the left side
		if (position_x > renderer.GetOutputWidth())
			position_x = 0;
		if (position_x < 0)
			position_x = renderer.GetOutputWidth()-50;

		if (position_y > renderer.GetOutputHeight())
			position_y = 0;
		if (position_y < 0)
			position_y = renderer.GetOutputHeight()-50;

		int vcenter = renderer.GetOutputHeight() / 2; // Y coordinate of window center
		//***********************************************************************************
		// Clear screen
		renderer.Clear();
		if(is_idle)
		{
			switch (idle_phase) {
				case 0:
					sprites_idle_1.SetAlphaMod(255); // sprite is fully opaque
					renderer.Copy(
						sprites_idle_1,
						Rect(idle_x, idle_y, 50, 50),
						Rect((int)position_x, position_y, 50, 50)
					);
					break;
			 case 1:
				 sprites_idle_2.SetAlphaMod(255); // sprite is fully opaque
				 renderer.Copy(
					 sprites_idle_2,
					 Rect(idle_x, idle_y, 50, 50),
					 Rect((int)position_x, position_y, 50, 50)
				 );
				 break;
				case 2:
					sprites_idle_3.SetAlphaMod(255); // sprite is fully opaque
					renderer.Copy(
						sprites_idle_3,
						Rect(idle_x, idle_y, 50, 50),
						Rect((int)position_x, position_y, 50, 50)
					);
					break;
			}
		}
		// Draw player sprite
			if(is_running)
			{
				if(direction == 6)
				{
					switch (run_phase_x) {
						case 0:
							sprites_run_1.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_1,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 1:
							sprites_run_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 2:
					 		sprites_run_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 3:
						sprites_run_3.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
								sprites_run_3,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 4:
						sprites_run_4.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
								sprites_run_4,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 5:
							sprites_run_6.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_6,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
					}
				}
				if(direction == 4)
				{
					switch (run_phase_x) {
						case 0:
							sprites_run_1.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_1,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
						case 1:
							sprites_run_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
						case 2:
					 		sprites_run_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
						case 3:
						sprites_run_3.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
								sprites_run_3,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
						case 4:
						sprites_run_4.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
								sprites_run_4,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
						case 5:
							sprites_run_6.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_6,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50),
								0.0,
								NullOpt,
								SDL_FLIP_HORIZONTAL
							);
							break;
					}
				}
				if(direction == 8)
				{
					switch (run_phase_y) {
						case 0:
							sprites_run_up_1.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_up_1,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 1:
							sprites_run_up_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_up_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 2:
							sprites_run_up_3.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_up_3,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 3:
							sprites_run_up_4.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_up_4,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
					}
				}
				if(direction == 2)
				{
					switch (run_phase_y) {
						case 0:
							sprites_run_down_1.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_down_1,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 1:
							sprites_run_down_2.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_down_2,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 2:
							sprites_run_down_3.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_down_3,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
						case 3:
							sprites_run_down_4.SetAlphaMod(255); // sprite is fully opaque
							renderer.Copy(
								sprites_run_down_4,
								Rect(run_x, run_y, 50, 50),
								Rect((int)position_x, position_y, 50, 50)
							);
							break;
					}
				}
			}
			if(is_spell)
			{
				switch (spell_phase) {
					case 0:
						sprites_spell_1.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_1,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 1:
						sprites_spell_2.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_2,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 2:
						sprites_spell_3.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_3,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100,100)
						);
						break;
					case 3:
						sprites_spell_4.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_4,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 4:
						sprites_spell_5.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_5,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 5:
						sprites_spell_6.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_6,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 6:
						sprites_spell_7.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_7,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
					case 7:
						sprites_spell_8.SetAlphaMod(255); // sprite is fully opaque
						renderer.Copy(
							sprites_spell_8,
							Rect(spell_x, spell_y, 500, 500),
							Rect((int)position_x, position_y, 100, 100)
						);
						break;
				}
			}
			for (size_t i = 0; i <= bullet; i++)
			{
				if(is_shooting[i]) {
					sprites_projectil.SetAlphaMod(255); // sprite is fully opaque
					renderer.Copy(
							sprites_projectil,
							Rect(bullet_x, bullet_y, 50, 50),
							Rect((int)bullet_position_x[i], bullet_position_y[i], 50, 50)
						);
					}
			}
			//***********************************************************************************
		// Create text string to render
		std::string text =
			"Position x: "
			+ std::to_string((int)position_x)
			+",Position y: "
			+ std::to_string((int)position_y)
			+ ", running: "
			+ (is_running ? "true" : "false")
			+ ", shooting: "
			+ (is_shooting[0] ? "true" : "false")
			+ ", bullet: "
			+ std::to_string((int)bullet)
			+ ", spell: "
			+ (is_spell ? "true" : "false")
			+ ", direction: "
			+ std::to_string((int)direction);
			//***********************************************************************************
		// Render the text into new texture. Note that SDL_ttf render
		// text into Surface, which is converted into texture on the fly
		Texture text_sprite(
			renderer,
			font.RenderText_Blended(text, SDL_Color{255, 255, 255, 255})
		);

		// Copy texture into top-left corner of the window
		renderer.Copy(text_sprite, NullOpt, Rect(0, 0, text_sprite.GetWidth(), text_sprite.GetHeight()));
		//***********************************************************************************
		// Show rendered frame
		renderer.Present();

		// Frame limiter: sleep for a little bit to not eat 100% of CPU
		SDL_Delay(1);
	}
	//***********************************************************************************
	// Here all resources are automatically released and libraries deinitialized
	return 0;
} catch (std::exception& e)
{
	// If case of error, print it and exit with error
	std::cerr << e.what() << std::endl;

	return EXIT_SUCCESS;
}
