// ui.h
// ui.h
#ifndef UI_H
#define UI_H
 
#include "storage.h"
 
void show_menu(void);
void show_cards_list(const Card cards[], int count);
void input_new_card(char *question, char *answer, int *level);
 
#endif
 
 
