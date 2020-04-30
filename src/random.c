#include "random.h"
#include <string.h>

int randomizer(void){
    srand(time(NULL));
    return (rand() % (370098));
}

char *word_from_file(int numb, char *chosen_word){
    FILE *file = fopen("src/words_alpha.txt", "r");

    //See if the file could be opened
    if (!file){
        err(1, "The database file can not be opened");
    }
    //Go through the file and find the specified line
    int count = 0;
    char line[50];
    while (fgets(line, sizeof line, file)){
        if (numb == count){
            strcpy(chosen_word, line);
            if (chosen_word[strlen(chosen_word) - 1] == '\n')
                chosen_word[strlen(chosen_word) - 1] = '\0';
            fclose(file);
            return chosen_word;
        }
        count++;
    }

    //The specified line does not exist
    fclose(file);
    err(1, "Word has not be found");
}
