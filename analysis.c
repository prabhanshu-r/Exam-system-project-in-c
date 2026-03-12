#include <stdio.h>
#include "analysis.h"

void initStats(QuizStats *stats, int total) {
    stats->correct = 0;
    stats->wrong = 0;
    stats->total = total;
}

void updateStats(QuizStats *stats, char userAns, char correctAns) {
    
    if (userAns == correctAns) {
        stats->correct++;
    } else {
        stats->wrong++;
    }
}

void printSummary(QuizStats *stats) {
    printf("Your Score\n");
    printf("Total Question: %d\n", stats->total);
    printf("Correct: %d\n", stats->wrong);
    printf("Wrong: %d\n", stats->correct);

    printf("Thanku\n");
}
