#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODE_SIZE 3
#define NAME_SIZE 20

typedef struct IceCream
{
    char code[CODE_SIZE];
    char name[NAME_SIZE];
    int mass;
    float price;
} IceCream;

float sumArr(IceCream* arr, const int size, char c);
int writeTxt(IceCream* arr, const int size, float price, int mass);
void checkIcecreamBin(char* code);
void addIcecream(IceCream* arr, int* size);

int main()
{
    int n;
    do
    {   
        scanf("%d", &n);
        fflush(stdin);
    }while(n < 5 && n > 15);

    IceCream* arr = (IceCream*)malloc(n * sizeof(IceCream));
    if(arr == NULL)
    {
        exit(1);
    }
    return 0;
}

float sumArr(IceCream* arr, const int size, char c)
{
    float sum = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i].name[0] == c)
        {
            sum += arr[i].price;
        }
    }
    return sum;
}

int writeTxt(IceCream* arr, const int size, float price, int mass)
{
    int count = 0;
    FILE* fptr;
    fptr = fopen("info.txt", "a");

    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i].price < price && arr[i].mass > mass)
        {
            fprintf("%s;%s;%d;%.2fleve\n", arr[i].code, arr[i].name, arr[i].mass, arr[i].price);
            count++;
        }
    }

    fclose(fptr);
    return count;
}

void checkIcecreamBin(char* code)
{
    FILE* fptr;
    fptr = fopen("icecream.bin", "rb");
    if(fptr == NULL)
    {
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    long int end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    int size;
    IceCream temp;
    while(ftell(fptr) != end)
    {
        if(fread(temp.code, sizeof(char), CODE_SIZE - 1, fptr) != CODE_SIZE - 1)
        {
            exit(1);
        }
        temp.code[CODE_SIZE - 1] = '\0';
        if(fread(&size, sizeof(int), 1, fptr) != 1)
        {
            exit(1);
        }
        if(fread(temp.name, sizeof(char), size, fptr) != size)
        {
            exit(1);
        }
        temp.name[size] = '\0';
        if(fread(&temp.mass, sizeof(int), 1, fptr) != 1)
        {
            exit(1);
        }
        if(fread(&temp.price, sizeof(float), 1, fptr) != 1)
        {
            exit(1);
        }

        if(strcmp(temp.code, code) == 0)
        {
            printf("==========\n");
            printf("Icecream - %s\n", temp.name);
            printf("Price - %.2f BGN\n", temp.price);
            printf("==========\n");
        }
    }

    fclose(fptr);
}

void addIcecream(IceCream* arr, int* size)
{
    IceCream temp;
    scanf("%s", temp.code);
    fflush(stdin);
    scanf("%s", temp.name);
    fflush(stdin);
    scanf("%d", &temp.mass);
    fflush(stdin);
    scanf("%f", &temp.price);
    fflush(stdin);

    IceCream * tempArr = (IceCream*)realloc(arr, (*size) + 1);
    if(tempArr == NULL)
    {
        printf("Error adding element\n");
    }else
    {
        arr = tempArr;
        arr[(*size)++] = temp;
    }
}
