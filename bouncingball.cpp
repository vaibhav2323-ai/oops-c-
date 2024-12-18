#include <iostream>    // Standard input-output stream library
#include <cstdlib>     // For using functions like system(), exit()
#include <graphics.h>  // Graphics library for drawing shapes and animations

using namespace std;

int main() 
{ 
    int gd = DETECT, gm;  // Graphics driver and mode variables
    int i, x, y, flag = 0; // 'x' and 'y' for coordinates, 'flag' to control direction

    initgraph(&gd, &gm, NULL); // Initialize graphics mode
    
    // Get the horizontal center of the screen (middle of x-axis) and set initial y-coordinate
    x = getmaxx() / 2;  // x = center of the screen
    y = 30;             // Starting y-coordinate is at 30 (near top of the screen)

    while (1)  // Infinite loop to animate the bouncing ball
    { 
        // Check if the ball reaches the top or bottom of the screen
        if (y >= getmaxy() - 30 || y <= 30) 
            flag = !flag;  // Reverse the direction (if ball hits top or bottom)

        // Draw the ball (circle) at the current position (x, y)
        setcolor(RED);  // Set the drawing color to red
        circle(x, y, 30);  // Draw a circle with radius 30 at position (x, y)
        floodfill(x, y, RED);  // Fill the circle with the color red

        delay(50);  // Wait for 50 milliseconds before the next iteration (smooth animation)

        cleardevice();  // Clear the screen to erase the previous ball position

        // Move the ball up or down based on the 'flag' value
        if (flag) 
        { 
            y = y + 5;  // Move ball down if 'flag' is true
        } 
        else 
        { 
            y = y - 5;  // Move ball up if 'flag' is false
        }
    } 

    delay(5000);  // Wait for 5 seconds before closing the graphics window
    closegraph();  // Close the graphics mode and return to text mode
    return 0;  // End the program
}

