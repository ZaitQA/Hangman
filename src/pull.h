#pragma once
#include <stdio.h>
#include <curl/curl.h>
#include <err.h>
#include <stdlib.h>
#include <string.h>

struct string{
    char *ptr;
    size_t len;
};

void init_string(struct string *s);
size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, struct string *s);
char *get_web_page(char *url);
