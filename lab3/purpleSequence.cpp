#include"../show_mem.h"
#include <iostream>

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int main() {
    int width, height;
    _get_image_dimensions("small.ppm", width, height);

    Pixel** image;
    
    image = new Pixel*[height];
  
    for(int i = 0; i < height; ++i) {
        image[i] = new Pixel[width];
    }

    _read_image("small.ppm", reinterpret_cast<char **>(image), width, height);

    unsigned char pixelR = 255;
    unsigned char pixelG = 0;
    unsigned char pixelB = 255;

    for(int i = 0; i < 1; ++i) {
        for(int j = 0; j < (width / 4); ++j) {
            image[i][j].red = pixelR;
            image[i][j].green = pixelG;
            image[i][j].blue = pixelB;
        }
    }

    _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

    for(int i = 0; i < height; ++i) {
        delete[] image[i];
    }
    
    delete[] image;
}