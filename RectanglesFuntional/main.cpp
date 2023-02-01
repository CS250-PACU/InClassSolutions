//**********************************************************************
// File name:		 main.cpp
// Author:			 CS Faculty
// Date:				 2/1/2023
// Class:				 CS250
// Assignment:	 In-class examples
// Purpose:			 Practice with arrays of structs and functions
//**********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

struct Rectangle {
	double length, width;
};

int readRectangles (Rectangle[], const int);
void displayRectangles (const Rectangle[], const int);
double getArea (const Rectangle);
Rectangle getLargest (const Rectangle[], const int);

//*********************************************************************
// Function:		main
//
// Description: Practice with functions and arrays of structs
// 
// Parameters:	None
//
// Returned:		EXIT_SUCCESS
//*********************************************************************

int main () {
	const int MAX = 50;

	Rectangle sRectangles[MAX];
	int count;
	Rectangle sLargest;

	count = readRectangles(sRectangles, MAX);

	cout << "Here are the rectangles from the file: \n";
	displayRectangles (sRectangles, count);

	sLargest = getLargest (sRectangles, count);
	cout << "\nLargest is:\n" << "Length: " << sLargest.length
		   << ", Width: " << sLargest.width;

	cout << "\n\nprogram ended successfully" << endl << endl;
	return EXIT_SUCCESS;
}

//*********************************************************************
// Function:		readRectangles
//
// Description: Reads Rectangle structs from file into array
// 
// Parameters:	sRectangles - Array of rectangle structs
//							MAX - Maximum number of objects in array
//
// Returned:		Number of structs read into the array
//*********************************************************************

int readRectangles (Rectangle sRectangles[], const int MAX) {
	ifstream myFile;
	int count = 0;
	 
	myFile.open ("rectangles.txt");
	if (myFile.fail ()) {
		cout << "Could not open file" << endl;
		exit (EXIT_FAILURE);
	}

	while (myFile >> sRectangles[count].length && count < MAX) {
		myFile >> sRectangles[count].width;
		count++;
	}

	myFile.close ();

	return count;
}

//*********************************************************************
// Function:		displayRectangles
//
// Description: Sum the numbers from 0 to 10
// 
// Parameters:	sRectangles - Array of rectangle structs
//							size - number of rectangle structs in array
//
// Returned:		EXIT_SUCCESS
//*********************************************************************

void displayRectangles (const Rectangle sRectangles[], const int size){
	for (int i = 0; i < size; i++) {
		cout << "Length: " << sRectangles[i].length << ", Width: "
			   << sRectangles[i].width << endl;
	}
}

//*********************************************************************
// Function:		getArea
//
// Description: Computes area of since Rectangle struct
// 
// Parameters:	sRecangle - Rectangle struct
//
// Returned:		area of rectangle struct
//*********************************************************************

double getArea (const Rectangle sRectangle) {
	return sRectangle.length * sRectangle.width;
}

//*********************************************************************
// Function:		getLargest
//
// Description: Determines Rectangle struct with largest area
// 
// Parameters:	sRectangles - Array of rectangle structs
//							size - number of rectangle structs in array
//
// Returned:		Rectangle struct with the largest area
//*********************************************************************

Rectangle getLargest (const Rectangle sRectangles[], const int size) {
	int indexLargest = 0;
	double largestArea = getArea (sRectangles[indexLargest]);

	for (int i = 0; i < size; i++) {
		if (getArea (sRectangles[i]) > largestArea) {
			indexLargest = i;
			largestArea = getArea (sRectangles[i]);
		}
	}
	return sRectangles[indexLargest];
}