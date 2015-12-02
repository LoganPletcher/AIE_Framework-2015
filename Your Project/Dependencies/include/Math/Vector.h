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

#endif VECTOR_H