#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PRODUCT_SIZE 30
#define DATE_SIZE 11

typedef struct product
{
    char productName[PRODUCT_SIZE];
    char date[DATE_SIZE];
    int id;
    float price;
} product;

void addProduct(product* arr, int* size, int* usedSize, product prd);
product* filtrateProduct(product* arr, const int size, float price, int* filtretedSize);
void readFile(product* arr, const int size);

int main()
{
    int usedSize, size;
    size = 5;
    usedSize = 0;
    product * arr = (product*)malloc(size * sizeof(product));
    //printf("%d\n", sizeof(product));
    product ex1 = {"Honda", "2023.04.03", 1, 20.32};
    product ex2 = {"Mercedes", "2023.04.03", 2, 10.32};
    product ex3 = {"Golf", "2023.04.03", 3, 2.78};

    addProduct(arr, &size, &usedSize, ex1);
    addProduct(arr, &size, &usedSize, ex2);
    addProduct(arr, &size, &usedSize, ex3);

    product* arrFilter;
    int filterSize;
    arrFilter = filtrateProduct(arr, usedSize, 9.0, &filterSize);
    int i;
    for(i = 0; i < filterSize; i++)
    {
        printf("[%s|%s|%d|%.2f], \n", arrFilter[i].productName, arrFilter[i].date, arrFilter[i].id, arrFilter[i].price);
    }

    /*
    int i;
    for(i = 0; i < usedSize; i++)
    {
        printf("[%s|%s|%d|%.2f], ", arr[i].productName, arr[i].date, arr[i].id, arr[i].price);
    }
    */
    readFile(arr, usedSize);
    free(arr);
    free(arrFilter);
    return 0;
}

void addProduct(product* arr, int* size, int* usedSize, product prd)
{
    if(*usedSize >= *size)
    {
        product* temp = realloc(arr, *size + 5);
        if(temp == NULL)
        {
            printf("Failed to add product");
        }else
        {
            arr = temp;
            arr[(*usedSize)++] = prd;
            *size += 5;
        }
    }else
    {
        arr[(*usedSize)++] = prd;
    }
    FILE * fptr;
    fptr = fopen("in.bin", "ab+");

    if(fptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    int s = strlen(prd.productName);
    if(fwrite(&s, sizeof(int), 1, fptr) != 1)
    {
        printf("Error1\n");
        exit(1);
    }
    if(fwrite(prd.productName, sizeof(char), s, fptr) != s)
    {
        printf("Error2\n");
        exit(1);
    }
    if(fwrite(&prd.id, sizeof(int), 1, fptr) != 1)
    {
        printf("Error3\n");
        exit(1);
    }
    if(fwrite(prd.date, sizeof(char), DATE_SIZE - 1, fptr) != DATE_SIZE - 1)
    {
        printf("Error4\n");
        exit(1);
    }
    if(fwrite(&prd.price, sizeof(float), 1, fptr) != 1)
    {
        printf("Error5\n");
        exit(1);
    }

    fclose(fptr);
}

product* filtrateProduct(product* arr, const int size, float price, int* filtretedSize)
{
    product* out = (product*)malloc(size * sizeof(product));
    int i, j;
    j = 0;
    for(i = 0; i < size; i++)
    {  
        if(arr[i].price >= price)
        {
            out[j++] = arr[i];
        } 
    }
    *filtretedSize = j;
    return out;
}

void readFile(product* arr, const int size)
{
    FILE* ptrTxt;
    FILE* ptr;
    ptrTxt = fopen("out.txt", "w+");
    ptr = fopen("in.bin", "rb");

    if(ptrTxt == NULL || ptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    product prd;
    int s, i, j;
    
    for(i = 0; i < size; i++)
    {
        if(fread(&s, sizeof(int), 1, ptr) != 1)
        {
            printf("Error1\n");
            exit(1);
        }
        if(fread(prd.productName, sizeof(char), s, ptr) != s)
        {
            printf("Error2\n");
            exit(1);
        }
        prd.productName[s] = '\0';
        if(fread(&prd.id, sizeof(int), 1, ptr) != 1)
        {
            printf("Error3\n");
            exit(1);
        }
        if(fread(prd.date, sizeof(char), DATE_SIZE - 1, ptr) != DATE_SIZE - 1)
        {
            printf("Error4\n");
            exit(1);
        }
        prd.date[DATE_SIZE - 1] = '\0';
        if(fread(&prd.price, sizeof(float), 1, ptr) != 1)
        {
            printf("Error5\n");
            exit(1);
        }

        fprintf(ptrTxt, "Text Item:\n");
        fprintf(ptrTxt, "\tName: %s\n", prd.productName);
        fprintf(ptrTxt, "\tID: %d\n", prd.id);
        fprintf(ptrTxt, "\tDate: %s\n", prd.date);
        fprintf(ptrTxt, "\tPrice: %.2f\n", prd.price);
        fprintf(ptrTxt, "-------------\n");
    }

    fseek(ptr, 0, SEEK_SET);
    fseek(ptrTxt, 0, SEEK_SET);
    char row[100];
    for(i = 0; i < size; i++)
    {
        if(fread(&s, sizeof(int), 1, ptr) != 1)
        {
            printf("Error1\n");
            exit(1);
        }
        if(fread(prd.productName, sizeof(char), s, ptr) != s)
        {
            printf("Error2\n");
            exit(1);
        }
        prd.productName[s] = '\0';
        if(fread(&prd.id, sizeof(int), 1, ptr) != 1)
        {
            printf("Error3\n");
            exit(1);
        }
        if(fread(prd.date, sizeof(char), DATE_SIZE - 1, ptr) != DATE_SIZE - 1)
        {
            printf("Error4\n");
            exit(1);
        }
        prd.date[DATE_SIZE - 1] = '\0';
        if(fread(&prd.price, sizeof(float), 1, ptr) != 1)
        {
            printf("Error5\n");
            exit(1);
        }

        printf("Bin Item:\n");
        printf("\tName: %s\n", prd.productName);
        printf("\tID: %d\n", prd.id);
        printf("\tDate: %s\n", prd.date);
        printf("\tPrice: %.2f\n", prd.price);

        for(j = 0; j < 6; j++)
        {
            fgets(row, 100, ptrTxt);
            printf("%s", row);
            //printf("lol\n");
        }
    }
    fclose(ptrTxt);
    fclose(ptr);
}
