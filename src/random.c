#include "random.h"

int randomizer(void){
    srand(time(NULL));
    return (rand() % (370098));
}

char *word_from_file(int numb){
    FILE *file = fopen("src/words_alpha.txt", "r");

    //See if the file could be opened
    if (!file){
        err(1, "The database file can not be opened");
    }

    //Go through the file and find the specified line
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

    //The specified line does not exist
    fclose(file);
    err(1, "Word has not be found");
}
