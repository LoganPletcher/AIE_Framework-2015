#include <time.h>
#include <iostream>
#include "GameLoop.h"
#include "Vector.h"

int x = 450;
int y = 100;
int size = 50;
int sides = 50;
int R = 255;
int G = 255;
int B = 0;
int density = 255;


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
	for (float i = 0; i < 9; i++)
	{
		Graphics::DrawLine({ 400 , 50 + (100 * i) }, { 1200, 50 + (100 * i) }, { 255, 255, 255, 255 });
		Graphics::DrawLine({ 400 + (100 * i), 50 }, { 400 + (100 * i), 850 }, { 255, 255, 255, 255 });
	}
	Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
	//Vector<float> Vec1 = { 300, 0, 0 };
	//Vector<float> Vec2 = { 0, 400, 0 };
	//Vector<float> Vec3 = Vec1 + Vec2;
	//Graphics::DrawLine({ 10, 10 }, { 10, Vec2.y }, { 255, 255, 255, 255 });
	//Graphics::DrawLine({ 10, 10 }, { Vec1.x, 10 }, { 255, 255, 255, 255 });
	//Graphics::DrawLine({ Vec3.x, 10 }, { 10, Vec3.y }, { 255, 255, 255, 255 });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	case SDLK_w: if (y > 100) { y -= 100; break; } else { break; }
	case SDLK_s: if (y < 800) { y += 100; break; } else { break; }
	case SDLK_d: if (x < 1150) { x += 100; break; } else { break; }
	case SDLK_a: if (x > 450) { x -= 100; break; } else { break; }
	case SDLK_y: if (R < 255) { R += 5; break; } else { break; }
	case SDLK_h: if (R > 0) { R -= 5;  break; } else { break; }
	case SDLK_u: if (G < 255) { G += 5; break; } else { break; }
	case SDLK_j: if (G > 0) { G -= 5;  break; } else { break; }
	case SDLK_i: if (B < 255) { B += 5; break; } else { break; }
	case SDLK_k: if (B > 0) { B -= 5; break; } else { break; }
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
