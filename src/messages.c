#include <stdio.h>
#include "messages.h"
#include "play.h"

//here are all the differente messages that you can find during the game
//all the interactions, winning or loosing messages, ...

void question_playing(){
    printf("Do you want to play Hangman game?(yes/no)\n");
}

int no_play(){
    printf("Ok, bye then!\n");
    return 1;
}

int yes_play(){
    printf("Ok let's start the game!\n");
    return 0;
}

void suggest(){
    printf("Which letter do you want to try? Or perhaps you have the whole word?\n");
}

void already_gave(){
    printf("You already tried this letter.\n");
}

void right_letter(){
    printf("Well done! You gave a letter which is in the hidden word!\n");
}

void wrong_letter(){
    printf("WRONG! You miss it this time.\n");    //maybe add the number of try it remains ??
}

int game_won(){
    printf("Congratulations! You find the hidden word!\n");
    return 1;
}

void wrong_word(){
    printf("Oups! That's not the hidden word! You fail!\n");
}

void false_entry(){
    printf("what's that?!\n");
}

int game_lost(){
    printf("You lost, sorry!\nThe correct word was %s\n", chosen_word);
    return 1;
}
