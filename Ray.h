#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray{

    public:
    Ray(){}
    Ray(const point3& orig, const Vec3 direc)
        : origin(orig), direction(direc){}

    point3 get_origin() const {return origin;}
    Vec3 get_direction() const {return direction;}

    point3 at(double t){
        return origin + (t * direction);
    }

    public:
        point3 origin;
        Vec3 direction;
};



#endif