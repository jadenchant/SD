#include <iostream>
#include <iomanip>

struct Town {
    double total_pizza;
    int num_inhabitants;
    int num_student;
    double per_capita() {
        double res = total_pizza/num_inhabitants;
        return res;
    }
    double pizza_for_students() {
        double res = total_pizza/num_inhabitants;
        return res;
    }
    void eat_more() {
        total_pizza = (total_pizza * 0.1) + total_pizza;
    }
    void show_change() {
        std::cerr << pizza_for_students() << std::endl;
        eat_more();
        std::cerr << pizza_for_students() << std::endl;
    }
};

int main() {
    Town northfield {500000.1, 20007, 4067};
    Town faribault {400000, 23750, 3652};
    std::cerr << northfield.per_capita() << std::endl;
    std::cerr << faribault.per_capita() << std::endl;

    std::cout << std::setprecision(7) << northfield.total_pizza << std::endl;
    northfield.eat_more();
    std::cout << northfield.total_pizza << std::endl;

    faribault.show_change();
}