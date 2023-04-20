#ifndef COURSE_PROJECT_PLAYER_STATUS_H
#define COURSE_PROJECT_PLAYER_STATUS_H
#include <string>
#endif //COURSE_PROJECT_PLAYER_STATUS_H

struct Role {
    std::string name;
    std::string skill;
    int HP = 0, Attack = 0, SP = 0;
    bool defense = false;
    int good_end = 0;
    bool half_hp = false;
    int boss_skill_charge = 0;
};
void input_status();
void show_status();
Role player_status_main();
Role boss_status_init(int set);
int random_event(std::string event);
bool check_winloss(int player_hp, int boss_hp, bool& player_loss);
void boss_skill1(Role* player_addr, Role* boss_addr);
void boss_skill2(Role* player_addr, Role* boss_addr);
void boss_skill3(Role* player_addr, Role* boss_addr);
void boss_skill4(Role* player_addr, Role* boss_addr);
bool player_skill(Role* player_addr, Role* boss_addr, std::string skill);
