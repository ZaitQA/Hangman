#include "pull.h"


void init_string(struct string *s){
    s->len = 0;
    s->ptr = malloc(s->len + 1);
    if (s->ptr == NULL)
        err(1, "string problem");
    s->ptr[0] = '\0';
}

size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, struct string *s){
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL)
        err(1, "Callback problem");
    memcpy(s->ptr + s->len, buffer, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;
    return size * nmemb;
}

char *get_web_page(char *url){
    CURL *curl = NULL;
    curl = curl_easy_init();
    struct string s;
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_func);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

    curl_easy_perform(curl);
    char *buffer = calloc(1000, sizeof(char));
    char *divdef = strstr(s.ptr, "<div class=\"def\">");
    if (!divdef){
        buffer = "Definition not found on www.collinsdictionary.com";
        return buffer;
    }
    size_t ind = 0;
    size_t size = strlen(divdef);
    for (size_t i = 0; i < size; i++){
        if (divdef[i] == '<' && divdef[i + 1] == '/' &&
                divdef[i + 2] == 'd' && divdef[i + 3] == 'i' &&
                divdef[i + 4] == 'v' && divdef[i + 5] == '>')
            break;
        else if (divdef[i] == '<'){
            while (divdef[i] != '>'){
                i++;
            }
        }
        else if (divdef[i] != '\n'){
            buffer[ind] = divdef[i];
            ind++;
        }
    }
    curl_easy_cleanup(curl);
    return buffer;
}

