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

            auto r_multiplyer = double(i) / (img_width - 1); //0 red on left full red on right
            auto g_multiplyer = double(j) / (img_height - 1);//full green on top 0 green on bottom
            auto b_multiplyer = 0.25;

            int r = static_cast<int>(255.999 * r_multiplyer);
            int g = static_cast<int>(255.999 * g_multiplyer);
            int b = static_cast<int>(255.999 * b_multiplyer);

            cout << r << " " << g << " " << b << "\n";
        }
    }

    cerr << "\nDone \n";
}