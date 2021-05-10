#include "Colour.h"
#include "Vec3.h"
#include "Ray.h"

#include <iostream>

using namespace std;


bool hit_sphere(const point3& center, double radius, const Ray& r){
    //checking if point on ray intersects with sphere by solving for t in t^2*b^2 + 2tb * (A - C) + (A - C)^2 - r^2 = 0
    Vec3 oc = r.get_origin() - center;
    auto a = dot(r.get_direction(), r.get_direction());
    auto b = 2.0 * dot(oc, r.get_direction());
    auto c = dot(oc, oc) - radius * radius;
    auto determinant = b * b - 4 * a * c;
    return (determinant > 0);//returns true if the line has intersects with the sphere
}

colour ray_colour(const Ray& r){
    //returns red if the ray intersects with sphere
    if(hit_sphere(point3(0, 0, -1), 0.5, r)){
        return colour(1, 0, 0);
    }
    //linearly blends the ray between white and blue based on its unit vector
    Vec3 unit_direction = unit_vector(r.get_direction());   
    auto t = 0.5 * (unit_direction.get_y() + 1.0);
    return (1.0 - t) * colour(1.0, 1.0, 1.0) + t * colour(0.5, 0.7, 1.0);
}




int main(){
    //Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int img_width = 400;
    const int img_height = static_cast<int>(img_width / aspect_ratio);

    //Camera

    auto viewport_height = 2.0; 
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    //setting up view from camera
    auto horizontal = Vec3(viewport_width, 0, 0);
    auto vertical = Vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length); 

    //Render --- will write into a plain text PPM format
    cout << "P3\n" << img_width << " " << img_height << "\n255\n";
    for (int j = img_height - 1; j >= 0; j--){
        cerr << "\n Scanlines remaining: " << j << ' ' << flush;
        for(int i = 0; i < img_width; i++){
            auto u = double(i) / (img_width - 1);
            auto v = double(j) / (img_height - 1);

            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin); //subtract origin incase it is not (0, 0, 0)

            colour pixel_colour = ray_colour(r);//making a coulour vector containing the colour multiplyers
            write_colour(cout, pixel_colour);//printing colour value of pixel
        }
    }

    cerr << "\nDone \n";
}