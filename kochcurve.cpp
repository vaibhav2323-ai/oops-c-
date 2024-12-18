#include <iostream>   // For input and output
#include <math.h>     // For mathematical functions like sqrt
#include <graphics.h> // For graphics functions

using namespace std;

class kochCurve { // Class to generate the Koch curve
public:
    // Function to draw the Koch curve recursively
    void koch(int it, int x1, int y1, int x5, int y5) {
        int x2, y2, x3, y3, x4, y4;
        int dx, dy;

        if (it == 0) { // Base case: If iterations are 0, draw a straight line
            line(x1, y1, x5, y5); // Draw a line from (x1, y1) to (x5, y5)
        } else { // Recursive case: If iterations > 0, divide the line into 4 segments
            delay(10); // Delay to make the drawing visible step by step

            dx = (x5 - x1) / 3; // Calculate the distance in x-direction for 1/3 of the line
            dy = (y5 - y1) / 3; // Calculate the distance in y-direction for 1/3 of the line

            // Calculate the coordinates of the 4 points
            x2 = x1 + dx; // Point 2: 1/3 along the line from (x1, y1)
            y2 = y1 + dy;
            x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6); // Point 3: Peak of the triangle
            y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
            x4 = 2 * dx + x1; // Point 4: 2/3 along the line from (x1, y1)
            y4 = 2 * dy + y1;

            // Recursively draw the four smaller Koch curves
            koch(it - 1, x1, y1, x2, y2); // First segment
            koch(it - 1, x2, y2, x3, y3); // Second segment (triangle peak)
            koch(it - 1, x3, y3, x4, y4); // Third segment
            koch(it - 1, x4, y4, x5, y5); // Fourth segment
        }
    }
};

int main() {
    kochCurve k; // Create an object of the kochCurve class
    int it; // Variable to store the number of iterations

    cout << "Enter Number Of Iterations : " << endl;
    cin >> it; // Get the number of iterations from the user

    int gd = DETECT, gm; // Graphics driver and mode
    initgraph(&gd, &gm, NULL); // Initialize the graphics mode

    // Draw the Koch snowflake by drawing three Koch curves
    k.koch(it, 150, 20, 20, 280); // First side of the triangle
    k.koch(it, 280, 280, 150, 20); // Second side of the triangle
    k.koch(it, 20, 280, 280, 280); // Third side of the triangle

    getch(); // Wait for user input before closing the window
    closegraph(); // Close the graphics window
    return 0; // Exit the program
}

