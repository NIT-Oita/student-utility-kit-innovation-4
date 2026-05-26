#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "storage.h"

int load_cards(const char *filename, Card cards[]) {

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Failed to open file");
        return 0;
    }

    char line[512];
    int count = 0;

    // ヘッダー読み飛ばし
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp)) {

        // 改行削除
        line[strcspn(line, "\n")] = '\0';

        char *token;

        token = strtok(line, ",");

        if (token != NULL) {
            strcpy(cards[count].question, token);
        }

        token = strtok(NULL, ",");

        if (token != NULL) {
            strcpy(cards[count].answer, token);
        }

        token = strtok(NULL, ",");

        if (token != NULL) {
            cards[count].level = atoi(token);
        }

        count++;

        if (count >= MAX_CARDS) {
            break;
        }
    }

    fclose(fp);

    return count;
}

int save_cards(const char *filename, Card cards[], int count) {

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Failed to save file");
        return 0;
    }

    fprintf(fp, "question,answer,level\n");

    for (int i = 0; i < count; i++) {

        fprintf(fp,
                "%s,%s,%d\n",
                cards[i].question,
                cards[i].answer,
                cards[i].level);
    }
    fclose(fp);
    
    return 1;
}