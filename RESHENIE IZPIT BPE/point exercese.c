#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
} point;

void printArray(point* arr, const int size);
void addPoint(point* arr, int* size, int* usedSize, point p);
void readBinFile();

int main()
{
    int size, usedSize;
    size = 10;
    usedSize = 0;
    point* arr = (point*)malloc(size * sizeof(point));

    point a = {1, 5};
    point b = {2, 5};
    point c = {3, 2};
    point d = {0, -4};
    point e = {5, 7};

    addPoint(arr, &size, &usedSize, a);
    //printArray(arr, usedSize);
    addPoint(arr, &size, &usedSize, b);
    addPoint(arr, &size, &usedSize, c);
    //printArray(arr, usedSize);
    addPoint(arr, &size, &usedSize, d);
    addPoint(arr, &size, &usedSize, e);
    printArray(arr, usedSize);
    //printf("%d\n", size);
    readBinFile();
    free(arr);
    return 0;
}

void printArray(point* arr, const int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("[%d %d], ", arr[i].x, arr[i].y);
    }
    printf("\t%d\n", size);
    //printf("\n");
}

void addPoint(point* arr, int* size, int* usedSize, point p)
{
    if(*usedSize >= *size)
    {
        point* temp = realloc(arr, (*size) + 5);

        if(temp == NULL)
        {
            printf("Failed to add item\n");
        }else
        {
            arr = temp;
            arr[(*usedSize)++] = p;
            *size += 5;
        }
    }else
    {
        arr[(*usedSize)++] = p;
    } 

    FILE * fptr;
    fptr = fopen("points.bin", "ab");
    if(fptr == NULL)
    {
        printf("Failed to acces file.\n");
        return;
    }

    if(fwrite(&p.x, sizeof(int), 1, fptr) != 1)
    {
        printf("Faile to write x point in file\n");
        return;
    }
    if(fwrite(&p.y, sizeof(int), 1, fptr) != 1)
    {
        printf("Faile to write y point in file\n");
        return;
    }
    fclose(fptr);
}

void readBinFile()
{
    point temp;
    FILE * fptr;
    fptr = fopen("points.bin", "rb");
    if(fptr == NULL)
    {
        printf("Failed to acces file.\n");
        return;
    }

    fseek(fptr, 0, SEEK_END);
    long int end = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    printf("Binary file:\n");
    while(ftell(fptr) != end)
    {
        if(fread(&temp.x, sizeof(int), 1, fptr) != 1)
        {
            printf("Faile to read x point in file\n");
            return;
        }
        if(fread(&temp.y, sizeof(int), 1, fptr) != 1)
        {
            printf("Faile to read y point in file\n");
            return;
        }
        printf("%d %d\n", temp.x, temp.y);
    }
    fclose(fptr);
}