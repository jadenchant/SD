#include"../react.h"

int main() {
  init();  // commented out for now

  add_yaml("button.yaml", {{"id", 0}});
  add_yaml("button.yaml", {{"id", 1}});
  add_yaml("button.yaml", {{"id", 2}});

  quit();
}