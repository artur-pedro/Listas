#include "anselmodream.h"
// --------------------------------------------------------------//

                        // simplesmente encadeada //

typedef struct slnode{
    void *data;
    struct slnode *next;
} SLNode;

// ------------------------ //

typedef struct sllist{
    SLNode *first;
    SLNode *cur;
}Sllist;
// ------------------------ //


// -------------------------------------------------------------//

                        // duplamente encadeada //

typedef struct dlnode{
    void *data;
    struct dlnode *next, *prev;
} DLNode;


// ---------------------------- //
typedef struct dllist{
    DLNode *first;
    DLNode *cur;
}Dllist;
// ------------------------ //

Sllist *slCreate(void) {
    Sllist *l = (Sllist *)malloc(sizeof(Sllist));
    if(l != NULL) {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}
Dllist *dlCreate(void) {
    Dllist *l = (Dllist *)malloc(sizeof(Dllist));
    if(l != NULL) {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

// 1 questão) inserir novo dado na primeira posição na lista na primeira posição

// simplismente encadeada
void *dllGetfirst(Dllist *l) {
    if (l != NULL && l->first != NULL) {
        l->cur = l->first;  
        return l->cur->data;  
    }
    return NULL;
}
void *dllGetnext(Dllist *l) {
    if (l != NULL && l->cur != NULL && l->cur->next != NULL) {
        l->cur = l->cur->next; 
        return l->cur->data;  
    }
    return NULL;
}
void *sllGetfirst(Sllist *l) {
    if (l != NULL && l->first != NULL) {
        l->cur = l->first;  
        return l->cur->data;  
    }
    return NULL;
}
void *sllGetnext(Sllist *l) {
    if (l != NULL && l->cur != NULL && l->cur->next != NULL) {
        l->cur = l->cur->next; 
        return l->cur->data;  
    }
    return NULL;
}
int sllinsertasFirst(Sllist *l, void *data) {
    if(l!=NULL && data != NULL) {
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
        if(novo != NULL) {
            novo->data = data;
            novo->next = l->first;
            l->first = novo;
            return TRUE;
        }

    }
    return FALSE;
}
// duplamente encadeada
int dllinsertasFirst(Dllist *l, void *data) {
    if(l!=NULL && data != NULL) {
        DLNode *novo = (DLNode*)malloc(sizeof(DLNode));
        if(novo != NULL){
            novo->data = data;
            novo->next = l->first;
            novo->prev = NULL;
            if(l->first != NULL) {
                l->first->prev = novo;
            }
            l->first = novo;
            return TRUE;
        }
    }
    return FALSE;
}
// circular simplismente encadeada
int sllcircinsertasFirst(Sllist *l, void *data) {
    SLNode *prev;   
    if(l!=NULL && data != NULL) {
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
        if(novo != NULL) {
            prev = l->first;
            if(prev != NULL) {
                while(prev != NULL && prev->next != l->first) {
                    prev = prev->next;
                }
            }
            novo->data = data;
            if(l->first != NULL) {
                prev->next = novo;
                novo->next = l->first;
            }
            else {
                novo->next = novo;
            }
            l->first = novo;
            return TRUE;         
        }
    }
    return FALSE;
}
// circular duplamente encadeada
int dllcircinsertasFirst(Dllist *l, void *data) {
    DLNode *prev;   
    if(l!=NULL && data != NULL) {
        DLNode* novo = (DLNode*)malloc(sizeof(DLNode));
        if(novo != NULL) {
            prev = l->first;
            while(prev != NULL && prev->next != l->first) {
                    prev = prev->next;
            }
            novo->data = data;
            if(l->first != NULL) {
                prev->next = novo;
                novo->next = l->first;
                novo->prev = prev;
            }
            else {
                novo->next = novo;
                novo->prev = novo;
            }
            l->first = novo;
            return TRUE;         
        }
    
    }
    return FALSE;
}
// b) adicionar como ultimo

// simplesmente encadeada
int sllinsertasLast(Sllist *l, void *data) {
    if(l!=NULL && data != NULL) {
        SLNode *actual, *prev;
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL) {
                    prev = actual;
                    actual = actual->next;
                }
                novo->data = data;
                novo->next = NULL;
                if(l->first != NULL) {  
                    prev->next = novo;
                }
                else {
                    l->first = novo;
                }
                return TRUE;
        }
    }
    return FALSE;
}
//duplamente encadeada
int dllinsertasLast(Dllist *l, void *data) {
    if(l!=NULL && data != NULL) {
        DLNode *actual, *prev;
        DLNode* novo = (DLNode*)malloc(sizeof(DLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL) {
                    prev = actual;
                    actual = actual->next;
                }
                novo->data = data;
                novo->next = NULL;
                novo->prev = prev;
                if(l->first != NULL) {  
                    prev->next = novo;
                }
                else {
                    l->first = novo;
                }
                return TRUE;
        }
    }
    return FALSE;
}
//simplesmente encadeada circular
int sllcircinsertasLast(Sllist *l, void *data) {
    if(data != NULL) {
        SLNode *actual, *prev;
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL) {
                    prev = actual;
                    actual = actual->next;
                }
                novo->data = data;
                if(l->first != NULL) {  
                    prev->next = novo;
                    novo->next = l->first;
                }
                else {
                    l->first = novo;
                    novo->next = novo;
                }
                return TRUE;
        }
    }
    return FALSE;
}
// duplamente encadeada circular
int dllcircinsertasLast(Dllist *l, void *data) {
    if(l!=NULL && data != NULL) {
        DLNode *actual, *prev;
        DLNode* novo = (DLNode*)malloc(sizeof(DLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL) {
                    prev = actual;
                    actual = actual->next;
                }
                novo->data = data;
                if(l->first != NULL) {  
                    novo->prev = prev;
                    prev->next = novo;
                    novo->next = l->first;
                }
                else {
                    novo->next = novo;
                    novo->prev = novo;
                    l->first = novo;       
                }
                return TRUE;
        }
    }
    return FALSE;
}
// c) insert na posição enésima

// implismente encadeada
int sllinsertEnesimal(Sllist *l, void *data,int pos) {
    if(l!=NULL && data != NULL && pos >= 0) {
        SLNode *actual, *prev;
        int cont=0;
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL && cont < pos) {
                    prev = actual;
                    actual = actual->next;
                    cont++;
                }
                novo->data = data;
                if(prev != NULL) {
                    prev->next = novo;
                }
                else {
                    l->first = novo;
                }
                novo->next = actual;
                return TRUE;
            }
    }
    return FALSE;
}
// duplamente encadeada
int DllinsertEnesimal(Dllist *l, void *data,int pos) {
    if(l!=NULL && data != NULL && pos >= 0) {
        DLNode *actual, *prev;
        int cont=0;
        DLNode* novo = (DLNode*)malloc(sizeof(DLNode));
            if(novo != NULL) {
                actual = l->first;
                prev = NULL;
                while(actual != NULL && cont < pos) {
                    prev = actual;
                    actual = actual->next;
                    cont++;
                }
                novo->data = data;
                if(prev != NULL) { // se eu quero adicionar em uma posição que n seja a primeira
                    prev->next = novo;
                    novo->prev= prev;
                }
                else {             // se eu quero adicionar na primeira posição
                    l->first = novo;
                    novo->prev = NULL;
                }
                novo->next = actual;  // o next sempre recebe o ectual
                return TRUE;
            }
    }
    return FALSE;
}
// simplesmente encadeada circular
int sllcircinsertEnesimal(Sllist *l, void *data, int pos) {
    if(l!=NULL && data != NULL && pos >= 0) {
        SLNode *actual, *prev;
        int cont=0;
        SLNode* novo = (SLNode*)malloc(sizeof(SLNode));
            if(novo != NULL) {
                prev = l->first;
                if(l->first != NULL) {
                    actual = l->first->next; 
                    while(actual != l->first && cont < pos-1) {
                        prev = actual;
                        actual = actual->next;
                        cont++;
                    }
                }
                novo->data = data;
                if(prev != NULL) {
                    if(pos == 0) {
                        novo->next = l->first;
                        actual = l->first;
                        while(actual->next != l->first) {
                            actual = actual->next;
                        }
                        actual->next = novo;
                        l->first = novo;
                    }
                    else {
                        prev->next = novo;
                        novo->next = actual;
                    }
                }
                else {
                    l->first = novo;
                    novo->next = novo;
                }
                return TRUE;
            }
    }
    return FALSE;
}
int dllcircinsertEnesimal(Dllist *l, void *data, int pos) {
    if(l!=NULL && data != NULL && pos >= 0) {
        DLNode *actual, *prev;
        int cont=0;
        DLNode* novo = (DLNode*)malloc(sizeof(DLNode));
            if(novo != NULL) {
                prev = l->first;
                if(l->first != NULL) {
                    actual = l->first->next; 
                    while(actual != l->first && cont < pos-1) {
                        prev = actual;
                        actual = actual->next;
                        cont++;
                    }
                }
                novo->data = data;
                if(prev != NULL) {
                    if(pos == 0) {
                        novo->next = l->first;
                        actual = l->first;
                        while(actual->next != l->first) {
                            actual = actual->next;
                        }
                        actual->next = novo;
                        l->first = novo;
                    }
                    else {
                        prev->next = novo;
                        novo->next = actual;
                    }
                novo->prev = actual;
                }
                else {
                    l->first = novo;
                    novo->next = novo;
                    novo->prev = novo;
                }
                return TRUE;
            }
    }
    return FALSE;
} 
// c  adicionar após um nó identificado por uma chave key
// simplismente encadeada
int slladdSpec(Sllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    SLNode *prev, *next;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            SLNode *novo = (SLNode *)malloc(sizeof(SLNode));
            if(novo != NULL) {
                prev = l->first;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != NULL) {
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    next = prev->next;
                    novo->data = data;
                    novo->next = next;
                    prev->next = novo;
                    return TRUE;
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
// duplamente encadeada
int dlladdSpec(Dllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    DLNode *prev, *next;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            DLNode *novo = (DLNode *)malloc(sizeof(DLNode));
            if(novo != NULL) {
                prev = l->first;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != NULL) {
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    next = prev->next;
                    novo->data = data;
                    novo->next = next;
                    prev->next = novo;
                    novo->prev = prev;
                    if(next != NULL) {
                        next->prev = novo;
                    }
                    return TRUE;
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
//simplesmente encadeada circular
int slladdSpeccirc(Sllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    SLNode *beforeprev, *prev, *next;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            SLNode *novo = (SLNode *)malloc(sizeof(SLNode));
            if(novo != NULL) {
                beforeprev = l->first;
                prev = beforeprev->next;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev != l->first && prev != NULL) {
                    prev = prev->next;
                    stat = cmp(key, prev->data);   // prev vai me retornar o elemento ou o ultimo elemento da lista
                }
                if( stat == TRUE) {
                     novo->data = data;
                    if(prev != NULL) {
                        next = prev->next;  // next vai receber o next do elemento retornado // seta o novo
                        novo->next = next; // novo->next vai receber o next do elemento encontrado (inserindo o novo no meio deles)
                        prev->next = novo; // precisa fazer o next-> prev apontar para o novo e o prev do novo apontar para o prev
                    }
                    else {
                        l->first->next = novo;
                        novo->next  = l->first;
                    }
                return TRUE;
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
int dlladdSpeccirc(Dllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    DLNode *beforeprev, *prev, *next;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            DLNode *novo = (DLNode *)malloc(sizeof(DLNode));
            if(novo != NULL) {
                beforeprev = l->first;
                prev = beforeprev->next;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev != l->first && prev != NULL) {
                    prev = prev->next;
                    stat = cmp(key, prev->data); 
                }
                if( stat == TRUE) {
                     novo->data = data;
                    if(prev != NULL) {
                        next = prev->next;  
                        novo->next = next; 
                        prev->next = novo;
                        novo->prev = prev;
                        next->prev = novo; 
                    }
                    else {
                        l->first->next = novo;
                        novo->next  = l->first;
                        l->first->prev =novo;
                    }
                    if(next == l->first) {
                        l-> first = novo;
                    }           
                return TRUE;
                }

                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
// e) Antes de um nó identificado por uma chave key//
int slladdbeforeSpec(Sllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    SLNode *beforeprev,*prev;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            SLNode *novo = (SLNode *)malloc(sizeof(SLNode));
            if(novo != NULL) {
                prev = l->first;
                beforeprev = NULL;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != NULL) {
                    beforeprev = prev;
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    novo->data = data;
                    novo->next = prev;
                    if(beforeprev != NULL){
                    beforeprev->next = novo;
                    }
                    else {
                    l->first =  novo;
                    } 
                return TRUE; 
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
int dlladdbeforeSpec(Dllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    DLNode *beforeprev,*prev;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            DLNode *novo = (DLNode *)malloc(sizeof(DLNode));
            if(novo != NULL) {
                prev = l->first;
                beforeprev = NULL;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != NULL) {
                    beforeprev = prev;
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    novo->data = data;
                    novo->next = prev;
                    novo -> prev = beforeprev;
                    prev->prev = novo;
                    if(beforeprev != NULL){
                    beforeprev->next = novo;

                    }
                    else {
                    l->first =  novo;
                    } 
                return TRUE; 
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
int slladdbeforeSpeccirc(Sllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    SLNode *beforeprev,*prev;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            SLNode *novo = (SLNode *)malloc(sizeof(SLNode));
            if(novo != NULL) {
                prev = l->first;
                beforeprev = NULL;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != l->first) {
                    beforeprev = prev;
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    novo->data = data;
                    novo->next = prev;
                    if(beforeprev != NULL){
                    beforeprev->next = novo;
                    }
                    else {
                    prev = l-> first;
                    while(prev-> next != l->first) {
                        prev = prev->next;
                    }
                    prev->next = novo;
                    l->first =  novo;
                    } 
                return TRUE; 
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
int dlladdbeforeSpeccirc(Dllist *l, void *key, int(*cmp)(void *, void*), void *data) {
    int stat;
    DLNode *beforeprev,*prev;
    if(l != NULL && key != NULL) {
        if(l->first != NULL) {
            DLNode *novo = (DLNode *)malloc(sizeof(DLNode));
            if(novo != NULL) {
                prev = l->first;
                beforeprev = NULL;
                stat = cmp(key, prev->data);
                while(stat != TRUE && prev->next != l->first) {
                    beforeprev = prev;
                    prev = prev->next;
                    stat = cmp(key, prev->data);
                }
                if( stat == TRUE) {
                    novo->data = data;
                    novo->next = prev;
                    if(beforeprev != NULL){ 
                        beforeprev->next = novo;
                        novo->prev = beforeprev;
                        return TRUE;
                    }
                    else {
                        DLNode *last = l->first->prev;
                        novo->prev = last;
                        last->next = novo;
                        l->first->prev = novo;
                        l->first = novo;
                        return TRUE;
                    }
                }
                else {
                    free(novo);
                    return FALSE;
                }
            }
        }
    }
    return FALSE;
}
// 2023.2

void *RemoveNoDoMeio(Dllist *l) {
    DLNode *aux, *next, *saved;
    if(l!=NULL && l->first != NULL) {
        DLNode *prev = l->first;
        int cont = 1;
        int pos =0;
        while(prev->next != NULL) { // contando os elementos da lista
            prev = prev->next;
            cont++;
        }
        if(cont % 2 == 0) {
           pos = (cont)/2;
        }
        else {
           pos = (cont+1)/2;
        }
        prev = l->first;
        cont = 1;
        while(cont != pos) { // contando os elementos da lista está certo  
            cont++;
            prev = prev->next;
        }
        aux = prev->prev;
        next = prev->next;
        if(aux != NULL) {
            next->prev = aux;
            aux->next = next;      
        }
        else {
            if(prev->next != NULL) {
                l->first = next;
                next->prev = NULL;
            }
            else {
                l->first = NULL;
            }
        }
    saved = prev->data;
    free(prev);
    return saved;
    }
    return NULL;
}
int ContaDuplicadosDuplicated(Sllist *l, int(*cmp)(void *, void*)) {
    if(l != NULL && l->first != NULL) {
        int contrep=0;
        SLNode *actual = l->first;
        SLNode *next;
        Slnode *temp = l->first->next;
        int stat;
        int contnodes =1;
        while(temp != l->first) {
            temp = temp->next;
            contnodes++; 
        }

        for(int i =0; i<contnodes; i++) {
            next = actual->next;
            for(int j=i+1; j < contnodes; j++) {
                stat = cmp(actual->data, next->data);
                if(stat == TRUE) {
                    contrep++;
                    break;
                }
                
                next = next->next;
            }
            actual = actual->next;
        } 

    return contrep;
    }
    return FALSE;
}
int EInversa(Sllist *l1, Sllist *l2) {
    if(l1!= NULL && l2 != NULL) {
        SLNode *current1  = l1->first;
        SLNode *current2  = l2->first;
        int cont1 = 0;
        int cont2 = 0;
        while(current1 != NULL) {
            cont1++;
            current1 = current1->next;
        }
        while(current2!=NULL) {
            cont2++;
            current2 = current2->next;
        }
        if(cont1 > cont2) {
            return -2;
        }
        else if(cont2 > cont1) {
            return -1;
        }
        else {
            SLNode *prev, *next;
            current2 = l2->first;
            prev = NULL;
            next = NULL;
            while(current2!=NULL) {
                next = current2->next;
                current2->next = prev;
                prev = current2;
                current2 = next;
            }
            l2->first = prev;
            current1 = l1->first;
            current2 = l2->first;
            while(current1!=NULL) {
                if(current1->data != current2->data) {
                    return 0;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
        return 1;
        }
}
return 0;
}
// 2 prova
int EInversaDuplamente(Dllist *l1, Dllist *l2) {
    if (l1 != NULL && l2 != NULL) {
        DLNode *current1 = l1->first->next;
        DLNode *current2 = l2->first->next;
        int cont1 = 1;
        int cont2 = 1;
        do {
           
            current1 = current1->next;
             cont1++;
        } while (current1 != l1->first);
        do {
            
            current2 = current2->next;
            cont2++;
        } while (current2 != l2->first);

        if (cont1 > cont2) {
            return -2; 
        } else if (cont2 > cont1) {
            return -1; 
        } else {
            current1 = l1->first;
            current2 = l2->first->prev;
            do {
                if (*(int *)current1->data != *(int *)current2->data) {
                    return 0; 
                }
                current1 = current1->next;
                current2 = current2->prev;
            } while (current1 != l1->first && current2 != l2->first->prev);
        }

        return 1; 
    }

    return 0; 
}



Dllist *MoveNewNodes(Dllist *l1, Dllist *l2, void *key, int (*cmp)(void*, void*)) {
    if(l1!=NULL && l2!=NULL) {
        int stat;
        DLNode *next, *prev, *spec;
        spec = l2->first;
        while(spec!=NULL) {
            stat = cmp(spec->data, key);
            if(stat == -1) {
                prev = spec->prev;
                next = spec->next;
                if(spec == l2->first)  {
                    l2->first = next;
                    if(l2->first!= NULL) {
                        l2->first->prev = NULL;
                    }
                }
                else {
                    if(next!=NULL) {
                        next->prev = spec->prev;
                    }
                    if(prev!= NULL) {
                        prev->next = next;
                    }
                }
                if(l1->first!= NULL) {
                    l1->first->prev = spec;
                    }
                    spec->prev = NULL;
                    spec->next = l1->first;
                    l1->first = spec;
                }
                spec = next;
            }
            return l1;
            
        }
        return NULL;

    }
Dllist *PegaElementosIguais(Dllist *l1, Dllist *l2, Dllist *l3) {
    if(l1 != NULL && l2 != NULL) {
        DLNode *current1, *current2, *prev, *next;
        current1 = l1->first;
        while(current1 != NULL) {
            current2 = l2->first;
            while(current2 != NULL) {
                if(*(int *)current1->data == *(int *)current2->data) {
                    prev = current1->prev;
                    next = current1->next;
                    if(prev != NULL) {
                        prev->next = next;
                            
                        }
                    else {
                            l1->first = next;
                    }
                    if(next != NULL) {
                            next->prev = prev;
                        }
                    current1->next = l3->first;
                    current1->prev = NULL;
                    if(l1->first !=NULL) {
                        l3->first->prev = current1;
                    }
                    l3->first =current1;
                    break;
                    }
            current2 = current1->next;
            }
            current1 = current1->next;
            }
            return l3;
            
        }
        return NULL;
    }
void *RemoveKEsimo(Dllist *l,  int k) {
    if(l != NULL && k > 0) {
        DLNode *current;
        current = l->first;
        int cont = 0;
        do {
            current = current->next;
            cont++;
        }while(cont<k && current->next != l->first);
        if (cont != k) return NULL;
        DLNode *prev = current->prev;
        DLNode *next = current->next;
        void *data = current->data;
        if(current == l->first) {
            if(next == l->first) {
                l->first = NULL;
            }
            else {
                l->first = next;
            }
        }
        if(prev!= NULL) {
            prev->next = next;
        }
        
        if(next!= NULL) {
            next->prev = prev;
        }
        free(current);
        return data;
    }
    return NULL;
}
void inverte(Dllist *l1, Dllist *l2) {
    if(l1!= NULL && l2!= NULL) {
        DLNode *current, *next, *prev;
        current = l1->first;
        while(current!=NULL) {
            next = current->next;
            prev = current->prev;
            if(prev!=NULL) {
                prev->next = next;
            }
            else {
                l1->first = next;
            }
            if(next!= NULL) {
                next->prev = prev;
            }
            if(l2->first!=NULL) {
               l2->first->prev = current;
            }
             current->next = l2->first;
             current->prev = NULL;
             l2->first = current;
             current = next;
        }

    }
}
Sllist *removeImpar(Sllist *l1) {
    if(l1 != NULL) {
        SLNode *current, *next, *prev;
        int cont = 1;
        prev = NULL;
        current = l1->first;
        while(current != NULL) {
            next = current->next;
            if(cont % 2 ==1) {
                if(prev != NULL) {
                    prev->next = next;
                } 
                else {
                    l1->first = next;
                }  
            } else {
                 prev = current;
            }
            current = next;
            cont++;
        }

    return  l1;
    }
    return NULL;
}

int RemoveOCaraEOSVizinhos(Dllist *l, void *key, int (*cmp)(void*, void*)) {
    if (l != NULL) {
        DLNode *current = l->first;
        DLNode *prevprev;
        DLNode *nextnext;
        int stat = 0;
        while (current != NULL && stat != TRUE) {
            stat = cmp(key, current->data);
            if (stat == TRUE) {
                DLNode *prev = current->prev;
                DLNode *next = current->next;
                if (prev != NULL) {
                    prev->next = next;
                    if(prev->prev!= NULL) {
                        prevprev = prev->prev;
                        if(next!= NULL) {
                            nextnext = next->next;
                            prevprev->next = nextnext;
                        }
                        else {
                            prevprev->next = NULL;
                        }
                    }
                    else {
                        if(next!= NULL) {
                            l->first = next->next;
                        }
                        else {
                            l->first = next;
                        }
                    }
                } else {
                    if(next!= NULL) {
                        l->first = next->next;
                        if(next->next != NULL) {
                            next->next->prev = NULL;
                        }
                        }
                    else {
                        l->first = next;
                        }
                }
                if (next != NULL) {
                    nextnext = next->next;
                    if(nextnext != NULL) {
                        if(prev!= NULL) {
                            nextnext->prev = prev->prev;
                        }
                } 
                }
                else {
                    if(prev!= NULL) {
                        if(prev->prev != NULL) {
                            prev->prev->next = NULL;
                        }
                        else {
                            l->first = NULL;
                        }
                    }
                    
                }  
            return TRUE;
        }
        current = current->next;
        }
        
    }
    return FALSE;
}
int incluirintercalado(Sllist *l1, Sllist *l2) {
    if(l1!=NULL && l2!=NULL) {
        int index=1;
        SLNode *prev1, *current1, *current2, *next;
        prev1 = NULL;
        current1 = l1->first;
        current2 = l2->first;
         do{
            if(current1 != l1->first) {
                next= current2->next;
                current2->next = current1;
                if(prev1 != NULL) {
                    prev1->next = current2;
                }
                prev1 = current2;
                current2 = next;
        }
        index++;
        prev1 = current1;
        current1 = current1->next;
        }while(current1 != l1->first);
        prev1->next = current2;
        current2->next = current1;
        return TRUE;
    }
    return FALSE;
}
int incluirintercaladodll(Dllist *l1, Dllist *l2) {
    if(l1!=NULL && l2!=NULL) {
        DLNode *current1, *current2, *next, *next2;
        current1 = l1->first;
        current2 = l2->first;
         do{
            next= current1->next;
            next2= current2->next;
            current2->next = current1->next;
            current2->prev = current1; 
            current1->next->prev = current2;
            current1->next = current2;
            current2 = next2;
            current1 = next;
        }while(current1->next != l1->first);
        current2->next = l1->first;
        current2->prev = current1;
        current1->next =current2;
        l1->first->prev = current2;
        return TRUE;
    }
    return FALSE;
}
int ajeitarLista(Dllist *l) {
    if(l != NULL) {
        DLNode *current, *prev, *last;
        if(l->first != NULL){
            prev = NULL;
            current = l->first;
            last = l->first;
            while(last->next!= NULL) {
            last = last->next;
            }
            if(last != NULL && l->first != NULL)
            {
            last->next = l->first;
            l->first->prev = last;
            }
            // até aqui tá certo
            
            prev = l->first;
            current = prev->next;
            while(current!= l->first) {
                current->prev = prev;
                prev = current;
                current = current->next;
            }
            return TRUE;
        }
    }
    return FALSE;
}
int transformalista(Dllist *l) {
    if(l!= NULL) {
        DLNode *prev, *current;
        if(l->first!=NULL) {
            //Tirando a circularidade
            prev=l->first->prev;
            prev->next = NULL;
            l->first->prev = NULL;
            current=l->first->next;
            prev = l->first;
            // tirando os prev da lista
            while(current!=NULL) {
                current->prev = NULL;
                current = current->next;
            }
        return TRUE;
        } 
    }
    return FALSE;
}
int copyduplamente(Dllist *l1, Dllist *l2) {
    if(l1!= NULL && l2 != NULL) {
        DLNode *current, *next;
        current = l1->first;
        while(current != NULL){
            next = current->next;
            current->prev = NULL;
            current->next = l2->first;
            if(l2->first!= NULL){
                l2->first->prev = current;
            }
            l2->first = current;
            current = next;
        }
        return TRUE;
    }
    return FALSE;
}
void *RemoveKEsimosll(Sllist *l,  int k) {
    if(l!=NULL) {
        SLNode *current, *prev;
        void *data;
        current = l->first;
        prev = NULL;
        int cont=1;
        while(current!=NULL && cont != k) {
            cont++;
            prev = current;
            current = current->next;
        }
        if(current!= NULL) {
            data = current->data;
            if(prev != NULL) {
                prev->next = current->next; 
            }
            else {
                l->first = current->next;
            }
            return data;
            free(current);
        }
    }
    return NULL;
}
void dllIntercalar2(Dllist *l1, Dllist *l2) {
    DLNode *current1,*current2, *next1, *next2;
    if (l1 != NULL || l2 != NULL) {
        if (l1->first != NULL && l2->first != NULL) {
            current1 = l1->first;
            next1 = current1->next;
            current2 = l2->first; next2 = current2->next;
            while (next1 != l1->first) {
                    current1->next = current2;
                    current2->prev = current1;
                    current2->next = next1;
                    next1->prev = current2;
                    current1 = next1; 
                    current2 = next2;
                    next1 = next1->next; 
                    next2 = next2->next;
            }
            while(next2 != l2->first) {
                current2->next = next2; 
                next2->prev =current2;
            }
            if (next1 == l1->first) {
                current1->next = current2;
                current2->prev = current1;
            } else {
                current2->next = current1;
                current1->prev = current2;
            }
            l1->first = l1->first->prev;
        }
    }
}
int GetNumberOfOcurrences(Sllist *l, void *key, int (*cmp)(void*, void*)) {
    if(l!=NULL) {
        SLNode *current;
        int cont = 0;
        current = l->first->next;
        int stat = cmp(current->data, key);
        if(stat == TRUE) {
            cont++;
        }
        while(current!=l->first) {
            current = current->next;
            stat = cmp(current->data, key);
            if(stat == TRUE) {
                cont++;
            }
        } 
        return cont;
    }
    return FALSE;
}
DLNode* createNode(void *data) {
    DLNode *newNode = (DLNode*)malloc(sizeof(DLNode));  // Aloca memória para o novo nó
    if (newNode != NULL) {
        newNode->data = data;  // Atribui o ponteiro genérico ao campo 'data'
        newNode->next = NULL;  // Inicializa o próximo nó como NULL
        newNode->prev = NULL;  // Inicializa o nó anterior como NULL
    }
    return newNode;  // Retorna o ponteiro para o novo nó criado
}


void printsllist(Sllist *l) {
    if (l != NULL && l->first != NULL) {
        SLNode *node = l->first;
        while (node != NULL) {
            printf("%d -> ", *(int *)(node->data));
            node = node->next;
        }
        printf("NULL\n"); // Indica o final da lista
    } else {
        printf("Lista vazia\n");
    }
}
void printdllist(Dllist *l) {
    if (l != NULL && l->first != NULL) {
        DLNode *node = l->first;
        while (node != NULL) {
            printf("%d -> ", *(int *)(node->data));
            node = node->next;
        }
        printf("NULL\n"); // Indica o final da lista
    } else {
        printf("Lista vazia\n");
    }
}
void printsllistcirc(Sllist *l) {
    if (l != NULL && l->first != NULL) {
        SLNode *node = l->first;
        do {
            printf("%d -> ", *(int *)(node->data));
            node = node->next;
        } while (node != l->first);
        printf("(head: %d)\n", *(int *)(l->first->data));
    } else {
        printf("Lista está vazia.\n");
    }
}
void printdllistcirc(Dllist *l) {
    if (l != NULL && l->first != NULL) {
        DLNode *node = l->first;
        do {
            printf("%d -> ", *(int *)(node->data));
            node = node->next;
        } while (node != l->first);
        printf("(head: %d)\n", *(int *)(l->first->data));
        printf("(l->first->prev: %d)\n", *(int *)(l->first->prev->data)); // Indicate the start of the list
    } else {
        printf("Lista vazia\n");
    }
}
int compint(void *key, void *pacote) {
    int *g = (int*) pacote;
    int *key_codigoNumerico = (int*) key;
    if(key != NULL && pacote != NULL) {
        if(*key_codigoNumerico == *g) {
            return TRUE;
        }
    }
    return FALSE;
}
