#include <iostream>
#include <fstream>

using namespace std;

struct Rectangle {
	double length, width;
};

int readRectangles(Rectangle[], const int);
void displayRectangles(const Rectangle[], const int);
double getArea(const Rectangle);
Rectangle getLargest(const Rectangle[], const int);

int main() {
	const int MAX = 50;

	Rectangle sRectangles[MAX];
	int count;
	Rectangle sLargest;

	count = readRectangles(sRectangles, MAX);

	cout << "Here are the rectangles from the file: \n";
	displayRectangles(sRectangles, count);

	sLargest = getLargest(sRectangles, count);
	cout << "\nLargest is:\n" << "Length: " << sLargest.length
		<< ", Width: " << sLargest.width;

	cout << "\n\nprogram ended successfully" << endl << endl;
	return EXIT_SUCCESS;
}

int readRectangles(Rectangle sRectangles[], const int MAX) {
	ifstream myFile;
	int count = 0;

	myFile.open("rectangles.txt");
	if (myFile.fail()) {
		cout << "Could not open file" << endl;
		exit(EXIT_FAILURE);
	}

	while (myFile >> sRectangles[count].length && count < MAX) {
		myFile >> sRectangles[count].width;
		count++;
	}

	myFile.close();

	return count;
}

void displayRectangles(const Rectangle sRectangles[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Length: " << sRectangles[i].length << ", Width: "
			<< sRectangles[i].width << endl;
	}
}

double getArea(const Rectangle sRectangle) {
	return sRectangle.length * sRectangle.width;
}

Rectangle getLargest(const Rectangle sRectangles[], const int size) {
	int indexLargest = 0;
	double largestArea = getArea(sRectangles[indexLargest]);

	for (int i = 0; i < size; i++) {
		if (getArea(sRectangles[i]) > largestArea) {
			indexLargest = i;
			largestArea = getArea(sRectangles[i]);
		}
	}
	return sRectangles[indexLargest];
}