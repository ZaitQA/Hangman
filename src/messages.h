#pragma once
#include "play.h"

void question_playing();
int no_play();
int yes_play();
void suggest();
void already_gave();
void right_letter();
void wrong_letter();
int game_won(char *definition);
void wrong_word();
void false_entry();
int game_lost(char *chosen_word, char *definition);
