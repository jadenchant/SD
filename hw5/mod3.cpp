# include "../show_mem.h"

int main() {
  // get a numeric character from the user
  _put_raw(0, "Please enter a small integer (0 - 9): ");
  _print_raw(0);
  _user_input(0);

  // change what the user typed into a number
  char c = _get_char(0);  // this is the character
  char num = c - '0';     // this is the number

  if (num % 3 == 0) {
    _put_raw(0, "This integer is divisible by 3!\n");
  } else if (num % 3 == 1) {
    _put_raw(0, "This integer has a remainder of 1, when divided by 3.\n");
  } else {
    _put_raw(0, "This integer has a remainder of 2, when divided by 3.\n");
  }
  _print_raw(0);
}
