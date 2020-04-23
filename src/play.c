#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"

//here you can find all the interactions with the player.

int letter_tested[26] = {0};      //all letters the player will have tested
short tries = 0;

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
int is_in(char *chosen_word, long len_w, char test)
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

//test if the word gave by the player is the hidden word
int is_it(char *chosen_word, char *test)
{
    return strcmp(chosen_word, test);
}

//calcul real size of the input
int size_of(char *input)
{
    int i = 0;
    while (input[i])
    {
        i++;
    }
    return i;
}

//the player will give a character or a word suggestion to try to find the hidden word
void start_the_game(char *chosen_word)
{
    printf("%s\n", chosen_word);
    char proposition[26];

    suggest();
    scanf("%s", proposition);
    int len_p = size_of(proposition);
    int len_input = size_of(chosen_word);
    printf("%d\n", len_input);
    printf("%s\n", chosen_word);

    if (len_p == 1)
    {
        int pos = proposition[0] - 97;
        if (letter_tested[pos] == 1)
        {
            already_gave();
            start_the_game(chosen_word);
        }
        else
        {
            if (is_in(chosen_word, len_input, proposition[0]) == 0)
            {
                right_letter();
                start_the_game(chosen_word);
            }
            else
            {
                wrong_letter();
                tries++;
                start_the_game(chosen_word);
            }
            letter_tested[pos] = 1;
        }
    }

    else if (len_p == len_input)
    {
        if (is_it(chosen_word, proposition) == 0)
        {
            find_word();
        }
        else
        {
            wrong_word();
            tries += 3;
            start_the_game(chosen_word);
        } 
    }

    else
    {
        false_entry();
        tries += 3;
        start_the_game(chosen_word);
    }
}