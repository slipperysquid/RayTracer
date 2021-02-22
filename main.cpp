#include "Colour.h"
#include "Vec3.h"

#include <iostream>

using namespace std;

int main(){
    //Image

    const int img_height = 256;
    const int img_width = 256;

    //Render --- will write into a plain text PPM format
    cout << "P3\n" << img_width << " " << img_height << "\n255\n";
    for (int j = img_height - 1; j >= 0; j--){
        cerr << "\n Scanlines remaining: " << j << ' ' << flush;
        for(int i = 0; i < img_width; i++){
            colour pixel_colour(double(i) / (img_width - 1), double(j) / (img_height - 1), 0.25);//making a coulour vector containing the colour multiplyers
            write_colour(cout, pixel_colour);//printing colour value of pixel
        }
    }

    cerr << "\nDone \n";
}