#include <time.h>
#include <iostream>
#include "GameLoop.h"
#include "Vector.h"

void BULLET(int &bullet, int deltaTime)
{
	bullet -= 10 * deltaTime;
}


int x = 1600;
int y = 0;
int size = 200;
int sides = 50;
int R = 255;
int G = 255;
int B = 0;
int density = 255;
int bullet = 1610;
int by = 450;
float currentTime = clock();
float previousTime = currentTime;
int deltaTime = 0;
float bodyX = 800;
float bodyY = 330;
bool left = false;
bool inverse = false;
Vector<int> RGBAC = { 230,230,230,255 };
Vector<float> RGBAR = { 230, 230, 230, 255 };
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

			char hexcode[8] = "#AA7807";
			Vector<float> RGBA4D = RGBA4D.HexConv(hexcode);
			
			if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size)))
			{
				if (bullet < 1610 && bullet > -10) { BULLET(bullet, deltaTime); }
				else { bullet = 1610; }
			}

			if (bodyY >= 1800)
			{
				bodyX = 800;
				bodyY = 330;
			}

			if (bodyY > 330)
			{
				bodyY += 5;
			}

			if (bodyX >= 1250 || bodyX <= 170)
			{
				bodyY += 5;
			}

			if (bodyY < 330)
			{
				bodyY++;
			}

			previousTime = currentTime;

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
	
	Graphics::DrawRect({ 0, 0 }, { 1600, 900 }, { 150, 200, 255, 255 });
	Graphics::DrawRect({ 410, 0 }, { 400, 900 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });
	Vector<float> Vec1 = { 300, 0};
	Vector<float> Vec2 = { 0, 400};
	Vector<float> Vec3 = Vec1 + Vec2;
	Graphics::DrawLine({ 10, 10 }, { 10, Vec2.y }, { 255, 255, 255, 255 });
	Graphics::DrawLine({ 10, 10 }, { Vec1.x, 10 }, { 255, 255, 255, 255 });
	Graphics::DrawLine({ Vec3.x, 10 }, { 10, Vec3.y }, { 255, 255, 255, 255 });
	Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });

	Graphics::DrawRing({ 10, 10 }, 50, 25, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
	Graphics::DrawCircle({ bullet, 450 }, 10, 500, { 100,100,100,255 });

	int playerX = bodyX;
	int playerY = bodyY;
	Vector<int> SUBC = { 255,255,255,510 };
	Vector<float> SUBR = { 255,255,255,510 };
	Vector<int> rgbaC = SUBC - RGBAC;
	Vector<float> rgbaR = SUBR - RGBAR;

	if (!inverse)
	{
		if (left != true)
		{
			Graphics::DrawCircle({ playerX + 80, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand one
			Graphics::DrawRect({ bodyX + 55, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });  //foot one
			Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { RGBAR.x - 80, RGBAR.y - 80, RGBAR.z - 80, RGBAR.w });//Body
			Graphics::DrawCircle({ playerX + 55, playerY - 10 }, 50, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //Head
			Graphics::DrawCircle({ playerX + 25, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand two
			Graphics::DrawRect({ bodyX + 5, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });	  //foot two
		}
		else if (left = true)
		{
			Graphics::DrawCircle({ playerX, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand one
			Graphics::DrawRect({ bodyX - 15, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });   //foot one
			Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { RGBAR.x - 80, RGBAR.y - 80, RGBAR.z - 80, RGBAR.w });//Body
			Graphics::DrawCircle({ playerX + 25, playerY - 10 }, 50, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //Head
			Graphics::DrawCircle({ playerX + 55, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand two
			Graphics::DrawRect({ bodyX + 35, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });  //foot two
		}
	}
	else if (inverse)
	{
		if (left != true)
		{
			Graphics::DrawCircle({ playerX + 80, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand one
			Graphics::DrawRect({ bodyX + 55, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });  //foot one
			Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { rgbaR.x - 80, rgbaR.y - 80, rgbaR.z - 80, rgbaR.w });//Body
			Graphics::DrawCircle({ playerX + 55, playerY - 10 }, 50, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //Head
			Graphics::DrawCircle({ playerX + 25, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand two
			Graphics::DrawRect({ bodyX + 5, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });	  //foot two
		}
		else if (left = true)
		{
			Graphics::DrawCircle({ playerX, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand one
			Graphics::DrawRect({ bodyX - 15, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });   //foot one
			Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { rgbaR.x - 80, rgbaR.y - 80, rgbaR.z - 80, rgbaR.w });//Body
			Graphics::DrawCircle({ playerX + 25, playerY - 10 }, 50, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //Head
			Graphics::DrawCircle({ playerX + 55, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand two
			Graphics::DrawRect({ bodyX + 35, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });  //foot two
		}
	}
	Vector<float> Vec3D = { 200, 300, 543 };										//Creates a 3D vector
	std::cout << "3D Vector Values: (" << Vec3D.x << ", " << Vec3D.y << ", " << Vec3D.z << ")\n";
	float dotprod = Vec1.DotProduct(Vec2);											//Gets the dotproduct of Vec1 & Vec2
	std::cout << "Vector Dot Product: " << dotprod << std::endl;
	Vec3D.Magnitude();																//Creates a variable for the 3D vector magnitude
	std::cout << "3D Vector Magnitude: " << Vec3D.magnitude << std::endl;
	Vec3D.Normalize();																//Normalizes the 3D vector
	Vector<float> Vec3DNi = { 1234, 3213, 8595 };									//Creates another 3D vector
	Vec3DNi = Vec3DNi - Vec3D;														//Sets the values of the second 3D vector to the vector minus the first 3D vector
	Vec3DNi = Vec3DNi.CrossProduct(Vec3D);											//Sets the values of the second 3D vector to the crossproduct of the first and second 3D vectors
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	case SDLK_b:if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size))) { BULLET(bullet, deltaTime);  break; } else { break; }
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
	case SDLK_UP: if (bodyY > 320) { bodyY -= 10; break; } else { break; }
	case SDLK_RIGHT: bodyX += 10; left = false; break;
	case SDLK_LEFT: bodyX -= 10; left = true; break;
	case SDLK_t: if (inverse) { inverse = false; break; } else { inverse = true; break; }
	case SDLK_z: if (RGBAC.x < 255) { RGBAC.x += 1; RGBAR.x += 1; break; } else { break; }
	case SDLK_x: if (RGBAC.x > 0) { RGBAC.x -= 1; RGBAR.x -= 1; break; } else { break; }
	case SDLK_c: if (RGBAC.y < 255) { RGBAC.y += 1; RGBAR.y += 1; break; } else { break; }
	case SDLK_v: if (RGBAC.y > 0) { RGBAC.y -= 1; RGBAR.y -= 1; break; } else { break; }
	case SDLK_n: if (RGBAC.z < 255) { RGBAC.z += 1; RGBAR.z += 1; break; } else { break; }
	case SDLK_m: if (RGBAC.z > 0) { RGBAC.z -= 1; RGBAR.z -= 1; break; } else { break; }

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
