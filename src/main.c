#include "random.h"
#include "play.h"
#include "messages.h"
#include <string.h>
#include <unistd.h>

int main(void){
    system("clear");
    start_game();
    chosen_word = "salut";//word_from_file(randomizer());
    len_chosen = 5;//strlen(chosen_word);

    //launch the game
    int is_ended = 0;
    while (!is_ended){
        is_ended = play_round();
        if (!is_ended)
            system("clear");
    }
    return 0;
}
