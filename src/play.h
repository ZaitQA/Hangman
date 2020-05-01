#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "messages.h"
#include "dessin.h"
#include "unistd.h"
#include "pull.h"

//char *chosen_word;
//int len_chosen;

int start_game();
int play_round(char *chosen_word, int len_chosen);
