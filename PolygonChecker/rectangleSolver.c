#include "rectangleSolver.h"

char* analyzeRectangle(int x[], int y[], int distances[4]) {
    double dot_products[4];

    // Calculate distances between consecutive points
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4; // Circular index to connect the last point back to the first
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        distances[i] = sqrt(dx * dx + dy * dy);
    }

    // Calculate dot products for each angle
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        int k = (i + 2) % 4;
        dot_products[i] = (x[j] - x[i]) * (x[k] - x[j]) + (y[j] - y[i]) * (y[k] - y[j]);
    }

    // Check if all four angles are 90 degrees
    int isRectangle = 1;
    for (int i = 0; i < 4; i++) {
        if (dot_products[i] != 0) {
            isRectangle = 0;
            break;
        }
    }

    // Check if opposite sides are equal in length
    if (distances[0] != distances[2] || distances[1] != distances[3]) {
        isRectangle = 0;
    }

    if (isRectangle) {
        printf("The given coordinates form a rectangle.\n");
        SortingCorners(x, y, distances);
        printf("Sorted corners: (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3]);
        Rectangle_Perimeter(distances[0], distances[1]);
        Rectangle_Area(distances[0], distances[1]);
    }
    else {
        printf("The given coordinates do not form a rectangle.\n");
        Rectangle_Perimeter(distances[0], distances[1]);
    }

    return NULL;    //can be changed if needed
}

bool checkForRectangle(int length, int width) {
    if (length > 0 && width > 0) {
        return true;
    }
    return false;
}

//
float calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

bool FormsRectangle(int x[], int y[])
{
    float d[6];
    int index = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            d[index++] = calculateDistance(x[i], y[i], x[j], y[j]);
        }
    }

    //Sort distances in ascending order
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
        return true;
    }
    else
    {
        return false;
    }
}

bool SortingCorners(int* x, int* y, int distances[])
{
    bool is_rectangle = FormsRectangle(x, y);
    if (is_rectangle == false)
    {
        printf("Does not forms a rectangle!\n");
        Rectangle_Perimeter(distances[0], distances[1]);
        return false;
    }

    int top_left = 0;
    for (int i = 0; i < 4; i++)
    {
        if (x[top_left] > x[i])
        {
            top_left = i;
        }
        if (x[top_left] == x[i])
        {
            if (y[top_left] < y[i])
            {
                top_left = i;
            }
        }
    }

    int top_right = 0;
    for (int i = 0; i < 4; i++)
    {
        if (y[top_right] < y[i] && i != top_left)
        {
            top_right = i;
        }
    }

    int bottom_right = 0;
    for (int i = 0; i < 4; i++)
    {
        if (x[bottom_right] < x[i] && i != top_left && i != top_right)
        {
            bottom_right = i;
        }
    }

    int bottom_left = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != bottom_right && i != top_left && i != top_right)
        {
            bottom_left = i;
        }
    }

    int x_new[] = { x[top_left], x[top_right], x[bottom_right], x[bottom_left] };
    int y_new[] = { y[top_left], y[top_right], y[bottom_right], y[bottom_left] };

    for (int i = 0; i < 4; i++)
    {
        x[i] = x_new[i];
        y[i] = y_new[i];
    }

    return true;
}
//


//function to find perimeter of rectangle
int Rectangle_Perimeter(int length, int width) {
    int Perimeter = 2 * (length + width);
    return Perimeter;
}

//function to find perimeter of rectangle
int Rectangle_Area(int length, int width) {
    int Area = length * width;
    return Area;
}