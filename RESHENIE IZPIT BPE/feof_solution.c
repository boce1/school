#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[100];
	int age;
} human;

int main(int argc, char* argv[])
{
	FILE * fptr;
	fptr = fopen("textBin.bin", "wb+");
	if(fptr == NULL)
	{
		printf("Something went wrong!\n");
		exit(1);
	}
	human h1 = {"Bojan", 19};
	human h2 = {"Dosto", 60};
	human h3 = {"Dekar", 90};
	human h4 = {"Newto", 29};


	if(fwrite(h1.name, sizeof(char), strlen(h1.name), fptr) != 5)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(&h1.age, sizeof(int), 1, fptr) != 1)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(h2.name, sizeof(char), strlen(h2.name), fptr) != 5)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(&h2.age, sizeof(int), 1, fptr) != 1)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(h3.name, sizeof(char), strlen(h3.name), fptr) != 5)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(&h3.age, sizeof(int), 1, fptr) != 1)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(h4.name, sizeof(char), strlen(h4.name), fptr) != 5)
	{
		printf("something went wrong.\n");
		exit(1);
	}
	if(fwrite(&h4.age, sizeof(int), 1, fptr) != 1)
	{
		printf("something went wrong.\n");
		exit(1);
	}

	// ako se koristi while(ftell(fptr) != end)
	fseek(fptr, 0, SEEK_END);
	long int end = ftell(fptr); 
	fseek(fptr, 0, SEEK_SET);
	//

	human out;
	//while(ftell(fptr) != end)
	while(feof(fptr) == 0)
	{
		unsigned int a, b;
		a = fread(out.name, sizeof(char), 5, fptr);
		b = fread(&out.age, sizeof(int), 1, fptr);
		if(a != 5 || b != 1)
		{
			break;
		}
		printf("%s, %d\n", out.name, out.age);
	}
	return 0;
}
