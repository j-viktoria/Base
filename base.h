#ifndef BASE_H
#define BASE_H



struct TAbonent{
int id;
char name [20];
int year;
int good,bad;
char data [20];
} ;
int sortFamilia (struct TAbonent abn1,struct TAbonent abn2);
int sortData (struct TAbonent abn1,struct TAbonent abn2);
int sortStag (struct TAbonent abn1,struct TAbonent abn2);
int sortPooshrenia (struct TAbonent abn1,struct TAbonent abn2);
int sortVziskania (struct TAbonent abn1,struct TAbonent abn2);
#endif // BASE_H


