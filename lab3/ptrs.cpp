#include"../show_mem.h"
#include <iostream>

// Struct for Pixel object
struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int main() {
    // declare a variable 'image' of the correct type
    Pixel** image;
    
    int width = 16;
    int height = 16;
    
    // dynamically allocate memory for the pointers to scanlines
    image = new Pixel*[height];
  
    // dynamically allocate memory for each of the scanlines, 
    //   using a loop
    for(int i = 0; i < height; ++i) {
        image[i] = new Pixel[width];
    }
    
    // Make pattern

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            image[i][j].red = 50 * (i % 5);
            image[i][j].green = 50 * (j % 5);
            image[i][j].blue = (i * j) % 256;
        }
    }

    // Writes the image as an output.ppm
    _write_image("pattern.ppm", reinterpret_cast<char **>(image), width, height);

    // de-allocate the memory for each of the scanlines, 
    //    using a loop
    for(int i = 0; i < height; ++i) {
        delete[] image[i];
    }
    
    //  de-allocate the memory for the pointers to the scanlines
    delete[] image;
}
