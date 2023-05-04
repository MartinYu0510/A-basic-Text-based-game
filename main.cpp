#include <iostream>
#include <string>
#include <algorithm>
#include "start_menu.h"
#include "game_content.h"
using namespace std;

bool maingame(char mode){ //for player to choose the option in the game's opening and it will produce relative functions
    bool player_loss;
    switch(mode){
        case '1':
            player_loss=new_game();
            break;
        case '2':
            player_loss=load_game();
            break;
        case '3':
            cout << "This game is made by Martin Yu, Boris Wong and IDonnol." << '\n' << "This game is not funny because we aim to get good grade only." << '\n' << "If you want good gaming experience, I highly suggest you to play Elden Ring!!" << endl;
            player_loss=-1;
            break;
        case '4':
            cout << "Hope to seee you again !";
            exit(0);
    }
    return player_loss;
}

int main() {
    char mode;
    bool player_loss;
    string option;
    while (true) {
        mode = menu();
        player_loss = maingame(mode);
        if (player_loss != -1) {
            ending(!player_loss);
            while (true) {
                if (player_loss) {
                    cout << "Do you want to try again ?(Yes/No): ";
                    cin >> option;
                } else {
                    cout << "Do you want to start a new game ?(Yes/No): ";
                    cin >> option;
                }
                transform(option.begin(), option.end(), option.begin(), ::tolower);
                if (option != "yes" and option != "no") {       //Checking invalid input
                    cout << "Invalid input! Please input Yes or No !! ";
                } else {
                    break;
                }
            }
            if (option == "yes") {
                continue;
            } else {
                cout << "See you nex time !" << endl;
                break;
            }
        }
    }
    return 0;
}


