#include <stdio.h>
#include <stdlib.h>

g
struct Aluno {
    int mat;
    float a1;
    float a2;
    float a3;
    float finalnota;
    struct Aluno* prox;
    };

void inserirAluno(struct Aluno** lista, struct Aluno* novoAluno) {
    struct Aluno* atual = *lista;
    struct Aluno* anterior = NULL;

    while (atual != NULL && novoAluno->finalnota < atual->finalnota) {
        anterior = atual;
        atual = atual->prox;}

    if (anterior == NULL) {
        novoAluno->prox = *lista;
        *lista = novoAluno;
    } else {
        anterior->prox = novoAluno;
        novoAluno->prox = atual;}}

int contarAlunosComMediaSuperior(struct Aluno* lista, float valorLimite) {
    int contador = 0;
    struct Aluno* atual = lista;

    while (atual != NULL) {
        if (atual->finalnota > valorLimite) {
            contador++;}
        atual = atual->prox;}

    return contador;}

int main() {
    struct Aluno* list = NULL;
    int opcao;

    do {
        printf("Opte por uma opcao:\n");
        printf("1. Inserir aluno\n");
        printf("2. Contabilizar estudantes com media final superior ao limite\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct Aluno* nvAluno = (struct Aluno*)malloc(sizeof(struct Aluno));
                printf("Informe a matricula: ");
                scanf("%d", &(nvAluno->mat));
                printf("Informe a nota da Primeira Atividade: ");
                scanf("%f", &(nvAluno->a1));
                printf("Informe a nota da Segunda Atividade: ");
                scanf("%f", &(nvAluno->a2));
                printf("Informe a nota da Terceira Atividade: ");
                scanf("%f", &(nvAluno->a3));
                nvAluno->finalnota = (nvAluno->a1 + nvAluno->a2 + nvAluno->a3) / 3.0;
                nvAluno->prox = NULL;
                inserirAluno(&list, nvAluno);
                break;}

            case 2: {
                float limitedvalor;
                printf("Diga o valor limite para a media: ");
                scanf("%f", &limitedvalor);
                int quanti = contarAlunosComMediaSuperior(list, limitedvalor);
                printf("Numero de alunos com media superior a %.2f: %d\n", limitedvalor, quanti);
                break;}

            case 3: {
                while (list != NULL) {
                    struct Aluno* temp = list;
                    list = list->prox;
                    free(temp);}
                break;}

            default:
                printf("Opcao invalida.\n");
                break;}
    } while (opcao != 3);

    return 0;}
