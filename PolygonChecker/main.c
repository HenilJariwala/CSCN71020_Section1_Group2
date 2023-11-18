#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include"rectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);

			//Angles of triangle
			int triangleAngles[3] = { 0, 0, 0 };
			int r = find_angles_of_triangle(triangleSides, triangleAngles);

			bool is_valid = checkForTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (is_valid == true)
			{
				printf("Forms a triangle\n");
				char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
				printf_s("%s\n", result);
			}
			else
			{
				printf("Does not form a triangle\n");
			}
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			int x[4];
			int y[4];
			for (int i = 0;i < 4;i++)
			{
				printf("Enter the x coordinate of a corner:");
				int numparsed1 = scanf_s("%d", &x[i]);
				printf("Enter y coordinate of that corner:");
				int numparsed2 = scanf_s("%d", &y[i]);
				if (numparsed1 != 1 || numparsed2 != 1)
				{
					printf("Incorrect input\n");
					return EXIT_FAILURE;
				}
			}
			bool flag = formsRectangle(&x, &y);
			if (flag == true)
			{
				SortingCorners(&x,&y);
				printf("Forms a rectangle\n");
				printf("The corners of rectangle in order are:\n");
				for (int i = 0; i < 4;i++)
				{
					printf("%d is ( %d , %d)\n", (i + 1), x[i], y[i]);
				}
				float length = calculateDistance(x[0],y[0],x[1],y[1]);
				float width = calculateDistance(x[1], y[1],x[2], y[2]);
				float perimeter = rectanglePerimeter(length, width);
				float area = rectangleArea(length, width);
				printf("\nPerimeter is %f\nArea is %f\n",perimeter, area);
			}
			else
			{
				printf("Does not form a rectangle\n");
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		int numparsed = scanf_s("%d", &triangleSides[i]);
		if (numparsed != 1 || triangleSides[i] <= 0)
		{
			printf("Not a valid input\n");
			exit(EXIT_FAILURE);
		}
	}
	return triangleSides;
}