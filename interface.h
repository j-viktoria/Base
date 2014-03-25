#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

void file_entry(struct TAbonent *abn, int curRec, int numRec);
void input_data(struct TAbonent *abn, int num, int (**p)(TAbonent,TAbonent));
void output_data( struct TAbonent *abn, int numRec);
#endif // INTERFACE_H_INCLUDED
