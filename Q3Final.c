#include <stdio.h>
#include <stdlib.h>

struct lista {
    int inf;
    struct lista* proxi;
    struct lista* ant;
};

typedef struct lista TLDE;

TLDE* inserir(TLDE* l, int info) {
    TLDE* novo = (TLDE*)malloc(sizeof(TLDE));
    if (novo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);}

    novo->ant = NULL;
    novo->proxi = l;
    novo->inf = info;

    if (l != NULL) {
        l->ant = novo;}

    return novo;}

TLDE* excluir(TLDE* l, int info) {
    TLDE* at = l;

    while (at != NULL) {
        if (at->inf == info) {
            if (at->ant != NULL) {
                at->ant->proxi = at->proxi;
            }
            if (at->proxi != NULL) {
                at->proxi->ant = at->ant;}

            TLDE* temp = at->proxi;
            free(at);

            if (l == at) {
                return temp;}

            return l;}

        at = at->proxi;}

    return l;}

void imprimeLista(TLDE* l) {
    TLDE* atual = l;
    while (atual != NULL) {
        printf("%d ", atual->inf);
        atual = atual->proxi;}
    printf("\n");}

int main() {
    TLDE* list = NULL;

    list = inserir(list, 1);
    list = inserir(list, 2);
    list = inserir(list, 3);

    printf("Lista original: ");
    imprimeLista(list);

    list = excluir(list, 2);

    printf("Lista apos a exclusao: ");
    imprimeLista(list);

    while (list != NULL) {
        TLDE* temp = list;
        list = list->proxi;
        free(temp);}    
        
        return 0;}
