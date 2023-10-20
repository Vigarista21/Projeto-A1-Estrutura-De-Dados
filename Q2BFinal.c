#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* constroi(int x, int* vetor) {
    if (x <= 0 || vetor == NULL) {
        return NULL;}

    TLista* cab = NULL;
    TLista* atual = NULL;

    for (int i = 0; i < x; i++) {
        TLista* novoNo = (TLista*)malloc(sizeof(TLista));
        if (novoNo == NULL) {
            printf("Erro: Não foi possível alocar memória para o nó da lista.\n");
            exit(EXIT_FAILURE);}
        novoNo->info = vetor[i];
        novoNo->prox = NULL;

        if (cab == NULL) {
            cab = novoNo;
            atual = cab;
        } else {
            atual->prox = novoNo;
            atual = novoNo;}}

    return cab;}

void imprimeLista(TLista* lista) {
    TLista* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");}

int main() {
    int tam_vet;

    printf("tamanho do vetor: ");
    scanf("%d", &tam_vet);

    if (tam_vet <= 0) {
        printf("Tamanho de vetor inválido.\n");
        return 1;}

    int* vet = (int*)malloc(tam_vet * sizeof(int));

    if (vet == NULL) {
        printf("Erro de alocação de memória para o vetor.\n");
        return 1; }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tam_vet; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vet[i]);}

    TLista* list = constroi(tam_vet, vet);

    if (list == NULL) {
        printf("Vetor vazio, lista resultante: vazia\n");
    } else {
        printf("Lista resultante: ");
        imprimeLista(list);}

    free(vet);

    TLista* temp;
    while (list != NULL) {
        temp = list;
        list = list->prox;
        free(temp);}

    return 0;}
