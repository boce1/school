#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fptr;
    fptr = fopen("text.txt", "a+");

    if(fptr == NULL)
    {
        printf("Files doesnt exists!\n");
        exit(1);
    }

    int n = 100;
    char str[n];

    while(fgets(str, n, fptr) != NULL) /* reding files with fgets() || fgets vrca parametaro char*str a ako ima greska ili EOF - NULL*/
    {
        printf("%s", str);
    }
    
    //fseek(fptr, 5, SEEK_SET); // raboti samo pri r r+ w w+
    //fprintf(fptr, "==========");

    //fprintf(fptr, "\nI wanted to be happy so I gave up all the\nsuffering in the world.\n\n");
    printf("Enter the sentence you want to add: ");
    gets(str);
    fprintf(fptr, "\n%s\n", str);
   
    printf("\n###################\n");
    
    fseek(fptr, 0, SEEK_SET); // ftell() e na kraj na fileo ka e mode-o "a" ili "a+"
    char c;
    while((c = fgetc(fptr)) != EOF) /* reading files with fgets || fgets vrca char ako e EOF tegaj vrca EOF*/
    {
        printf("%c", c);
    }
    
    return 0;
}
