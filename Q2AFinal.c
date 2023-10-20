#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* proxim;
} TLista;

TLista* inverte(TLista* A) {
    TLista* B = NULL;  

   
    while (A != NULL) {
        TLista* novoN = (TLista*)malloc(sizeof(TLista));
        novoN->info = A->info;
        novoN->proxim = B;
        B = novoN;

        A = A->proxim;  }

    return B;}


void imprimeLista(TLista* list) {
    TLista* atual = list;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->proxim;}
    printf("\n");}

TLista* insereInicio(TLista* list, int val) {
    TLista* novoN = (TLista*)malloc(sizeof(TLista));
    novoN->info = val;
    novoN->proxim = list;
    return novoN;}

int main() {
    TLista* A = NULL;  

    int num_elementos;
    printf("Quantos elementos deseja colocar na lista? ");
    scanf("%d", &num_elementos);

   
    int i = 0;
    while ( i < num_elementos) {
        int valor;
        printf("Escreva o valor para o elemento %d: ", i);
        scanf("%d", &valor);
        A = insereInicio(A, valor);
        i = i+1;}
    TLista* B = inverte(A);
    
    printf("Lista original (A): ");
    imprimeLista(A);

    

    printf("Lista invertida (B): ");
    imprimeLista(B);

    TLista* temp;
    while (A != NULL) {
        temp = A;
        A = A->proxim;
        free(temp);}
    

    while (B != NULL) {
        temp = B;
        B = B->proxim;
        free(temp);}
    

    return 0;}