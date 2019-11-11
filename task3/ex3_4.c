#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
char *replaceWord(const char *s, const char *oldW, 
                                 const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
            i += oldWlen - 1; 
        } 
    } 
  
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

int main(int argc, char *argv[])
{
    FILE *fp;
    int i,ch;
    char str[4095];

    if (argc != 4) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) { 
        fprintf(stderr, "Can't open %s\n", argv[1]);
        return 1;
    }

    char *result = NULL; 

    i=0;
    while ((ch = fgetc(fp)) != EOF) {
        str[i]=ch;
        i++;
    }   

    printf("Old string:\n %s\n", str);
    printf("Old Word: %s\n",argv[2]);
    printf("New Word: %s\n", argv[3]); 

    printf("\n");

    result = replaceWord(str, argv[2], argv[3]); 
    printf("New String:\n %s", result); 

    free(result); 
    return 0; 
}