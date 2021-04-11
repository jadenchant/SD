#include<iostream>

int item_count;
double *item_price;

void print_items() {
  for (int i = 0; i < item_count; ++i) {
    std::cerr << item_price[i] << ' ';
  }
  std::cerr << '\n';
}

void change_items() {
  delete [] item_price;
  item_count = 3;
  item_price = new double[item_count];
  item_price[0] = 9;
  item_price[1] = 11;
  item_price[2] = 13;
}

void double_items() {
    double *temp = new double[2 * item_count];
    for(int j = 0; j < item_count; ++j) {
        temp[j] = item_price[j];
    }
    for(int j = 0; j < item_count; ++j) {
            temp[item_count + j] = item_price[j];
        }
    delete [] item_price;
    item_count *= 2;
    item_price = temp;
}

int main() {
  item_count = 2;
  item_price = new double[item_count];
  item_price[0] = 5;
  item_price[1] = 7;
  print_items();
  double_items();
  print_items();
  change_items();
  print_items();
  double_items();
  print_items();
  delete [] item_price;
}
