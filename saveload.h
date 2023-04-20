//
// Created by MartinYu on 6/4/2023.
//

#ifndef COURSE_PROJECT_SAVELOAD_H
#define COURSE_PROJECT_SAVELOAD_H
#endif //COURSE_PROJECT_SAVELOAD_H

struct Role;
void save(Role *player_addr, int set);
Role load(Role *player_addr, int &set);