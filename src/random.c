#include "random.h"

int randomizer(void){
    return (rand() % (370098));
}

char *word_from_file(int numb){
    FILE *file = fopen("words_alpha.txt", "r");
    if (!file){
        err(1, "The database file can not be opened");
    }
    int count = 0;
    char line[50];
    char *chosen_word = calloc(30, sizeof(char));
    while (fgets(line, sizeof line, file)){
        if (numb == count){
            chosen_word = line;
            fclose(file);
            return chosen_word;
        }
        count++;
    }
    fclose(file);
    err(1, "Word has not be found");
}
