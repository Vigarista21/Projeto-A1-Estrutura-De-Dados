#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int inf;
    struct lista* proxi;
} TLista;

int Igual(TLista* L1, TLista* L2) {
    while (L1 != NULL && L2 != NULL) {
        if (L1->inf != L2->inf) {
            return 0;
        }
        L1 = L1->proxi;
        L2 = L2->proxi;}
    
    return (L1 == NULL && L2 == NULL) ? 1 : 0;}

TLista* insereInicio(TLista* lista, int valor) {
    TLista* novoNo = (TLista*)malloc(sizeof(TLista));
     novoNo->inf = valor;
     novoNo->proxi = lista;
     return novoNo;}

void imprimeLista(TLista* lista) {
     TLista* atual = lista;
     while (atual != NULL) {
        printf("%d ", atual->inf);
        atual = atual->proxi;}
     printf("\n");}

int main() {
     int t_lista1, t_lista2;

     printf("tamanho da lista 1: ");
    scanf("%d", &t_lista1);

     printf("elementos da lista 1:\n");
    TLista* l1 = NULL;
    for (int i = 0; i < t_lista1; i++) {
        int valor;
         printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        l1 = insereInicio(l1, valor);}

    printf(" tamanho da lista 2: ");
    scanf("%d", &t_lista2);

    printf("elementos da lista 2:\n");
    TLista* l2 = NULL;
    for (int i = 0; i < t_lista2; i++) {
        int valor;
          printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        l2 = insereInicio(l2, valor);}

    int resultado = Igual(l1, l2);

    
    TLista* temp;
    while (l1 != NULL) {
        temp = l1;
        l1 = l1->proxi;
        free(temp);}

    while (l2 != NULL) {
        temp = l2;
        l2 = l2->proxi;
        free(temp);}

    if (resultado) {
        printf("1\n");
    } else {
        printf("0\n");}

    return 0;}