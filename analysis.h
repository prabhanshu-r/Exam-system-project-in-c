#ifndef ANALYSIS_H
#define ANALYSIS_H

typedef struct {
    int correct;
    int wrong;
    int total;
} QuizStats;

void initStats(QuizStats *stats, int total);
void updateStats(QuizStats *stats, char userAns, char correctAns);
void printSummary(QuizStats *stats);

#endif
