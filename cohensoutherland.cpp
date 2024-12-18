#include<iostream>
#include<graphics.h>
using namespace std;

class Coordinate {
public:
    int x, y;
    char code[4];  // Holds the region code for the point
};

class Lineclip {
public:
    void drawwindow();                          // Draws the clipping window
    void drawline(Coordinate p1, Coordinate p2); // Draws a line between two points
    Coordinate setcode(Coordinate p);            // Sets region code based on point position
    int visibility(Coordinate p1, Coordinate p2); // Determines if line is inside, outside, or partially inside the window
    Coordinate resetendpt(Coordinate p1, Coordinate p2); // Adjusts endpoints if line is partially inside
};

int main() {
    Lineclip lc;
    int gd = DETECT, gm; // Graphics driver and mode
    Coordinate p1, p2, p3, p4;

    // Get coordinates from user
    cout << "\nEnter x1 and y1\n";
    cin >> p1.x >> p1.y;
    cout << "\nEnter x2 and y2\n";
    cin >> p2.x >> p2.y;

    initgraph(&gd, &gm, "VGA");
    lc.drawwindow();  // Draw the clipping window
    delay(2000);
    lc.drawline(p1, p2);  // Draw the original line
    delay(2000);
    cleardevice();
    delay(2000);

    // Set region codes for the endpoints
    p1 = lc.setcode(p1);
    p2 = lc.setcode(p2);

    int v = lc.visibility(p1, p2);  // Check line visibility
    delay(2000);

    // Clip the line based on visibility
    switch(v) {
        case 0: // Completely outside
            lc.drawwindow();
            delay(2000);
            lc.drawline(p1, p2);
            break;
        case 1: // Completely inside
            lc.drawwindow();
            delay(2000);
            break;
        case 2: // Partially inside
            p3 = lc.resetendpt(p1, p2);
            p4 = lc.resetendpt(p2, p1);
            lc.drawwindow();
            delay(2000);
            lc.drawline(p3, p4);
            break;
    }
    delay(2000);
    closegraph();
}

// Draws the clipping window (rectangle)
void Lineclip::drawwindow() {
    line(150, 100, 450, 100); // Top side
    line(450, 100, 450, 350); // Right side
    line(450, 350, 150, 350); // Bottom side
    line(150, 350, 150, 100); // Left side
}

// Draws a line between two points
void Lineclip::drawline(Coordinate p1, Coordinate p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Sets region code based on the position of a point relative to the window
Coordinate Lineclip::setcode(Coordinate p) {
    Coordinate ptemp;
    ptemp.code[0] = (p.y < 100) ? '1' : '0';  // Top
    ptemp.code[1] = (p.y > 350) ? '1' : '0';  // Bottom
    ptemp.code[2] = (p.x > 450) ? '1' : '0';  // Right
    ptemp.code[3] = (p.x < 150) ? '1' : '0';  // Left
    ptemp.x = p.x;
    ptemp.y = p.y;
    return ptemp;
}

// Determines if the line is inside, outside, or partially inside the clipping window
int Lineclip::visibility(Coordinate p1, Coordinate p2) {
    int i, flag = 0;
    // Check if both points are outside the window
    for (i = 0; i < 4; i++) {
        if (p1.code[i] != '0' || p2.code[i] == '1') flag = '0'; // Outside check
    }
    if (flag == 0) return 0;  // Line is outside the window

    // Check if both points are inside
    for (i = 0; i < 4; i++) {
        if (p1.code[i] == p2.code[i] && p2.code[i] == '1') flag = '0'; // Inside check
    }
    if (flag == 0) return 1;  // Line is fully inside the window

    return 2;  // Line is partially inside the window
}

// Adjusts endpoint to make sure it's inside the clipping window
Coordinate Lineclip::resetendpt(Coordinate p1, Coordinate p2) {
    Coordinate temp;
    int x, y;
    float m, k;

    // If the point is outside the left or right boundary
    if (p1.code[3] == '1') x = 150;
    if (p1.code[2] == '1') x = 450;

    // Calculate the y coordinate based on x
    if (p1.code[3] == '1' || p1.code[2] == '1') {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = p1.y + m * (x - p1.x);
        temp.y = k;
        temp.x = x;
        for (int i = 0; i < 4; i++) temp.code[i] = p1.code[i];
        if (temp.y <= 350 && temp.y >= 100) return temp;
    }

    // If the point is outside the top or bottom boundary
    if (p1.code[0] == '1') y = 100;
    if (p1.code[1] == '1') y = 350;

    if (p1.code[0] == '1' || p1.code[1] == '1') {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        k = p1.x + (float)(y - p1.y) / m;
        temp.x = k;
        temp.y = y;
        for (int i = 0; i < 4; i++) temp.code[i] = p1.code[i];
        return temp;
    } else {
        return p1;
    }
}

