#include "play.h"


//here you can find all the interactions with the player.
//all letters the player will have tested
int letter_tested[26] = {0};
short tries = 0;

//do you want to play ?
int start_game(){

    //message to know if the user wants to play
    question_playing();
    char answer[50];
    fgets(answer, 50, stdin);
    size_t len = strlen(answer);
    for (size_t i = 0; i < len; i++) {
        if (answer[i] == '\n')
            answer[i] = '\0';
    }
    if (strcmp(answer, "yes") != 0){
        return no_play();
    } else {
        return yes_play();
    }
}

//test if the given char is in the hidden word
int is_correct(char *chosen_word, long len_w, char test){
    for (int i = 0; i < len_w; i++){
        if (chosen_word[i] == test){
            return 0;
        }
    }
    return 1;
}

//test if the word gave by the player is the hidden word
int is_found(char *chosen_word, char *test){
    return strcmp(chosen_word, test);
}

//calcul real size of the input
int size_of(char *input){
    int i = 0;
    while (input[i]){
        i++;
    }
    return i;
}

int verify_win(char *chosen_word, int len_chosen){
    for (int i = 1; i < len_chosen; i++){
        int pos = chosen_word[i] - 97;
        if (!letter_tested[pos])
            return 0;
    }
    return 1;
}

int current_state(char *chosen_word, int len_chosen){
    printf("\n   ");
    for (int i = 0; i < len_chosen; i++){
        int pos = chosen_word[i] - 97;
        if (i == 0)
            printf("\033[01;32m%c\033[0m", chosen_word[i]);
        else if (!letter_tested[pos])
            printf("\033[01;33m-\033[0m");
        else
            printf("\033[01;32m%c\033[0m", chosen_word[i]);
    }
    printf("\n\n\n");
    return 1;
}


void drawing(){
    switch(tries){
        case 0:
            zero_step();
            break;
        case 1:
            first_step();
            break;
        case 2:
            two_step();
            break;
        case 3:
            three_step();
            break;
        case 4:
            four_step();
            break;
        case 5:
            five_step();
            break;
        case 6:
            six_step();
            break;
        case 7:
            seven_step();
            break;
        case 8:
            eigth_step();
            break;
        case 9:
            nine_step();
            break;
    }
}

//the player will give a character or a word suggestion to try to find the hidden word
int play_round(char *chosen_word, int len_chosen)
{
    drawing();
    current_state(chosen_word, len_chosen);
    char *proposition = calloc(30, sizeof(char));
    suggest();
    fgets(proposition, 50, stdin);

    int len_p = size_of(proposition);
    for (int i = 0; i < len_p; i++){
        if (proposition[i] == '\n'){
            proposition[i] = '\0';
            len_p--;
        }
    }
    if (len_p == 1){
        int pos = proposition[0] - 97;
        if (letter_tested[pos]){
            already_gave();
            sleep(1);
        }else{
            if (!is_correct(chosen_word, len_chosen, proposition[0])){
                right_letter();
                sleep(1);
            }else{
                wrong_letter();
                sleep(1);
                tries++;
            }
            letter_tested[pos] = 1;
        }
    }else if (len_p == len_chosen){
        if (!is_found(chosen_word, proposition)){
            char url[100] = "https://www.collinsdictionary.com/dictionary/english/";
            strcat(url, chosen_word);
            return game_won(get_web_page(url));
        }else{
            wrong_word();
            sleep(1);
            tries += 3;
        }
    }else{
        false_entry();
        sleep(1);
        tries += 3;
    }
    if (tries >= 9){
        system("clear");
        nine_step();
        current_state(chosen_word, len_chosen);
        char url[100] = "https://www.collinsdictionary.com/dictionary/english/";
        strcat(url, chosen_word);
        return game_lost(chosen_word, get_web_page(url));
    }
    if (verify_win(chosen_word, len_chosen)){
        system("clear");
        drawing();
        current_state(chosen_word, len_chosen);
        char url[100] = "https://www.collinsdictionary.com/dictionary/english/";
        strcat(url, chosen_word);
        return game_won(get_web_page(url));
    }
    return 0;
}
