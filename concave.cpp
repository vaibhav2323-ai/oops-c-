#include <graphics.h>   // This is the header for graphics functions (like drawing lines, shapes, etc.)
#include <iostream>      // For input and output
#include <stdlib.h>      // For the exit function (not really used here)

using namespace std;     // To avoid using "std::" before every standard library function

// The flood-fill function: It fills an area with a specific color using recursion
void ffill(int x, int y, int o_col, int n_col)
{
    int current = getpixel(x, y);  // Get the color of the pixel at coordinates (x, y)
    
    if (current == o_col)  // If the pixel's color is the original color (the one to be filled)
    {
        delay(1);  // Pause for 1 millisecond (this is not necessary but adds some delay)
        putpixel(x, y, n_col);  // Set the pixel's color to the new color (filling the region)
        
        // Recursively call the flood-fill function for neighboring pixels
        ffill(x + 1, y, o_col, n_col);  // Check right
        ffill(x - 1, y, o_col, n_col);  // Check left
        ffill(x, y + 1, o_col, n_col);  // Check bottom
        ffill(x, y - 1, o_col, n_col);  // Check top
    }
}

int main()
{
    int x1, y1, x2, y2, x3, y3, xavg, yavg;  // Coordinates of the triangle's vertices and its average (centroid)
    int gdriver = DETECT, gmode;               // Graphics mode variables (used to initialize graphics)
    
    initgraph(&gdriver, &gmode, NULL);  // Initialize graphics mode

    cout << " \n\t Enter the points of triangle: ";  // Ask the user to input the vertices of the triangle
    setcolor(1);  // Set the color for the triangle's outline (color code 1 is typically black or white)
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;  // Take input for the 3 vertices of the triangle

    // Calculate the centroid (average) of the triangle
    xavg = (x1 + x2 + x3) / 3;  // X-coordinate of the centroid
    yavg = (y1 + y2 + y3) / 3;  // Y-coordinate of the centroid

    // Draw the triangle by connecting its vertices
    line(x1, y1, x2, y2);  // Draw line from point 1 to point 2
    line(x2, y2, x3, y3);  // Draw line from point 2 to point 3
    line(x3, y3, x1, y1);  // Draw line from point 3 to point 1

    // Fill the triangle with the color RED, starting from the centroid
    ffill(xavg, yavg, BLACK, RED);  // The color to fill is red, starting from the centroid

    getch();  // Wait for user input before closing the graphics window
    return 0;  // End of the program
}

