#include <iostream>
#include <fstream>
// #include "../show_mem.h"

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
    char *name;
    int width;
    int height;
    int depth;
    Pixel **data;

public:
    Image(const char *fname) {
        std::ifstream f(fname);
        name = new char[3];
        f >> name;
        f >> width;
        f >> height;
        f >> depth;
        f.get();

        // allocating memory
        data = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            data[i] = new Pixel[width];
        }

        // filling memory
        for(int i = 0; i < height; ++i) {
            f.read(reinterpret_cast<char *>(data[i]), 3 * width);
        }

        f.close();
    }

    ~Image() {
        delete [] name;

        for(int i = 0; i < height; ++i) {
            delete [] data[i];
        }
        delete [] data;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    void zeroRed() {
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                data[i][j].red = 0;
            }
        }
    }

    void greyScale() {
        unsigned char pixelR;
        unsigned char pixelG;
        unsigned char pixelB;

        unsigned char avg;

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                pixelR = data[i][j].red;
                pixelG = data[i][j].green;
                pixelB = data[i][j].blue;
                
                avg = (pixelR + pixelG + pixelB) / 3;

                data[i][j].red = avg;
                data[i][j].green = avg;
                data[i][j].blue = avg;
            }
        }
    }

    void print() {
        std::ofstream f("output.ppm");
        f << name << std::endl;
        f << width << " " << height << std::endl;
        f << depth << std::endl;
        for(int i = 0; i < height; ++i) {
            f.write(reinterpret_cast<char *>(data[i]), 3 * width);
        }
        f.close();
    }
};

int main() {
    Image i1("tiny.ppm");

    

    i1.print();
}