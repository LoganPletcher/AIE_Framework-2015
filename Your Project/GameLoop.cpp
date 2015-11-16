#include <time.h>
#include <iostream>
#include "GameLoop.h"
#include "Vector.h"

void BULLET(int &bullet, int deltaTime, int movement)
{
	bullet -= movement * deltaTime;
}

float x = 50;
float y = 100;
int size = 50;
int sides = 50;
int R = 255;
int G = 255;
int B = 0;
int density = 255;
float currentTime = clock();
float previousTime = currentTime;
int deltaTime = 0;
int bullet = 1610;
int by = 500;
float a = 1550;
float b = 100;
bool p1W = false;
bool p1S = false;
//bool p1D = false;
//bool p1A = false;
bool p2UP = false;
bool p2DOWN = false;
//bool p2RIGHT = false;
//bool p2LEFT = false;
int movement = 10;

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
			currentTime = clock();
			deltaTime = (currentTime - previousTime) / 10;
			std::cout << deltaTime << std::endl;

			previousTime = currentTime;

			if (((bullet == x - 20) && (by >= y && by <= y + 90)))
			{
				movement = -10;
				
			}

			if ((bullet < 1610 && bullet > -10))
			{
				BULLET(bullet, deltaTime, movement);
			
			}
			
			else { bullet = 800; }

			if (p1W) { if (y > 0) { y -= 10; } }

			if (p1S) { if (y < 900) { y += 10; } }

			//if (p1D) { if (x < 1150) { x += 50; } }

			//if (p1A) { if (x > 450) { x -= 50; } }

			if (p2UP) { if (b > 0) { b -= 10; } }
			
			if (p2DOWN) { if (b < 900) { b += 10; }}

			//if (p2RIGHT) { if (a < 1150) { a += 50; } }

			//if (p2LEFT) { if (a > 450) { a -= 50; } }

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
	//Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
	Graphics::DrawRect({ 10, y }, { 10, 100 }, { 150, 200, 255, 255 });
	//Graphics::DrawCircle({ a, b }, size, sides, { R, G, B, density });
	Graphics::DrawRect({ 1580, b }, { 10, 100 }, { 150, 200, 255, 255 });
	Graphics::DrawCircle({ bullet, by }, 10, 500, { 200,200,200,255 });
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
	case SDLK_b: if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size))) { BULLET(bullet, deltaTime, movement);  break; } else { break; }
	case SDLK_w: p1W = true; /*if (y > 100) { y -= 100; break; } else { break; }*/ break;
	case SDLK_s: p1S = true; /*if (y < 800) { y += 100; break; } else { break; }*/ break;
	//case SDLK_d: p1D = true; /*if (x < 1150) { x += 100; break; } else { break; }*/ break;
	//case SDLK_a: p1A = true; /*if (x > 450) { x -= 100; break; } else { break; }*/ break;
	case SDLK_y: if (R < 255) { R += 5; break; } else { break; }
	case SDLK_h: if (R > 0) { R -= 5;  break; } else { break; }
	case SDLK_u: if (G < 255) { G += 5; break; } else { break; }
	case SDLK_j: if (G > 0) { G -= 5;  break; } else { break; }
	case SDLK_i: if (B < 255) { B += 5; break; } else { break; }
	case SDLK_k: if (B > 0) { B -= 5; break; } else { break; }
	case SDLK_UP: p2UP = true; /*if (b > 100) { b -= 100; break; } else { break; }*/ break;
	case SDLK_DOWN: p2DOWN = true; /*if (b < 800) { b += 100; break; } else { break; }*/ break;
	//case SDLK_RIGHT: p2RIGHT = true; /*if (a < 1150) { a += 100; break; } else { break; }*/ break;
	//case SDLK_LEFT: p2LEFT = true; /*if (a > 450) { a -= 100; break; } else { break; }*/ break;
	case SDLK_ESCAPE: m_bRunning = false; break;

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_w: p1W = false; break;
	case SDLK_s: p1S = false; break;
	//case SDLK_d: p1D = false; break;
	//case SDLK_a: p1A = false; break;
	case SDLK_UP: p2UP = false; break;
	case SDLK_DOWN: p2DOWN = false; break;
	//case SDLK_RIGHT: p2RIGHT = false; break;
	//case SDLK_LEFT: p2LEFT = false; break;
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
