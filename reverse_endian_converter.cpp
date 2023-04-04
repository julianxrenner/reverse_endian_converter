/*
Name: Julian Renner
Date: Feb 17, 2023
Decription: write a program named assignment 6 that prompts the user to 
enter an unsigned integer in base 10 then prints the way it is stored in big and little endian
*/
#include <iomanip>	//allows the program to use formatting options like setw
#include <iostream>	//allows the program to use input and output
#include <fstream>	//allows the progrom to use files
#include <cmath>    //allows use of math operations
#include <string>	// allows use of strtok

using namespace std;	//allows the program to use cout and cin

const int INTSIZE = 4; // in bytes
const int BYTESIZE = 8; // in bits
const int NIBSIZE = 4; // nibble, in bits

union integer4 {	//creates a union named integer4
	unsigned int intrep;	//unsigned int representing a number
	unsigned char byterep[INTSIZE];	//array of bytes
};


void prHex(unsigned char b) {	//function that prints in hexadecimal
	const char hexChars[] = "0123456789ABCDEF";		//hex digits
	cout << hexChars[b >> 4] << hexChars[b & 0x0F] << ' ';	//converts to hexadecimal and prints
}

void prBin(unsigned char b) {	//function that prints in binary
	for (int i = BYTESIZE - 1; i >= 0; i--) {	//iterates each bit of the byte
		int bit = (b >> i) & 1;		//takes the i-th bit of the byte
		cout << bit;	
		if (i % BYTESIZE == 0) {	//adds a space between each byte
			cout << ' '; 
		}
	}
}

int main()	//starts the code
{
	integer4 num;	//declare a variable named integer4

	cout << "Enter an unsigned integer in base 10 => " << endl;	//prompts the user to enter a base 10 integer
	cin >> num.intrep;	// read and store the number entered in integer4 variable
		
	cout << "In hex: " << endl;	//prints the output in hex
	for (int a = 0; a < INTSIZE; a++)	//for loop
	{
		prHex(num.byterep[a]);	//print hexadecimal value
	}
	cout << endl;	//ends the line

	cout << "In binary: " << endl;	//print sthe output in binary
	for (int a = 0; a < INTSIZE; a++)	//for loop
	{
		prBin(num.byterep[a]);	//print the binary value of the byte
	}
	cout << endl;

	cout << endl << "Reverse Endian " << endl << "In hex: " << endl;	//Now it does reverse endian and changes how the data is stored
	for (int a = INTSIZE - 1; a >= 0; a--) //for loop in reverse
	{
		prHex(num.byterep[a]);	//prints the value in hex
	}
	cout << endl;	//ends the line

	cout << "In bin: " << endl;	//prints in binary
	for (int a = INTSIZE - 1; a >= 0; a--)	//for loop in reverse
	{
		prBin(num.byterep[a]);	//prints the value in binary
	}
	cout << endl;	//ends the line
	return 0;	//ends the code
}