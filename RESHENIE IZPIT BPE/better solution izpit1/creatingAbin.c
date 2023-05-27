#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * fptr;
    fptr = fopen("animalsBin.bin", "wb");

    char *names[3] = {"Marcus", "Seneca", "Epictitus"}; 
    char *codes[3] = {"A123457", "123456Q", "Q123A45"};
    float p[] = {2.14, 2.65, 7.145};
    //printf("%s %s %s", names[0], names[1], names[2]);
    int i, size;
    for(i = 0; i < 3; i++)
    {
        for(size = 0; names[i][size] != '\0'; size++);
        fwrite(&size, sizeof(size), 1, fptr);
        fwrite(names[i], sizeof(char), strlen(names[i]), fptr);
        fwrite(codes[i], sizeof(char), strlen(codes[i]), fptr);
        fwrite(&p[i], sizeof(float), 1, fptr);
    }

    fclose(fptr);
    return 0;
}