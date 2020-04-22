#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"

int letter_tested[26] = {0};
//here you can find all the interactions with the player.

//do you want to play ?
int do_you_want()
{
    char *answer = calloc(25, sizeof(char));
    question_playing();
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 1)
    {
        no_play();
        return 1;
    }
    else
    {
        yes_play();
        return 0;
    }
}

//test if the given char is in the hidden word
int is_in(char *chosen_word, size_t len_w, char test)
{
    for (int i = 0; i < len_w; i++)
    {
        if (chosen_word[i] == test)
        {
            return 0;
        }
    }
    return 1;
}

int is_it(char *chosen_word, char *test)
{
    return strcmp(chosen_word, test);
}

//the player will give a character or a word suggestion to try to find the hidden word
int test_char_or_word(char *chosen_word)
{
    size_t len_w = sizeof(chosen_word);
    char *proposition = calloc(25, sizeof(char));

    suggest();
    scanf("%c", proposition);
    size_t len_p = sizeof(proposition);

    if (len_p == 8)
    {
        if (letter_tested[(int)proposition] == 1)
        {
            already_gave();
        }
        else
        {
            if (is_in(chosen_word, len_w, proposition[0]) == 0)
            {
                right_letter();
            }
            else
            {
                wrong_letter();
            }
            letter_tested[(int)proposition] = 1;
        }
    }

    else if (len_p == len_w)
    {
        if (is_it(chosen_word, proposition) == 0)
        {
            find_word();
        }
        else
        {
            wrong_word();
        } 
    }
    else
    {
        false_entry();
    }
    return 0;
}