/*Desenvolver uma fun��o que, dado um arquivo
texto contendo n�meros, determine se estes
encontram-se ordenados crescentemente.*/

#include <stdio.h>

int arquivo(char nome[]);

void main() {
    char nome[10]; 
    
    printf("Digite o nome do arquivo:\n");
    fflush(stdin);
    gets(nome);

    int retorno = arquivo(nome);

    if (retorno == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else if (retorno == 1) {
        printf("Est� ordenado crescentemente.\n");
    } else {
        printf("N�o est� ordenado crescentemente.\n");
    }
}

int arquivo(char nome[]) {
    FILE* arq = fopen(nome, "r");
    int num_ant = -99999999; 
    int num_atual;

    if (!arq) {
        return -1; 
    }

    while (fscanf(arq, "%c", &ch) != EOF) {
        if (num_atual < num_ant) {
            fclose(arq);
            return 0; 
        }
        num_ant = num_atual;
    }

    fclose(arq);
    return 1; 
}

