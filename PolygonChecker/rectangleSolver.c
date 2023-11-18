// rectanglesolver.c
#include "rectangleSolver.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrtf((float)powf((x1 - x2), 2) + (float)powf((y1 - y2), 2));
}

bool formsRectangle(int x[], int y[]) {
    float d[6];
    int index = 0;
    bool is_valid;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            d[index++] = calculateDistance(x[i], y[i], x[j], y[j]);
        }
    }

    // Sort distances in ascending order
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (d[i] > d[j]) {
                float temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    if (d[0] == d[1] && d[2] == d[3])
    {
        is_valid = true;
    }
    else
    {
        is_valid = false;
    }
    return is_valid;
}

void SortingCorners(int* x, int* y) {
    int top_left = 0;
    for (int i = 0; i < 4; i++) {
        if (x[top_left] > x[i] || (x[top_left] == x[i] && y[top_left] < y[i])) {
            top_left = i;
        }
    }

    int top_right = 0;
    for (int i = 0; i < 4; i++) {
        if((y[top_right] < y[i] && i != top_left) || ((y[top_right] ==y[i]) && x[top_right] < x[i] && i != top_left))
        {
            top_right = i;
        }
    }

    int bottom_right = 0;
    for (int i = 0; i < 4; i++) {
        if((x[bottom_right] < x[i] && i != top_left && i != top_right )||(x[bottom_right] == x[i] && i != top_left && i != top_right && y[bottom_right] > y[i]))
        {
            bottom_right = i;
        }
    }

    int bottom_left = 0;
    for (int i = 0; i < 4; i++) {
        if (i != bottom_right && i != top_left && i != top_right) {
            bottom_left = i;
        }
    }

    int x_new[] = { x[top_left], x[top_right], x[bottom_right], x[bottom_left] };
    int y_new[] = { y[top_left], y[top_right], y[bottom_right], y[bottom_left] };

    for (int i = 0; i < 4; i++) {
        x[i] = x_new[i];
        y[i] = y_new[i];
    }
}

float rectanglePerimeter(float length, float width) {
    printf("\n length %f, \nWidth %f\n",length, width );
    float perimeter = 2 * (length + width);
    return perimeter;
}

float rectangleArea(float length, float width)
{
    float area = length * width;
    return area;
}

