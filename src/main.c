#include "random.h"

int main(void){
    int numb = randomizer();
    printf("number : %d\n", numb);
    char *chosen_word = word_from_file(numb);
    printf("word : %s", chosen_word);
    return 0;
}
