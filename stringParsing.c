#include <string.h>


// Function to check if a string contains only white-spaces ("","\n","\r",etc)
int is_empty(const char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s)){
        return 0;
    }
    s++;
  }
  return 1;
}


// Function to trim white-spaces arround a string
char *trim_space(char *in)
{
    char *out = NULL;
    int len;
    if (in) {
        len = strlen(in);
        while(len && isspace(in[len - 1])) --len;
        while(len && *in && isspace(*in)) ++in, --len;
        if (len) {
            out = strndup(in, len);
        }
    }
    return out;
}


// Function to split a string and store each substring in array. Returns array size
int split(char* str, char* delim, char** args){
    int i = 0;
    char* token = strtok(str, delim);
    while (token != NULL) {
        // printf("%s", token);
        if (is_empty(token)){
            break;
        }
        args[i++] = trim_space(token);
        token = strtok(NULL, delim);   
    }
    return i;
}
