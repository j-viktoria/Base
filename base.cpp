#include "base.h"
#include <cstring>

int sortFamilia (struct TAbonent abn1,struct TAbonent abn2)
{
    return strcmp(abn1.name,abn2.name);
}
int sortData (struct TAbonent abn1,struct TAbonent abn2)
{
    return strcmp(abn1.data,abn2.data);
}
int sortStag (struct TAbonent abn1,struct TAbonent abn2)
{
    return abn1.stag-abn2.stag;
}
int sortPooshrenia (struct TAbonent abn1,struct TAbonent abn2)
{
    return abn1.pooshrenia-abn2.pooshrenia;
}
int sortVziskania (struct TAbonent abn1,struct TAbonent abn2)
{
    return abn1.vziskania-abn2.vziskania;
}

void mysort (struct TAbonent *abn1, int num, int (*fp)(TAbonent,TAbonent), bool vozr)
{
    int a=0, b=num-1;
    if (vozr)
    {
        sortV(abn1,numRec,(*fp));
    }
    else
    {
        sortY(abn1,numRec(*fp));
    }
}
//--------------------------------------------------------------
void RepairV(struct TAbonent *abn1, int i,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    TAbonent t;
    int l,r,larg=i;
    l=2*i+1;
    r=2*i+2;
    if(l<numRec&&(*fp)(abn1[l],abn1[i])>0) larg=l;
    if(r<numRec&&(*fp)(abn1[r], abn1[larg])>0) larg=r;
    if(larg!=i)
    {
        t=abn1[larg];
        abn1[larg]=abn1[i];
        abn1[i]=t;

        RepairV(abn1,larg,numRec,(*fp));
    }
}

void BuildV(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    for(int i=numRec/2; i>=0; --i)
        RepairV(abn1,i,numRec,(*fp));
}



void sortV(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    TAbonent t;
    int larg=0;
    BuildV(abn1,numRec,(*fp));

    for(int i=numRec-1; i>=1; --i)
    {

        t = abn1[larg];
        abn1[larg] = abn1[i];
        abn1[i] = t;
        RepairV(abn1,larg,numRec,(*fp));

    }
}

//-------------------------------------------------------------------------------------------
void RepairY(struct TAbonent *abn1, int i,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    TAbonent t;
    int l,r,larg=i;
    l=2*i+1;
    r=2*i+2;
    if(l<numRec&&(*fp)(abn1[l],abn1[i])<0) larg=l;
    if(r<numRec&&(*fp)(abn1[r], abn1[larg])<0) larg=r;
    if(larg!=i)
    {
        t=abn1[larg];
        abn1[larg]=abn1[i];
        abn1[i]=t;

        RepairY(abn1,larg,numRec,(*fp));
    }
}

void BuildY(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    for(int i=numRec/2; i>=0; --i)
        RepairY(abn1,i,numRec,(*fp));
}



void sortY(struct TAbonent *abn1,int mumRec, int (*fp)( TAbonent, TAbonent))
{
    TAbonent t;
    int larg=0;
    BuildV(abn1,numRec,(*fp));

    for(int i=numRec-1; i>=1; --i)
    {

        t = abn1[larg];
        abn1[larg] = abn1[i];
        abn1[i] = t;
        RepairY(abn1,larg,numRec,(*fp));

    }
}

