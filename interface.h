#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void file_entry(struct TAbonent *abn, int curRec, int numRec);
void download();
void famalia();
void data();
void stag();
void pooshrenia();
void vziskania();
void save();


void input_data(struct TAbonent *abn, int num, int (**p)(TAbonent,TAbonent));
#endif // INTERFACE_H_INCLUDED
