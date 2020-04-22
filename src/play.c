#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pre-game : do you want to play ?
int do_you_want()
{
    char *answer = calloc(25, sizeof(char));
    printf("Do you want to play Hangman game?(yes/no)\n");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 1)
    {
        printf("Ok, bye then!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}