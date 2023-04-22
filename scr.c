#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE * fptr;
	fptr = fopen("animalsBin.bin", "wb");

	if(fptr == NULL)
	{
		printf("something went wrong!");
		exit(1);
	}
	
	char * names[] = {"Marcus Aurelius", "Seneca", "Fyodor Dostoyevski", "Franz Kafka"};
	char * codes[] = {"A12345B", "A123G5B", "QT23G5B", "AE23TTB"};
	float prizes[] = {40., 50., 40., 20.5};

	int n = sizeof(prizes) / sizeof(prizes[0]);
	int i;
	int size;
	for(i = 0; i < n; i++)
	{
		for(size = 0; names[i][size] != '\0'; size++);
	
		fwrite(&size, sizeof(unsigned int), 1, fptr);
		fwrite(names[i], sizeof(char), size, fptr);
		//printf("%d, ", sizeof(names[i]));
		fwrite(codes[i], sizeof(char), 7, fptr);
		fwrite(&prizes[i], sizeof(float), 1, fptr);	
	}  
	return 0;
}