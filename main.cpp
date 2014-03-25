
#include "interface.h"
#include "base.h"
using namespace std;

int main()
{

    typedef int (*fp)(TAbonent,TAbonent);
    fp *poins;
    poins = new fp[5];
    poins[1] = sortFamilia;
    poins[2] = sortData;
    poins[3] = sortStag;
    poins[4] = sortPooshrenia;
    poins[5] = sortVziskania;
    TAbonent *abn;
    const int num=20;
    abn = new TAbonent[num];
    input_data(abn,num,poins);
    output_data(abn,numRec);
    delete [] abn;
    delete [] poins;
    return 0;
}




