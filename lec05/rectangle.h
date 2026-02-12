/*
 * A class for Rectangles that uses Points
 *
 * Mark A. Sheldon, Tufts University
 *
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
public:
        Rectangle(Point low_left, Point up_right);

        void print();

private:
        Point lower_left, upper_right;
};

#endif