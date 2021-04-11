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

    unsigned char pixelR;
    unsigned char pixelG;
    unsigned char pixelB;

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < width; ++j) {
            pixelR = image[i][j].red;
            pixelG = image[i][j].green;
            pixelB = image[i][j].blue;

            for(int k = 2 + i; k < height; k +=2) {
                image[k][j].red = pixelR;
                image[k][j].green = pixelG;
                image[k][j].blue = pixelB;
            }
        }
    }

    _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

    for(int i = 0; i < height; ++i) {
        delete[] image[i];
    }
    
    delete[] image;
}