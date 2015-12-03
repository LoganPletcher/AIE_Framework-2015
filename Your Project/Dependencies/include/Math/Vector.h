#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector		//Vector class to perform vector equations
{
public:
	Vector<T>();							//Default constructor for the Vector class
	Vector<T>(T, T);						//Manual constructor for a 2D Vector class
	Vector<T>(T, T, T);						//Manual constructor for a 3D Vector class
	Vector<T>(T, T, T, T);					//Manual constructor for a 4D Vector class
	T x, y, z, w;								//Creates the x, y, and z variables to represent the x, y, and z values for Vectors
	template <typename T>
	Vector<T> operator+(Vector<T> other)	//Overloads the addition operator to allow for Vectors to be added together
	{
		Vector<T> temp;
		temp.x = x + other.x;
		temp.y = y + other.y;
		temp.z = z + other.z;
		temp.w = w + other.w;

		return temp;
	}
	template <typename T>
	Vector<T> operator-(Vector<T> other)	//Overloads the subtraction operator to allow a Vector to subtract the values of another Vector
	{
		Vector<T> temp;
		temp.x = x - other.x;
		temp.y = y - other.y;
		temp.z = z - other.z;
		temp.w = w - other.w;

		return temp;
	}
	template <typename T>
	Vector<T> operator*(Vector<T> other)	//Overloads the multiplication operator to allow for Vectors to be multiplied by each other
	{
		Vector<T> temp;
		temp.x = x * other.x;
		temp.y = y * other.y;
		temp.z = z * other.z;
		temp.w = w * other.w;

		return temp;
	}
	T magnitude;							//Creates the magnitude variable to hold the value of a Vector's magnitude
	T Magnitude();							//Multiplies the Vector by itself, adds the resulting x, y, & z values together and retrieves the square root of the result to find the magnitude
	Vector<T> Normalize();					//Divides the Vectors x, y, z, & magnitude by it's magnitude and assigns the results to a temporary Vector for assinging the values to a Vector
	T DotProduct(Vector<T>);				//Gets the dot product of two Vectors and stores it in a temporary variable
	Vector<T> CrossProduct(Vector<T>);		//Gets the cross product of two Vectors and stores it in a temporary Vector
	Vector<T> Interpolation(Vector<T>, float);		//Finds a new Vector that lies somewhere between two Vectors.
	Vector<T> Vector<T>::HexConv(char[8]);	//Converts hexadecimal code to an RGB vector
private:

};

template <typename T>
Vector<T>::Vector()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
	w = 0.0;
}

template <typename T>
Vector<T>::Vector(T a, T b)
{
	x = a;
	y = b;
	z = 0.0;
	w = 0.0;
}

template <typename T>
Vector<T>::Vector(T a, T b, T c)
{
	x = a;
	y = b;
	z = c;
	w = 0.0;
}

template <typename T>
Vector<T>::Vector(T a, T b, T c, T d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

template <typename T>
T Vector<T>::Magnitude()
{
	Vector<T> temp = *this * *this;
	magnitude = sqrt(temp.x + temp.y + temp.z + temp.w);

	return magnitude;
}

template <typename T>
Vector<T> Vector<T>::Normalize()
{
	Vector<T> temp;
	temp.x = x / magnitude;
	temp.y = y / magnitude;
	temp.z = z / magnitude;
	temp.w = w / magnitude;
	temp.magnitude = magnitude / magnitude;

	return temp;
}

template <typename T>
T Vector<T>::DotProduct(Vector<T> other)
{
	T dotprod;
	dotprod = ((x*other.x) + (y*other.y) + (z*other.z) + (w*other.w));

	return dotprod;
}

template <typename T>
Vector<T> Vector<T>::CrossProduct(Vector<T> other)
{
	Vector<T> temp;
	temp.x = ((y*other.z) - (z*other.y));
	temp.y = ((z*other.x) - (x*other.z));
	temp.z = ((x*other.y) - (y*other.x));
	
	return temp;
}

template <typename T>
Vector<T> Vector<T>::Interpolation(Vector<T> other, float t)
{
	Vector<float> L;
	L.x = (1 - t) * x + t * other.x;
	L.y = (1 - t) * y + t * other.y;
	L.z = (1 - t) * z + t * other.z;
	L.w = (1 - t) * w + t * other.w;
	return L;
}

template <typename T>
Vector<T> Vector<T>::HexConv(char HEX[8])
{
	float holder;
	Vector<float> HEXVEC;
	if (HEX[0] == '#')
	{
		for (int i = 1; i < 7; i++)
		{
			if (HEX[i] == '0') { holder = 0; }
			else if (HEX[i] == '1') 
			{ if (i == 1 || i == 3 || i == 5) { holder = 16; }
				else { holder = 1; } }
			else if (HEX[i] == '2') 
			{ if (i == 1 || i == 3 || i == 5) { holder = 32; }
				else { holder = 2; } }
			else if (HEX[i] == '3') {
				if (i == 1 || i == 3 || i == 5) { holder = 48; }
				else { holder = 3; } }
			else if (HEX[i] == '4') {
				if (i == 1 || i == 3 || i == 5) { holder = 64; }
				else { holder = 4; } }
			else if (HEX[i] == '5') {
				if (i == 1 || i == 3 || i == 5) { holder = 80; }
				else { holder = 5; } }
			else if (HEX[i] == '6') {
				if (i == 1 || i == 3 || i == 5) { holder = 96; }
				else { holder = 6; } }
			else if (HEX[i] == '7') {
				if (i == 1 || i == 3 || i == 5) { holder = 112; }
				else { holder = 7; } }
			else if (HEX[i] == '8') {
				if (i == 1 || i == 3 || i == 5) { holder = 128; }
				else { holder = 8; } }
			else if (HEX[i] == '9') {
				if (i == 1 || i == 3 || i == 5) { holder = 144; }
				else { holder = 9; } }
			else if (HEX[i] == 'A') {
				if (i == 1 || i == 3 || i == 5) { holder = 160; }
				else { holder = 10; } }
			else if (HEX[i] == 'B') {
				if (i == 1 || i == 3 || i == 5) { holder = 176; }
				else { holder = 11; } }
			else if (HEX[i] == 'C') {
				if (i == 1 || i == 3 || i == 5) { holder = 192; }
				else { holder = 12; } }
			else if (HEX[i] == 'D') {
				if (i == 1 || i == 3 || i == 5) { holder = 208; }
				else { holder = 13; } }
			else if (HEX[i] == 'E') {
				if (i == 1 || i == 3 || i == 5) { holder = 224; }
				else { holder = 14; } }
			else if (HEX[i] == 'F') {
				if (i == 1 || i == 3 || i == 5) { holder = 240; }
				else { holder = 15; } }

			if (i == 1) { HEXVEC.x = holder; }
			else if (i == 2) { HEXVEC.x += holder; }
			else if (i == 3) { HEXVEC.y = holder; }
			else if (i == 4) { HEXVEC.y += holder; }
			else if (i == 5) { HEXVEC.z = holder; }
			else { HEXVEC.z += holder; }
		}
		HEXVEC.w = 255;
	}
	std::cout << HEXVEC.x << ", " << HEXVEC.y << ", " << HEXVEC.z << ", " << HEXVEC.w << std::endl;
	return HEXVEC;
}

#endif VECTOR_H