#include <time.h>
#include <iostream>
#include "GameLoop.h"
#include "Vector.h"
#include <cstdlib>

//void BULLET(int &bullet, int deltaTime)
//{
//	bullet -= 10 * deltaTime;
//}

bool BCollision(Vector<float> minOne, Vector<float> maxOne, Vector<float> minTwo, Vector<float> maxTwo)
{
	bool Xcollision = false;
	bool Ycollision = false;
	bool Zcollision = false;
	bool collision = false;

	if (((minOne.x >= minTwo.x && minOne.x <= maxTwo.x) || (maxOne.x >= minTwo.x && maxOne.x <= maxTwo.x)) 
		|| ((minTwo.x >= minOne.x && minTwo.x <= maxOne.x) || (maxTwo.x >= minOne.x && maxTwo.x <= maxOne.x)))
	{
		Xcollision = true;
	}

	if (((minOne.y >= minTwo.y && minOne.y <= maxTwo.y) || (maxOne.y >= minTwo.y && maxOne.y <= maxTwo.y))
		|| ((minTwo.y >= minOne.y && minTwo.y <= maxOne.y) || (maxTwo.y >= minOne.y && maxTwo.y <= maxOne.y)))
	{
		Ycollision = true;
	}

	if (((minOne.z >= minTwo.z && minOne.z <= maxTwo.z) || (maxOne.z >= minTwo.z && maxOne.z <= maxTwo.z))
		|| ((minTwo.z >= minOne.z && minTwo.z <= maxOne.z) || (maxTwo.z >= minOne.z && maxTwo.z <= maxOne.z)))
	{
		Zcollision = true;
	}
	if (Xcollision == true && Ycollision == true && Zcollision == true)
	{
		collision = true;
		std::cout << "BOOYAW!" << std::endl;
	}

	return collision;
}

//int x = 1600;
//int y = 0;
int size = 200;
int sides = 50;
int R = 255;
int G = 255;
int B = 0;
int density = 255;
//int bullet = 1610;
//int by = 450;
float currentTime = clock();
float previousTime = currentTime;
int deltaTime = 0;
//float bodyX = 800;
//float bodyY = 330;
//bool left = false;
//bool inverse = false;
//Vector<int> RGBAC = { 230,230,230,255 };
//Vector<float> RGBAR = { 230, 230, 230, 255 };
Vector<float> p0 = { 0, 450, 1 };
Vector<float> p1 = { 50, 450, 1 };
Vector<float> p2 = { 0, 500, 1 };
Vector<float> p3 = { 50, 500, 1 };
Vector<float> q0 = { 1550,450 };
Vector<float> q1 = { 1600,450 };
Vector<float> q2 = { 1550,500 };
Vector<float> q3 = { 1600,500 };
float randx = rand() % 1550;
float randy = rand() & 850;
Vector<float> g0 = { randx, randy };
bool p1W = false;
bool p1S = false;
bool p1D = false;
bool p1A = false;
bool p2UP = false;
bool p2DOWN = false;
bool p2RIGHT = false;
bool p2LEFT = false;
bool Up = false;
bool Left = false;
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
			std::cout << deltaTime << "\n\n";
			


			//if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size)))
			//{
			//	if (bullet < 1610 && bullet > -10) { BULLET(bullet, deltaTime); }
			//	else { bullet = 1610; }
			//}

			//if (bodyY >= 1800)
			//{
			//	bodyX = 800;
			//	bodyY = 330;
			//}

			//if (bodyY > 330)
			//{
			//	bodyY += 5;
			//}

			//if (bodyX >= 1250 || bodyX <= 170)
			//{
			//	bodyY += 5;
			//}

			//if (bodyY < 330)
			//{
			//	bodyY++;
			//}
			//BCollision(p0, p1, , maxTwo);
			if (!(BCollision(p0, p1, q2, q3)))
			{
				if (p1W) { if (p0.y > 0) { p0.y -= 10 * deltaTime; } }
			} 

			if (!(BCollision(p2, p3, q0, q1)))
			{
				if (p1S) { if (p0.y < 850) { p0.y += 10 * deltaTime; } }
			}

			if (!(BCollision(p1, p3, q0, q2)))
			{
				if (p1D) { if (p0.x < 1550) { p0.x += 10 * deltaTime; } }
			}

			if (!(BCollision(p0, p2, q1, q3)))
			{
				if (p1A) { if (p0.x > 0) { p0.x -= 10 * deltaTime; } }
			}

			if (!(BCollision(q0, q1, p2, p3)))
			{
				if (p2UP) { if (q0.y > 0) { q0.y -= 10 * deltaTime; } }
			}

			if (!(BCollision(q2, q3, p0, p1)))
			{
				if (p2DOWN) { if (q0.y < 850) { q0.y += 10 * deltaTime; } }
			}

			if (!(BCollision(q1, q3, p0, p2)))
			{
				if (p2RIGHT) { if (q0.x < 1550) { q0.x += 10 * deltaTime; } }
			}

			if (!(BCollision(q0, q2, p1, p3)))
			{
				if (p2LEFT) { if (q0.x > 0) { q0.x -= 10 * deltaTime; } }
			}
			
			if (g0.x <= 0) { Left = false; }
			if (g0.x >= 1550) { Left = true; }
			if (g0.y <= 0) { Up = false; }
			if (g0.y >= 850) { Up = true; }

			if (Up){ g0.y -= 10 * deltaTime; }
			else { g0.y += 10 * deltaTime; }

			if (Left){ g0.x -= 10 * deltaTime; }
			else { g0.x += 10 * deltaTime; }

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
	//Vector<float> test2DvectorONE = { 1,1 };
	//std::cout << "Test 2D Vector 1: ( " << test2DvectorONE.x << "," << test2DvectorONE.y << " )\n";
	//Vector<float> test2DvectorTWO = { 2,2 };
	//std::cout << "Test 2D Vector 2: ( " << test2DvectorTWO.x << "," << test2DvectorTWO.y << " )\n";
	//float DOTPRODUCT = test2DvectorONE.DotProduct(test2DvectorTWO);
	//std::cout << "Dot Product: " << DOTPRODUCT << std::endl;

	//Vector<float> test3DvectorONE = { 1,1,1 };
	//std::cout << "Test 3D Vector 1: ( " << test3DvectorONE.x << "," << test3DvectorONE.y << "," << test3DvectorONE.z << " )\n";
	//Vector<float> test3DvectorTWO = { 2,2,2 };
	//std::cout << "Test 3D Vector 2: ( " << test3DvectorTWO.x << "," << test3DvectorTWO.y << "," << test3DvectorTWO.z << " )\n";
	//float DOTPRODUCT = test3DvectorONE.DotProduct(test3DvectorTWO);
	//std::cout << "Dot Product: " << DOTPRODUCT << std::endl;

	//Vector<float> test2Dvector = { 5,5 };
	//std::cout << "Test 2D Vector: ( " << test2Dvector.x << "," << test2Dvector.y << " )\n";
	//test2Dvector.Magnitude();
	//Vector<float> NormalizedTest2Dvector = test2Dvector.Normalize();
	//std::cout << "Normalized Test 2D Vector: ( " << NormalizedTest2Dvector.x << "," << NormalizedTest2Dvector.y << " )\n";

	//Vector<float> test3Dvector = { 5,5,5 };
	//std::cout << "Test 3D Vector: ( " << test3Dvector.x << "," << test3Dvector.y << "," << test3Dvector.z << " )\n";
	//test3Dvector.Magnitude();
	//Vector<float> NormalizedTest3Dvector = test3Dvector.Normalize();
	//std::cout << "Normalized Test 3D Vector: ( " << NormalizedTest3Dvector.x << "," << NormalizedTest3Dvector.y << "," << NormalizedTest3Dvector.z << " )\n";

	//Vector<float> test3DvectorONE = { 2,1,2 };
	//std::cout << "Test 3D Vector 1: ( " << test3DvectorONE.x << "," << test3DvectorONE.y << "," << test3DvectorONE.z << " )\n";
	//Vector<float> test3DvectorTWO = { 1,2,1 };
	//std::cout << "Test 3D Vector 2: ( " << test3DvectorTWO.x << "," << test3DvectorTWO.y << "," << test3DvectorTWO.z << " )\n";
	//Vector<float> CRSSPRODUCT = test3DvectorONE.CrossProduct(test3DvectorTWO);
	//std::cout << "Cross Product: ( " << CRSSPRODUCT.x << "," << CRSSPRODUCT.y << "," << CRSSPRODUCT.z << " )\n";

	//Vector<float> test2Dvector = { 5,5 };
	//std::cout << "Test 2D Vector: ( " << test2Dvector.x << "," << test2Dvector.y << " )\n";
	//test2Dvector.Magnitude();
	//std::cout << "Magnitude: " << test2Dvector.magnitude << std::endl;

	//Vector<float> test3Dvector = { 5,5,5 };
	//std::cout << "Test 3D Vector: ( " << test3Dvector.x << "," << test3Dvector.y << "," << test3Dvector.z << " )\n";
	//test3Dvector.Magnitude();
	//std::cout << "Magnitude: " << test3Dvector.magnitude << std::endl;

	//Vector<float> test2DvectorONE = { 1,1 };
	//std::cout << "Test 2D Vector 1: ( " << test2DvectorONE.x << "," << test2DvectorONE.y << " )\n";
	//Vector<float> test2DvectorTWO = { 2,2 };
	//std::cout << "Test 2D Vector 2: ( " << test2DvectorTWO.x << "," << test2DvectorTWO.y << " )\n";
	//Vector<float> test2DvectorTHREE = test2DvectorONE + test2DvectorTWO;
	//std::cout << "Test 2D Vector 3: ( " << test2DvectorTHREE.x << "," << test2DvectorTHREE.y << " )\n";
	//Vector<float> test2DvectorFOUR = test2DvectorTHREE - test2DvectorONE;
	//std::cout << "Test 2D Vector 4: ( " << test2DvectorFOUR.x << "," << test2DvectorFOUR.y << " )\n";

	//Vector<float> test3DvectorONE = { 1,1,1 };
	//std::cout << "Test 3D Vector 1: ( " << test3DvectorONE.x << "," << test3DvectorONE.y << "," << test3DvectorONE.z << " )\n";
	//Vector<float> test3DvectorTWO = { 2,2,2 };
	//std::cout << "Test 3D Vector 2: ( " << test3DvectorTWO.x << "," << test3DvectorTWO.y << "," << test3DvectorTWO.z << " )\n";
	//Vector<float> test3DvectorTHREE = test3DvectorONE + test3DvectorTWO;
	//std::cout << "Test 3D Vector 3: ( " << test3DvectorTHREE.x << "," << test3DvectorTHREE.y << "," << test3DvectorTHREE.z << " )\n";
	//Vector<float> test3DvectorFOUR = test3DvectorTHREE - test3DvectorONE;
	//std::cout << "Test 3D Vector 4: ( " << test3DvectorFOUR.x << "," << test3DvectorFOUR.y << "," << test3DvectorFOUR.z << " )\n";

	//Vector<float> test4Dvector = { 5,5,5,5 };
	//std::cout << "Test 4D Vector: ( " << test4Dvector.x << "," << test4Dvector.y << "," << test4Dvector.z << "," << test4Dvector.w << " )\n";
	//test4Dvector.Magnitude();
	//Vector<float> NormalizedTest4Dvector = test4Dvector.Normalize();
	//std::cout << "Normalized Test 4D Vector: ( " << NormalizedTest4Dvector.x << "," << NormalizedTest4Dvector.y << "," << NormalizedTest4Dvector.z << "," 
	//<< NormalizedTest4Dvector.w << " )\n";

	//char hexacode[8] = "#F383F3";
	//std::cout << hexacode << std::endl;
	//Vector<float> Test4DvectorRGBA = Test4DvectorRGBA.HexConv(hexacode);

	//Vector<float> test2DvectorOne = { 0,3 };
	//std::cout << "Test 2D Vector 1: ( " << test2DvectorOne.x << "," << test2DvectorOne.y << " )\n";
	//Vector<float> test2DvectorTwo = { 4,0 };
	//std::cout << "Test 2D Vector 2: ( " << test2DvectorTwo.x << "," << test2DvectorTwo.y << " )\n";
	//Vector<float> test2DvectorThree;
	//test2DvectorThree.x = test2DvectorThree.Interpolation(test2DvectorOne.x, test2DvectorTwo.x, .5);
	//test2DvectorThree.y = test2DvectorThree.Interpolation(test2DvectorOne.y, test2DvectorTwo.y, .5);
	//std::cout << "Test 2D Vector 3: ( " << test2DvectorThree.x << "," << test2DvectorThree.y << " )\n";
	
	//float DEGREES = 180;
	//std::cout << "Degree Value: " << DEGREES << std::endl;
	//float RADIANS = rad(DEGREES);
	//std::cout << "Radian Value: " << RADIANS << std::endl;

	//char hexcode[8] = "#AE21AB";
	//float degr = 140.321;
	////std::cout << degr << std::endl;
	//float radi = rad(degr);
	////std::cout << radi << std::endl;
	//radi = radi * 2;
	////std::cout << radi << std::endl;
	//degr = deg(radi);
	////std::cout << degr << std::endl;
	//Vector<float> RGBA4D = RGBA4D.HexConv(hexcode);
	//Graphics::DrawRect({ 0, 0 }, { 1600, 900 }, { RGBA4D.x, RGBA4D.y, RGBA4D.z, RGBA4D.w });
	//Graphics::DrawRect({ 410, 0 }, { 400, 900 }, { 160, 65, 255, 255 });
	//Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });
	//Vector<float> Vec1 = { 300, 0};
	//Vector<float> Vec2 = { 0, 400};
	//double percentage = 0.0;
	//for (int i = 0; i < 96; i++)
	//{
	//	Vector<float> Vec3;
	//	Vec3.x = 5 + Vec3.Interpolation(Vec1.x, Vec2.x, percentage);
	//	Vec3.y = 5 + Vec3.Interpolation(Vec1.y, Vec2.y, percentage);
	//	//Graphics::DrawLine({ Vec3.x, 10 }, { 10, Vec3.x }, { 255, 255, 255, 255 });
	//	Graphics::DrawLine({ Vec3.x - 5, 10 }, { 10, Vec3.x - 5 }, { 255, 255, 255, 255 });
	//	percentage += 0.01;
	//}
	//
	//Graphics::DrawLine({ 10, 10 }, { 10, Vec2.y }, { 255, 255, 255, 255 });
	//Graphics::DrawLine({ 10, 10 }, { Vec1.x, 10 }, { 255, 255, 255, 255 });
	//
	//Graphics::DrawPoint({ 10, 10 }, { 255, 0, 0, 255 });

	//Graphics::DrawRing({ 10, 10 }, 50, 25, { 255, 0, 0, 255 });
	//Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
	//Graphics::DrawCircle({ bullet, 450 }, 10, 500, { 100,100,100,255 });

	//int playerX = bodyX;
	//int playerY = bodyY;
	//Vector<int> SUBC = { 255,255,255,510 };
	//Vector<float> SUBR = { 255,255,255,510 };
	//Vector<int> rgbaC = SUBC - RGBAC;
	//Vector<float> rgbaR = SUBR - RGBAR;

	//if (!inverse)
	//{
	//	if (left != true)
	//	{
	//		Graphics::DrawCircle({ playerX + 80, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand one
	//		Graphics::DrawRect({ bodyX + 55, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });  //foot one
	//		Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { RGBAR.x - 80, RGBAR.y - 80, RGBAR.z - 80, RGBAR.w });//Body
	//		Graphics::DrawCircle({ playerX + 55, playerY - 10 }, 50, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //Head
	//		Graphics::DrawCircle({ playerX + 25, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand two
	//		Graphics::DrawRect({ bodyX + 5, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });	  //foot two
	//	}
	//	else if (left = true)
	//	{
	//		Graphics::DrawCircle({ playerX, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand one
	//		Graphics::DrawRect({ bodyX - 15, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });   //foot one
	//		Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { RGBAR.x - 80, RGBAR.y - 80, RGBAR.z - 80, RGBAR.w });//Body
	//		Graphics::DrawCircle({ playerX + 25, playerY - 10 }, 50, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //Head
	//		Graphics::DrawCircle({ playerX + 55, playerY + 70 }, 20, 40, { RGBAC.x, RGBAC.y, RGBAC.z, RGBAC.w }); //hand two
	//		Graphics::DrawRect({ bodyX + 35, bodyY + 150 }, { 40, 20 }, { RGBAR.x, RGBAR.y, RGBAR.z, RGBAR.w });  //foot two
	//	}
	//}
	//else if (inverse)
	//{
	//	if (left != true)
	//	{
	//		Graphics::DrawCircle({ playerX + 80, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand one
	//		Graphics::DrawRect({ bodyX + 55, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });  //foot one
	//		Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { rgbaR.x - 80, rgbaR.y - 80, rgbaR.z - 80, rgbaR.w });//Body
	//		Graphics::DrawCircle({ playerX + 55, playerY - 10 }, 50, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //Head
	//		Graphics::DrawCircle({ playerX + 25, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand two
	//		Graphics::DrawRect({ bodyX + 5, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });	  //foot two
	//	}
	//	else if (left = true)
	//	{
	//		Graphics::DrawCircle({ playerX, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand one
	//		Graphics::DrawRect({ bodyX - 15, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });   //foot one
	//		Graphics::DrawRect({ bodyX, bodyY }, { 80, 160 }, { rgbaR.x - 80, rgbaR.y - 80, rgbaR.z - 80, rgbaR.w });//Body
	//		Graphics::DrawCircle({ playerX + 25, playerY - 10 }, 50, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //Head
	//		Graphics::DrawCircle({ playerX + 55, playerY + 70 }, 20, 40, { rgbaC.x, rgbaC.y, rgbaC.z, rgbaC.w }); //hand two
	//		Graphics::DrawRect({ bodyX + 35, bodyY + 150 }, { 40, 20 }, { rgbaR.x, rgbaR.y, rgbaR.z, rgbaR.w });  //foot two
	//	}
	//}
	//Vector<float> Vec3D = { 200, 300, 543 };										//Creates a 3D vector
	//std::cout << "3D Vector Values: (" << Vec3D.x << ", " << Vec3D.y << ", " << Vec3D.z << ")\n";
	//float dotprod = Vec1.DotProduct(Vec2);											//Gets the dotproduct of Vec1 & Vec2
	//std::cout << "Vector Dot Product: " << dotprod << std::endl;
	//Vec3D.Magnitude();																//Creates a variable for the 3D vector magnitude
	//std::cout << "3D Vector Magnitude: " << Vec3D.magnitude << std::endl;
	//Vec3D.Normalize();																//Normalizes the 3D vector
	//Vector<float> Vec3DNi = { 1234, 3213, 8595 };									//Creates another 3D vector
	//Vec3DNi = Vec3DNi - Vec3D;														//Sets the values of the second 3D vector to the vector minus the first 3D vector
	//Vec3DNi = Vec3DNi.CrossProduct(Vec3D);											//Sets the values of the second 3D vector to the crossproduct of the first and second 3D vectors

	Graphics::DrawRect({ p0.x, p0.y }, { 50, 50 }, { 85, 107, 47, 200 });
	p1.x = p0.x + 50;
	p1.y = p0.y;
	p2.x = p0.x;
	p2.y = p0.y + 50;
	p3.x = p0.x + 50;
	p3.y = p0.y + 50;
	Graphics::DrawRect({ q0.x, q0.y }, { 50, 50 }, { 112, 41, 99, 200 });
	q1.x = q0.x + 50;
	q1.y = q0.y;
	q2.x = q0.x;
	q2.y = q0.y + 50;
	q3.x = q0.x + 50;
	q3.y = q0.y + 50;
	int x = p0.x + 25;
	int y = p0.y + 25;
	Graphics::DrawRect({ g0.x, g0.y }, { 50, 50 }, { 178, 255, 255, 200 });
	Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	//case SDLK_b:if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size))) { BULLET(bullet, deltaTime);  break; } else { break; }
	//case SDLK_w: y -= 10; break;
	//case SDLK_s: y += 10; break;
	//case SDLK_d: x += 10; break;
	//case SDLK_a: x -= 10; break;
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
	//case SDLK_UP: if (bodyY > 320) { bodyY -= 10; break; } else { break; }
	//case SDLK_RIGHT: bodyX += 10; left = false; break;
	//case SDLK_LEFT: bodyX -= 10; left = true; break;
	//case SDLK_t: if (inverse) { inverse = false; break; } else { inverse = true; break; }
	//case SDLK_z: if (RGBAC.x < 255) { RGBAC.x += 1; RGBAR.x += 1; break; } else { break; }
	//case SDLK_x: if (RGBAC.x > 0) { RGBAC.x -= 1; RGBAR.x -= 1; break; } else { break; }
	//case SDLK_c: if (RGBAC.y < 255) { RGBAC.y += 1; RGBAR.y += 1; break; } else { break; }
	//case SDLK_v: if (RGBAC.y > 0) { RGBAC.y -= 1; RGBAR.y -= 1; break; } else { break; }
	//case SDLK_n: if (RGBAC.z < 255) { RGBAC.z += 1; RGBAR.z += 1; break; } else { break; }
	//case SDLK_m: if (RGBAC.z > 0) { RGBAC.z -= 1; RGBAR.z -= 1; break; } else { break; }

	case SDLK_w: p1W = true; /*if (y > 100) { y -= 100; break; } else { break; }*/ break;
	case SDLK_s: p1S = true; /*if (y < 800) { y += 100; break; } else { break; }*/ break;
	case SDLK_d: p1D = true; /*if (x < 1150) { x += 100; break; } else { break; }*/ break;
	case SDLK_a: p1A = true; /*if (x > 450) { x -= 100; break; } else { break; }*/ break;
	case SDLK_UP: p2UP = true; /*if (b > 100) { b -= 100; break; } else { break; }*/ break;
	case SDLK_DOWN: p2DOWN = true; /*if (b < 800) { b += 100; break; } else { break; }*/ break;
	case SDLK_RIGHT: p2RIGHT = true; /*if (a < 1150) { a += 100; break; } else { break; }*/ break;
	case SDLK_LEFT: p2LEFT = true; /*if (a > 450) { a -= 100; break; } else { break; }*/ break;
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
	case SDLK_d: p1D = false; break;
	case SDLK_a: p1A = false; break;
	case SDLK_UP: p2UP = false; break;
	case SDLK_DOWN: p2DOWN = false; break;
	case SDLK_RIGHT: p2RIGHT = false; break;
	case SDLK_LEFT: p2LEFT = false; break;
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
