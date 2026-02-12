/*
 * An implementation of Rectangles using Points
 *
 * Mark A. Sheldon, Tufts University
 * Spring 2013
 *
 */

#include <iostream>

#include "Point.h"
#include "Rectangle.h"

// If Point doesn't have nullary constructor, need to add initialization list:
//
// : lower_left(0, 0), upper_right(0, 0)
//
// test
Rectangle::Rectangle(Point low_left, Point up_right)
{
        lower_left  = low_left;
        upper_right = up_right;
}

void Rectangle::print()
{    
        std::cout << "[Rectangle: "
                  << "Lower left:  ";
        lower_left.print();
        std::cout << "; " << "Upper right:  ";
        upper_right.print();
        std::cout << "]";
}
