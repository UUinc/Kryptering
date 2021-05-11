#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

//Function Declaration
int Menu();
void Uppercase(char *str);
char* Encrypt(char *text);
char* Decrypt(char *encrypted);
int Random(int first, int last);

int main()
{
    int result;
    char *text = (char *) malloc(sizeof(char));

    //Set Seed for rand() Function
    srand(time(0));

    while(result = Menu())
    {
        switch (result)
        {
            case 1:
                /* Encrypte */
                printf("Plain text: "); scanf("%s",text);
                Uppercase(text);
                printf("Encrypted text: %s\n",Encrypt(text));
                break;
            case 2:
                /* Dencrypte */
                printf("Encrypted text: "); scanf("%s",text);
                Uppercase(text);
                printf("Decrypted text: %s\n",Decrypt(text));
                break;
            case 0: exit(0);
        }
        getch();
        system("cls");
    }
}

int Menu()
{
    int choice, error;

    printf("Encryption\n\nMenu :\n");
    printf(" 1.Encrypt\n");
    printf(" 2.Decrypt\n");
    printf(" 0.Exit\n");

    do
    {
        printf("\nChoice : ");
        fflush(stdin);
        error = !scanf("%d",&choice);
        error = error || choice > 2 || choice < 0 ? 1 : 0;
        if(error)
            printf("choice incorrect!\n");
    } while (error);

    return choice;
}

void Uppercase(char *str)
{
    int i=0;
    while(str[i])
    {
      str[i] = toupper(str[i]); i++;
    }
}

char* Encrypt(char *text)
{
    int i, j, len = strlen(text), len2;
    char *str = (char *) malloc(len+1);

    for(i=0, j=0; i<len-1; i++)
    {
        *(str+j) = *(text+i);
        len2 = j+*(text+i)-64;
        str = (char *) realloc(str,strlen(str)+len2);
        for(j++; j<len2; j++) *(str+j) = Random(65,90);
    }
    *(str+j) = *(text+i); *(str+j+1) = '\0';

    return str;
}

char* Decrypt(char *encrypted)
{
    int i, j, len = strlen(encrypted);
    char *str = (char *) malloc(len+1);

    for(i=0, j=0; i<len;j++)
    {
        *(str+j) = *(encrypted+i);
        i += *(encrypted+i) - 64;
    }
    *(str+j) = '\0';

    str = (char *) realloc(str,j);

    return str;
}

int Random(int first, int last)
{
    int r;
    last += (1-first);
    r = rand()%last + first;
    return r;
}