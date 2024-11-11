#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

// Function to check if two line segments are parallel
bool areParallel(Point P1, Point P2, Point P3, Point P4) {
    // Calculate the slopes of the two line segments
    double slope1 = (P2.y - P1.y) / (P2.x - P1.x);
    double slope2 = (P4.y - P3.y) / (P4.x - P3.x);
    
    // If the slopes are equal, the lines are parallel
    return slope1 == slope2;
}

// Function to check if two line segments are perpendicular
bool arePerpendicular(Point P1, Point P2, Point P3, Point P4) {
    // Calculate the slopes of the two line segments
    double slope1 = (P2.y - P1.y) / (P2.x - P1.x);
    double slope2 = (P4.y - P3.y) / (P4.x - P3.x);
    
    // If the product of the slopes is -1, the lines are perpendicular
    return slope1 * slope2 == -1;
}

int main() {
    Point P1 = {0, 0};
    Point P2 = {1, 1};
    Point P3 = {0, 0};
    Point P4 = {1, -1};

    if (areParallel(P1, P2, P3, P4)) {
        std::cout << "The line segments are parallel." << std::endl;
    } else {
        std::cout << "The line segments are not parallel." << std::endl;
    }

    if (arePerpendicular(P1, P2, P3, P4)) {
        std::cout << "The line segments are perpendicular." << std::endl;
    } else {
        std::cout << "The line segments are not perpendicular." << std::endl;
    }

    return 0;
}