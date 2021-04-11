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

    unsigned char pixelG;
    int valueG;
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            pixelG = image[i][j].green;
            valueG = pixelG;
            valueG *= 2;
            if(valueG > 255) {
                image[i][j].green = 0xff;
            } else{
                image[i][j].green = 2 * pixelG;
            }
        }
    }

    _write_image("output.ppm", reinterpret_cast<char **>(image), width, height);

    for(int i = 0; i < height; ++i) {
        delete[] image[i];
    }
    
    delete[] image;
}