#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[15];
    int age;
} human;

int main()
{
    FILE * fptr;
    fptr = fopen("bojan.bin", "wb+");

    if(fptr == NULL)
    {
        printf("Error");
        exit(1);
    }

    human h1 = {"Bojan", 19};
    human h2 = {"Alber", 60};
    human h3 = {"Franc", 80};

    int flag = 1;
    if(fwrite(h1.name, sizeof(char), 5, fptr) != 5)
    {
        printf("Something went wrong!");
        flag = 0;
    }
    if(fwrite(&h1.age, sizeof(int), 1, fptr) != 1)
    {
        printf("Something went wrong!");
        flag = 0;
    }
    if(fwrite(h2.name, sizeof(char), 5, fptr) != 5)
    {
        printf("Something went wrong!");
        flag = 0;
    }
    if(fwrite(&h2.age, sizeof(int), 1, fptr) != 1)
    {
        printf("Something went wrong!");
        flag = 0;
    }
    if(fwrite(h3.name, sizeof(char), 5, fptr) != 5)
    {
        printf("Something went wrong!");
        flag = 0;
    }
    if(fwrite(&h3.age, sizeof(int), 1, fptr) != 1)
    {
        printf("Writing to the file went wrong!\n");
        flag = 0;
    }

    if(flag == 1)
    {
        human out;
        fseek(fptr, 0, SEEK_END);
        long int end = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        unsigned a, b;
        while(ftell(fptr) != end)
        {
            a = fread(out.name, sizeof(char), 5, fptr);
            b = fread(&out.age, sizeof(int), 1, fptr);
            if(a == 5 && b == 1)
            {
                out.name[5] = '\0';
                printf("%s -- %d\n", out.name, out.age);
            }else
            {
                printf("Reading a files went wrong!\n");
            }
            
        }
    }
    fclose(fptr);
    return 0;
}
