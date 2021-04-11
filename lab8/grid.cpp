#include"../react.h"
using namespace std;

void make_button(int i, int r, int g, int b, int r2, int g2, int b2) {
  add_yaml("button.yaml", {{"id", i}, {"r", r}, {"g", g}, {"b", b}, {"r2", r2}, {"g2", g2}, {"b2", b2}});
}

void handle_button(int button, int num_moves) {
  ++num_moves;
  if(num_moves == 1) {
    _put_raw(0,  (to_string(num_moves) + " move").c_str());
  } else {
    _put_raw(0,  (to_string(num_moves) + " moves").c_str());
  }
}

string getNumMoves(int index){
  string str;
  while(_global_mem[index]) {
    str += _global_mem[index++];
  }
  return str;
}

void build_random_board(int off, int w, int h, int num_c, const unsigned char colors[]) {
  
}

const int num_colors = 6;
const unsigned char button_colors[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240, 255};
int num_moves;
string str;

int main() {
  init();
  
  if(just_starting()) {
    num_moves = 0;
    str = to_string(num_moves) + " moves";
    _put_raw(0,  str.c_str());
    // build_random_board()
  } else {
    num_moves = stoi(getNumMoves(0));
  }

  add_yaml("flood_fill.yaml", {{"top_index", 0}});
  for(int i = 0, j = 0; i < num_colors; ++i, j += 3) {
    if(i == 0) {
      make_button(i, button_colors[j + 12], button_colors[j + 1], button_colors[j + 2], button_colors[j + 12] + 25, button_colors[j + 1] + 50, button_colors[j] + 30);
    }else if(i == 3) {
      make_button(i, button_colors[j - 7], button_colors[j + 1], button_colors[j + 2], button_colors[j - 7] + 25, button_colors[j + 1] + 25, button_colors[j] + 30);
    }else {
      make_button(i, button_colors[j], button_colors[j + 1], button_colors[j + 2], button_colors[j] + 25, button_colors[j + 1] + 10, button_colors[j] + 30);
    }
  }


  for(int i = 0; has_event_id() && i < num_colors; ++i) {
    if (event_id_is("button_", i)) {
      handle_button(i, num_moves);
      break;
    }
  }

  quit();
}