
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
    delete [] abn;
    delete [] poins;
    return 0;
}



/*   cout<<"Dlya zapisi poverh starogo faila vvedite - 1"<<endl
         <<"Dlya zagryzki faila vvedite - 2"<<endl
        <<"Dlya sortirovki po familii vvedite - 3"<<endl
        <<"Dlya sortirovki po date v formate dd.mm.yy vvedite - 4"<<endl
        <<"Dlya sortirovki po stagy v godax vvedite - 5"<<endl
        <<"Dlya sortirovki po kolichestvy pooshrenii vvedite - 6"<<endl
        <<"Dlya sortirovki  po kolichestvy vziskanii vvedite - 7"<<endl
        */
