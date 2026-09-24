#include "../include/myfilefunctions.h"
#include <string.h>
#include <stdlib.h>

int wordCount(FILE* file, int* lines, int* words, int* chars)
{
    int c;
    int inWord = 0;

    if (file == NULL)
    {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    while ((c = fgetc(file)) != EOF)
    {
        (*chars)++;

        if (c == '\n')
        {
            (*lines)++;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            (*words)++;
            inWord = 1;
        }
    }

    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches)
{
    char line[1000];
    int count = 0;

    if (fp == NULL || search_str == NULL || matches == NULL)
    {
        return -1;
    }

    *matches = NULL;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, search_str) != NULL)
        {
            char** temp;

            temp = realloc(*matches, (count + 1) * sizeof(char*));

            if (temp == NULL)
            {
                return -1;
            }

            *matches = temp;

            (*matches)[count] = malloc(strlen(line) + 1);

            if ((*matches)[count] == NULL)
            {
                return -1;
            }

            strcpy((*matches)[count], line);

            count++;
        }
    }

    return count;
}
