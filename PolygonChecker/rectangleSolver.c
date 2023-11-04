#include "rectangleSolver.h"

char* analyzeRectangle() {
    int x[] = { 1, 5, 5, 1 };
    int y[] = { 0, 0, 4, 4 };

    double distances[4];
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
    }
    else {
        printf("The given coordinates do not form a rectangle.\n");
    }

    return NULL; // If you want to return a string, replace NULL with the appropriate message.
}

bool checkForRectangle(int length, int width) {
    if (length > 0 && width > 0) {
        return true;
    }
    return false;
}
