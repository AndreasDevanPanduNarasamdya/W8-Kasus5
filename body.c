#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

void InitiateList(KotaList *KotaKotaan)
{
    *KotaKotaan = NULL;
}

void EnterCityData(KotaList *Kota, int option, int count)
{
    KotaList First = *Kota;
    KotaList TempKota;
    char cityname[10];
    printf("\nEnter a city name: ");
    scanf("%s", cityname);
    if (*Kota == NULL)
    {
        *Kota = (KotaList)malloc(sizeof(struct tElmnt));
        strcpy((*Kota)->Kota, cityname);
        (*Kota)->Next = NULL;
        (*Kota)->NextName = NULL;
    }
    else
    {
        TempKota = (KotaList)malloc(sizeof(struct tElmnt));
        strcpy(TempKota->Kota, cityname);
        TempKota->Next = NULL;
        TempKota->NextName = NULL;
        while (First != NULL)
        {
            ++count;
            printf("%i. %s\n", count, First->Kota);
            First = First->Next;
        }
        printf("\nSelect after which city you wanna add this: ");
        scanf("%i", &option);
        while (option > count)
        {
            printf("\nThat path doesn't exist, try again\n");
            scanf("%i", &option);
        }
        First = *Kota;
        while (option > 1)
        {
            First = First->Next;
            --option;
        }
        if (First->Next != NULL)
        {
            TempKota->Next = First->Next;
        }
        First->Next = TempKota;
    }
}

void EnterNameData(KotaList *Kota, int option, int count)
{
    char Name[10];
    ListLinked TempName;
    KotaList First = *Kota;
    while (First != NULL)
    {
        ++count;
        printf("%i. %s\n", count, First->Kota);
        First = First->Next;
    }
    printf("\nWhich city would you like to add");
    scanf("%i", &option);
    while (option > count)
    {
        printf("\nThat path doesn't exist, try again");
        scanf("%i", &option);
    }
    First = *Kota;
    while (option > 1)
    {
        --option;
        First = First->Next;
    }
    printf("\n\nEnter a Name");
    scanf("%s", Name);
    TempName = (ListLinked) malloc(sizeof(struct LinkedList));
    strcpy(TempName->Nama, Name);
    TempName->Next = NULL;
    if (First->NextName == NULL)
    {
        First->NextName = TempName;
    }
    else
    {
        ListLinked TempNode = First->NextName;
        count = 0;
        while (TempNode != NULL)
        {
            ++count;
            printf("%i. %s\n", count, TempNode->Nama);
            TempNode = TempNode->Next;
        }
        printf("\nChoose after which name to put this new name");
        scanf("%i", &option);
        while (option > count)
        {
            printf("\nThat path doesn't exist, try again");
            scanf("%i", &option);
        }
        TempNode = First->NextName;
        while (option > 1)
        {
            TempNode = TempNode->Next;
            --option;
        }
        if (TempNode->Next != NULL)
        {
            TempName->Next = TempNode->Next;
        }
        TempNode->Next = TempName;
    }
}

void EnterData(KotaList *KotaKotaan)
{
    int count = 0;
    int option = 0;
    printf("\n\nSelect an option:\n");
    printf("1. Enter City\n");
    printf("2. Enter Name\n");
    scanf("%i", &option);
    if (option == 1)
    {
        EnterCityData(KotaKotaan, option, count);
    }
    else if (option == 2)
    {
        EnterNameData(KotaKotaan, option, count);
    }
}

void DeleteKota(KotaList *Kota, int option, int count)
{
    KotaList First = *Kota;
    KotaList TempKota = *Kota;
    while (First != NULL)
    {
        ++count;
        printf("%i. %s\n", count, First->Kota);
        First = First->Next;
    }
    printf("\nPilih sebuah opsi: ");
    scanf("%i", &option);
    while (option > count)
    {
        printf("\nThat path doesn't exist, try again");
        scanf("%i", &option);
    }
    First = *Kota;
    while (option > 1)
    {
        First = TempKota;
        TempKota = TempKota->Next;
        --option;
    }
    if (TempKota->NextName == NULL)
    {
        if (TempKota == First)
        {
            if (TempKota->Next != NULL)
            {
                *Kota = TempKota->Next;
            }
            else
            {
                *Kota = NULL;
            }
        }
        else
        {
            if (TempKota->Next != NULL)
            {
                First->Next = TempKota->Next;
            }
            else
            {
                First->Next = NULL;
            }
        }
    }
    else
    {
        ListLinked TempName;
        ListLinked PrevName;
        TempName = TempKota->NextName;
        while (TempName != NULL)
        {
            PrevName = TempName;
            TempName = TempName->Next;
            free(PrevName);
        }
        if (TempKota == First)
        {
            if (TempKota->Next != NULL)
            {
                *Kota = TempKota->Next;
            }
            else
            {
                *Kota = NULL;
            }
        }
        else
        {
            if (TempKota->Next != NULL)
            {
                First->Next = TempKota->Next;
            }
            else
            {
                First->Next = NULL;
            }
        }
    }
    free (TempKota);
}

void DeleteNama(KotaList *Kota, int option, int count)
{
    ListLinked TempName;
    KotaList TemporaryKota = *Kota;
    KotaList First = *Kota;
    while (First != NULL)
    {
        ++count;
        printf("%i. %s\n", count, First->Kota);
        First = First->Next;
    }
    printf("\nChoose a city");
    scanf("%i", &option);
    while (option > count)
    {
        printf("\nThat path doesn't exist, try again\n");
        scanf("%i", &option);
    }
    First = *Kota;
    while (count > 1)
    {
        --count;
        First = First->Next;
    }
    TempName = First->NextName;
    if (TempName == NULL)
    {
        printf("\nNo names to dsiplay\n");
    }
    count = 0;
    while (TempName != NULL)
    {
        ++count;
        printf("%i. %s\n", count, TempName->Nama);
        TempName = TempName->Next;
    }
    printf("\nChoose a name to delete: ");
    scanf("%i", &option);
    while (option > count)
    {
        printf("\nThat path doesn't exist, try again\n");
        scanf("%i", &option);
    }
    TempName = First->NextName;
    ListLinked TempTempName = TempName;
    while(option > 1)
    {
        --option;
        TempTempName = TempName;
        TempName = TempName->Next;

    }
    if (TempTempName == TempName)
    {
        if (TempTempName->Next != NULL)
        {
            TemporaryKota->NextName = TempName->Next;
        }
        else
        {
            TemporaryKota->NextName = NULL;
        }
    }
    else
    {
        if (TempName->Next != NULL)
        {
            TempTempName->Next = TempName->Next;
        }
        else
        {
            TempTempName->Next = NULL;
        }
    }
    free (TempName);
}

void DeleteData(KotaList *KotaKotaan)
{
    int count = 0;
    int option = 0;
    KotaList TempKota = *KotaKotaan;
    printf("Pilih Opsi:\n");
    printf("1. Hapus Kota\n");
    printf("2. Hapus Nama\n");

    scanf("%i", &option);

    if (option == 1)
    {
        DeleteKota(KotaKotaan, option, count);
    }
    else if (option == 2)
    {
        DeleteNama(KotaKotaan, option, count);
    }
}

void PrintList(KotaList Kota)
{
    if (Kota == NULL)
    {
        printf("\n\nNo Data to print\n");
    }
    while (Kota != NULL)
    {
        ListLinked TempName;
        printf("\nNama Kota: %s", Kota->Kota);
        TempName = Kota->NextName;
        while (TempName != NULL)
        {
            printf("\n  Nama Orang: %s", TempName->Nama);
            TempName = TempName->Next;
        }
        Kota = Kota->Next;
    }
}