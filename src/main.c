#include "random.h"
#include "play.h"
#include "messages.h"
#include <string.h>
#include <unistd.h>

int main(void){
    system("clear");
    int is_playing = start_game();
    if (is_playing)
        return 0;
    sleep(1);
    system("clear");
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
