#include "logic.h"
#include <stdio.h>
#include <string.h>

void add_card(Card cards[], int *count)
{
    if (*count >= MAX_CARDS) {
        printf("カードがいっぱいです。\n");
        return;
    }

    printf("英単語: ");
    scanf("%255s", cards[*count].question);

    printf("意味: ");
    scanf("%255s", cards[*count].answer);

    cards[*count].level = 1;

    (*count)++;
}

void review_cards(Card cards[], int count)
{
    char input[256];

    for (int i = 0; i < count; i++) {

        printf("\n%s\n", cards[i].question);
        printf("答え: ");
        scanf("%255s", input);

        if (strcmp(input, cards[i].answer) == 0) {
            printf("正解！\n");
            cards[i].level++;
        } else {
            printf("不正解: %s\n", cards[i].answer);
        }
    }
}