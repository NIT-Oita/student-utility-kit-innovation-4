/*#include "logic.h"
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
}*/
#include "storage.h"
 
// カードを新しく追加する
// 成功したら1、上限に達していたら0を返す
int add_card(Card cards[], int *count, const char *question, const char *answer, int level) {
    if (*count >= MAX_CARDS) {
        return 0; // 追加失敗
    }
 
    // 安全にコピーするために、ui側から直接構造体に書き込んでもらっても良いですが、
    // 関数を挟むことでデータのバリデーション（検証）がここで行えます。
    Card new_card;
   
    // 文字列のコピー（ui側でサイズ制限されている前提）
    int i;
    for (i = 0; question[i] != '\0' && i < 255; i++) {
        new_card.question[i] = question[i];
    }
    new_card.question[i] = '\0';
 
    for (i = 0; answer[i] != '\0' && i < 255; i++) {
        new_card.answer[i] = answer[i];
    }
    new_card.answer[i] = '\0';
 
    new_card.level = level;
 
    // 配列に格納
    cards[*count] = new_card;
    (*count)++; // 件数を増やす
 
    return 1; // 追加成功
}