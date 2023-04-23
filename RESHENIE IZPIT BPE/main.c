#include <stdio.h>
#include <stdlib.h>

#define CHIP_SIZE 8
#define NAME_SIZE 30

struct pet createPet();
void checkPet(struct pet *, int, float);
void checkPrice(float);

struct pet
{
  char name[NAME_SIZE];
  char chip[CHIP_SIZE];
  float price;
};

int main()
{
  /*
  int i = 0;
  struct pet * pets = (struct pet *)malloc(sizeof(struct pet));
  pets[i++] = createPet();
  pets[i++] = createPet();
  pets[i++] = createPet();
  free(pets);
  */
  checkPrice(10);
  return 0;
}

struct pet createPet()
{
  struct pet p;
  FILE * fptr;
  fptr = fopen("animalText.txt", "a");

  if(fptr == NULL)
  {
    printf("Error! Something went wrong!");
    exit(1);
  }

  printf("Enter name of the owner: ");
  gets(p.name);
  fflush(stdin);
  printf("Enter the chip must be 7 symbols: ");
  scanf("%s", p.chip);
  fflush(stdin);
  printf("Enter the price: ");
  scanf("%f", &p.price);
  fflush(stdin);
  printf("\n");

  fprintf(fptr, "%s,%.2f\n", p.name, p.price);
  fclose(fptr);
  return p;
}

void checkPet(struct pet * pets, int size, float price)
{
  int isFound = 0;
  int i;
  for(i = 0; i < size; i++)
  {
    if(pets[i].price == price)
    {
       printf("%s - %s\n", pets[i].name, pets[i].chip);
       isFound = 1;
       break;
    }
  }
  if(isFound == 0)
  {
    printf("No results found!\n");
  }
}

void checkPrice(float price)
{
  FILE * fptr;
  fptr = fopen("AnimalsBin.bin", "rb");
  if(fptr == NULL)
  {
    printf("Error! Something went wrong!\n");
    exit(1);
  }

  char name[NAME_SIZE];
  char code[CHIP_SIZE];
  float p;
  unsigned int size;
  
  fseek(fptr, 0, SEEK_END);
  int end = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);

  while(ftell(fptr) != end)
  {
    if(fread(&size, sizeof(unsigned int), 1, fptr) != 1)
    {
      printf("Error!1");
      fclose(fptr);
      exit(1);
    }
    if(fread(name, sizeof(char), size, fptr) != size)
    {
      printf("Error!2");
      fclose(fptr);
      exit(1);
    }
    name[size] = '\0';
    if(fread(code, sizeof(char), CHIP_SIZE - 1, fptr) != (CHIP_SIZE - 1))
    {
      printf("Error!3");
      fclose(fptr);
      exit(1);
    }
    code[CHIP_SIZE - 1] = '\0';
    if(fread(&p, sizeof(float), 1, fptr) != 1)
    {
      printf("Error!4");
      fclose(fptr);
      exit(1);
    }

    if(p >= price)
    {
      printf("Bin OwnerName: %s\n", name);
      printf("Bin Chip: %s\n", code);
      printf("Bin Price: %.2f\n", p);
      printf("--------\n");
    }
  }

  fclose(fptr);
}