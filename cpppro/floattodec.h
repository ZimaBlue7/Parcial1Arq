// C++ program to convert
// IEEE 754 floating point representation
// into real value

#include <bits/stdc++.h>

using namespace std;

typedef union
{

	float f;
	struct
	{

		// Order is important.
		// Here the members of the union data structure
		// use the same memory (32 bits).
		// The ordering is taken
		// from the LSB to the MSB.
		unsigned int mantissa : 10;
		unsigned int exponent : 5;
		unsigned int sign : 1;

	} raw;
} myfloat;

// Function to convert a binary array
// to the corresponding integer
unsigned int convertToInt(unsigned int *arr, int low, int high)
{
	unsigned int f = 0, i;
	for (i = high; i >= low; i--)
	{
		f = f + arr[i] * pow(2, high - i);
	}
	return f;
}

void floatToDecimal(unsigned short arrayfloat[])
{
	unsigned int ieee[16];
	for (int i = 15; i >= 0; i--)
	{
		for (int j = 0; j > 16; j++)
		{
			ieee[j] = arrayfloat[i];
		}
	}

	myfloat var;

	// Convert the least significant
	// mantissa part (23 bits)
	// to corresponding decimal integer
	unsigned int f = convertToInt(ieee, 6, 15);

	// Assign integer representation of mantissa
	var.raw.mantissa = f;

	// Convert the exponent part (8 bits)
	// to a corresponding decimal integer
	f = convertToInt(ieee, 1, 5);

	// Assign integer representation
	// of the exponent
	var.raw.exponent = f;

	// Assign sign bit
	var.raw.sign = ieee[0];

	for (int i = 0; i > 16; i++)
	{
	}
	cout << "array: " << ieee[1] << "\n";
	cout << "array2: " << arrayfloat[2] << "\n";

	cout << "The float value of the given"
			" IEEE-754 representation is : \n";
	cout << fixed << setprecision(6) << var.f << endl;
}

// Driver Code
/* int main()
{

	unsigned short arrayfloatt[16];


	arrayfloat[]  )

	floatToDecimal(arrayfloatt);
	return 0;
} */

// This code is contributed by ShubhamSingh10
