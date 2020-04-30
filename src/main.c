#include "random.h"
#include "play.h"
#include "messages.h"
#include <string.h>
#include <unistd.h>

int main(void){
    system("clear");
    start_game();
    char *chosen_word = calloc(30, sizeof(char));
    word_from_file(randomizer(), chosen_word);
    int len_chosen = strlen(chosen_word);

    //launch the game
    int is_ended = 0;
    while (!is_ended){
        is_ended = play_round(chosen_word, len_chosen);
        if (!is_ended)
            system("clear");
    }
    return 0;
}
