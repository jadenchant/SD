#include "../show_mem.h"

int main() {
    // Intro to the story
    _put_raw(0, "Once upon a time there was a man from Delaware, USA.\nHe created a machine that could cure all diseases.\n\n");
    _print_raw(0);

    // Initial Choice
    _put_raw(0, "Please choose one of the following options:\n1) Keep the matchine.\n2) Destroy it.\nInput your choice (either 1 or 2):\n");
    _print_raw(0);
    _user_input(0);

    // Choice #1
    if ('1' == _get_char(0)) {
        _put_raw(0, "\nYou chose to keep the matchine that can save human lives.\n\n");
        _print_raw(0);

        // Secondary Choice A
        _put_raw(0, "Please choose one of the following options:\n1) Make the matchine widely available.\n2) Keep it for you.\nInput your choice (either 1 or 2):\n");
        _print_raw(0);
        _user_input(0);

        
        if('1' == _get_char(0)) {
            _put_raw(0, "\nYou chose to make the matchine widely available.\nDue to the fact that disease does not exist anymore,\noverpopulation takes over and the rich are the only ones who survive.\nYou become imfamous and are the first to die in a rebellion. :(\n");
        } else {
            _put_raw(0, "\nYou chose to keep the matchine for yourself.\nEventually people become suspicous due to the fact that you are 500 years old.\nFinally the Chinese Government steal the matchine from your workshop and they takeover the world. :(\n");
        }
    
    } 
    // Choice #2
    else {
        _put_raw(0, "\nYou chose to destroy the matchine.\nIt broke into a million pieces and was unfixable.\n\n");
        _print_raw(0);

        // Secondary Choice B
        _put_raw(0, "Please choose one of the following options:\n1) Build a time matchine and go back to before you broke the matchine that cure diseases.\n2) Eat a sandwich and get on with your life.\nInput your choice (either 1 or 2):\n");
        _print_raw(0);
        _user_input(0);

        
        if ('1' == _get_char(0)) {
            _put_raw(0, "\nYou chose to build a time matchine and go back to the past.\nYou were on the final component of the time matchine,\nbut it exploded and you died. :(\n");
        } else {
            _put_raw(0, "\nYou chose to eat a sandwich.\nAs you see the mustard drip on to your pant leg,\nyou realize how to become immortal and live out the rest of your life as a god. :)\n");
        }
        
    }
    
    // Prints the final outcome of all choices
    _print_raw(0);

}
