#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 30
#define CODE_SIZE 8

typedef struct pet
{
    char ownerName[NAME_SIZE];
    char code[CODE_SIZE];
    float price;
} pet;

pet makePet();
void addPet(pet *arr, int* usedSize, int* size, pet animal);
void printArr(pet* arr, int usedSize);
void checkPet(pet* arr, const int usedSize, const float price);
void readBin(float price);

int main()
{
    int usedSize, size, index;
    usedSize = 0;
    size = 10;
    pet *arr = (pet*)malloc(size * sizeof(pet));
    //printf("%ld\n", sizeof(pet));

    // reading pets from console
    /*
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    addPet(arr, &usedSize, &size, makePet());
    printf("%d %d", usedSize, size);
    printArr(arr, usedSize);
    */
    readBin(2.5);
    free(arr);
    return 0;
}

pet makePet()
{
    FILE *fptr;
    fptr = fopen("animalsText.txt", "a");
    if(fptr == NULL)
    {
        exit(1);
    }
    pet temp;
    printf("Enter owner name: ");
    scanf("%s", temp.ownerName);
    fflush(stdin);
    printf("Enter code: ");
    scanf("%s", temp.code);
    fflush(stdin);
    printf("Enter price: ");
    scanf("%f", &temp.price);
    fflush(stdin);
    printf("\n");

    fprintf(fptr, "%s, %.2f\n", temp.ownerName, temp.price);
    fclose(fptr);
    return temp;
}

void addPet(pet *arr, int* usedSize, int* size, pet animal)
{
    if(*usedSize >= *size)
    {
        pet* temp = realloc(arr, *size + 5);
        if(temp == NULL)
        {
            printf("Failed to write changes.\n");
        }else
        {
            *size += 5;
            arr = temp;
            arr[(*usedSize)++] = animal;
        }
    }else
    {
        arr[(*usedSize)++] = animal;
    }
}

void printArr(pet* arr, int usedSize)
{
    int i;
    for(i = 0; i < usedSize; i++)
    {
        printf("[%s|%s|%.2f], ", arr[i].ownerName, arr[i].code, arr[i].price);
    }
    printf("\n");
}


void checkPet(pet* arr, const int usedSize, const float price)
{
    int i, flag;
    flag = 0;
    for(i = 0; i < usedSize; i++)
    {
        if(price == arr[i].price)
        {
            printf("%s - %s\n", arr[i].ownerName, arr[i].code);
            flag = 1;
        }
    }
    
    if(flag == 0)
    {
        printf("No pet found!\n");
    }
}


void readBin(float price)
{
    FILE * fptr;
    fptr = fopen("animalsBin.bin", "rb");

    pet temp;
    int size;

    fseek(fptr, 0, SEEK_END);
    long int end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    while(ftell(fptr) != end)
    {
        if(fread(&size, sizeof(int), 1, fptr) != 1)
        {
            printf("Error 1\n");
            exit(1);
        }
        if(fread(temp.ownerName, sizeof(char), size, fptr) != size)
        {
            printf("Error 2\n");
            exit(1);
        }
        temp.ownerName[size] = '\0';
        if(fread(temp.code, sizeof(char), CODE_SIZE - 1, fptr) != CODE_SIZE - 1)
        {
            printf("Error 3\n");
            exit(1);
        }
        temp.code[CODE_SIZE - 1] = '\0';
        if(fread(&temp.price, sizeof(float), 1, fptr) != 1)
        {
            printf("Error 4\n");
            exit(1);
        }
        if(temp.price > price)
        {
            printf("Bin Owner: %s\n", temp.ownerName);
            printf("Bin Chip: %s\n", temp.code);
            printf("Bin Price: %0.2f\n", temp.price);
            printf("-------------\n");
        }
    }

    fclose(fptr);
}
