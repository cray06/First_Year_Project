/*
** EPITECH PROJECT, 2024
** get_score.c
** File description:
** get_score.c
*/

#include "include/my.h"

void get_score_text(int score, char *scoreText)
{
    int temp = 0;
    int digits = 0;

    my_strcpy(scoreText, "Score: ");
    if (score == 0) {
        scoreText[7] = '0';
        scoreText[8] = '\0';
    } else {
        temp = score;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        temp = score;
        scoreText[7 + digits] = '\0';
        for (int i = digits - 1; i >= 0; i--) {
            scoreText[7 + i] = '0' + (temp % 10);
            temp /= 10;
        }
    }
}
