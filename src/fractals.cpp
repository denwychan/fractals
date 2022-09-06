// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "fractals.h"
#include "error.h"
#include "gwindow.h"
#include <cmath>;
using namespace std;

/*
 * Order 1 - 1 triangle pow(3, order - 1)
 * Line 1: drawLine(x, y, x + size, y)
 * Line 2: drawLine(x + size, y, x/2, (sqrt(3)/2) * size)
 * Line 3: drawLine(x/2, (sqrt(3)/2) * size, x, y)
 *
 * Order 2 - 3 triangles
 * Line 1: drawLine(x, y, x + (size/ 2), y)
 * Line 2: drawLine(x + (size/2), y, x/2, (sqrt(3)/2) * (size/2))
 * Line 3: drawLine(x/2, (sqrt(3)/2) * (size/2), x, y)
 *
 * Order 3 - 9 triangles, order 4
 *
 */

void drawSierpinskiTriangle(GWindow& window, double x, double y, double size, int order) {
    double triangles = pow(3, order - 1);
    double triangleSize = size/ triangles;
    if (order == 0) { // Base case: draw nothing if the order is 0
        cout << endl;
    } else if (x < 0 || y < 0 || size < 0 || order < 0) { // Base case: throw error if any parameter
        // is a negative number
        error("x, y, size and order must be a positive number");
    } else if (order == 1){ // Base case: draw 1 triangle if the order is 1
        // Draw each line in order to form triangle
        window.drawLine(x, y, x + triangleSize, y);
        window.drawLine(x + triangleSize, y, triangleSize/2, (sqrt(3)/2) * triangleSize);
        window.drawLine(triangleSize/2, (sqrt(3)/2) * triangleSize, x, y);
    } else { // Recursive case
        drawSierpinskiTriangle(window, x + triangleSize, y, size, order - 1);
        drawSierpinskiTriangle(window, triangleSize/2, (sqrt(3)/2) * triangleSize, size, order - 1);
    }
}

int floodFill(GWindow& window, int x, int y, int color) {
    // TODO: write this function

    return 0;   // this is only here so it will compile
}
