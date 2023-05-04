#include <iostream>
#include <iomanip>
#include "start_menu.h"
#include <chrono>
#include <thread>
#include <vector>
#include "game_status.h"
using namespace std;
using namespace ::this_thread;

char menu(){  //it is used for the opening of the game, it will include 4 choices, 1: new game; 2: load game and go back to where you stop; 3:some credits; 4:Exit
    cout << "                         ,--,     ,--,                                                                                                                               \n"
            "          ,--,        ,---.'|  ,---.'|      ,----..                   ,--,   ,----..           ,--.                          ,--.  ,----..           ,--.            \n"
            "        ,--.'|   ,---,|   | :  |   | :     /   /   \\                ,--.'|  /   /   \\        ,--.'| ,----..              ,--/  /| /   /   \\        ,--.'| ,----..    \n"
            "     ,--,  | : ,'  .' :   : |  :   : |    /   .     :            ,--,  | : /   .     :   ,--,:  : |/   /   \\          ,---,': / '/   .     :   ,--,:  : |/   /   \\   \n"
            "  ,---.'|  : ,---.'   |   ' :  |   ' :   .   /   ;.  \\        ,---.'|  : '.   /   ;.  ,`--.'`|  ' |   :     :         :   : '/ /.   /   ;.  ,`--.'`|  ' |   :     :  \n"
            "  |   | : _' |   |   .;   ; '  ;   ; '  .   ;   /  ` ;        |   | : _' .   ;   /  ` |   :  :  | .   |  ;. /         |   '   ,.   ;   /  ` |   :  :  | .   |  ;. /  \n"
            "  :   : |.'  :   :  |-'   | |__'   | |__;   |  ; \\ ; |        :   : |.'  ;   |  ; \\ ; :   |   \\ | .   ; /--`          '   |  / ;   |  ; \\ ; :   |   \\ | .   ; /--`   \n"
            "  |   ' '  ; :   |  ;/|   | :.'|   | :.'|   :  | ; | '        |   ' '  ; |   :  | ; | |   : '  '; ;   | ;  __         |   ;  ; |   :  | ; | |   : '  '; ;   | ;  __  \n"
            "  '   |  .'. |   :   .'   :    '   :    .   |  ' ' ' :        '   |  .'. .   |  ' ' ' '   ' ;.    |   : |.' .'        :   '   \\.   |  ' ' ' '   ' ;.    |   : |.' .' \n"
            "  |   | :  | |   |  |-|   |  ./|   |  ./'   ;  \\; /  |        |   | :  | '   ;  \\; /  |   | | \\   .   | '_.' :        |   |    '   ;  \\; /  |   | | \\   .   | '_.' : \n"
            "  '   : |  : '   :  ;/;   : ;  ;   : ;   \\   \\  ',  /         '   : |  : ;\\   \\  ',  /'   : |  ; .'   ; : \\  |        '   : |.  \\   \\  ',  /'   : |  ; .'   ; : \\  | \n"
            "  |   | '  ,/|   |    |   ,/   |   ,/     ;   :    /          |   | '  ,/  ;   :    / |   | '`--' '   | '/  .'        |   | '_\\.';   :    / |   | '`--' '   | '/  .' \n"
            "  ;   : ;--' |   :   .'---'    '---'       \\   \\ .'           ;   : ;--'    \\   \\ .'  '   : |     |   :    /          '   : |     \\   \\ .'  '   : |     |   :    /   \n"
            "  |   ,/     |   | ,'                       `---`             |   ,/         `---`    ;   |.'      \\   \\ .'           ;   |,'      `---`    ;   |.'      \\   \\ .'    \n"
            "  '---'      `----'                                           '---'                   '---'         `---`             '---'                 '---'         `---`  " << endl;
    
    sleep_for(chrono::seconds(1));
    cout << "==========" << "Welcome to Hello Hong Kong" << "==========" << '\n' << "1. New Game" << '\n' << "2. Load Game" << '\n' << "3. Credit" << '\n' << "4. Exit" << endl;
    sleep_for(chrono::seconds(1));
    char option;
    while(true) {
        cout << "Please input (1/2/3/4): " ;
        cin >> option ;
        if (isdigit(option)) {
            if (option >=49 and option <=52) {
                break;
            }
            else{
                cout << "Please input a valid value!!" << endl;
            }
        }
        else {
            cout << "Please input a valid value!!" << endl;
        }
    }
    return option;
}

void ending(bool result){   //True=good(real)/bad(fake) ending && False=lose ending
    if(result){
        cout << "THE END"<< endl;
        cout << "THANK FOR PLAYING" << endl;
        return;
    }
    else{
        cout << "YOU LOSE" << endl;     sleep_for(chrono::seconds(1));
        vector<string> lamo;    //initializing vector as a container for some quote
        lamo.push_back("Try harder next time!");
        lamo.push_back("You are a nerf !");
        lamo.push_back("What a pity !");
        lamo.push_back("Quite game is the only solution for you..");
        int index=random_event("ending_lose")-1;
        cout << lamo[index] << endl;
        lamo.clear();
    }
}
