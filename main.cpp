#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "start_menu.h"
#include "game_content.h"
using namespace std;
using namespace ::this_thread;

int maingame(char mode){
    switch(mode){
        case '1':
            new_game();
            break;
        case '2':
            load_game();
            break;
        case '3':
            cout << "Hope to seee you again !";
            exit(0);
    }
}


int main() {
    char mode;      //rmb to implement a function for returning to the main meun
    mode=menu();
    maingame(mode);
    //ending()
    return 0;
}


