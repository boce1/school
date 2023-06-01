#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_SIZE 55
#define ID_SIZE 7

typedef struct member 
{
    char names[NAMES_SIZE];
    char id[ID_SIZE];
    float price;
    int code;
} member;

void addMember(member* arr, int* size, FILE* fptr);
void avgPrice(member* arr, const int size);
void findMember(char* code);

int main()
{
    int size = 10;
    member* arr = malloc(size * sizeof(member));

    FILE* fptr;
    fptr = fopen("membersText.txt", "w");
    if(fptr == NULL)
    {
        exit(1);
    }

    fclose(fptr);
    free(arr);
    return 0;  
}

void addMember(member* arr, int* size, FILE* fptr)
{
    member el;
    scanf("%s", el.names);
    fflush(stdin);
    scanf("%s", el.id);
    fflush(stdin);
    scanf("%f", &el.price);
    fflush(stdin);
    do
    {
        scanf("%d", &el.code);
        fflush(stdin);
    }while(el.code / 100 > 0);

    member* temp = realloc(arr, (*size) + 1);
    if(temp == NULL)
    {
        printf("Failes adding a element");
    }else
    {
        arr = temp;
        arr[(*size)++] = el;
    }
    unsigned int sizeNames = strlen(el.names);
    fprintf(fptr, "%u;%s;%s;%.2f;%d\n", sizeNames, el.names, el.id, el.price, el.code);
}

void avgPrice(member* arr, const int size)
{
    int i;
    float sum = 0;
    for(i = 0; i < size; i++)
    {
        sum += arr[i].price;
    }
    float avg = sum / size;

    for(i = 0; i < size; i++)
    {
        if(arr[i].price == avg)
        {
            printf("%s - %s - %.2f\n", arr[i].names, arr[i].id, arr[i].price);
        }
    }
}

void findMember(char* code)
{
    FILE* fptr;
    fptr = fopen("members.bin", "rb");
    if(fptr == NULL)
    {
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    long int end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    member temp;
    int size;
    while(ftell(fptr) != end)
    {
        if(fread(&size, sizeof(int), 1, fptr) != 1)
        {
            exit(1);
        }
        if(fread(temp.names, sizeof(char), size, fptr) != size)
        {
            exit(1);
        }
        temp.names[size] = '\0';
        if(fread(temp.id, sizeof(char), ID_SIZE - 1, fptr) != ID_SIZE - 1)
        {
            exit(1);
        }
        temp.id[ID_SIZE - 1] = '\0';
        if(fread(&temp.price, sizeof(float), 1, fptr) != 1)
        {
            exit(1);
        }
        if(fread(&temp.code, sizeof(int), 1, fptr) != 1)
        {
            exit(1);
        }

        if(strcmp(temp.id, code) == 0)
        {
            printf("Bin Name %s\n", temp.names);
            printf("Bin ID %s\n", temp.id);
            printf("Bin price %.2f\n", temp.price);
            printf("Bin Locker %d\n", temp.code);
        }
    }

    fclose(fptr);
}
