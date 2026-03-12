#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include "timer.h"

char askWithTimer(Question *q, int timeLimit) {

    printf("\n%s\n", q->question);
    printf("%s\n", q->options[0]);
    printf("%s\n", q->options[1]);
    printf("%s\n", q->options[2]);
    printf("%s\n", q->options[3]);
    printf("You have %d seconds. Enter A, B, C, or D:\n", timeLimit);
    int remaining = timeLimit;

    while (remaining > 0) {

        if (_kbhit()) {
            char input = toupper(getch());

            printf("%c\n", input);

            // if (input == 'A' || input == 'B' || input == 'C' || input == 'D')
            //     return input;
            return 'X';
        }

        Sleep(1000);
        
        remaining--;
    }

    printf("\nYour time is up\n");
    return 'X';
}
