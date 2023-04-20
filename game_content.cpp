//
// Created by MartinYu on 4/4/2023.
//
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "game.status.h"
#include "saveload.h"
#include <algorithm>
#include "start_menu.h"
#include "game_plot.h"
#include <vector>
#include "ascii.h"
using namespace std;
using namespace ::this_thread;
using namespace chrono;
const int sleep_t=1;
vector<string> trashword;

void set1(Role *player_addr, int &set, bool player_loss){
    Role boss;
    boss=boss_status_init(set);
    Role *boss_addr=&boss;
    plot1_start(player_addr, boss_addr);
    boss_addr->half_hp=false;
    player_addr->HP=15;
    player_addr->Attack=2;
    int hp=boss_addr->HP;
    while(check_winloss(player_addr->HP, boss_addr->HP, player_loss)){
        char move;
        cout << "========================Your Turn========================" << endl;    sleep_for(::seconds(sleep_t));
        cout << "HP: " << player_addr->HP << "  " << "Attack: " << player_addr->Attack << endl;
        cout << "1. Attack" << '\n' << "2. Defend" << '\n' << "3. Escape" << endl;
        while(true) {
            cout << "Your move(1/2/3): ";
            cin >> move;
            if (move > 51 || move < 49) {
                cout << "Please input a valid value!!" << endl;
            } else {
                break;
            }
        }
        switch(move){
            case '1':
                cout << player_addr->name << " use attack." << endl;    sleep_for(::seconds(sleep_t));
                if(random_event("critical")==1){
                    cout << player_addr->name << " get a critical hit !" << endl;
                    boss_addr->HP-=(player_addr->Attack * 1.5);
                }
                else{
                    boss_addr->HP-=player_addr->Attack;
                }

                if(boss_addr->HP<0){
                    boss_addr->HP=0;
                }
                cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;
                break;
            case '2':
                int chance;
                chance=random_event("def");
                if(chance==1){
                    player_addr->defense=true;
                }
                else{
                    player_addr->defense=false;
                }
                cout << player_addr->name << " use defense." << endl;   sleep_for(::seconds(sleep_t));
                break;
            case '3':
                cout << player_addr->name << " use escape." << endl;    sleep_for(::seconds(sleep_t));
                cout << boss_addr->name << " You are a loser !!!" << endl;  sleep_for(::seconds(sleep_t));
                ending(false);
                break;
        }
        if(boss_addr->HP<=0){
            player_loss=false;
            break;
        }
        if(boss_addr->HP<=hp/2 && boss_addr->half_hp==false){
            boss_addr->half_hp=true;
            cout << boss_addr->name << " : You are making me.... ANGRYYYYY!!!!!!!!" << endl;    sleep_for(::seconds(sleep_t));
            cout << "[" << boss_addr->name << " get into Overloading mode...]" << endl;
            cout << "[" << boss_addr->name << "'s attack rose...]" << endl;     sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : use special skill, " << boss_addr->skill << endl;    sleep_for(::seconds(sleep_t));
            for(int i=0; i<2;i++){
                cout << "Ding... Ding... Ding... Ding..." << endl;  sleep_for(::seconds(sleep_t));
                player_addr->HP-=2;
                if(player_addr->HP<0){
                    player_addr->HP=0;
                }
                cout << player_addr->name << "'s hp is decreasing due to horrible alarm..." << '\n' << "HP: " << player_addr->HP << endl;   sleep_for(::seconds(sleep_t));
                cout << player_addr->name << " : Oh come on... why will this happen to me..." << endl;  sleep_for(::seconds(sleep_t));
            }
            cout << boss_addr->name << " : Why don't you just give up?" << endl;    sleep_for(::seconds(sleep_t));
        }
        cout << "========================Boss Turn========================" << endl;    sleep_for(::seconds(sleep_t));
        cout << "HP: " << boss_addr->HP << endl;
        move=random_event("move")+48;
        switch(move){
            case '1':
                cout << boss_addr->name << " use attack." << endl;  sleep_for(::seconds(sleep_t));
                if(player_addr->defense){
                    cout << player_addr->name << " successfully defend " << boss_addr->name << "'s attack " << endl;    sleep_for(::seconds(sleep_t));
                    boss_addr->HP-=(player_addr->Attack/2);
                    cout << boss_addr->name << " is hurt due to the rebound damage." << endl;
                    cout << boss_addr->name << "'s HP decrease to " << boss_addr->HP << endl;   sleep_for(::seconds(sleep_t));
                }
                else{
                    player_addr->HP-=boss_addr->Attack;
                    cout << player_addr->name << "'s HP decreases to " << player_addr->HP << endl;  sleep_for(::seconds(sleep_t));
                }
                break;
            case '2':
                cout << boss_addr->name << " use recharging." << endl;    sleep_for(::seconds(sleep_t));
                boss_addr->HP+=1;
                cout << boss_addr->name << "'s HP is regenerate by 1." << '\n' << boss_addr->name << " : HaHa!! My health has returned! " << endl;  sleep_for(::seconds(sleep_t));
                break;
            case '3':
                cout << boss_addr->name << " use ridicule." << endl;    sleep_for(::seconds(sleep_t));
                trashword.emplace_back("You must be a Android user!"); trashword.emplace_back("I should feed you some apples, kid!"); trashword.emplace_back("Do you want some Iphone alarm sound??");
                cout << boss_addr->name << " : " << trashword[random_event("trashword")-1] << endl; sleep_for(::seconds(sleep_t));
                trashword.clear();
                break;
            case '4':
                if(boss_addr->boss_skill_charge>=3) {
                    cout << boss_addr->name << " : use special skill, " << boss_addr->skill << endl;
                    sleep_for(::seconds(sleep_t));
                    boss_skill1(player_addr, boss_addr);
                    boss_addr->boss_skill_charge-=3;
                }
                break;
            }
        boss_addr->boss_skill_charge++;
        player_addr->defense=false;
    }
    plot1_ending(player_addr, boss_addr, player_loss);
    if(player_loss){
        ending(false);
    }
    string option;
    cout << "Do you want to save your game ?(Yes/No) " ;
    while(true) {
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        if (option != "yes" and option != "no") {       //Checking invalid input
            cout << "Invalid input! Please input Yes or No !! ";
        }
        else {
            save(player_addr, set);
            break;
        }
    }
    set++;
}

void skill_choice(Role *player_addr, int &set){
    cout << "[" << player_addr->name << "'s HP is regenerated to 20 due to breakfast]" << endl;   sleep_for(::seconds(sleep_t));
    player_addr->HP=20;
    cout << "[" << player_addr->name << " also gain 10 skill point for using special skill]" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Maybe I should buy something in 7-11...eH? What are those things?" << endl;    sleep_for(::seconds(sleep_t));
    cout << "You can choose your own skill here. Remember, you cannot change your skill after confirmation..." << endl;
    cout << "1. Unlimited Void " << '\n' << "2. Rumbling " << '\n' << "3. Star Platinum" << '\n' << "4. Fire Flower" << endl;
    cout << "If you want to get further information, please enter help (1/2/3/4)." << endl;
    while(true) {
        string command;char choice;
        cout << "Please choose your desirable skill(Help/Add) (1/2/3/4): ";
        cin >> command >> choice;
        transform(command.begin(),command.end(),command.begin(),::tolower);
        if(command=="add") {
            if (choice > 52 || choice < 49) {
                cout << "Please input a valid value!" << endl;  sleep_for(::seconds(sleep_t));
            } else {
                switch (choice) {
                    case '1':
                        player_addr->skill="UnlimitedVoid";
                        break;
                    case '2':
                        player_addr->skill="Rumbling";
                        break;
                    case '3':
                        player_addr->skill="StarPlatinum";
                        break;
                    case '4':
                        player_addr->skill="FireFlower";
                        break;
                }
                break;
            }
        }
        else if (command=="help"){
            switch (choice) {
                case '1':
                    skill1_ascii();
                    cout << "An advanced jujutsu named domain expansion. It seems to be a technique belong to a powerful man. " << endl;
                    cout << "Enemy will stop for 1 turn and your Attack will be increased by 5 in 1 turn after activating this skill with 8 SP." << endl;
                    break;
                case '2':
                    skill2_ascii();
                    cout << "A horrible skill as people always mention that 80% of the humanity was killed due to rumbling a long time ago...." << endl;
                    cout << "Enemy will be damged by 10HP after activating this skill with 12 SP." << endl;
                    break;
                case '3':
                    skill3_ascii();
                    cout << "A purple ghost but it seem to be a powerful fighter.." << endl;
                    cout << "Enemy will be damaged by 2HP for 3 turn after activating this skill with 8 SP." << endl;
                    break;
                case '4':
                    skill4_ascii();
                    cout << "A red flower and you will get fire when touching it..." << endl;
                    cout << "Your attack will be increased by 2 in 2 turns and enemy will be burnt in 2 turns after activating this skill with 8 SP." << endl;
                    break;
            }
        }
        else{
            cout << "Please input a valid value!" << endl;
        }
    }

    cout << player_addr->name << " learn " << player_addr->skill << endl;   sleep_for(::seconds(sleep_t));
}
void set2(Role *player_addr, int &set, bool player_loss){
    Role boss;
    boss=boss_status_init(set);
    Role *boss_addr=&boss;
    int hp=boss_addr->HP; boss_addr->half_hp=false;
    plot2_start(player_addr, boss_addr);
    //To be implemented
    string option;
    cout << "Do you want to save your game ?(Yes/No) " ;
    while(true) {
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        if (option != "yes" and option != "no") {       //Checking invalid input
            cout << "Invalid input! Please input Yes or No !! ";
        }
        else {
            save(player_addr, set);
            break;
        }
    }
    set++;
}

void set3(Role *player_addr, int &set, bool player_loss){
    Role boss;
    boss=boss_status_init(set);
    Role *boss_addr=&boss;
    int hp=boss_addr->HP; boss_addr->half_hp=false;
    plot3_start(player_addr, boss_addr);
    //To be implemented
    string option;
    cout << "Do you want to save your game ?(Yes/No) " ;
    while(true) {
        cin >> option;
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        if (option != "yes" and option != "no") {       //Checking invalid input
            cout << "Invalid input! Please input Yes or No !! ";
        }
        else {
            save(player_addr, set);
            break;
        }
    }
    set++;
}

void set4(Role *player_addr, int &set, bool player_loss){
    Role boss;
    boss=boss_status_init(set);
    Role *boss_addr=&boss;
    int hp=boss_addr->HP; boss_addr->half_hp=false;
    plot4_start(player_addr,boss_addr);
    //To be implemented
}

void new_game(){        //Starting a new game
    int set=1;
    bool player_loss=false;
    Role player;
    Role *player_addr=&player;
    player=player_status_main();
    set1(player_addr, set, player_loss);
    skill_choice(player_addr, set);
    set2(player_addr, set, player_loss);
    set3(player_addr, set, player_loss);
    set4(player_addr, set, player_loss);
}

void load_game(){       //Loading the original game
    int set;
    bool player_loss=false;
    Role player;
    Role *player_addr=&player;
    player=load(player_addr, set);
    switch(set){
        case 1:
            skill_choice(player_addr, set);
            set2(player_addr, set, player_loss);
            set3(player_addr, set, player_loss);
            set4(player_addr, set, player_loss);
            break;
        case 2:
            set2(player_addr, set, player_loss);
            set3(player_addr, set, player_loss);
            set4(player_addr, set, player_loss);
            break;
        case 3:
            set3(player_addr, set, player_loss);
            set4(player_addr, set, player_loss);
            break;
        case 4:
            set4(player_addr, set, player_loss);
            break;
    }
}


