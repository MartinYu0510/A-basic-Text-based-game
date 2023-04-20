#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "game_status.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace ::this_thread;
using namespace chrono;
const int sleep_t=1;

void input_status(Role *player) {       //Read input and assign value to player's name variable
    string option;
    cout << "Please input your character's name: ";
    cin >> player->name;
    sleep_for(chrono::seconds(1));
    cout << "Your name is " << player->name << '\n' << "Do you want to change your name ? (Yes/No): ";
    while (true) {
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        if (option != "yes" and option != "no") {       //Checking invalid input
            cout << "Invalid input! Please input Yes or No !! ";
        }
        else {
            if (option == "yes") {      //Looping for final determination of character's name
                cout << "Please input your name again: ";
                cin >> player->name;
                cout << "Your name is " << player->name << '\n' << "Do you want to change your name ? (Yes/No): ";
            }
            else  break;
        }
    }
}

void show_status(string name){          //Displaying the name of the character
    cout << "===============================================================================" << endl;
    cout <<  "Hello " << name << '\n' << "The game is going to start in..." << '\n' << "3" << endl;
    sleep_for(chrono::seconds(1));
    cout << '2' << endl;
    sleep_for(chrono::seconds(1));
    cout << '1' << endl;
    }

Role player_status_main(){      //Initializing player's status
    Role player;
    Role *player_addr=&player;
    input_status(player_addr);      //Assigning value for player's variable
    show_status(player_addr->name);        //Printing player's  name
    return player;
}

Role boss_status_init(int set){     //Initializing variable for boss's status
    Role boss;
    Role *boss_addr=&boss;
    switch(set) {                   //Assigning value to the variable due to different game sets
        case 1:
            boss.name="IPhone";boss.skill="Iphone Alarm Ring"; boss.HP=15 ; boss.Attack=2;
            break;
        case 2:
            boss.name="MrLai";boss.skill="Shinra Tensei"; boss.HP=25 ; boss.Attack=4;
            break;
        case 3:
            boss.name="ShoeShiner";boss.skill="Talk No Jutsu"; boss.HP=30 ; boss.Attack=6;
            break;
        case 4:
            boss.name="Your Boss";boss.skill="Slave"; boss.HP=40 ; boss.Attack=8;
            break;
    }
    return boss;
}

int random_event(string event){ //Generating random event i.e. critical hit and boss's moves
    srand(time(NULL));      //Randomize the seed for random function
    int result;
    if(event=="critical" || event=="def"){      //Random event for critical hit
        result=rand()%2;
        return result;
    }
    else if (event=="move"){    //Random for boss's moves
        result= 1+ (rand()%4);
        return result;
    }
    else if (event=="ending_lose"){     //Random for ending quote
        result=1+(rand()%4);
        return result;
    }
    else if(event =="trashword"){
        result=1+(rand()%3);
        return result;
    }
    return -1;
}

bool check_winloss(int player_hp, int boss_hp, bool &player_loss){      //Checking win or lose
    if(player_hp<=0){
        player_loss=true;
        return false;
    }
    else if(boss_hp<=0){
        player_loss= false;
        return false;
    }
    return true;
}

bool player_skill(Role *player_addr, Role *boss_addr, string skill){
    if(skill=="UnlimitedVoid") {
        if(player_addr->SP<8){
            cout << "Your SP is not enough, please choose another choice." << endl;
            return true;
        }
        else {
            player_addr->SP-=8;
            cout << player_addr->name << " : Domain Expansion: Unlimited Void." << endl;
            sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Wh...What?! What is this place..?" << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : It's ironic, right? When granted everthing you can't do anything.."
                 << endl;
            sleep_for(::seconds(sleep_t));
            cout << "[" << boss_addr->name << " cannot move for 1 turn]" << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " use attack." << endl;
            sleep_for(::seconds(sleep_t));
            if (random_event("critical") == 1) {
                cout << player_addr->name << " get a critical hit !" << endl;
                boss_addr->HP -= ((player_addr->Attack + 5) * 1.5);
            } else {
                boss_addr->HP -= (player_addr->Attack + 5);
            }

            if (boss_addr->HP < 0) {
                boss_addr->HP = 0;
                cout << player_addr->name << " : It's fine after all. You're weakkkk..." << endl;
            }
            cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;
        }
    }
    else if(skill=="Rumbling") {
        if(player_addr->SP<10){
            cout << "Your SP is not enough, please choose another choice." << endl;
            return true;
        }
        else {
            player_addr->SP-=10;
            cout << "[" << player_addr->name << " transforms into a giant titian with numerous skeletons]" << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : I, " << player_addr->name
                 << ", as the founding titan will destroy you until all the...." << endl;
            sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : ... ... ... That is .... Yeah... It's him" << endl;
            sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : ATTACK ON TITIAN!!!" << endl;
            sleep_for(::seconds(sleep_t));
            boss_addr->HP -= 10;
            if (boss_addr->HP < 0) {
                boss_addr->HP = 0;
                cout << player_addr->name << " : The people who witnessed these things..." << endl;
                sleep_for(::seconds(sleep_t));
                cout << player_addr->name << " : were the ones that had obtained the greatest freedom in thr world."
                     << endl;
                sleep_for(::seconds(sleep_t));
                cout << player_addr->name << " : This... is FREEDOM!!" << endl;
                sleep_for(::seconds(sleep_t));
            }
            cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;
        }
    }
    else if(skill=="StarPlatinum") {
        if(player_addr->SP<8){
            cout << "Your SP is not enough, please choose another choice." << endl;
            return true;
        }
        else {
            player_addr->SP-=8;
            cout << "[a purple ghost appears behind " << player_addr->name << "]" << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : It's is a stand named Star Platinum with a short range and a strong power."
                 << endl;
            sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Are you gonna do the ORA ORA thing..?" << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : YES! YES! YES! YES!" << endl;
            sleep_for(::seconds(sleep_t));
            for (int i = 0; i < 3; i++) {
                cout << "[ORA ORA ORA ORA ORA ORA ORA ORA ORA ORA" << endl;
                cout << boss_addr->name << " : AHHHHHHH!" << endl;
                sleep_for(::seconds(sleep_t));
                boss_addr->HP -= 3;
                if (boss_addr->HP < 0) {
                    boss_addr->HP = 0;
                    cout << player_addr->name << " : There's only one reason why you lost, " << boss_addr->name << endl;
                    sleep_for(::seconds(sleep_t));
                    cout << player_addr->name << " : There's just one simple answer." << endl;
                    sleep_for(::seconds(sleep_t));
                    cout << player_addr->name << " : You really pissed me off." << endl;
                    sleep_for(::seconds(sleep_t));
                    break;
                }
                cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;
            }
        }
    }
    else {
        if(player_addr->SP<8){
            cout << "Your SP is not enough, please choose another choice." << endl;
            return true;
        }
        else {
            player_addr->SP-=8;
            cout << "[A red flower occurred and " << player_addr->name << " turn into a guy with white clothing]"
                 << endl;
            sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Time to have BBQ" << endl;
            sleep_for(::seconds(sleep_t));
            for (int i = 0; i < 2; i++) {
                cout << "[" << boss_addr->name << " is burnt due to " << player_addr->name << " fire attacks]" << endl;
                sleep_for(::seconds(sleep_t));
                cout << boss_addr->name << " : Too HOt!!!!!" << endl;
                sleep_for(::seconds(sleep_t));
                boss_addr->HP -= (player_addr->Attack * 2);
                boss_addr->HP -= 2;
                if (boss_addr->HP == 0) {
                    boss_addr->HP = 0;
                    cout << player_addr->name << " : Mario Time !!!" << endl;
                    sleep_for(::seconds(sleep_t));
                }
                cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;
            }
        }
    }
    return false;
}
