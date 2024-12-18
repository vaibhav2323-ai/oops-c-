#include <graphics.h>  // Include the graphics library for drawing
#include <iostream>     // Include standard input-output library
using namespace std;

int main() 
{ 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, NULL);  // Initialize the graphics system
    
    int midx, midy, r = 10;  // midx and midy will be used for the center of the circle; r is the radius
    midx = getmaxx() / 2;  // Find the horizontal center of the screen
    midy = getmaxy() / 2;  // Find the vertical center of the screen (though not used here)

    // Loop to increase the radius of the circle from 10 to 50
    while (r <= 50) 
    { 
        cleardevice();  // Clear the previous drawing to update the screen

        // Draw a diamond shape with 5 lines
        setcolor(WHITE);  // Set color to white for the lines
        line(0, 310, 160, 150);  // First diagonal line
        line(160, 150, 320, 310); // Second diagonal line
        line(320, 310, 480, 150); // Third diagonal line
        line(480, 150, 640, 310); // Fourth diagonal line
        line(0, 310, 640, 310);   // Horizontal line across the bottom

        // Draw an arc with a dynamic radius
        arc(midx, 310, 225, 133, r); // Draw an arc with center (midx, 310), angles from 225 to 133, radius 'r'

        floodfill(midx, 300, 15);  // Fill the area inside the arc with color 15 (white)

        // When the radius exceeds 20, add different colors for flood fill effects
        if (r > 20) 
        { 
            setcolor(7);  // Set color to light gray
            floodfill(2, 2, 15); // Fill the top-left corner

            setcolor(6);  // Set color to light yellow
            floodfill(150, 250, 15); // Fill an area near the center-left

            setcolor(2);  // Set color to green
            floodfill(550, 250, 15); // Fill an area near the center-right

            setcolor(2);  // Set color to green
            floodfill(2, 450, 15); // Fill the bottom-left corner
        }

        delay(50);  // Delay for 50 milliseconds to make the animation visible
        r += 2;  // Increase the radius by 2 to expand the arc in each iteration
    }

    getch();  // Wait for a key press before closing the program
    closegraph();  // Close the graphics mode and return to the text mode
    return 0;  // End of the program
}

