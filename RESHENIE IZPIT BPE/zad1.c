#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
#define SIZE_NAME 30

struct patient
{
	char name[SIZE_NAME];
	char chip[SIZE];
	float prize;
};

struct patient makePatient();
void checkPatient(struct patient * patients, const int size, const float prize);
void showPatients(float prize);

int main()
{
	int i = 0;
	/*
	struct patient * patients = (struct patient *)malloc(sizeof(struct patient));

	patients[i++] = makePatient();
	patients[i++] = makePatient();
	patients[i++] = makePatient();

	checkPatient(patients, i, 10.0);
	*/
	showPatients(40);
	return 0;
}

struct patient makePatient()
{
	struct patient p1;

	FILE * fptr;
	fptr = fopen("animalsText.txt", "a");
	
	if(fptr == NULL)
	{
		printf("Something went wrong!");
		exit(1);
	}

	printf("Enter first and last name of the user: "); //
	gets(p1.name);
	fflush(stdin);
	printf("Enter the chip: "); //
	scanf("%s", p1.chip);
	fflush(stdin);
	printf("Enter the prize per something idk: "); //
	scanf("%f", &p1.prize);
	fflush(stdin);
	printf("\n");

	fprintf(fptr, "%s,%.2f\n", p1.name, p1.prize);
	fclose(fptr);
	return p1;
}

void checkPatient(struct patient * patients, const int size, const float prize)
{
	int isFound = 0;
	int i;
	for(i = 0; i < size; i++)
	{
		if(patients[i].prize == prize)
		{
			isFound = 1;
			printf("%s - %s\n",patients[i].name, patients[i].chip);
			break;
		}
	}
	if(isFound == 0)
	{
		printf("Not Found!\n");
	}
}

void showPatients(float prize)
{
	FILE * fptr;
	fptr = fopen("animalsBin.bin", "rb");

	if(fptr == NULL)
	{
		printf("something went wrong!");
		exit(1);
	}

	char name[SIZE_NAME];
	char code[SIZE + 1];
	float p;
	unsigned int size;

	fseek(fptr, 0, SEEK_END);
	int n = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	//while(feof(fptr) == 0)
	while(ftell(fptr) != n)
	{
		printf("%ld - ", ftell(fptr));
		fread(&size, sizeof(unsigned int), 1, fptr);
		fread(name, sizeof(char), size, fptr);
		name[size] = '\0';
		fread(code, sizeof(char), SIZE, fptr);
		code[SIZE] = '\0';
		fread(&p, sizeof(float), 1, fptr);
		printf("%ld\n", ftell(fptr));
		if(p == prize)
		{
			printf("Bin OwnerName: %s\n", name);
			printf("Bin Chip: %s\n", code);
			printf("Bin Price: %.2f\n", p);
			printf("----------\n");
		}
	}
	fclose(fptr);
}