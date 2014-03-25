#ifndef BASE_H
#define BASE_H



struct TAbonent{
int id;
char name [20];
int stag;
int pooshrenia,vziskania;
char data [20];
} ;
int sortFamilia (struct TAbonent abn1,struct TAbonent abn2);
int sortData (struct TAbonent abn1,struct TAbonent abn2);
int sortStag (struct TAbonent abn1,struct TAbonent abn2);
int sortPooshrenia (struct TAbonent abn1,struct TAbonent abn2);
int sortVziskania (struct TAbonent abn1,struct TAbonent abn2);
void mysort (struct TAbonent *abn1, int num, int (*fp)(TAbonent,TAbonent), bool vozr);

void RepairV(struct TAbonent *abn1, int i,int mumRec, int (*fp)( TAbonent, TAbonent));
void BuildV(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent));
void sortV(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent));
void RepairY(struct TAbonent *abn1, int i,int mumRec, int (*fp)( TAbonent, TAbonent));
void BuildY(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent));
void sortY(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent));
#endif // BASE_H


