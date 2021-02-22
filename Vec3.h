#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>


using namespace std;

class Vec3 {

    public:
        Vec3():
        e{0,0,0} {}
        Vec3(double e0, double e1, double e2):
        e{e0,e1,e2}{}

        double get_x() const {return e[0];}
        double get_y() const {return e[1];}
        double get_z() const {return e[2];}

        Vec3 operator -() const {return Vec3(-e[0], -e[1], -e[2]);}
        double operator [](int i) const {return e[i];}
        double& operator [](int i) {return e[i];}

        Vec3 operator +=(const Vec3 &v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        Vec3 operator *=(const double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        Vec3 operator /(const double t){
            return *this *= 1/t;
        }

        double length(){
            return sqrt(lengthSquared());
        }

        double lengthSquared(){
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }

    public:
        double e[3];
};

//aliases for Vec3
using point3 = Vec3; //for 3D points
using colour = Vec3; //for colour vectors

//Vec3 Utility functions

inline ostream& operator <<(ostream &out, const Vec3 &v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

inline Vec3 operator +(Vec3 &v, Vec3 &u){
    return Vec3(v.e[0] + u.e[0], v.e[1] + u.e[1], v.e[2] + u.e[2]);
}

inline Vec3 operator -(Vec3 &v, Vec3 &u){
    return Vec3(v.e[0] - u.e[0], v.e[1] - u.e[1], v.e[2] - u.e[2]);
}

inline Vec3 operator *(Vec3 &v, Vec3 &u){
    return Vec3(v.e[0] * u.e[0], v.e[1] * u.e[1], v.e[2] * u.e[2]);
}

inline Vec3 operator *(double t, Vec3 &v){
    return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator /=( Vec3 v, double t){
    return (1/t) * v;
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 unit_vector(Vec3 v){
    return v / v.length();
}
#endif