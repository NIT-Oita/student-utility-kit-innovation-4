#ifndef STORAGE_H
#define STORAGE_H

#define MAX_CARDS 100
#define MAX_TEXT_LEN 256

/*
 * 保存形式:
 * question|answer|level
 *
 * 例:
 * What is C?|Programming language|3
 */

typedef struct {
    char question[MAX_TEXT_LEN];
    char answer[MAX_TEXT_LEN];
    int level;
} Card;

/*
 * 保存成功: 1
 * 保存失敗: 0
 */
int save_cards(const char *filename,
               Card cards[],
               int count);

/*
 * 読み込んだカード数を返す
 * 不正行は警告を出してスキップする
 */
int load_cards(const char *filename,
               Card cards[]);

#endif