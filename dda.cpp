#include <graphics.h>  // Header file for graphics functions (drawing shapes)
#include <stdlib.h>    // For basic standard library functions like exit()

using namespace std;   // To avoid prefixing "std::" with functions like cout, cin

// Class to represent a circle and draw it
class dcircle {
private:
    int x0, y0;  // Coordinates of the center of the circle
public:
    dcircle() {   // Constructor initializes circle's center to (0,0)
        x0 = 0;
        y0 = 0;
    }

    // Method to set the center of the circle
    void setoff(int xx, int yy) {
        x0 = xx;
        y0 = yy;
    }

    // Method to draw the circle using Bresenham's circle algorithm
    void drawc(int x1, int y1, int r) {
        float d;
        int x, y;
        x = 0;
        y = r;
        d = 3 - 2 * r;  // Initial decision parameter
        do {
            // Draw 8 symmetrical points around the circle
            putpixel(x1 + x0 + x, y0 + y - y1, 15);  // 1st point
            putpixel(x1 + x0 + y, y0 + x - y1, 15);  // 2nd point
            putpixel(x1 + x0 + y, y0 - x - y1, 15);  // 3rd point
            putpixel(x1 + x0 + x, y0 - y - y1, 15);  // 4th point
            putpixel(x1 + x0 - x, y0 - y - y1, 15);  // 5th point
            putpixel(x1 + x0 - y, y0 - x - y1, 15);  // 6th point
            putpixel(x1 + x0 - y, y0 + x - y1, 15);  // 7th point
            putpixel(x1 + x0 - x, y0 + y - y1, 15);  // 8th point

            // Update decision parameter and adjust x and y
            if (d <= 0) {
                d = d + 4 * x + 6;  // Choose E
            } else {
                d = d + 4 * (x - y) + 10;  // Choose SE
                y = y - 1;
            }
            x = x + 1;
        } while (x < y);  // Continue until x >= y
    }
};

// Class to represent a point with coordinates and color
class pt {
protected:
    int xco, yco, color;  // Coordinates (xco, yco) and color
public:
    pt() {  // Constructor to initialize point with default values
        xco = 0;
        yco = 0;
        color = 15;  // Default color is white
    }

    // Set the coordinates of the point
    void setco(int x, int y) {
        xco = x;
        yco = y;
    }

    // Set the color of the point
    void setcolor(int c) {
        color = c;
    }

    // Draw the point on the screen
    void draw() {
        putpixel(xco, yco, color);
    }
};

// Class to represent a line, derived from the point class
class dline: public pt {
private:
    int x2, y2;  // Second point (x2, y2) to define the line
public:
    dline() : pt() {  // Constructor initializing the base class pt
        x2 = 0;
        y2 = 0;
    }

    // Set the coordinates of the two endpoints of the line
    void setline(int x, int y, int xx, int yy) {
        pt::setco(x, y);  // Set the first point (xco, yco)
        x2 = xx;
        y2 = yy;
    }

    // Draw the line using Bresenham's line algorithm
    void drawl(int colour) {
        float x, y, dx, dy, length;
        int i;
        pt::setcolor(colour);  // Set the color for the line

        dx = abs(x2 - xco);  // Difference in x-coordinates
        dy = abs(y2 - yco);  // Difference in y-coordinates

        // Decide the length of the line
        if (dx >= dy) {
            length = dx;
        } else {
            length = dy;
        }

        dx = (x2 - xco) / length;  // Step size in x-direction
        dy = (y2 - yco) / length;  // Step size in y-direction

        x = xco + 0.5;  // Initialize x-coordinate
        y = yco + 0.5;  // Initialize y-coordinate

        i = 1;
        while (i <= length) {
            pt::setco(x, y);  // Set the current coordinates
            pt::draw();       // Draw the point at the current coordinates
            x = x + dx;       // Update x-coordinate
            y = y + dy;       // Update y-coordinate
            i = i + 1;
        }
        pt::setco(x, y);  // Set final coordinates and draw the last point
        pt::draw();
    }
};

int main() {
    int gd = DETECT, gm;  // Graphics driver and mode
    initgraph(&gd, &gm, NULL);  // Initialize the graphics mode

    // Declare variables for user input
    int x, y, r, x1, x2, y1, y2, xmax, ymax, xmid, ymid, n, i;
    dcircle c;

    // Get circle parameters from the user
    cout << "\nEnter coordinates of center of circle: ";
    cout << "\nEnter the value of x: "; cin >> x;
    cout << "\nEnter the value of y: "; cin >> y;
    cout << "\nEnter the value of radius: "; cin >> r;

    // Calculate the center of the screen
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax / 2;
    ymid = ymax / 2;

    // Draw the coordinate axes
    setcolor(1);  // Set color to black
    c.setoff(xmid, ymid);  // Set the center of the circle
    line(xmid, 0, xmid, ymax);  // Vertical axis
    line(0, ymid, xmax, ymid);  // Horizontal axis

    // Set color to white and draw the first circle
    setcolor(15);
    c.drawc(x, y, r);

    pt p1;  // Create a point object
    p1.setco(100, 100);  // Set point coordinates
    p1.setcolor(14);  // Set point color to yellow

    dline l;  // Create a line object
    cout << "Enter Total Number of lines: ";
    cin >> n;  // Get the number of lines to draw

    // Get coordinates of lines from the user and draw them
    for (i = 0; i < n; i++) {
        cout << "Enter co-ordinates of point x1: "; cin >> x1;
        cout << "Enter coordinates of point y1: "; cin >> y1;
        cout << "Enter co-ordinates of point x2: "; cin >> x2;
        cout << "Enter coordinates of point y2: "; cin >> y2;

        l.setline(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2);  // Adjust for screen center
        l.drawl(15);  // Draw the line in white
    }

    // Get parameters for a second circle
    cout << "\nEnter coordinates of center of circle: ";
    cout << "\nEnter the value of x: "; cin >> x;
    cout << "\nEnter the value of y: "; cin >> y;
    cout << "\nEnter the value of radius: "; cin >> r;

    // Set color to magenta and draw the second circle
    setcolor(5);
    c.drawc(x, y, r);

    getch();  // Wait for user input
    delay(200);  // Delay for 200ms to view the result
    closegraph();  // Close the graphics mode and window

    return 0;  // End of the program
}

