#include "random.h"
#include "play.h"
#include "messages.h"
#include <string.h>

int main(void){
    start_game();
    chosen_word = "salut";//word_from_file(randomizer());
    len_chosen = 5;//strlen(chosen_word);
    int len_chosen = strlen(chosen_word);

    //launch the game
    int is_ended = 0;
    while (!is_ended){
        is_ended = play_round();
    }
    return 0;
}
