#include <iostream>
#include <fstream>
#include "../react.h"

// http://anansi.stolaf.edu/sd/local/?TO=rns202-10.cs.stolaf.edu:25118

int _mem_size = 10000;
const int text_input_index = 20;

void write_message(int index, const char author[], const char msg[]) {
  _put_raw(index, time_of_day(current_time()), true);
  _put_raw(index + 9, author, true);
  _put_raw(index + 20, msg, true);
}

void display_messages(int num_messages) {
  for(int i = 1, currentIndex = 100; i <= num_messages; ++i, currentIndex += 100) {
    add_yaml("bubble.yaml", {{"indent", 50}, {"time_index", currentIndex}, {"author_index", currentIndex + 9}, {"msg_index", currentIndex + 20}});
  }
}

int main(int argc, char **argv) {
    init();
    get_shared_data();
    add_yaml("scrollable.yaml");
    if(just_starting()) {
      _global_shared_mem[10] = 0;
      _global_mem[10] = 0;
    } else if (received_event()) {
      char *message = _global_shared_mem + get_event_index();
      if(message[0] != 0) {
          ++_global_shared_mem[10];
          write_message(100 * _global_shared_mem[10], get_user_name(), message);
      }
    }
    _global_mem[10] = _global_shared_mem[10];
    // std::cerr << _global_mem[10] << std::endl;
    int tempIndex;
    for(int i = 1, currentIndex = 100; i <= _global_mem[10]; ++i, currentIndex += 100) {
      tempIndex = currentIndex;
      // Time
      while(_global_shared_mem[tempIndex] != 0 && _global_shared_mem[tempIndex] != '~') {
        _global_mem[tempIndex] = _global_shared_mem[tempIndex];
        ++tempIndex;
      }
      _global_mem[tempIndex++] = 0;
      // Author
      while(_global_shared_mem[tempIndex] != 0 && _global_shared_mem[tempIndex] != '~') {
        _global_mem[tempIndex] = _global_shared_mem[tempIndex];
        ++tempIndex;
      }
      _global_mem[tempIndex++] = 0;
      // Message
      while(_global_shared_mem[tempIndex] != 0 && _global_shared_mem[tempIndex] != '~') {
        _global_mem[tempIndex] = _global_shared_mem[tempIndex];
        ++tempIndex;
      }
      _global_mem[tempIndex] = 0;
    }

    display_messages(_global_shared_mem[10]);
    add_yaml("end_input.yaml", {{"index", text_input_index}});
    _put_raw(text_input_index, "", true);
    _put_raw(text_input_index, "");
    quit();
}