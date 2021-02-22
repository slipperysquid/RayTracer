#ifndef COLOUR_H
#define COLOUR_H

#include "Vec3.h"

#include <iostream>

using namespace std;

void write_colour(ostream &out, colour pixel_colour){
    //write the rgb colour value of the pixel
    out << static_cast<int>(255.999 * pixel_colour.get_x()) << " "
        << static_cast<int>(255.999 * pixel_colour.get_y()) << " "
        << static_cast<int>(255.999 * pixel_colour.get_y()) << "\n";
}

#endif