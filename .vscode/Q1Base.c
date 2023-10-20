#include <stdio.h>

 /*
    float %f
    char %c 
    string %s
*/
// Estrutura 
struct Aluno {
    char matricula[11];
    float notas[3];
};


float calcularMediaFinal(float nota[]) {
    
    for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
    if (nota[i] < nota[j]) {
                float temp = nota[i];
                nota[i] = nota[j];
                nota[j] = temp;
     }
    }
    }
  
    return (nota[0] + nota[1]) / 2;
}

int main() {
    int numeroAlunos;
    printf("Numero de alunos: ");
    scanf("%d", &numeroAlunos);

    struct Aluno aluno[numeroAlunos];

    for (int i = 0; i < numeroAlunos; i++){
        printf("Digite a matricula do aluno:");
        scanf("%s", aluno[i].matricula);

        printf("Digite as tres notas do aluno separadas:");
    for (int j = 0; j < 3; j++) {
        scanf("%f", &aluno[i].notas[j]);
    }
    }

        printf("\nMedias Finais:\n");

    
    for (int i = 0; i < numeroAlunos; i++) {
        float mediaFinal = calcularMediaFinal(aluno[i].notas);
        printf("Matricula: %s, Media Final: %.2f\n", aluno[i].matricula, mediaFinal);
    }

    return 0;
}