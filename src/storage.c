// storage.c
#include "storage.h"
#include <stdio.h>

int save_cards(const char *filename, Card cards[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) return 0;

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s|%s|%d\n",
                cards[i].question,
                cards[i].answer,
                cards[i].level);
    }

    fclose(fp);
    return 1;
}

int load_cards(const char *filename, Card cards[])
{
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    int count = 0;

    while (count < MAX_CARDS &&
           fscanf(fp, "%255[^|]|%255[^|]|%d\n",
                  cards[count].question,
                  cards[count].answer,
                  &cards[count].level) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}