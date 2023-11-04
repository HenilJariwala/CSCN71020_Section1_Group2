#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}
bool checkForTriangle(int side1, int side2, int side3)
{
	if (((side1 + side2) > side3) && ((side1 + side3) > side2) && ((side2 + side3) > side1))
	{
		return true;
	}
	return false;
}

int find_angles_of_triangle(int* triangleSides, float* trianglesAngle) {

	//Formula to find (Side3)^2 = (Side1)^2 + (Side2)^2 - 2*(Side1)*(Side2)*(cos Side3)
	//This is to find third angle 

	int side3square = pow(triangleSides[2], 2);
	int side2square = pow(triangleSides[1], 2);
	int side1square = pow(triangleSides[0], 2);

	//Get the 3rd angle
	float Cal_Side3 = acos((float)(side1square + side2square - side3square) / (2 * triangleSides[0] * triangleSides[1]));
	trianglesAngle[2] = Cal_Side3 * (180 / M_PI);

	//Get the 2nd angle
	float Cal_Side2 = acos((float)(side1square + side3square - side2square) / (2 * triangleSides[0] * triangleSides[2]));
	trianglesAngle[1] = Cal_Side2 * (180 / M_PI);

	//To get the last number we need to subtract the sum of two by 180
	trianglesAngle[0] = 180 - (trianglesAngle[1] + trianglesAngle[2]);



	/*for (int i = 0;i < 3;i++) {
		printf("side %d: %lF\n", (i+1),trianglesAngle[i]);
	}
	return 0;*/

	return trianglesAngle;

}