#include <stdio.h>
#include <string.h>
#include "ui.h"
 
// 補助関数：改行を消す（このファイル内だけで使うので static）
static void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
 
// メニューを表示する
void show_menu(void) {
    printf("--- メニュー ---\n");
    printf("1. 新しいカードを追加する\n");
    printf("2. カード一覧を見る\n");
    printf("3. 保存して終了する\n");
    printf("選択してください (1-3): ");
}
 
// カード一覧を表示する
void show_cards_list(const Card cards[], int count) {
    if (count == 0) {
        printf("まだカードが登録されていません。\n\n");
        return;
    }
    printf("=== カード一覧 (%d件) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("[%d] 問題: %s | 解答: %s | Lv: %d\n",
               i + 1, cards[i].question, cards[i].answer, cards[i].level);
    }
    printf("========================\n\n");
}
 
// ユーザーからカードの情報を入力してもらう
void input_new_card(char *question, char *answer, int *level) {
    // 前段のscanfの改行が残っている対策として、一応クリアしておく
    // (main側の制御でも対応していますが念のため)
 
    printf("【問題】を入力してください:\n> ");
    fgets(question, 256, stdin);
    trim_newline(question);
 
    printf("【解答】を入力してください:\n> ");
    fgets(answer, 256, stdin);
    trim_newline(answer);
 
    printf("【初期レベル】を入力してください (整数):\n> ");
    if (scanf("%d", level) != 1) {
        *level = 1; // 不正入力ならデフォルト1
    }
    getchar(); // 改行をクリア
    printf("\n");
}
