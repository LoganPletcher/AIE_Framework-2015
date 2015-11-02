#include <thread>
#include <chrono>
#include "GameLoop.h"

void BULLET(int &bullet)
{
	bullet -= 10;
}

int x = 800;
int y = 450;
int size = 200;
int sides = 50;
int R = 0;
int G = 255;
int B = 255;
int density = 150;
int bullet = 1610;

void GameLoop::Loop()
{
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed

		while (m_bRunning)
		{
			// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
			// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
			// 'SDL_PollEvent' returns 0 when there are no more events to parse
			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}
			Update();

			LateUpdate();

			Draw();

			for (int i = 0; i < 2; i++)
			{
				if (bullet = -10)
				{
					bullet = 1610;
					break;
				}
				else if (bullet < 1610)
				{
					this_thread::sleep_for(chrono::seconds(1));
					BULLET(bullet);
					Draw();
					i = 0;
				}
				else
				{
					break;
				}
			}

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::Update()
{

}
void GameLoop::LateUpdate()
{

}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });

	Graphics::DrawRing({ 140, 140 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ bullet, 450 }, 10, 500, { 200,200,200,255 });

}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	case SDLK_b: BULLET(bullet); break;
	case SDLK_w: y -= 10; break;
	case SDLK_s: y += 10; break;
	case SDLK_d: x += 10; break;
	case SDLK_a: x -= 10; break;
	case SDLK_q: if (size > 0) { size -= 1; break; } else { break; }
	case SDLK_e: size += 1; break;
	case SDLK_r: sides += 1; break;
	case SDLK_f: if (sides > 3) { sides -= 1; break; } else { break; }
	case SDLK_y: if (R < 255) { R += 1; break; } else { break; }
	case SDLK_h: if (R > 0) { R -= 1;  break; } else { break; }
	case SDLK_u: if (G < 255) { G += 1; break; } else { break; }
	case SDLK_j: if (G > 0) { G -= 1;  break; } else { break; }
	case SDLK_i: if (B < 255) { B += 1; break; } else { break; }
	case SDLK_k: if (B > 0) { B -= 1; break; } else { break; }
	case SDLK_o: if (density < 255) { density += 1; break; } else { break; }
	case SDLK_l: if (density > 0) { density -= 1; break; } else { break; }

	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{

	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
