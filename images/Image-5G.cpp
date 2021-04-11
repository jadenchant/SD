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

    Image(Image &image1) {
        width = image1.width;
        height = image1.height;
        depth = image1.depth;

        name = new char[3];
        for(int i = 0; i < 3; ++i) {
            name[i] = image1.name[i];
        }

        data = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            data[i] = new Pixel[width];
        }

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                data[i][j] = image1.data[i][j];
            }
        }
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

    void horizSqueeze() {
        int newWidth;
        if(width % 2 == 0) {
            newWidth = width / 2;
        } else {
            newWidth = (width / 2) + 1;
        }

        Pixel **newData = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            newData[i] = new Pixel[newWidth];
        }

        for(int i = 0; i < height; ++i) {
            for(int j = 0, index = 0; j < newWidth && (index + 2) < width; ++j) {
                newData[i][j] = data[i][index];
                index += 2;
            }
        }
        
        for(int i = 0; i < height; ++i) {
            delete[] data[i];
        }
        delete[] data;


        this->width = newWidth;

        data = new Pixel*[height];
        for(int i = 0; i < newWidth; ++i) {
            data[i] = new Pixel[newWidth];
        }

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                data[i][j] = newData[i][j];
            }
        }

        for(int i = 0; i < height; ++i) {
            delete[] newData[i];
        }
        delete[] newData;
    }

    void addBoarder() {
        // int initWidth = width;
        int initHeight = height;

        width += 2;
        height += 2;

        Pixel **newData = new Pixel*[height];
        for(int i = 0; i < height; ++i) {
            newData[i] = new Pixel[width];
        }

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(i != 0 && j != 0 && i != (height - 1) && j != (width - 1) && i != (height - 2) && j != (width - 2)) {
                    newData[i][j] = data[i - 1][j - 1];
                } else {
                    newData[i][j].red = 0;
                    newData[i][j].green = 0;
                    newData[i][j].blue = 0;
                }
            }
        }
        
        for(int i = 0; i < initHeight; ++i) {
            delete[] data[i];
        }
        delete[] data;

        data = new Pixel*[height];
        for(int i = 0; i < width; ++i) {
            data[i] = new Pixel[width];
        }

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                data[i][j] = newData[i][j];
            }
        }

        for(int i = 0; i < height; ++i) {
            delete[] newData[i];
        }
        delete[] newData;
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
    Image i2(i1);
    i1.addBoarder();
    i1.print();
}