/*
Given the two end points P1, P2 of a line segement P1P2, and the coor
dinates of a point q, design an algorithm to check whether the point q in
 the clockwise direction from the line segment P1P2 or not. Analyse your
 algorithm with the time complexity*/

#include <iostream>
using namespace std;
/*
The provided C++ code snippet is a simple program that determines the relative position of a point with respect to a line segment defined by two endpoints. The program begins by declaring several integer variables: x1, y1, x2, y2, x, and y. These variables will store the coordinates of the endpoints of the line segment and the coordinates of the point to be evaluated.

The program then prompts the user to enter the coordinates of the endpoints of the line segment (x1, y1, x2, y2) and the coordinates of the point (x, y). These values are read from the standard input using cin.

Next, the program calculates the cross product of two vectors: one vector from the first endpoint of the line segment to the second endpoint ((x2 - x1, y2 - y1)) and another vector from the first endpoint of the line segment to the point ((x - x1, y - y1)). The cross product is computed using the formula (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1). This value, stored in the variable val, helps determine the relative position of the point with respect to the line segment.

The program then uses conditional statements to evaluate the value of val. If val is greater than 0, the point is in the clockwise direction from the line segment. If val is less than 0, the point is in the anticlockwise direction. If val is equal to 0, the point lies exactly on the line segment. The result is printed to the standard output using cout.

This approach leverages the geometric properties of vectors and the cross product to determine the relative orientation of a point with respect to a line segment, which is a common technique in computational geometry.
*/
int main() {
    int x1, y1, x2, y2, x, y;
    cout << "Enter the coordinates of the end points of the line segment: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the coordinates of the point: ";
    cin >> x >> y;
    // cross product of two vectors
    int val = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1); // cross product
    // if val > 0, then the point is in the clockwise direction from the line segment

    if (val > 0) {
        cout << "The point is in the clockwise direction from the line segment.";
    } else if (val < 0) {
        cout << "The point is in the anticlockwise direction from the line segment.";
    } else {
        cout << "The point is on the line segment.";
    }
    return 0;
}