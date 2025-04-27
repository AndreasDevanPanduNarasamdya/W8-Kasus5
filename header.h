#ifndef HEADER_H
#define HEADER_H

typedef struct LinkedList
{
    char Nama[10];
    struct LinkedList *Next;
}*ListLinked;

typedef struct tElmnt
{
    char Kota[10];
    struct tElmnt *Next;
    struct LinkedList *NextName;
}*KotaList;

//void InititateList(Kotalist *Kota, ListLinked *Nama);
//void EnterData(KotaList *Kota);
//void  DeleteData(KotaList *Kota);



#endif