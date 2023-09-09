#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char s[100], word[50][30];
int number_appears(char word[30], char document[50])
{
    int count = 0;
    char *p = strstr(document, word);
    while(p != NULL)
    {
        count++;
        int tmp = p - document;
        p = strstr(document + tmp + 1, word);
    }
    return count;
}
int main() {
    gets(s);
    int start = 0, end = -1, tmp = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(isalpha(s[i])) 
        {
            tmp = i;
            break;
        }
    }
    for(int i = tmp; i < strlen(s); i++)
    {
        if(isalpha(s[i]))
        {
            word[start][++end] = s[i];
        }
        else if(isalpha(s[i]) == 0 && isalpha(s[i + 1]))
        {
            if(i < strlen(s) - 1)
            {
                start++;
                end = -1;
            }
        }
    }
    return 0;
}
