#include <iostream>
#include <fstream>
#include "../show_mem.h"

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
    int width;
    int height;
    int depth;
    Pixel **data;

public:
    Image(int w, int h) {
        width = w;
        height = h;
        depth = 255;

        data = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            data[i] = new Pixel[width];
        }
    }

    ~Image() {
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

    Pixel** getData() {
        return data;
    }

    void print() {
        std::ofstream f("output.ppm");
        f.write("P6\n", 3);
        f << width << " " << height << std::endl;
        f << depth << std::endl;
        for(int i = 0; i < height; ++i) {
            f.write(reinterpret_cast<char *>(data[i]), 3 * width);
        }
    }
};

int main() {
    Image i1(3, 2);

    // _read_image("tiny.ppm", reinterpret_cast<char **>(i1.getData()), i1.getWidth(), i1.getHeight());    

    i1.print();
}