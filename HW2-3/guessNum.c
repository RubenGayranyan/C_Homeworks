/*
    Write a C program that plays a simple "Guess the
    Number" game with the user. The program should
    generate a random number between 1 and 100
    (inclusive) and ask the user to guess that number. The
    program should provide feedback to the user after
    each guess, indicating whether the guess was too
    high, too low, or correct. The user should continue
    guessing until they guess the correct number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkAnswer(const short *n, const short *myNum);

void getNum(const short *myNum) {
    short userNum;
    scanf("%hd", &userNum);
    if (userNum > 100 || userNum < 0) {
        printf("Your number must be in range [0; 100]. Try another one:");
        getNum(myNum);
    }
    else {
        checkAnswer(&userNum, myNum);
    }
}

int main() {
    srand(time(NULL));
    const short mynum = rand() % 100;
    printf("Hi! Try to guess my number! (0-100): ");
    getNum(&mynum);
    return 0;
}

void checkAnswer(const short *n, const short *myNum) {
    if (*n == *myNum) {
        printf("Congratulations! I my number was %hd. You WIN!", *myNum);
    }
    else if (abs(*n - *myNum) < 10) {
        printf("You are close! Try again: ");
        getNum(myNum);
    }
    else if (*n > *myNum) {
        if (*n - *myNum < 20)
            printf("Try a bit lower number: ");
        else
            printf("Your number is too high. Try something lower: ");
        getNum(myNum);
    }
    else if (*n < *myNum) {
        if (*myNum - *n < 20)
            printf("Try a bit higher number: ");
        else
            printf("Your number is too low. Try something higher: ");
        getNum(myNum);
    }
    else {
        printf("MISS. Try again: ");
        getNum(myNum);
    }
}