#include <stdio.h>
#include "messages.h"

//here are all the differente messages that you can find during the game
//all the interactions, winning or loosing messages, ...

void question_playing(){
    printf("Do you want to play Hangman game?(yes/no)\n");
}

void no_play(){
    printf("Ok, bye then!\n");
}

void yes_play(){
    printf("Ok let's start the game!\n");
}

void suggest(){
    printf("Which letter do you want to try? Or perhaps you have the whole word?\n");
}

void already_gave()
{
    printf("You already tried this letter.\n");
}

void right_letter()
{
    printf("Well done! You gave a letter which is in the hidden word!\n");
}

void wrong_letter()
{
    printf("WRONG! You miss it this time.\n");    //maybe add the number of try it remains ??
}

void find_word()
{
    printf("Wongratulations! You find the hidden word!\n");
}

void wrong_word()
{
    printf("Oups! That's not the hidden word! You fail!\n");
}

void false_entry()
{
    printf("what's that?!\n");
}