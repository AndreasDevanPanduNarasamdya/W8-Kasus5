#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include "body.c"

int main()
{
    int option;
    KotaList First;
    InitiateList(&First);
    while (1)
    {
        option = 0;

        printf("\n\nWelcome To Pendataan Kota, Choose an option:\n\n");
        printf("1. Enter a data\n");
        printf("2. Delete a data\n");
        printf("3. Print Whole data\n");

        scanf("%i", &option);
        switch (option)
        {
            case 1: EnterData(&First);                                                                  
            break;
            case 2: DeleteData(&First);
            break;
            case 3: PrintList(First); 
            break;
        }
    }
}