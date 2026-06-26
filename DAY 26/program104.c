#include <stdio.h>
#include <ctype.h>

typedef struct {
    char question[256];
    char options[4][50];
    char correct_option;
} QuizQuestion;

int main() {
    QuizQuestion quiz[5] = {
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. C", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the size of an int data type in C (usually on 32/64-bit systems)?",
            {"A. 2 bytes", "B. 4 bytes", "C. 8 bytes", "D. 1 byte"},
            'B'
        },
        {
            "Which keyword is used to prevent a variable from being modified in C?",
            {"A. static", "B. volatile", "C. const", "D. register"},
            'C'
        },
        {
            "What is the correct file extension for a standard C source file?",
            {"A. .cpp", "B. .h", "C. .exe", "D. .c"},
            'D'
        },
        {
            "Which function is used to allocate memory dynamically in C?",
            {"A. malloc()", "B. alloc()", "C. new", "D. create()"},
            'A'
        }
    };

    int total_questions = 5;
    int score = 0;
    char user_answer;

    printf("=========================================\n");
    printf("        WELCOME TO THE C QUIZ GAME       \n");
    printf("=========================================\n\n");

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Your Answer (A, B, C, or D): ");
        scanf(" %c", &user_answer);
        user_answer = toupper(user_answer);

        if (user_answer == quiz[i].correct_option) {
            printf("\nCorrect Answer! Clear progress.\n\n");
            score++;
        } else {
            printf("\nWrong Answer! The correct answer was %c.\n\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n");
    }

    printf("\n=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    
    if (score == total_questions) {
        printf("Perfect score! You are a C Expert.\n");
    } else if (score >= total_questions / 2) {
        printf("Good job! Passable knowledge.\n");
    } else {
        printf("Keep practicing. Review your C basics!\n");
    }
    printf("=========================================\n");

    return 0;
}
