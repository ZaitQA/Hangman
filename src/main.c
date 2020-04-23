#include "random.h"
#include "play.h"
#include "messages.h"

int main(void){
    do_you_want();
    int numb = randomizer();
    printf("number : %d\n", numb);
    char *chosen_word = word_from_file(numb);
    printf("word : %s", chosen_word);
    start_the_game(chosen_word);
    return 0;
}
