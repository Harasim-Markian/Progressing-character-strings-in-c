#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char my_string[100];
    char read[100];
    FILE *file;
    
    file = fopen("text.txt", "w");
    if ((file= fopen("text.txt","w")) == NULL)
    {
        perror("Opening file error!");
        exit(0);
    }

    printf("Enter the text : ");
    fgets(my_string, 100 , stdin);
    fputs(my_string, file);
    fclose(file);


    file = fopen("text.txt", "r");
    fgets(read, 100 , file);
    printf("\nText that is in the file : %s\n", read);
    fclose(file);

    
    int elements = 0;
    int sums = 0;

    for(int i = 0; read[i] != '\0'; i++)
    {
        if (read[i] == '{')
        {
            elements = 1;
        }
        else if (read[i] == '}')
        {
            elements = 0;
        }
        else if (elements)
        {
            printf("Symbol in {} : %c  Numerical value : %d\n", read[i] , read[i]);  
            sums += read[i];
        } 
    }

    printf("\n");
    printf("Sums numerical values = %d\n", sums); 
   
    return 0;

}