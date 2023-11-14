// rectanglesolver.h
#pragma once

#include <stdio.h>
#include <stdbool.h>

float calculateDistance(int x1, int y1, int x2, int y2);
bool formsRectangle(int x[], int y[]);
void sortCorners(int* x, int* y);
char* analyzeRectangle(int x[], int y[], int distances[4]);
bool checkForRectangle(int length, int width);
int rectanglePerimeter(int length, int width);
int rectangleArea(int length, int width);
bool SortingCorners(int* x, int* y);  // Add declaration for SortingCorners



//#pragma once
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//char* analyzeRectangle(int x[], int y[], int distances[4]);
//bool checkForRectangle(int length, int width);
//float calculateDistance(int, int, int, int);
//bool FormsRectangle(int*, int*);
//bool SortingCorners(int* x, int* y, int* distances);