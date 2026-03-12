#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quiz.h"
#include "random.h"
#include "timer.h"
#include "analysis.h"

int main() {
    int totalQuestion;
    Question *questions = loadQuestions("question.txt", &totalQuestion);

    if (!questions || totalQuestion == 0) {
        printf("No questions loaded. Exiting.\n");
        return 1;
    }
    int totalTime = 60;

    initRandom();

    int *used = calloc(totalQuestion, sizeof(int));

    if (!used) {
        printf("Memory allocation failed.\n");
        free(questions);

        return 1;
    }

    QuizStats stats;

    initStats(&stats, totalQuestion);

    clock_t startTime = clock();

    printf("\n");
    printf("\n");

    printf("You will be given %d seconds for the test. All the best!\n", totalTime);

    for (int i = 0; i < totalQuestion; i++) {

        double elapsed = (double)(clock() - startTime) / CLOCKS_PER_SEC;

        int timeLeft = totalTime - (int)elapsed;

        if (timeLeft <= 0) {
            printf("\nTime's up for the entire quiz!\n");
            break;
        }

        int index = getRandomIndex(totalQuestion, used);

        if (index == -1) {break;}

        used[index] = 1;

        char answer = askWithTimer(&questions[index], timeLeft);

        updateStats(&stats, answer, questions[index].correctOption);
    
    }
    printSummary(&stats);

    free(used);

    free(questions);

    return 0;
}
