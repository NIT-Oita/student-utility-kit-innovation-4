#ifndef STORAGE_H
#define STORAGE_H

#define MAX_CARDS 1000

typedef struct {
    char question[256];
    char answer[256];
    int level;
} Card;

int load_cards(const char *filename, Card cards[]);
int save_cards(const char *filename, Card cards[], int count);

#endif