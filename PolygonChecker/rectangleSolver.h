#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
char* analyzeRectangle(int x[], int y[], int distances[4]);
bool checkForRectangle(int length, int width);
float calculateDistance(int, int, int, int);
bool FormsRectangle(int*, int*);
bool SortingCorners(int* x, int* y, int* distances);