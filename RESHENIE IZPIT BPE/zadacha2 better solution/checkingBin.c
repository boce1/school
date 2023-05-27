#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct product
{
    char productName[30];
    char date[11];
    int id;
    float price;
} product;

int main()
{
    FILE * fptr;
    fptr = fopen("in.bin", "rb");

    //printf("%s %s %s", names[0], names[1], names[2]);
    fseek(fptr, 0, SEEK_END);
    long int end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    product temp;
    int size;
    while(ftell(fptr) != end)
    {
        fread(&size, sizeof(int), 1, fptr);
        fread(temp.productName, sizeof(char), size, fptr);
        temp.productName[size] = '\0';
        fread(&temp.id, sizeof(int), 1, fptr);
        fread(temp.date, sizeof(char), 10, fptr);
        temp.date[10] = '\0';
        fread(&temp.price, sizeof(float), 1, fptr);
        printf("%s %s %d %.2f\n", temp.productName, temp.date, temp.id, temp.price);
    }

    fclose(fptr);
    return 0;
}