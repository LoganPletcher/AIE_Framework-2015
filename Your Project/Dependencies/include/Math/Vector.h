#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector		//Vector class to perform vector equations.
{
public:
	Vector<T>();							//Default constructor for the Vector class.
	Vector<T>(T, T);						//Manual constructor for a 2D Vector class.
	Vector<T>(T, T, T);						//Manual constructor for a 3D Vector class.
	Vector<T>(T, T, T, T);					//Manual constructor for a 4D Vector class.
	T x, y, z, w;							//Creates the x, y, and z variables to represent the x, y, and z values for Vectors.
	template <typename T>
	Vector<T> operator+(Vector<T> other)	//Overloads the addition operator to allow for Vectors to be added together.
	{
		Vector<T> temp;
		temp.x = x + other.x;				//Sets the temp x variable to the sum of the x variable of the overloaded operator calling Vector and the x variable
											//of the parameter Vector.
		temp.y = y + other.y;				//Sets the temp y variable to the sum of the y variable of the overloaded operator calling Vector and the y variable
											//of the parameter Vector.
		temp.z = z + other.z;				//Sets the temp z variable to the sum of the z variable of the overloaded operator calling Vector and the z variable
											//of the parameter Vector.
		temp.w = w + other.w;				//Sets the temp w variable to the sum of the w variable of the overloaded operator calling Vector and the w variable
											//of the parameter Vector.
		return temp;						//Returns the temp Vector.
	}
	template <typename T>
	Vector<T> operator-(Vector<T> other)	//Overloads the subtraction operator to allow a Vector to subtract the values of another Vector.
	{
		Vector<T> temp;
		temp.x = x - other.x;				//Sets the temp x variable to the difference of the x variable of the overloaded operator calling Vector and the x
											//variable of the parameter Vector.
		temp.y = y - other.y;				//Sets the temp y variable to the difference of the y variable of the overloaded operator calling Vector and the y
											//variable of the parameter Vector.
		temp.z = z - other.z;				//Sets the temp z variable to the difference of the z variable of the overloaded operator calling Vector and the z
											//variable of the parameter Vector.
		temp.w = w - other.w;				//Sets the temp w variable to the difference of the w variable of the overloaded operator calling Vector and the w
											//variable of the parameter Vector.
		return temp;						//Returns the temp Vector.
	}
	template <typename T>
	Vector<T> operator*(Vector<T> other)	//Overloads the multiplication operator to allow for Vectors to be multiplied by each other.
	{
		Vector<T> temp;
		temp.x = x * other.x;				//Sets the temp x variable to the product of the x variable of the overloaded operator calling Vector and the x
											//variable of the parameter Vector.
		temp.y = y * other.y;				//Sets the temp y variable to the product of the y variable of the overloaded operator calling Vector and the y
											//variable of the parameter Vector.
		temp.z = z * other.z;				//Sets the temp z variable to the product of the z variable of the overloaded operator calling Vector and the z
											//variable of the parameter Vector.
		temp.w = w * other.w;				//Sets the temp w variable to the product of the w variable of the overloaded operator calling Vector and the w
											//variable of the parameter Vector.
		return temp;						//Returns the temp Vector.
	}
	T magnitude;							//Creates the magnitude variable to hold the value of a Vector's magnitude.
	T Magnitude();							//Multiplies the Vector by itself, adds the resulting x, y, & z values together and retrieves the square root of 
											//the result to find the magnitude.
	Vector<T> Normalize();					//Divides the Vectors x, y, z, & magnitude by it's magnitude and assigns the results to a temporary Vector for
											//assinging the values to a Vector.
	T DotProduct(Vector<T>);				//Gets the dot product of two Vectors and stores it in a temporary variable.
	Vector<T> CrossProduct(Vector<T>);		//Gets the cross product of two Vectors and stores it in a temporary Vector.
	T Interpolation(T, T, float);			//Takes in any two standard data types and a float for decimal percentage and calculates the number at the percentage
											//between the two data types.
	Vector<T> HexConv(char[8]);				//Converts hexadecimal code to an RGB vector.
private:
};

template <typename T>
Vector<T>::Vector()
{
	x = 0.0;			//Sets the x variable to 0.0.
	y = 0.0;			//Sets the y variable to 0.0.
	z = 0.0;			//Sets the z variable to 0.0.
	w = 0.0;			//Sets the w variable to 0.0.
}

template <typename T>
Vector<T>::Vector(T a, T b)
{
	x = a;				//Sets the x variable to the manual constructor value a.
	y = b;				//Sets the y variable to the manual constructor value b.
	z = 0.0;			//Sets the z variable to 0.0.
	w = 0.0;			//Sets the w variable to 0.0.
}

template <typename T>
Vector<T>::Vector(T a, T b, T c)
{
	x = a;				//Sets the x variable to the manual constructor value a.
	y = b;				//Sets the y variable to the manual constructor value b.
	z = c;				//Sets the z variable to the manual constructor value c.
	w = 0.0;			//Sets the w variable to 0.0.
}

template <typename T>
Vector<T>::Vector(T a, T b, T c, T d)
{
	x = a;				//Sets the x variable to the manual constructor value a.
	y = b;				//Sets the y variable to the manual constructor value b.
	z = c;				//Sets the z variable to the manual constructor value c.
	w = d;				//Sets the w variable to the manual constructor value d.
}

template <typename T>
T Vector<T>::Magnitude()
{
	Vector<T> temp = *this * *this;							//Multiplies the Magnitude function calling Vector by itself and sets the value of the temp vector to the product.
	magnitude = sqrt(temp.x + temp.y + temp.z + temp.w);	//Adds the x, y, z, and w variables of the temp Vector and finds the square root of the sum and sets the value to
															//the magnitude variable of the Magnitude function calling Vector.
	return magnitude;										//Returns the magnitude.
}

template <typename T>
Vector<T> Vector<T>::Normalize()
{
	Vector<T> temp;
	temp.x = x / magnitude;						//Sets the value of the temp x variable to the quotient of the Normalize function calling Vector's x and magnitude variables.
	temp.y = y / magnitude;						//Sets the value of the temp y variable to the quotient of the Normalize function calling Vector's y and magnitude variables.
	temp.z = z / magnitude;						//Sets the value of the temp z variable to the quotient of the Normalize function calling Vector's z and magnitude variables.
	temp.w = w / magnitude;						//Sets the value of the temp w variable to the quotient of the Normalize function calling Vector's w and magnitude variables.
	temp.magnitude = magnitude / magnitude;		//Sets the value of the temp magnitude variable to the quotient of the magnitude variable divided by the magnitude variable, 
												//both the magnitude variable of the Normalize function calling Vector.
	return temp;								//Returns the temp Vector.
}

template <typename T>
T Vector<T>::DotProduct(Vector<T> other)
{
	T dotprod;
	dotprod = ((x*other.x) + (y*other.y) + (z*other.z) + (w*other.w));	//Multiplies the x variable by the other x variable, multiplies the y variable by the other y variable
																		//Multiplies the z variable by the other z variable, multiplies the w variable by the other w variable
																		//Then takes the products of all the multiplication equations and adds them all together, setting the
																		//sum as the dotprod value.
	return dotprod;														//Returns the dotprod.
}

template <typename T>
Vector<T> Vector<T>::CrossProduct(Vector<T> other)
{
	Vector<T> temp;
	temp.x = ((y*other.z) - (z*other.y));		//Multiplies the y variable by the other z variable and multiplies the z variable by the other y variable. It then takes the
												//products of the two equations and gets the difference, setting the difference as the temp x variable.
	temp.y = ((z*other.x) - (x*other.z));		//Multiplies the z variable by the other x variable and multiplies the x variable by the other z variable. It then takes the
												//products of the two equations and gets the difference, setting the difference as the temp y variable.
	temp.z = ((x*other.y) - (y*other.x));		//Multiplies the x variable by the other y variable and multiplies the y variable by the other x variable. It then takes the
												//products of the two equations and gets the difference, setting the difference as the temp z variable.
	return temp;								//Returns the temp Vector.
}

template <typename T>
T Vector<T>::Interpolation(T a, T b, float t)
{
	T L;
	L = a + t * (b - a);	//gets the difference between b and a, multiplies that difference by t, takes the product and adds it to a, sets the value of L to the sum.
	return L;				//Returns L.
}

template <typename T>
Vector<T> Vector<T>::HexConv(char HEX[8])
{
	float holder;
	Vector<float> HEXVEC;
	if (HEX[0] == '#')													//An if statement is created if the inputted char string has the # in front to identify it as a
	{																	//hexadecimal code.
		for (int i = 1; i < 7; i++)										//A for loop is created to check each char in the char string after HEX[0]. The for loop will stop
		{																//once i is no longer less than 7.
			if (HEX[i] == '0') { holder = 0; }							//Checks to see if the current selected char of the char string is 0. If so the holder variable is
																		//givena value of 0.
			else if (HEX[i] == '1')										//Checks to see if the current selected char of the char string is 1.
			{ if (i == 1 || i == 3 || i == 5) { holder = 16; }			//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 1; } }									//variable is fiven the value of 16. If not the holder variable is given the value of 1.
			else if (HEX[i] == '2')										//Checks to see if the current selected char of the char string is 2.
			{ if (i == 1 || i == 3 || i == 5) { holder = 32; }			//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 2; } }									//variable is fiven the value of 32. If not the holder variable is given the value of 2.
			else if (HEX[i] == '3') {									//Checks to see if the current selected char of the char string is 3.
				if (i == 1 || i == 3 || i == 5) { holder = 48; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 3; } }									//variable is fiven the value of 48. If not the holder variable is given the value of 3.
			else if (HEX[i] == '4') {									//Checks to see if the current selected char of the char string is 4.
				if (i == 1 || i == 3 || i == 5) { holder = 64; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 4; } }									//variable is fiven the value of 64. If not the holder variable is given the value of 4.
			else if (HEX[i] == '5') {									//Checks to see if the current selected char of the char string is 5.
				if (i == 1 || i == 3 || i == 5) { holder = 80; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 5; } }									//variable is fiven the value of 80. If not the holder variable is given the value of 5.
			else if (HEX[i] == '6') {									//Checks to see if the current selected char of the char string is 6.
				if (i == 1 || i == 3 || i == 5) { holder = 96; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 6; } }									//variable is fiven the value of 96. If not the holder variable is given the value of 6.
			else if (HEX[i] == '7') {									//Checks to see if the current selected char of the char string is 7.
				if (i == 1 || i == 3 || i == 5) { holder = 112; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 7; } }									//variable is fiven the value of 112. If not the holder variable is given the value of 7.
			else if (HEX[i] == '8') {									//Checks to see if the current selected char of the char string is 8.
				if (i == 1 || i == 3 || i == 5) { holder = 128; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 8; } }									//variable is fiven the value of 128. If not the holder variable is given the value of 8.
			else if (HEX[i] == '9') {									//Checks to see if the current selected char of the char string is 9.
				if (i == 1 || i == 3 || i == 5) { holder = 144; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 9; } }									//variable is fiven the value of 144. If not the holder variable is given the value of 9.
			else if (HEX[i] == 'A') {									//Checks to see if the current selected char of the char string is A.
				if (i == 1 || i == 3 || i == 5) { holder = 160; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 10; } }									//variable is fiven the value of 160. If not the holder variable is given the value of 10.
			else if (HEX[i] == 'B') {									//Checks to see if the current selected char of the char string is B.
				if (i == 1 || i == 3 || i == 5) { holder = 176; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 11; } }									//variable is fiven the value of 176. If not the holder variable is given the value of 11.
			else if (HEX[i] == 'C') {									//Checks to see if the current selected char of the char string is C.
				if (i == 1 || i == 3 || i == 5) { holder = 192; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 12; } }									//variable is fiven the value of 192. If not the holder variable is given the value of 12.
			else if (HEX[i] == 'D') {									//Checks to see if the current selected char of the char string is D.
				if (i == 1 || i == 3 || i == 5) { holder = 208; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 13; } }									//variable is fiven the value of 208. If not the holder variable is given the value of 13.
			else if (HEX[i] == 'E') {									//Checks to see if the current selected char of the char string is E.
				if (i == 1 || i == 3 || i == 5) { holder = 224; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 14; } }									//variable is fiven the value of 224. If not the holder variable is given the value of 14.
			else if (HEX[i] == 'F') {									//Checks to see if the current selected char of the char string is F.
				if (i == 1 || i == 3 || i == 5) { holder = 240; }		//A secondary if statement is then run to see if the i is equal to 1, 3, or 5. If so the holder
				else { holder = 15; } }									//variable is fiven the value of 240. If not the holder variable is given the value of 15.
			else{														//If the selected char of the char string does not match any of the above if statements it is an
				HEXVEC.x = 0; HEXVEC.y = 0; HEXVEC.z = 0;				//invalid Hexadecimal code. It will change all RGB values to 0 and print out "Invalid Hexadecimal
				std::cout << "Invalid Hexadecimal Code\n"; break; }		//Code" and then break out of the for loop.

			if (i == 1) { HEXVEC.x = holder; }							//Another set of if statements are run that check the current value of i so the holder variable can
			else if (i == 2) { HEXVEC.x += holder; }					//be properly assigned to the variables of HEXVEC. If it is 1 then it assigns the current value of
			else if (i == 3) { HEXVEC.y = holder; }						//holder to HEXVEC.x. If it is 2 then it adds the current value of holder to HEXVEC.x. If it is 3
			else if (i == 4) { HEXVEC.y += holder; }					//then it assigns the current value of holder to HEXVEC.y. If it is 4 then it adds the current value 
			else if (i == 5) { HEXVEC.z = holder; }						//of holder to HEXVEC.y. If it is 5 then it assigns the value of holder to HEXVEC.z. If it is none
			else { HEXVEC.z += holder; }								//of the above if statements then the value of holder is added to HEXVEC.z.
		}
		HEXVEC.w = 255;			//After the for loop is complete it assigns the value of 255 to HEXVEC.w
	}
	else												//In the case the char string does not start with # it is considered invalid and the RGB values will all be set to 0
	{	HEXVEC.x = 0; HEXVEC.y = 0; HEXVEC.z = 0;		//and it will print out "Invalid Hexadecimal Code" to the command console.
		std::cout << "Invalid Hexadecimal Code\n";	}
	std::cout << HEXVEC.x << ", " << HEXVEC.y << ", " << HEXVEC.z << ", " << HEXVEC.w << std::endl;	//Outputs the values of HEXVEC x, y, z, and w to the command console.
	return HEXVEC;		//Returns the HEXVEC vector.
}

template <typename T>
T rad(T degree)						//Converts an inputted degree value into radians.
{
	T radians = degree / 57.296;	//Divides the degree variable by 57.296 and assigns the quotient to the radians variable.
	return radians;					//Returns radians.
}

template <typename T>
T deg(T radians)						//Converts an inputted radian value into degrees.
{
	T degree = radians * 57.296;		//Multiplies the radian variable by 57.296 and assigns the product to the degree variable.
	return degree;						//Returns degree.
}

#endif VECTOR_H