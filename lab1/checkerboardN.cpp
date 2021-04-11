#include "../show_mem.h"

// My image was not a regular size, so the addition/subtraction of 2
// was used to make it work on my image.
// If I had more time I would account for irregular shaped images.

int main() {
    _read_image("big.ppm");

    // Width and Height of the image
    int width, height;
    _get_image_dimensions(width, height);

    // Using the variable n to denote how many squares a present
    int n = 16;

    // Size of the rectangles in the image
    int sectionW = width / n;
    int sectionH = height / n;
    
    // The pixle that is being changed
    // I have no idea why the - (n - 2) works but it does for my image
    // It works with the first row sometimes having a line of purple
    int pixelRGB = 3 * (sectionW - (n / 2));

    // Main for loop to make all of the rectangles
    for(int z = 1; z < (n * n); z += 2) {

        // Loop for the height
        for(int i = 0; i <= sectionH; ++i) {

            // Loop for the width
            for(int j = 0; j <= sectionW; ++j) {
                // Changing each pixle
                _put_uchar(pixelRGB, 0xff);
                _put_uchar(pixelRGB + 1, 0x00);
                _put_uchar(pixelRGB + 2, 0xff);
                pixelRGB += 3;
            }
            pixelRGB += (3 * width) - (3 * (sectionW + 1));
        }

        // Determining if to keep going in row or switch to a new one
        if((z + 1) % n != 0) {
            pixelRGB -= ((sectionH + 1) * (3 * width) - (3 * (sectionW + 1)));
            pixelRGB += (3 * sectionW);
        } else {

            // Determining if the first rectangle is blank or purple
            if(((z + 1) / n) % 2 == 1) {
                pixelRGB = 3 * sectionH * width * ((z + 1) / n);
            } else {
                pixelRGB = 3 * sectionH * width * ((z + 1) / n) + (3 * (sectionW - (n / 2)));
            }
        }
    }
    
    // Outputs the image as a .ppm file
    _write_image("output.ppm");
}