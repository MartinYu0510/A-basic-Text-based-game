//
// Created by MartinYu on 9/4/2023.
//

#ifndef COURSE_PROJECT_GAME_PLOT_H
#define COURSE_PROJECT_GAME_PLOT_H

#endif //COURSE_PROJECT_GAME_PLOT_H
struct Role;
void plot1_start(Role *player_addr, Role *boss_addr);
void plot2_start(Role *player_addr, Role *boss_addr);
void plot3_start(Role *player_addr, Role *boss_addr);
void plot4_start(Role *player_addr, Role *boss_addr);
void plot1_ending(Role *player_addr, Role *boss_addr, int player_loss);
void plot2_ending(Role *player_addr, Role *boss_addr, int player_loss);
void plot3_ending(Role *player_addr, Role *boss_addr, int player_loss);
void plot4_ending(Role *player_addr, Role *boss_addr, int player_loss);

