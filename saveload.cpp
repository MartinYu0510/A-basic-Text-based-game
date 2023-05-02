//
// Created by MartinYu on 6/4/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "saveload.h"
#include "game_status.h"
#include "game_content.h"
using namespace std;

void save(Role *player_addr, int set) {
    Role *player;
    player = new Role;
    *player = *player_addr;
    ofstream savegame;
    savegame.open("saveload.txt");
    if(savegame.fail())     cout << "File cannot open" << endl;
    else{
        savegame << player->name  <<  ' ' << player->HP << ' ' << player->SP << ' ' << player->Attack << ' ' << player_addr->good_end << ' ' << player->skill << endl ;
        savegame << set << endl;
        savegame.close();
        cout << "Progress is successfully saved !" << endl;
    }
    delete player;
}

Role load(Role *player_addr, int &set){
    Role temp;
    Role *player=new Role;
    *player=*player_addr;
    cout << "Start loading save..." << endl;
    ifstream loadgame;
    loadgame.open("saveload.txt");
    if (loadgame.fail())    cout << "File cannot open" << endl;
    else{
        int count=0;
        string line;
        while(getline(loadgame, line)){
            if(count==0) {
                istringstream line_in(line);
                string word;
                int i = 0;
                string *temp;
                temp = new string[6];
                while (line_in >> word) {
                    temp[i] = word;
                    i++;
                }
                player->name=temp[0];   player->skill=temp[5];  player->HP=stoi(temp[1]);   player->Attack=stoi(temp[3]);   player->SP=stoi(temp
                        [2]);   player_addr->good_end=stoi(temp[4]);
                delete[]temp;
                count++;
            }
            else if(count==1){
                set=stoi(line);
            }
        }
    }
    loadgame.close();
    temp=(*player);
    delete player;
    return temp;
}

