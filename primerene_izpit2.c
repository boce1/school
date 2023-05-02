#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 30
#define DATE_SIZE 11

typedef struct product
{
    char name[NAME_SIZE];
    int id;
    char date[DATE_SIZE];
    float price;
} product;

void addProduct(product prd, int* size, product* productsArr, FILE * fptr);
product* filterProducts(product * arr, int size, float price, int* newSize);
void writeDataTxt(FILE * fbin, product * products, int size);

int main()
{
    FILE * fptr;
    fptr = fopen("in.bin", "ab+");
    if(fptr == NULL)
    {
        printf("Something went wrong!\n");
        exit(1);
    }

    int size = 0;
    product * products = (product*)malloc(sizeof(product));
    product p1 = {"Chocolate", 1, "2023.05.01", 2.56};
    product p2 = {"Smoki", 2, "2023.02.01", 20.3};
    product p3 = {"Rakija", 3, "2023.10.01", 78.56};

    addProduct(p1, &size, products, fptr);
    addProduct(p2, &size, products, fptr);
    addProduct(p3, &size, products, fptr);

    int sizeArr;
    product * arr = (product*)malloc(size * sizeof(product));
    arr = filterProducts(products, size, 2.56, &sizeArr);
    int i;
    for(i = 0; i < sizeArr; i++)
    {
            printf("%s, %d, %s, %.2f\n", arr[i].name, arr[i].id, arr[i].date, arr[i].price);
    }
    printf("\n\n");

    writeDataTxt(fptr, products, size);
    free(products);
    fclose(fptr);
    return 0;
}

void writeDataTxt(FILE * fbin, product * products, int size)
{
    FILE * ptr;
    ptr = fopen("out.txt", "w+");

    if(ptr == NULL)
    {
        printf("Something went wrong!");
        exit(1);
    }

    fseek(fbin, 0, SEEK_END);
    long int endBinFile = ftell(fbin);
    fseek(fbin, 0, SEEK_SET);

    int i = 0;
    int nameLen;
    product temp; 
    /* Reading from bin file and writing in txt */
    while(ftell(fbin) != endBinFile)
    {
        nameLen = strlen(products[i].name);
        if(fread(temp.name, sizeof(char), nameLen, fbin) != nameLen)
        {
            printf("Something went wrong1\n");
            exit(1);
        }
        if(fread(&temp.id, sizeof(int), 1, fbin) != 1)
        {
            printf("Something went wrong2\n");
            exit(1);
        }
        if(fread(temp.date, sizeof(char), DATE_SIZE - 1, fbin) != (DATE_SIZE - 1))
        {
            printf("Something went wrong3\n");
            exit(1);
        }
        if(fread(&temp.price, sizeof(float), 1, fbin) != 1)
        {
            printf("Something went wrong4\n");
            exit(1);
        }
        temp.name[nameLen] = '\0';
        temp.date[DATE_SIZE - 1] = '\0';

        fprintf(ptr, "Text Item:\n");
        fprintf(ptr, "\tName: %s\n", temp.name);
        fprintf(ptr, "\tID: %d\n", temp.id);
        fprintf(ptr, "\tExpire Date: %s\n", temp.date);
        fprintf(ptr, "\tPrice: %.2f\n", temp.price);
        fprintf(ptr, "-----------------\n");

        i++;
        if(i >= size)
        {
            break;
        }
    }
    /*-----------*/

    /* Writing both file in terminal */
    fseek(fbin, 0, SEEK_SET);
    fseek(ptr, 0, SEEK_SET);

    int n = 100;
    char row[n];
    int j;
    for(i = 0; i < size; i++)
    {
        nameLen = strlen(products[i].name);
        if(fread(temp.name, sizeof(char), nameLen, fbin) != nameLen)
        {
            printf("Something went wrong1\n");
            exit(1);
        }
        if(fread(&temp.id, sizeof(int), 1, fbin) != 1)
        {
            printf("Something went wrong2\n");
            exit(1);
        }
        if(fread(temp.date, sizeof(char), DATE_SIZE - 1, fbin) != (DATE_SIZE - 1))
        {
            printf("Something went wrong3\n");
            exit(1);
        }
        if(fread(&temp.price, sizeof(float), 1, fbin) != 1)
        {
            printf("Something went wrong4\n");
            exit(1);
        }

        temp.name[nameLen] = '\0';
        temp.date[DATE_SIZE - 1] = '\0';

        printf("Binary Item:\n");
        printf("\tName: %s\n", temp.name);
        printf("\tID: %d\n", temp.id);
        printf("\tExpire Date: %s\n", temp.date);
        printf("\tPrice: %.2f\n", temp.price);
        
        for(j = 0; j < 6; j++) // ima 6 reda
        {   
            fgets(row, n, ptr);
            printf("%s", row);
        }
    }
    /*------------------*/
    fclose(ptr);
}

product* filterProducts(product * arr, int size, float price, int* newSize)
{
    int i;
    (*newSize) = 0;
    product* out = (product*)malloc(sizeof(product) * size);
    for(i = 0; i < size; i++)
    {
        if(arr[i].price > price)
        {
            out[(*newSize)++] = arr[i];
        }
    }
    out = realloc(out, (*newSize) * sizeof(product));
    return out;
}

void addProduct(product prd, int* size, product* productsArr, FILE * fptr)
{
    (*size)++;
    productsArr = realloc(productsArr, sizeof(product) * (*size));
    productsArr[(*size) - 1] = prd;
    
    
    int sizeName = strlen(prd.name);
    //printf("[%d]\n", sizeName);
    if(fwrite(prd.name, sizeof(char), sizeName, fptr) != sizeName)
    {
        printf("Writing name gone wrong!");
        exit(1);
    }
    if(fwrite(&prd.id, sizeof(int), 1, fptr) != 1)
    {
        printf("Writing id gone wrong!");
        exit(1);
    }
    if(fwrite(prd.date, sizeof(char), DATE_SIZE - 1, fptr) != (DATE_SIZE - 1))
    {
        printf("Writing date gone wrong!");
        exit(1);
    }
    if(fwrite(&prd.price, sizeof(float), 1, fptr) != 1)
    {
        printf("Writing price gone wrong!");
        exit(1);
    }
}