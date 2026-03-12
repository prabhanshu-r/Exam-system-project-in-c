#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"


void trimNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}


Question* loadQuestions(const char *filename, int *outnum) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening %s\n", filename);
        *outnum = 0;
        return NULL;
    }

    int size = 5;
    int num = 0;
    Question *questions = malloc(sizeof(Question) * size);
    if (!questions) {
        fclose(fp);
        *outnum = 0;
        return NULL;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n')
            continue;


        if (num == size) {
            size *= 2;
            Question *temp = realloc(questions, sizeof(Question) * size);
            if (!temp) {
                printf("Memory allocation failed\n");
                free(questions);
                fclose(fp);
                *outnum = num;
                return NULL;
            }
            questions = temp;
        }

        trimNewline(line);
        strcpy(questions[num].question, line);

        for (int i = 0; i < 4; i++) {
            if (!fgets(line, sizeof(line), fp)) break;
            trimNewline(line);
            strcpy(questions[num].options[i], line);
        }

        if (!fgets(line, sizeof(line), fp)) break;
        trimNewline(line);
        questions[num].correctOption = line[strlen(line) - 1];

        num++;
    }

    fclose(fp);
    *outnum = num;
    return questions;
}


