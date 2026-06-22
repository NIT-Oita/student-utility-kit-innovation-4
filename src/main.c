/*#include <stdio.h>
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
}*/
#include <stdio.h>
#include "storage.h"
#include "ui.h"
 
// logic.c で作った関数を main で使えるようにプロトタイプ宣言
int add_card(Card cards[], int *count, const char *question, const char *answer, int level);
 
int main(void)
{
    Card my_cards[MAX_CARDS];
    int card_count = 0;
    const char *filename = "flashcards.txt";
 
    // 起動時にロード（ファイルロジック）
    card_count = load_cards(filename, my_cards);
    printf("現在、%d 件のカードが読み込まれました。\n\n", card_count);
 
    int choice;
    do {
        show_menu(); // UI呼び出し
       
        if (scanf("%d", &choice) != 1) {
            printf("数字を入力してください。\n\n");
            while (getchar() != '\n'); // バッファクリア
            continue;
        }
        getchar(); // 改行クリア
        printf("\n");
 
        if (choice == 1) {
            char q[256], a[256];
            int l;
           
            // UI関数でユーザーから入力を受け取る
            input_new_card(q, a, &l);
           
            // ロジック関数でデータを安全に配列に追加する
            if (add_card(my_cards, &card_count, q, a, l)) {
                printf("カードを追加しました！\n\n");
            } else {
                printf("エラー: これ以上カードを追加できません。\n\n");
            }
 
        } else if (choice == 2) {
            // UI関数で一覧表示
            show_cards_list(my_cards, card_count);
 
        } else if (choice == 3) {
            // 保存（ファイルロジック）
            printf("ファイルに保存しています...\n");
            if (save_cards(filename, my_cards, card_count)) {
                printf("保存が完了しました。アプリを終了します。\n");
            } else {
                printf("エラー: 保存に失敗しました。\n");
            }
        } else {
            printf("1~3の数字を選んでください。\n\n");
        }
 
    } while (choice != 3);
 
    return 0;
}