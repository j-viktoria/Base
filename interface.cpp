#include <iostream>
#include <fstream>
#include "interface.h"
#include "base.h"
using namespace std;

//------------------------------------------------------------
void file_entry(struct TAbonent *abn, int curRec, int numRec)
{
    for(int i=curRec; i<curRec+numRec; i++)
    {
        cout<<"Vvedite familiy"<<endl;
        cin.ignore();
        cin.getline(abn[i].name,20);
        cout<<"Vvedite daty DD.MM.YY"<<endl;
        cin.ignore();
        cin.getline(abn[i].data,20);
        cout<<"Vvedite stag"<<endl;
        cin>>abn[i].stag;
        cin.ignore();
        cout<<"Vvedite kolichestvo pooshrenii"<<endl;
        cin>>abn[i].pooshrenia;
        cout<<"Vvedite kolichestvo vziskanii"<<endl;
        cin.ignore(1,'\n');
        cin>>abn[i].vziskania;
    }

}

//----------------------------------------------------------------------------

void input_data(struct TAbonent *abn, int num, int (**p)(TAbonent,TAbonent))
{
    int num_operation,numabn;
    std::fstream strm;
    int run=1;
    int numRec=0;

    strm.open("setting.txt",ios::in|ios::binary);
    strm.seekg (0, strm.end);
    int length = strm.tellg();
    strm.seekg (0, strm.beg);
    char * buffer = new char [length];
    strm.read (buffer,length);
    strm.close();

    if((buffer[0]!=0) && (buffer[0]!=NULL))
    {
        for(int i=0; i<length; i++)
        {
            numRec |= (buffer[i] - 0x30);

            if(length!=i+1)
                numRec = numRec*10;

        }
    }

    cout << numRec <<endl;

    num_operation = 0;
    while(run)
    {
        switch(num_operation)
        {
        case 0:
            cout<<"Dlya zapisi poverh starogo faila vvedite - 1"<<endl
                <<"Dlya zagryzki faila vvedite - 2"<<endl
                <<"Dlya sortirovki po familii ot A-Z vvedite - 3"<<endl
                <<"Dlya sortirovki po familii ot Z-A vvedite - 4"<<endl
                <<"Dlya sortirovki po date po vozrastaniy vvedite - 5"<<endl
                <<"Dlya sortirovki po date po ybivaniy vvedite - 6"<<endl
                <<"Dlya sortirovki po stagy po vozrastaniy vvedite - 7"<<endl
                <<"Dlya sortirovki po stagy po vozrastaniy vvedite - 8"<<endl
                <<"Dlya sortirovki po kolichestvy pooshrenii po vozrastaniy vvedite - 9"<<endl
                <<"Dlya sortirovki po kolichestvy pooshrenii po ybivanay vvedite - 10"<<endl
                <<"Dlya sortirovki  po kolichestvy vziskanii po vozrastaniy vvedite - 11"<<endl
                <<"Dlya sortirovki  po kolichestvy vziskanii po ybivanay vvedite - 12"<<endl
                <<"Dlya dobavki abonenta vvedite - 13"<<endl
                <<"Exit - 14"<<endl
                <<"Select operation:"<<endl;
            cin >> num_operation;
            break;
        case 1:
            cout<<"Enter num abonents:"<<endl;
            cin>>numabn;
            file_entry(abn,0, numabn);
            strm.open ("data_base.txt",ios::out|ios::binary|ios::trunc);
            strm.write((char *) abn, numabn*sizeof(TAbonent));
            strm.close();
            numRec=numabn;
            num_operation = 0;
            break;
        case 2:
            strm.open("data_base.txt",ios::in|ios::binary);
            strm.read((char *) abn, numabn*sizeof(TAbonent));
            strm.close();
            num_operation = 0;
            break;

        case 3:
            mysort(abn,num, poins[1],true);
            num_operation = 0;
            break;
        case 4:
            mysort(abn,num, poins[1],false);
            num_operation = 0;
            break;
        case 5:
            mysort(abn,num, poins[2],true);
            num_operation = 0;
            break;
        case 6:
            mysort(abn,num, poins[2],false);
            num_operation = 0;
            break;
        case 7:
            mysort(abn,num, poins[3],true);
            num_operation = 0;
            break;
        case 8:
            mysort(abn,num, poins[3],false);
            num_operation = 0;
        case 9:
            mysort(abn,num, poins[4],true);
            num_operation = 0;
            break;
        case 10:
            mysort(abn,num, poins[4],false);
            num_operation = 0;
            break;
        case 11:
            mysort(abn,num, poins[5],true);
            num_operation = 0;
            break;
        case 12:
            mysort(abn,num, poins[5],false);
            num_operation = 0;
            break;
            */
        case 13:
            cout<<"Exist num abonents:";
            cout<<numRec<<endl;
            cout<<"Enter num add abonents:";
            cin>>numabn;
            file_entry(abn,numRec, numabn);
            strm.open("data_base.txt",ios::out|ios::binary|ios::app);
            strm.write((char *) abn, numabn*sizeof(TAbonent));
            strm.close();
            numRec=numabn;
            num_operation = 0;
            break;
        case 14:
            run=0;
            break;

        }
        char str[3];
        sprintf(str,"%d",numRec);
        strm.open("setting.txt",ios::out|ios::binary|ios::trunc);
        strm.write(str, 2);
        strm.close();
    }


}


//----------------------------------------------------------------------------------------
void output_data( struct TAbonent *abn, int numRec);
{
    cin.ignore(1,'\n');
    for( int i = 0; i < numRec; ++i)
    {
        cout << abn[i].name << endl;
        cout << abn[i].data << endl;
        cout << abn[i].stag<< endl;
        cout << abn[i].pooshrenia << endl
        cout << abn[i].vziskania << endl;
        cout << endl;
    }
}
