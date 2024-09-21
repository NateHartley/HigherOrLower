#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess1;
    int guess2;
    time_t t;
    char highlow;
    char yn;

    while(1){
        int score = 0;
        while(1){
            // chooses a new random number everytime the program runs
            srand((unsigned) time(&t));

            guess1 = rand() % 10;
            printf("------------------------------------------------------------------------\n");
            printf("The computer has picked the number %d\n", guess1);

            guess2 = rand() % 10;

            printf("Is the computer's second number going to be higher (h) or lower (l) than the first? ");
            // there MUST be a space before %c otherwise the program will loop back to the start from here
            scanf(" %c", &highlow); // & stores the input in the variable

            if (guess1 > guess2 && highlow == 'l'){
                printf("Correct! The second number is %d", guess2);
                printf("\n");
                score = score + 100;
                printf("Your score = %d", score);
                printf("\n");
            } else if (guess1 < guess2 && highlow == 'h'){
                printf("Correct! The second number is %d", guess2);
                printf("\n");
                score = score + 100;
                printf("Your score = %d", score);
                printf("\n");
            } else if (guess1 > guess2 && highlow == 'h'){
                printf("Wrong! The second number is %d", guess2);
                printf("\n");
                printf("You finished the game with %d points", score);
                printf("\n");
                break;
            } else if (guess1 < guess2 && highlow == 'l'){
                printf("Wrong! The second number is %d", guess2);
                printf("\n");
                printf("You finished the game with %d points", score);
                printf("\n");
                break;
            } else if (guess1 == guess2) {
                printf("They are the same! The second number is %d", guess2);
                printf("\n");
            }
        }
        printf("Play again? (y/n)");
        scanf(" %c", &yn);
        if (yn == 'n'){
            break;
        }
    }
    return 0;
}