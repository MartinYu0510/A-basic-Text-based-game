//
// Created by MartinYu on 9/4/2023.
//
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>
#include "game_plot.h"
#include "game_status.h"
#include "game_content.h"
#include "start_menu.h"
#include "ascii.h"
using namespace std;
using namespace ::this_thread;
using namespace chrono;
const int sleep_t=1;

void plot1_start(Role *player_addr, Role *boss_addr){       //Plot for set1
    cout << "Hello from Hong Kong !" << '\n' << "Be inspired by..." << endl;    sleep_for(::seconds(sleep_t));
    cout << "New Opportunities !" << endl;  sleep_for(::seconds(sleep_t));
    cout << "New Facilities !" << endl; sleep_for(::seconds(sleep_t));
    cout << "New Experience !" << endl; sleep_for(::seconds(sleep_t));
    cout << "And so much more..." << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : What the he...." << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh ! I forgot to close the youtube page bruh..." << endl;  sleep_for(::seconds(sleep_t));
    cout << "[" << player_addr->name << " suddenly throw the phone away]" << endl;  sleep_for(::seconds(sleep_t));
    cout << "Sh....t !!!! It's 8:30 a.m. now !!!! I am going to be late!!!!!" << endl;  sleep_for(::seconds(sleep_t));
    string option;
    cout << "Do you want to rush to work or I am suc.... (Yes/No)： " ;
    cin >> option;
    transform(option.begin(), option.end(), option.begin(), ::tolower);
    if(option=="no"){
        cout << "You are too lazy !" << endl;   sleep_for(::seconds(sleep_t));
        cout << "Being a HongKonger means that you should become a hard-working worker, so you're fired !!!"<< endl;    sleep_for(::seconds(sleep_t));
        ending(false);
    }
    cout << player_addr->name << " : I should run now...." << endl; sleep_for(::seconds(sleep_t));
    cout << "Strange Sound : Ding Ding Ding....." << endl;  sleep_for(::seconds(sleep_t));
    cout << "[Some footstep is approaching.....]" << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh My Jesus... Why is this happening !!!!" << endl;    sleep_for(::seconds(sleep_t));
    cout << "The smart phone is getting bigger and bigger" << endl; sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : What make you think that you can throw me away???" << endl;  sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : How dare You!!!!!!!!" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : What the ........ I don't want to break my phone..." << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : It costs $9000 !! Oh come on.... " << endl;    sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : I will help you to see Steve Job....." << endl;  sleep_for(::seconds(sleep_t));
    cout << "========================Battle 1========================" << endl;
    cout << "Boss : " << boss_addr->name << " HP: " << boss_addr->HP << " Skill: " << boss_addr->skill << endl;     sleep_for(::seconds(sleep_t));
}

void plot1_ending(Role *player_addr, Role *boss_addr, int player_loss){
    if(player_loss){
        cout << boss_addr->name << " : You were two steps too late..." << player_addr->name << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : Just prepare to see my creator, Steve Job...." << endl; sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : And I will replace your existence...." << endl;  sleep_for(::seconds(sleep_t));
    }
    else{
        string option;
        cout << boss_addr->name << " : You can't defeat me !!" << endl; sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : I know I know ! Who he can.." << endl; sleep_for(::seconds(sleep_t));
        cout << "[" << player_addr->name << " takes the charger away from the phone]" << endl;  sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : How... dare you.... your battery is lower than 20%.... 10%....." << endl;   sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : I... just ... want ... to ... be like...you..." << endl; sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : Oh...should I recharge it ?" << endl;    sleep_for(::seconds(sleep_t));
        cout << "Do you want to save " << boss_addr->name << " ? (Yes/No): ";
        while(true) {
            cin >> option;
            transform(option.begin(), option.end(), option.begin(), ::tolower);
            if (option != "yes" and option != "no") {       //Checking invalid input
                cout << "Invalid input! Please input Yes or No !! ";
            }
            else {
                break;
            }
        }
        if(option=="yes"){
            cout << boss_addr->name << " : Why...? You should not do this! I just hurt you...." << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : I don't care about it...as I am your owner.. I think?" << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : May be... we are the same type, we just wanna escape from our duty, escape from our role...." << endl; sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : And I just wanna escape from....jo... never mind.." << endl;   sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " leave the place after recharging the phone]" << endl; sleep_for(::seconds(sleep_t));
            cout << "[" << boss_addr->name << " just remain silence and watch " << player_addr->name << " leave...]" << endl;   sleep_for(::seconds(sleep_t));
            player_addr->good_end++;
        }
        else{
            cout << player_addr->name << " : I remember that you told me something at the beginning..." << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Oh!You said that you will help me to see Steve Job, right? " << endl;  sleep_for(::seconds(sleep_t));
            cout << "[" << boss_addr->name << " look at " << player_addr->name << " with a very scared face....]" << endl;  sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Please forgive me, my owner...." << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Say it to your creator boi, time to use my reverse card..." << endl;   sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " throw away the charger and " << boss_addr->name << " shut down immediately]" << endl;     sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Arrivederci!" << endl; sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " leave with a cool shadow]" << endl;   sleep_for(::seconds(sleep_t));
        }
    }
}

void plot2_start(Role *player_addr, Role *boss_addr){
    cout << "[" << player_addr->name << " finally arrive the MTR station]" << endl;     sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Fina...lly, I arrive the station. Oh! There is a car!" << endl;    sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Waittt! Be careful!!!" << endl;    sleep_for(::seconds(sleep_t));
    cout << "[" << player_addr->name << " run into a man in front of him]" << endl;     sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh... I am so careless... I am so sorry sir.." << endl;    sleep_for(::seconds(sleep_t));
    cout << "[The subway move away...]" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Hey ! Kid!! I miss this subway because of you !!! Are you blind ???" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : I am so sorry sir... I also miss subway too, so we are on the same boat." << endl;    sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : I don't care the boat!! You are making me late now!!!" << endl;  sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : My demand is to go to work !!!" << endl;     sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Do!! YOU!!!! UNDER!!!!STAND!!!!!!!!!" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh MY GOD...." << endl;    sleep_for(::seconds(sleep_t));
    cout << "========================Battle 2========================" << endl;
    cout << "Boss : " << boss_addr->name << " HP: " << boss_addr->HP << " Skill: " << boss_addr->skill << endl;     sleep_for(::seconds(sleep_t));
 }

void plot2_ending(Role *player_addr, Role *boss_addr, int player_loss){
    if(player_loss){
        cout << boss_addr->name << " : I TOLD YOU!! MY ONLY DEMAND IS TO GO TO WORK!" << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : I am the employee! I am the man who work for my employee!" << endl;  sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : That's not truth!! You work for yourself!!" << endl;   sleep_for(::seconds(sleep_t));
        cout << "[" << boss_addr->name << " just smile at " << player_addr->name << "]" << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : NOW! Say My Name!" << endl;  sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : " << boss_addr->name << endl;  sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : You are God ____ Right!" << endl;    sleep_for(::seconds(sleep_t));
    }
    else{
        string option;
        cout << boss_addr->name << " : WHY!! How can you beat me..." << endl;   sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : You are just a weak employee! How can you beat someone like me!!!" << endl;  sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : You are the noob who will always get into danger !!!! NOT MEE!!" << endl;    sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : Who are you talking to right now? Who is it you think you see?" << endl;   sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : You clearly don't know who you're talking to, so let me clue you in." << endl; sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : I am not in danger, " << boss_addr->name << endl;  sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : I AM THE DANGER !" << endl;    sleep_for(::seconds(sleep_t));
        cout << "[" << player_addr->name << " is ready to give " << boss_addr->name << " the last punch]" << endl;  sleep_for(::seconds(sleep_t));
        cout << "Do you want to forgive " << boss_addr->name << " ? (Yes/No)" << endl;
        while(true) {
            cin >> option;
            transform(option.begin(), option.end(), option.begin(), ::tolower);
            if (option != "yes" and option != "no") {       //Checking invalid input
                cout << "Invalid input! Please input Yes or No !! ";
            }
            else {
                break;
            }
        }
        if(option=="yes"){
            cout << "[" << player_addr->name  << " stops his punch]" << endl;   sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Why did you do that..?" << endl;     sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Don't think too much. I don't want to make my hands dirty instead of forgiving you!" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You are not the only man who suffer in employee.. We Live in... " << endl; sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : A SOciEty... All of us are suffered too..." << endl;   sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << "get into the subway]" << endl;     sleep_for(::seconds(sleep_t));
            player_addr->good_end++;
        }
        else{
            cout << player_addr->name << " : Do you think a guy open his door and get punched." << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You think that was me ??" << endl;     sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : NO!! I am the one who knocks!!" << endl;   sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Please no!!!!PLEASE!!!!" << endl;    sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " give his last punch to " << boss_addr->name  << endl;     sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You will understand your mistake when you wake up.." << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : OH NO!! I am late now !!!" << endl;    sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " rush into the subway]" << endl;   sleep_for(::seconds(sleep_t));
        }
    }
}

void plot3_start(Role *player_addr, Role *boss_addr){
    cout << "[" << player_addr->name  << " finally arrives his company]" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Huh....Huh....I finally arrive..." << endl;    sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh No!!! I am late for 1 minutes !!! OH GOD WHY WHY WHY..." << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : HAHA!! Look like someone is late today!!" << endl;   sleep_for(::seconds(sleep_t));
    cout << "[" << boss_addr->name << " comes out and laught at " << player_addr->name << endl; sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : So?? You are going to report to your favourite boss??" << endl;  sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : NONONO! I am a good people. If I tell him, you will get a very serious penalty. " << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Why don't you give me somethings... Maybe I can help you to speak somethings to the boss!" << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Huh? Are you crazy? Why do I need to bribe someone like you?" << endl; sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : O!K! This is your choice !! You are done." << endl;  sleep_for(::seconds(sleep_t));
    cout << "[" << player_addr->name << " is very angry and move to " << boss_addr->name << "]" << endl;    sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : " << boss_addr->name << "!" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Oh?! You are approaching me?" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Instead of running away, you're coming right to me?" << endl;    sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : I can't beat the hell out of you without getting closer." << endl; sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : OH!HO!Then come as close as you like." << endl;  sleep_for(::seconds(sleep_t));
    set3_ascii();   sleep_for(::seconds(sleep_t));
    cout << "========================Battle 3========================" << endl;
    cout << "Boss : " << boss_addr->name << " HP: " << boss_addr->HP << " Skill: " << boss_addr->skill << endl;     sleep_for(::seconds(sleep_t));


}

void plot3_ending(Role *player_addr, Role *boss_addr, int player_loss){
    if(player_loss){
        cout << boss_addr->name << " : What a pity?!People like you will never surpass me." << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : You should be grateful because you have lost in my hand!" << endl;   sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : And be thankful! I help you to escape from this hell! So long my friend!" << endl;   sleep_for(::seconds(sleep_t));
    }
    else{
        string option;
        cout << player_addr->name << " : CHECKMATE!" << endl;   sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : Impossible !I should not loss in your hand!!" << endl;   sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : You're wrong! You lost because you only fight with your mouth, but I win becuase I fight with my hands!!!" << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : Please forgive me... I just want to get a stable job and get an excellent promotion..." << endl; sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : I just want to earn more money... please..." << endl;    sleep_for(::seconds(sleep_t));
        cout << "Do you want to forgive " << boss_addr->name << " ? (Yes/No)" << endl;
        while(true) {
            cin >> option;
            transform(option.begin(), option.end(), option.begin(), ::tolower);
            if (option != "yes" and option != "no") {       //Checking invalid input
                cout << "Invalid input! Please input Yes or No !! ";
            }
            else {
                break;
            }
        }
        if(option=="yes"){
            cout << boss_addr->name << " : Huh?! You really forgive me??" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : I just realize..we are the same type" << endl; sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Maybe in the future.. I will become someone like you.." << endl;   sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : So... good luck man.." << endl;    sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : You....Why..." << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Just keep in mind. You are not the slave of the boss. And I am going to  meet him now!" << endl;   sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " walks into the boss office" << endl;   sleep_for(::seconds(sleep_t));
            player_addr->good_end++;
        }
        else{
            cout << player_addr->name << " : I don't care! You spoil my career path!" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : People like you should go to hell!! So, I am going to send you to hell, Loser!!!" << endl; sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : NOOOO!!!!!" << endl; sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Ha! None will spoil my job now!" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : But I have to explain to my boss..." << endl;  sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " walks into the boss office room]" << endl;    sleep_for(::seconds(sleep_t));
        }
    }
}

void plot4_start(Role *player_addr, Role *boss_addr){
    cout << player_addr->name << " : Good morning! Boss" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : I am so sorry that I am late." << endl;    sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Who do you think you are talking with?" << endl; sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Huh?! " << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Aren't you guilty ??" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : Did I pay you for this??" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : You are my employee!! You should obey me!" << endl;  sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Huh?? I have apologized already! What did you want from me ???" << endl;   sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " : YOU ! ARE ! FIRED !" << endl;    sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : That's not fair!! You cannot control everything you want!!!" << endl;  sleep_for(::seconds(sleep_t));
    cout << boss_addr->name << " :  Oh you're right! But, actually, I can!" << endl;    sleep_for(::seconds(sleep_t));
    cout << "[" << player_addr->name << " is thrown to the wall" << endl;   sleep_for(::seconds(sleep_t));
    boss_addr->name="KingPin";
    cout << boss_addr->name << " : I am the employer of the company! None can esacape from my control!!" << endl;   sleep_for(::seconds(sleep_t));
    cout << player_addr->name << " : Oh God! Here we go again..." << endl;  sleep_for(::seconds(sleep_t));
    cout << "========================Battle 3========================" << endl;
    cout << "Boss : " << boss_addr->name << " HP: " << boss_addr->HP << " Skill: " << boss_addr->skill << endl;     sleep_for(::seconds(sleep_t));
}

void plot4_ending(Role *player_addr, Role *boss_addr, bool player_loss){
    if(player_loss){
        cout << boss_addr->name << " : Oh! Poor " << player_addr->name << "!" << endl;  sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : If you act smarter, and be a good slave, thing will not run out of control." << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : Unfortunately, your life is going to end right NOW!!!" << endl;  sleep_for(::seconds(sleep_t));
    }
    else{
        cout << boss_addr->name << " : Impossible!! How can you do this to me.." << endl;   sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : You are a monster!! None will act like you in the society !!!" << endl;  sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : I am the monster ??? HAHA! You are very funny.." << endl;  sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : We live in a society" << endl; sleep_for(::seconds(sleep_t));
        cout << player_addr->name << " : You get what you deserved" << endl;    sleep_for(::seconds(sleep_t));
        cout << boss_addr->name << " : Please!!! I will promote you !! I will give you a lot of money!!!" << endl;  sleep_for(::seconds(sleep_t));
        if(player_addr->good_end==3){
            cout << player_addr->name << " : Why don't you shut up!!" << endl;  sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " beats " << boss_addr->name << " again and again]" << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You want me to beat you hard??? " << endl; sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : None can beat me like this!! Come on!! Beat me now!!!" << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : God knows I want to beat til the end of my life but you don't get to destroy who I am!!" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You will go to prison after all you have done to us !!!" << endl;  sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : You will eventually understand this society reject you!! It beat you !!!" << endl; sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : I! BEAT! YOU!!" << endl;   sleep_for(::seconds(sleep_t));
            cout << "[" << player_addr->name << " leaves the room]" << endl;    sleep_for(::seconds(sleep_t));
        }
        else{
            cout << player_addr->name << " : OK! I believe in you" << endl; sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Thank for your forgiving" << endl;   sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Don't need to thank me... I just want to get a stable job with high salary.." << endl; sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : Yes!!! You are my slave, right?" << endl;    sleep_for(::seconds(sleep_t));
            cout << player_addr->name << " : Yes... I am the slave..." << endl; sleep_for(::seconds(sleep_t));
            cout << boss_addr->name << " : HAHAHAHA! This is my victory!!!" << endl;    sleep_for(::seconds(sleep_t));
        }
    }
}