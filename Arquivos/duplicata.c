#include <stdio.h>

int removeDuplicatas(char *arquivo1, char *arquivo2) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2 = fopen(arquivo2, "w");

    if (!arq1 || !arq2) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return -1;
    }

    int numero, numeroTemp, duplicata;

    // Ler cada n�mero do arquivo de entrada
    while (fscanf(arq1, "%d", &numero) != EOF) {
        // Reiniciar a verifica��o de duplicatas
        duplicata = 0;

        // Abrir arquivo de sa�da para leitura
        FILE *saidaTemp = fopen(arquivo2, "r");

        if (!saidaTemp) {
            fclose(arq1);
            fclose(arq2);
            return -1;
        }

        // Verificar se o n�mero j� est� no arquivo de sa�da
        while (fscanf(saidaTemp, "%d", &numeroTemp) != EOF) {
            if (numeroTemp == numero) {
                duplicata = 1;
                break;
            }
        }

        fclose(saidaTemp);

        // Se n�o for duplicata, escreva no arquivo de sa�da
        if (!duplicata) {
            fprintf(arq2, "%d\n", numero);
        }
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}

int main() {
    if (removeDuplicatas("teste.txt", "B.txt") == 0) {
        printf("Arquivo processado com sucesso.\n");
    } else {
        printf("Erro ao processar o arquivo.\n");
    }
    return 0;
}

