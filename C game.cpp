#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0, maxAttempts, level;
    char playAgain;

    srand(time(NULL));

    do {
        printf("\n=== NUMBER GUESSING GAME ===\n");
        printf("Choose Difficulty Level:\n");
        printf("1. Easy   (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard   (1-200, 5 attempts)\n");
        printf("Enter your choice: ");
        scanf("%d", &level);

        if(level == 1) {
            number = rand() % 50 + 1;
            maxAttempts = 10;
        } 
        else if(level == 2) {
            number = rand() % 100 + 1;
            maxAttempts = 7;
        }
        else {
            number = rand() % 200 + 1;
            maxAttempts = 5;
        }

        attempts = 0;
        printf("\nGame Started! Try to guess the number.\n");

        while(attempts < maxAttempts) {
            printf("Attempt %d/%d - Enter your guess: ", attempts + 1, maxAttempts);
            scanf("%d", &guess);
            attempts++;

            if(guess == number) {
                printf("?? Correct! You guessed the number in %d attempts!\n", attempts);
                break;
            } 
            else if(guess > number) {
                printf("Too high! Try again.\n");
            } 
            else {
                printf("Too low! Try again.\n");
            }
        }

        if(attempts == maxAttempts && guess != number) {
            printf("\n? You lost! The correct number was %d.\n", number);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! Goodbye.\n");
    return 0;
}
