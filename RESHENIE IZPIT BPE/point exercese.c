#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define abs_(x) ((x > 0) ? x: -x)

typedef struct point
{
    int x;
    int y;
} point;

void printArray(point* arr, const int size);
void addPoint(point* arr, int* size, int* usedSize, point p);
void readBinFile();
int findIndexPoint(point* arr, const int size, point p);
int area(point* a, point* b);
float shortestDistance(point* a, point* b);

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

    int in = findIndexPoint(arr, usedSize, c);
    float side = shortestDistance(&a, &d);
    //printf("index c point: %d\n", in);

    printf("Area: %d\n", area(&a, &b));
    printf("Distance a - d: %.2f\n", side);
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

int findIndexPoint(point* arr, const int size, point p)
{
    int index = -1;
    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i].x == p.x && arr[i].y == p.y)
        {
            index = i;
            break;
        }
    }
    return index;
}

int area(point* a, point* b)
{
    return abs_((a->x - b->x)) * abs_((a->y - b->y));
}

float shortestDistance(point* a, point* b)
{
    float s1, s2;
    s1 = (float)abs_((a->x - b->x));
    s2 = (float)abs_((a->y - b->y)); 

    return sqrt(s1*s1 + s2*s2);
}
