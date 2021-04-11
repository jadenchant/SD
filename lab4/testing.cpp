#include "../react.h"
#include <iostream>


int nextFree(int index) {
  while(_get_char(index) != 0) {
    ++index;
  }
  return ++index;
}

void resetMem(int index) {
  while(_get_char(index) != 0) {
    _put_char(index, '~');
    ++index;
  }
  _put_char(index, '~');
}

int main() {
  init();

  int freeMem = 0;
  char screen = _get_char(0);
  _put_raw(2, "Option 1");
  _put_raw(11, "Option 2");
  
  if(just_starting()) {
    screen = 0;
    _put_raw(20, "Welcome to Choose Your Own Adventure!");
    freeMem = nextFree(20);
    _put_raw(freeMem, "There once was a boy named David, he grew up poor with his mother and his drunk father. As he grew older, David became more and more unstable and mentally ill. He is living on the streets with only $100 dollars to his name. Does he want to either find a job (Option 1) or go back and live with his elderly parents (Option 2)?");
  } else if(received_event()) {
    if(event_id_is("option1")) {
      screen = 1;
      _put_raw(20, "David decides it's time to find another job.");
      freeMem = nextFree(20);
      _put_raw(freeMem, "David, on his last $100, goes around his glorious town of Ogden, Utah trying to find a job. He has a choice, does he either trying to get a job at McDonald's (Option 1) or get a job at the Treehouse Museum (Option 2)?");
    } else if(event_id_is("option2")){
      screen = 2;
      _put_raw(20, "David decides to live at home with his parents.");
      freeMem = nextFree(20);
      _put_raw(freeMem, "Unfortunatly, David forgot that his parents live in a nursing home, due to fact that his father is 92 and his mother is 95. He sneeks in to live with them in thier 200 square foot nursing home. He now has an important choice, does he hide in the supply closet (Option 1) or move into the open room at the end of the hall (Option 2)?");
    } else if(event_id_is("option11")) {
      screen = 11;
      _put_raw(20, "Restart");
      freeMem = nextFree(20);
      _put_raw(freeMem, "David gets the job at McDonald's as a custodian. With the little money he makes at McDonald's, he buys a small trashy apartment. One day as he is scrubbing the dirty walls in the woman's bathroom of the McDonald's, he breaks from all of the menial labor. He quits his job and becomes a custodian at a large bank. He lives out his later years in Miami, Florida.");
    } else if(event_id_is("option12")) {
      screen = 12;
      _put_raw(20, "Restart");
      freeMem = nextFree(20);
      _put_raw(freeMem, "David gets the job at the Treehouse Museum (wow they must despritly need someone). He gives tours to children during school field trips. Due to the fact that it is a treehouse museum, he then has a place to live, in one of the treehouses. He loves his job and begins to pull his life around. After 2 years, he purchases a nice 2 bedroom apartment. He meets a nice girl in the apartment next to his. They eventually get married and have 3 children. In the later years of his life, after all of his children are grown up, he lives out the rest of his days with his wife in a small cabin on the Great Salt Lake.");
    } else if(event_id_is("option21")) {
      screen = 21;
      _put_raw(20, "Restart");
      freeMem = nextFree(20);
      _put_raw(freeMem, "David decided to hid / live in a supply closet. No one ever used that supply closet. Every morning, he put on some makeup in order to look older. He fit in quite nicely due to the fact that he was mentally ill. He enjoyed the bread pudding on Tuesdays and lived out the rest of his days in the nursing home.");
    } else if(event_id_is("option22")) {
      screen = 22;
      _put_raw(20, "Restart");
      freeMem = nextFree(20);
      _put_raw(freeMem, "David took the place of Margret Fishner. It was very difficult to pretend that he was Margret and convince the nursing home staff that he was her. It worked for a good 3 minutes to notice that Margret had returned from the dead. The staff caught David in the act of downing a chocolate pudding. He was thrown back onto the streets.");
    } else if(event_id_is("restart")) {
      screen = 0;
      _put_raw(20, "Restart");
      freeMem = nextFree(20);
    _put_raw(58, "There once was a boy named David, he grew up poor with his mother and his drunk father. As he grew older, David became more and more unstable and mentally ill. He is living on the streets with only $100 dollars to his name. Does he want to either find a job (Option 1) or go back and live with his elderly parents (Option 2)?");
    }
  }

  _put_char(0, screen);

  // Yaml
  if(_get_char(0) == 0) {
    add_yaml("test0.yaml");
  } else if(_get_char(0) == 1) {
    add_yaml("test1.yaml");
  } else if(_get_char(0) == 2) {
    add_yaml("test2.yaml");
  } else if(_get_char(0) == 11) {
    add_yaml("test11.yaml");
  } else if(_get_char(0) == 12) {
    add_yaml("test12.yaml"); 
  } else if(_get_char(0) == 21) {
    add_yaml("test21.yaml");
  } else if(_get_char(0) == 22) {
    add_yaml("test22.yaml");
  }
  
  quit();
}