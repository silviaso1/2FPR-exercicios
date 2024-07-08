/*Desenvolver uma fun��o que, dado um arquivo
texto, verifique o n�mero de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e s�mbolos).*/

#include <stdio.h>

int arquivo(char nome[]);

void main() {
    char nome[20]; 
    
    printf("Digite o nome do arquivo:\n");
    fflush(stdin);
    gets(nome);

    int retorno = arquivo(nome);

    if (retorno == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("H� %d letras no arquivo.\n", retorno);
    }
}

int arquivo(char nome[]) {
    FILE* arq = fopen(nome, "r");
    char ch;
    int quant = 0;

    if (!arq) {
        return -1; 
    }

    while (fscanf(arq, "%c", &ch) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            quant++;
        }
    }

    fclose(arq);
    return quant;
}

