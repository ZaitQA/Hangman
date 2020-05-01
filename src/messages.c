#include "messages.h"

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
    printf("\033[01;33mYou already tried this letter.\n\033[0m");
}

void right_letter(){
    printf("\033[01;32mWELL DONE! You gave a letter which is in the hidden word!\n\033[0m");
}

void wrong_letter(){
    printf("\033[01;31mWRONG! You miss it this time.\n\033[0m");
}

int game_won(char *definition){
    printf("\033[01;32mCongratulations! You find the hidden word!\n\033[0m");
    printf("To improve your knowledges, I found the definition for you:\n");
    printf("%s\n", definition);

    return 1;
}

void wrong_word(){
    printf("\033[01;31mOups! That's not the hidden word! You fail!\n\033[0m");
}

void false_entry(){
    printf("\033[01;31mwhat's that?!\n\033[0m");
}

char *upper_word(char *word){
    size_t len = strlen(word);
    for (size_t i = 0; i < len; i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}

int game_lost(char *chosen_word, char *definition){
    printf("\033[01;31mYou lost, sorry! The word was %s\n\033[0m", upper_word(chosen_word));
    printf("To improve your knowledges, I found the definition for you:\n");
    printf("\033[01;36m%s\n\033[0m", definition);
    return 1;
}
