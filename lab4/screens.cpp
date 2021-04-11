#include"../react.h"

int main() {
  init();

  char state = _get_char(2);
  _put_raw(5, "hello");
  if (just_starting()) {
    state = 'H';
    _put_char(2, state);
  } else if (received_event()) {
    if (event_id_is("to_screen_two")) {
      state = 'T';
      _put_char(2, state);
    } else if (event_id_is("button_1")) {
      std::cerr << "ok!";
    } else if (event_id_is("to_home_screen")) {
      state = 'H';
      _put_char(2, state);
    }
  }
  if ('H' == state) add_yaml("home.yaml");
  else add_yaml("screen1.yaml");

  quit();
}
