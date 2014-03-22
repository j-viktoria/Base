#include <iostream>
#include <fstream>
#include "interface.h"
#include "base.h"
using namespace std;

//---------------------------------------
void file_entry(struct TAbonent *abn, int curRec, int numRec)
{
    for(int i=curRec; i<curRec+numRec; i++)
    {
        cout<<"Enter name"<<endl;
        cin.ignore();
        cin.getline(abn[i].name,20,'\n');

        cout<<"Enter data DD.MM.YY"<<endl;
        cin.getline(abn[i].data,20,'\n');
        //cin.ignore();
        //cout<<"Enter stag"<<endl;
        //cin>>ar[i].stag;
        //cin.ignore();
        //cout<<"Enter pooshrenii"<<endl;
        //cin>>ar[i].pooshrenii;
        //cout<<"Enter vziskania"<<endl;
        //cin>>ar[i].vziskania;
    }

}
//---------------------------------------
void download()
{
    cout<<"download"<<endl;
}
//---------------------------------------
void save()
{
    cout<<"save"<<endl;
}

//---------------------------------------
void famalia()
{
    cout<<"famalia"<<endl;
}
//---------------------------------------
void data()
{
    cout<<"data"<<endl;
}
//---------------------------------------
void stag()
{
    cout<<"stag"<<endl;

}
//---------------------------------------
void pooshrenia()
{
    cout<<"pooshrenia"<<endl;
}
//---------------------------------------
void vziskania()
{
    cout<<"vziskania"<<endl;
}

//---------------------------------------
void input_data(struct TAbonent *abn, int num, int (**p)(TAbonent,TAbonent))
{
    int num_operation,numabn;

    fstream strm;
    int run=1;
    int numRec;

    strm.open("setting.txt",ios::in|ios::binary);
    strm.read((char *) &numRec, sizeof(int));
    strm.close();


num_operation = 0;
    while(run)
    {
        switch(num_operation)
        {
        case 0:
        cout<<"Dlya zapisi poverh starogo faila vvedite - 1"<<endl
        <<"Dlya zagryzki faila vvedite - 2"<<endl
        <<"Dlya soxranenia vvedite - 3"<<endl
        <<"Dlya dobavki abonenta vvedite - 4"<<endl
        <<"Exit - 9"<<endl
        <<"Select operation:"<<endl;
        cin >> num_operation;
            break;
        case 1:
            cout<<"Enter num abonents:"<<endl;
            cin>>numabn;
            file_entry(abn,0, numabn);

            strm.open("c:\\data_base.txt",ios::out|ios::binary|ios::trunc);
//
            strm.write((char *) abn, numabn*sizeof(TAbonent));
            strm.close();
            numRec=numabn;
            num_operation = 0;
            break;
        case 2:
            download();
            break;
        case 3:
            break;
        case 4:
            cout<<"Enter num add abonents:"<<endl;
            cin>>numabn;
            file_entry(abn,numRec, numabn);

            strm.open("data_base.txt",ios::out|ios::binary|ios::trunc);
            strm.write((char *) abn, numabn*sizeof(TAbonent));
            strm.close();
            numRec=numabn;
            num_operation = 0;
            break;
        case 9:
            run=0;
            break;

        }
    }


}
//----------------------------------------------------------------------------------------
/*<<"Dlya zapisi daty v formate dd.mm.yy vvedite - 4"<<endl
        <<"Dlya zapisi staga v godax vvedite - 5"<<endl
        <<"Dlya zapisi kolichestva pooshrenii vvedite - 6"<<endl
        <<"Dlya zapisi kolichestva vziskanii vvedite - 7"<<endl; */
//-----------------------------------------------------------------------------------------
/*{
   case 1:
      file_entry();
       break;
   case 2:
       download();
       break;
   case 3:
       famalia();
       break;
   case 4:
       data();
       break;
   case 5 :
       stag();
       break;
   case 6:
       pooshrenia();
       break;
   case 7:
       vziskania();
       break;
   }*/
