#include <stdio.h>
#include <stdlib.h>

void readFile(FILE * fptr);
void readFile2(FILE * fptr);

int main()
{
    FILE * ptr;
    ptr = fopen("sometext.txt", "r+");
    if(ptr == NULL)
    {
        printf("Files does not exists\n");
        exit(1);
    }
    //readFile(ptr);
    readFile2(ptr);
    fclose(ptr);
    return 0;
}

void readFile(FILE * fptr)
{
    int n = 100;
    char row[n];
    int num = 1;

    fseek(fptr, 0, SEEK_SET);
    while(fgets(row, n, fptr) != NULL)
    {
        printf("%3d. %s", num++, row);
    }
}

void readFile2(FILE * fptr)
{
    char c;
    int line = 1;
    int flag = 1;
    while((c = fgetc(fptr)) != EOF)
    {
        if(flag == 1)
        {
            printf("%d. ", line++);
        }
        if(c != '\n')
        {
            flag = 0;
        }else
        {
            flag = 1;
        }
        printf("%c", c);
    }
}

