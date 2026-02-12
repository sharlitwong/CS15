///////////////////////////////////////////////////////////////////////////
//                     Implementation of Points                          //
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Must include the corresponding header file.
#include "Point.h"

//
// Initialize a new point with given coordinates
//
Point::Point(int x_coord, int y_coord)
{
        x = x_coord;
        y = y_coord;
}

Point::Point()
{

        x = y = 0;
}

//
// Print out a point
//
void Point::print()
{
        cout << "(" << x << ", " << y << ")";
}

//
// return the x-coordinate of the point
//
int Point::get_x()
{
        return x;
}

//
// return the y-coordinate of the point
//
int Point::get_y()
{
        return y;
}

//
// return a point whose coordinates are the sum of the coordinates
// of this point and another one
//
Point Point::add(Point other)
{
        Point result(get_x() + other.get_x(),
                     get_y() + other.get_y());

        return result;
}