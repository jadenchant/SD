#include <iostream>
#include <fstream>
#include "../show_mem.h"

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
        std::cerr << width << "\n";
        f >> height;
        std::cerr << height << "\n";
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

    // _read_image("tiny.ppm", reinterpret_cast<char **>(i1.getData()), i1.getWidth(), i1.getHeight());    

    i1.print();
}