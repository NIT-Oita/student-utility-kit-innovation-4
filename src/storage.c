#include "storage.h"
#include <stdio.h>
#include <string.h>

#define LINE_BUF 1024

int save_cards(const char *filename, Card cards[], int count)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen");
        return 0;
    }

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
    if (!fp) {
        perror("fopen");
        return 0;
    }

    char line[LINE_BUF];
    int count = 0;
    int line_no = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {

        line_no++;

        /* 長すぎる行の検出 */
        if (strchr(line, '\n') == NULL) {
            fprintf(stderr,
                    "Warning: line %d is too long. Skipped.\n",
                    line_no);

            int ch;
            while ((ch = fgetc(fp)) != '\n' && ch != EOF)
                ;

            continue;
        }

        char question[256];
        char answer[256];
        int level;

        int n = sscanf(line,
                       "%255[^|]|%255[^|]|%d",
                       question,
                       answer,
                       &level);

        if (n != 3) {
            fprintf(stderr,
                    "Warning: invalid format at line %d\n",
                    line_no);
            continue;
        }

        /* level の妥当性チェック */
        if (level < 0 || level > 5) {
            fprintf(stderr,
                    "Warning: invalid level at line %d\n",
                    line_no);
            continue;
        }

        if (count >= MAX_CARDS) {
            fprintf(stderr,
                    "Warning: MAX_CARDS exceeded\n");
            break;
        }

        strcpy(cards[count].question, question);
        strcpy(cards[count].answer, answer);
        cards[count].level = level;

        count++;
    }

    fclose(fp);
    return count;
}