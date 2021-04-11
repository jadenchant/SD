#include "../react.h"
  
int main() {
  init();

  if (received_event()) {
    if (event_id_is("blue")) {
      std::cerr << "blue\n";
    } else if (event_id_is("pink")) {
      std::cerr << "pink\n";
    } else if (event_id_is("orange")) {
        std::cerr << "orange\n";
    }
  }
  add_yaml("three_buttons.yaml");

  quit();
}