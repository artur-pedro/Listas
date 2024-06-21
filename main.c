#include "anselmodream.c"
/* 
//test sll
int main() {
    Sllist *list = slCreate();
    int node1_data = 5;
    int new_data = 20;
    sllcircinsertasLast(list, &node1_data);
    printf("Original list:\n");
    printsllist(list);
    slladdbeforeSpec(list,  &node1_data, compint, &new_data);
    printf("List after slladdSpeccirc:\n");
    printsllist(list);
    int new_data1 = 40;
    slladdbeforeSpec(list,  &new_data, compint, &new_data1);
    printf("List after slladdSpeccirc:\n");
    printsllist(list);
    int new_data2 = 50;
    slladdbeforeSpec(list,  &node1_data, compint, &new_data2);
    printf("List after slladdSpeccirc:\n");
    slladdbeforeSpec(list,  &new_data1, compint, &new_data2);
    printsllist(list);
}
*/ 
//test dll
/* 
int main() {
    Dllist *list = dlCreate();
    int node1_data = 5;
    int new_data = 20;
    dllinsertasFirst(list, &node1_data);
    printf("Original list:\n");
    printdllist(list);
    dlladdbeforeSpec(list,  &node1_data, compint, &new_data);
    printf("List after dlladdSpeccirc:\n");
    printdllist(list);
    int new_data1 = 40;
    dlladdbeforeSpec(list,  &new_data, compint, &new_data1);
    printf("List after dlladdSpeccirc:\n");
    printdllist(list);
    int new_data2 = 50;
    dlladdbeforeSpec(list,  &node1_data, compint, &new_data2);
    printf("List after dlladdSpeccirc:\n");
    dlladdbeforeSpec(list,  &new_data1, compint, &new_data2);
    printdllist(list);
}
*/
// test circ sll
/*
int main() {
    Sllist *list = slCreate();
    int node1_data = 5;
    int new_data = 20;
    sllcircinsertasFirst(list, &node1_data);
    printf("Original list:\n");
    printsllistcirc(list);
    slladdbeforeSpeccirc(list,  &node1_data, compint, &new_data);
    printf("List after slladdSpeccirc:\n");
    printsllistcirc(list);
    int new_data1 = 40;
    slladdbeforeSpeccirc(list,  &new_data, compint, &new_data1);
    printf("List after slladdSpeccirc:\n");
    printsllistcirc(list);
    int new_data2 = 50;
    slladdbeforeSpeccirc(list,  &node1_data, compint, &new_data2);
    printf("List after slladdSpeccirc:\n");
    slladdbeforeSpeccirc(list,  &new_data1, compint, &new_data2);
    printsllistcirc(list);
}
*/

// test circ dll
/*
int main() {
    Dllist *list = dlCreate();
    int node1_data = 5;
    int node2_data = 10;
    int new_data = 20;
    dllcircinsertasFirst(list, &node1_data);
    printf("Original list:\n");
    printdllistcirc(list);
    dllcircinsertasFirst(list, &node2_data);
    printf("Original list:\n");
    printdllistcirc(list);
    dlladdbeforeSpeccirc(list,  &node1_data, compint, &new_data);
    printf("List after slladdSpeccirc:\n");
    printdllistcirc(list);
    int new_data1 = 40;
    dlladdbeforeSpeccirc(list,  &new_data, compint, &new_data1);
    printf("List after slladdSpeccirc:\n");
    printdllistcirc(list);
    int new_data2 = 50;
    dlladdbeforeSpeccirc(list,  &node1_data, compint, &new_data2);
    printdllistcirc(list);
    printf("List after slladdSpeccirc:\n");
    dlladdbeforeSpeccirc(list,  &node2_data, compint, &new_data2);
    printf("List after slladdSpeccirc:\n");
    printdllistcirc(list);
}
*/

/*
int main() {
    Dllist *list = dlCreate();
    int node1_data = 5;
    int node2_data = 10;
    int new_data = 20;
    dllinsertasLast(list, &node1_data);
    printf("Original list:\n");
    printdllist(list);
    dllinsertasLast(list, &node2_data);
    printf("Original list:\n");
    printdllist(list);
    dlladdbeforeSpec(list,  &node1_data, compint, &new_data);
    printf("List after slladdSpeccirc:\n");
    printdllist(list);
    int new_data1 = 40;
    dlladdbeforeSpec(list,  &new_data, compint, &new_data1);
    printf("List after slladdSpeccirc:\n");
    printdllist(list);
    int new_data2 = 50;
    dlladdbeforeSpec(list,  &node1_data, compint, &new_data2);
    printdllist(list);
    printf("List after slladdSpeccirc:\n");
    dlladdbeforeSpec(list,  &node2_data, compint, &new_data2);
    printf("List after slladdSpeccirc:\n");
    printdllist(list);
    RemoveNoDoMeio(list);
    printdllist(list);
    RemoveNoDoMeio(list);
    printdllist(list);
    RemoveNoDoMeio(list);
    printdllist(list);
    RemoveNoDoMeio(list);
    printdllist(list);
    RemoveNoDoMeio(list);
    printdllist(list);
    void *last = RemoveNoDoMeio(list);
    printdllist(list);
    printf("%d", *(int*)last);
}
*/
/*
int main() {
    Sllist *list = slCreate();
    int node1_data = 5;
    int node2_data = 10;
    sllcircinsertasLast(list, &node1_data);
    printsllistcirc(list);
    sllcircinsertasFirst(list, &node2_data);
    sllcircinsertasFirst(list, &node2_data);
    sllcircinsertasFirst(list, &node2_data);
    sllcircinsertasFirst(list, &node1_data);
    int num = ContaDuplicadosDuplicated(list, compint);
    printsllistcirc(list);
    printf("\n");
    printf("%d", num);    
}

int main() {
    // Criação da lista duplamente encadeada circular 1
    Dllist *list1 =  dlCreate();
    // Inserção de elementos na lista 1 usando dllinsertasLast
    int data1[] = {40, 30, 20, 10};
    int numElements1 = sizeof(data1) / sizeof(data1[0]);
    for (int i = 0; i < numElements1; i++) {
        dllcircinsertasFirst(list1, &data1[i]);
    }

    // Criação da lista duplamente encadeada circular 2
    Dllist *list2 = dlCreate();
    // Inserção  elementos na lista 2 usando dllinsertasLast
    int data2[] = {10, 20, 30, 40}; // lista inversa da lista 1
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        dllcircinsertasFirst(list2, &data2[i]);
    }
    printdllistcirc(list1);
    printdllistcirc(list2);
    // Chamada da função EInversa para verificar se as listas são inversas
    int result = EInversaDuplamente(list1, list2);

    // Impressão do resultado
    printf("%d", result);

    return 0;
}
*/
/*
int main() {
    Dllist *list1 =  dlCreate();
    Dllist *list3 =  dlCreate();
   
    int data1[] = {40, 30, 20, 10};
    int numElements1 = sizeof(data1) / sizeof(data1[0]);
    for (int i = 0; i < numElements1; i++) {
        dllinsertasFirst(list1, &data1[i]);
    }
    Dllist *list2 = dlCreate();
    int data2[] = {10, 20, 30, 40}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        dllinsertasFirst(list2, &data2[i]);
    }
    printdllist(list1);
    printdllist(list2);
    list3 = PegaElementosIguais(list1,list2,list3);
    printdllist(list3);
    return 0;
}
*/
/*
int main() {
    Dllist *list1 =  dlCreate();
   
    int data1[] = {40, 30, 20, 10};
    int numElements1 = sizeof(data1) / sizeof(data1[0]);
    for (int i = 0; i < numElements1; i++) {
        dllcircinsertasFirst(list1, &data1[i]);
    }
    Dllist *list2 = dlCreate();
    int data2[] = {10, 20, 30, 40}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        dllcircinsertasFirst(list2, &data2[i]);
    }
    printdllistcirc(list1);
    printdllistcirc(list2);
    RemoveKEsimo(list1,  3);
    printdllistcirc(list1);
    return 0;
}
*/
/*
int main() {
    int node2_data = 60;
    int node3_data = 50;
    Sllist *list2 = slCreate();
    int data2[] = {10, 20, 30, 40, 50, 60}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        sllcircinsertasFirst(list2, &data2[i]);
    }
    printsllistcirc(list2);
    slladdbeforeSpeccirc(list2, &node2_data, compint, &node3_data);
    printsllistcirc(list2);
    return 0;
}
*/
/*
int main() {
    Sllist *list2 = slCreate();
    Sllist *list1 = slCreate();
    int data2[] = {10, 20, 30, 40, 50, 60}; 
    int data3[] = {100, 110, 120, 130, 140, 150}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        sllcircinsertasFirst(list2, &data3[i]);
    }
    for (int i = 0; i < numElements2; i++) {
        sllcircinsertasFirst(list1, &data2[i]);
    }
    printsllistcirc(list2);
    printsllistcirc(list1);
    incluirintercalado(list1, list2);
    printsllistcirc(list1);
    return 0;
}
*/
/*
int main() {
    Dllist *list2 = dlCreate();
    Dllist *list1 = dlCreate();
    int data2[] = {10, 20, 30, 40, 50, 60}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        dllinsertasFirst(list1, &data2[i]);
    }
    printdllist(list2);
    printdllist(list1);
    copyduplamente(list1, list2);
    printdllist(list2);
    printdllist(list1);

    return 0;
}
*/
/*
int main() {
    Sllist *list2 = slCreate();
    int data2[] = {40, 20, 40, 50, 60, 40}; 
    int data3 = 40; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements2; i++) {
        sllcircinsertasFirst(list2, &data2[i]);
    }
    printsllistcirc(list2);
    int num = GetNumberOfOcurrences(list2, &data3, compint);
    printsllistcirc(list2);
    printf("%d", num);
    return 0;
}
*/

int main() {
    Dllist *list2 = dlCreate();
    Dllist *list1 = dlCreate();
    int data2[] = {10, 20, 30, 40}; 
    int data3[] = {100, 110, 120, 130, 140, 150, 120, 140, 150}; 
    int numElements2 = sizeof(data2) / sizeof(data2[0]);
    int numElements3 = sizeof(data2) / sizeof(data2[0]);
    for (int i = 0; i < numElements3; i++) {
        dllcircinsertasFirst(list2, &data3[i]);
    }
    for (int i = 0; i < numElements2; i++) {
        dllcircinsertasFirst(list1, &data2[i]);
    }
    printdllistcirc(list2);
    printdllistcirc(list1);
    dllIntercalar2(list1, list2);
    printdllistcirc(list1);
    return 0;
}
