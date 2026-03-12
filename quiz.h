#ifndef QUIZ_H
#define QUIZ_H

typedef struct {
    char question[512];
    char options[4][256];
    char correctOption;
} Question;



Question* loadQuestions(const char *filename, int *outcount);
#endif
