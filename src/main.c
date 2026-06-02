#include <stdio.h>
#include "storage.h"
#include "logic.h"
#include "ui.h"

int main(void)
{
    Card cards[MAX_CARDS];

    int count = load_cards("cards.txt", cards);

    int choice;

    while (1) {

        show_menu();
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            add_card(cards, &count);
            break;

        case 2:
            review_cards(cards, count);
            break;

        case 3:
            save_cards("cards.txt", cards, count);
            printf("保存しました。\n");
            return 0;

        default:
            printf("無効な入力です。\n");
        }
    }
}