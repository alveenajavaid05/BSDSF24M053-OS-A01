#include <stdio.h>
#include <stdlib.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    char source[] = "Hello";
    char destination[100];

    printf("--- Testing String Functions ---\n");

    printf("Length of source: %d\n", mystrlen(source));

    mystrcpy(destination, source);
    printf("After mystrcpy: %s\n", destination);

    mystrncpy(destination, "Operating Systems", 10);
    destination[10] = '\0';
    printf("After mystrncpy: %s\n", destination);

    mystrcpy(destination, "Hello ");
    mystrcat(destination, "World");
    printf("After mystrcat: %s\n", destination);

    printf("\n--- Testing File Functions ---\n");

    FILE* file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines;
    int words;
    int chars;

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }

    fclose(file);

    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    char** matches;
    int matchCount;

    matchCount = mygrep(file, "OS", &matches);

    printf("Matches found: %d\n", matchCount);

    if (matchCount > 0)
    {
        int i = 0;

        while (i < matchCount)
        {
            printf("%s", matches[i]);
            free(matches[i]);
            i++;
        }

        free(matches);
    }

    fclose(file);

    return 0;
}
