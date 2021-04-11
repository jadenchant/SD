#include "../react.h"
  
int main() {
  init();

  if (received_event()) {
    if (event_id_is("go")) {
      std::cerr << "yes\n";
    } else if (event_id_is("stop")) {
      std::cerr << "no\n";
    }
  }
  add_yaml("green_red.yaml");

  quit();
}
