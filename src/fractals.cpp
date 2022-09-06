// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "fractals.h"
#include "error.h"
#include "gwindow.h"
#include <cmath>;
using namespace std;

void drawSierpinskiTriangle(GWindow& window, double x, double y, double size, int order) {
    if (order == 0) { // Base case: draw nothing if the order is 0
        cout << endl;
    } else if (x < 0 || y < 0 || size < 0 || order < 0) { // Base case: throw error if any parameter
        // is a negative number
        error("x, y, size and order must be a positive number");
    } else if (order == 1){ // Base case: draw 1 triangle if the order is 1
        // Draw each line in order to form triangle
        window.drawLine(x, y, x + size, y);
        window.drawLine(x + size, y, x + (size/2), y + (sqrt(3)/2) * size);
        window.drawLine(x + (size/2), y + (sqrt(3)/2) * size, x, y);
    } else { // Recursive case: draw the cluster of 3 triangles
        drawSierpinskiTriangle(window, x, y, size/2, order - 1);
        drawSierpinskiTriangle(window, x + size/2, y , size/2, order - 1);
        drawSierpinskiTriangle(window, x + (size/4), y + (sqrt(3)/2) * size/2, size/2, order - 1);
    }
}

int floodFill(GWindow& window, int x, int y, int color) {
    // TODO: write this function

    return 0;   // this is only here so it will compile
}
