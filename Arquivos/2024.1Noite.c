/*Desenvolver uma fun��o que, dados os nomes de dois
arquivos textos, contendo n�meros inteiros, um por
linha, determine se o primeiro arquivo est� contido no
segundo (ou seja, se todos os elementos do primeiro
tamb�m est�o no segundo).*/
#include <stdio.h>

int verificarContido(char *arquivo1, char *arquivo2);

int main() {
    int contido = verificarContido("teste.txt", "teste2.txt");
    
    if (contido == -1) {
        printf("Erro ao abrir um dos arquivos.\n");
    } else if (contido == 1) {
        printf("O primeiro arquivo est� contido no segundo arquivo.\n");
    } else {
        printf("O primeiro arquivo n�o est� contido no segundo arquivo.\n");
    }
    
    return 0;
}

int verificarContido(char *arquivo1, char *arquivo2) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2;

    if (!arq1) {
        return -1; 
    }

    int num1, num2;
    int encontrado;

    while (fscanf(arq1, "%d", &num1) != EOF) {
        encontrado = 0;

        arq2 = fopen(arquivo2, "r");  // Reabre o segundo arquivo

        if (!arq2) {
            fclose(arq1);
            return -1; // Erro ao abrir arquivo2
        }

        while (fscanf(arq2, "%d", &num2) != EOF) {
            if (num1 == num2) {
                encontrado = 1;
                break;
            }
        }

        fclose(arq2);  // Fecha o segundo arquivo

        if (!encontrado) {
            fclose(arq1);
            return 0; // Um n�mero de arq1 n�o est� em arq2
        }
    }

    fclose(arq1);
    return 1; // Todos os n�meros de arq1 est�o em arq2
}

