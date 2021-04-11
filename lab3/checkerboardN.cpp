#include"../show_mem.h"
#include <iostream>

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int main() {
    int width, height;
    _get_image_dimensions("big.ppm", width, height);

    Pixel** image;
    
    image = new Pixel*[height];
  
    for(int i = 0; i < height; ++i) {
        image[i] = new Pixel[width];
    }

    _read_image("big.ppm", reinterpret_cast<char **>(image), width, height);

    int n = 8;
    unsigned char pixelR = 255;
    unsigned char pixelG = 0;
    unsigned char pixelB = 255;
    int l;

    for(int k = 0; k < n; ++k) {
        if(k % 2 == 0) {
            l = 1;
        }
        while(l < n) {
            for(int i = k * (height / n); i < (k + 1) * (height / n); ++i) {
                for(int j = l * (width / n); j < (l + 1) * (width / n); ++j) {
                    image[i][j].red = pixelR;
                    image[i][j].green = pixelG;
                    image[i][j].blue = pixelB;
                }
            }
            l += 2;
        }
        l = 0;
    }

    _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

    for(int i = 0; i < height; ++i) {
        delete[] image[i];
    }
    
    delete[] image;
}