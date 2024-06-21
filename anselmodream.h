#ifndef anselmo_h
#define anselmo_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct slnode Slnode;
typedef struct sllist Sllist;
typedef struct dlnode Dlnode;
typedef struct dllist Dllist;
Sllist *slCreate(void);
Dllist *dlCreate(void);
int sllinsertasFirst(Sllist *l, void *data);
int dllinsertasFirst(Dllist *l, void *data);
int sllcircinsertasFirst(Sllist *l, void *data);
int dllcircinsertasFirst(Dllist *l, void *data);
int sllinsertasLast(Sllist *l, void *data);
int dllinsertasLast(Dllist *l, void *data);
int sllcircinsertasLast(Sllist *l, void *data);
int dllcircinsertasLast(Dllist *l, void *data);
int sllinsertEnesimal(Sllist *l, void *data, int pos);
int DllinsertEnesimal(Dllist *l, void *data, int pos);
int sllcircinsertEnesimal(Sllist *l, void *data,int pos);
void printsllistcirc(Sllist *l);
void printsllist(Sllist *l);
void printdllist(Dllist *l);
void printdllistcirc(Dllist *l);
int slladdSpec(Sllist *l, void *key, int(*cmp)(void *, void*), void *data);
int dlladdSpec(Dllist *l, void *key, int(*cmp)(void *, void*), void *data);
int slladdSpeccirc(Sllist *l, void *key, int(*cmp)(void *, void*), void *data);
void *dllGetfirst(Dllist *l);
void *dllGetnext(Dllist *l);
void *sllGetfirst(Sllist *l);
void *sllGetnext(Sllist *l);
int dlladdSpeccirc(Dllist *l, void *key, int(*cmp)(void *, void*), void *data);
int slladdbeforeSpec(Sllist *l, void *key, int(*cmp)(void *, void*), void *data);
int dlladdbeforeSpec(Dllist *l, void *key, int(*cmp)(void *, void*), void *data);
int slladdbeforeSpeccirc(Sllist *l, void *key, int(*cmp)(void *, void*), void *data);
int dlladdbeforeSpeccirc(Dllist *l, void *key, int(*cmp)(void *, void*), void *data);
void *RemoveNoDoMeio(Dllist *l);
int ContaDuplicadosDuplicated(Sllist *l1, int(*cmp)(void *, void*));
int EInversa(Sllist *l1, Sllist *l2);
int EInversaDuplamente(Dllist *l1, Dllist *l2);
Dllist *PegaElementosIguais(Dllist *l1, Dllist *l2, Dllist *l3);
void *RemoveKEsimo(Dllist *l,  int k);
void inverte(Dllist *l1, Dllist *l2);
Sllist *removeImpar(Sllist *l1);
int RemoveOCaraEOSVizinhos(Dllist *l, void *key, int (*cmp)(void*, void*));
int incluirintercalado(Sllist *l1, Sllist *l2);
int ajeitarLista(Dllist *l);
int transformalista(Dllist *l);
int copyduplamente(Dllist *l1, Dllist *l2);
void *RemoveKEsimosll(Sllist *l,  int k);
int GetNumberOfOcurrences(Sllist *l, void *key, int (*cmp)(void*, void*));



#endif