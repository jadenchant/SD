#include <iostream>

class Image0 {
    int width;
    int height;

public:
    Image0(int w, int h) {
        width = w;
        height = h;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }
};

int main() {
    Image0 i1(640, 480);
    Image0 i2(1024, 768);

    std::cerr << i1.getWidth() << 'x' << i1.getHeight() << std::endl;
    std::cerr << i2.getWidth() << 'x' << i2.getHeight() << std::endl;
    
}