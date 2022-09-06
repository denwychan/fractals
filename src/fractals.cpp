// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include "fractals.h"
#include "error.h"
#include "gwindow.h"
#include <cmath>
using namespace std;
// Function prototype
int floodFillHelper(
        GWindow& window, int x, int y, int color, int backgroundColor, int pixelsChanged);

void drawSierpinskiTriangle(GWindow& window, double x, double y, double size, int order) {
    if (order == 0) { // Base case: draw nothing if the order is 0
        cout << "I'm done drawing" << endl;
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
    int backgroundColor = window.getPixel(x, y);
    int pixelsChanged  = 0;
    floodFillHelper(window, x, y, color, backgroundColor, pixelsChanged);
    return 0;   // this is only here so it will compile
}

int floodFillHelper(
        GWindow& window, int x, int y, int color, int backgroundColor, int pixelsChanged) {
    // Base case: return 0 if the flood fill colour is the same as the background colour
    if (color == backgroundColor) {
        return 0;
    } else if (x < 0 || y < 0 || !window.inCanvasBounds(x, y)) {
    // Base case: throw exception if x or y are negative, or if the pixel is out of bound
        error("x and y must be a positive number and be in bounds of canvas");
    } else if (window.getPixel(x, y) != backgroundColor) {
    // Base case: stop exploring if the background colour changes
        cout << "Number of pixels change" << pixelsChanged << endl;
        return pixelsChanged;
    } else {
        // Colour the pixel
        window.setPixel(x, y, color);
        pixelsChanged++;
        // Look left
        floodFillHelper(window, x - 1, y, color, backgroundColor, pixelsChanged);
        // Look right
        floodFillHelper(window, x + 1, y, color, backgroundColor, pixelsChanged);
        // Look up
        floodFillHelper(window, x, y - 1, color, backgroundColor, pixelsChanged);
        // Look down
        floodFillHelper(window, x, y + 1, color, backgroundColor, pixelsChanged);
    }
}
