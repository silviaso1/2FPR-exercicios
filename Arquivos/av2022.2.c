/*Implementar uma função que, dados dois arquivos texto (arquivoA e arquivoB), 
contendo números inteiros, um por linha e sem repetições, determine o número de
elementos comuns entre os dois arquivos.*/

#include <stdio.h>

int contarNumerosComuns(char arqA[], char arqB[]);

int main() {
    int retorno = contarNumerosComuns("teste.txt", "teste2.txt");
    
    if (retorno == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("%d numeros comuns.\n", retorno);
    }
    return 0;
}

int contarNumerosComuns(char arqA[], char arqB[]) {
    FILE *arq1 = fopen(arqA, "r");
    FILE *arq2 = fopen(arqB, "r");

    if (!arq1 || !arq2) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return -1;  
    }
    
    int numA, numB, quant = 0;
    int lidoA = fscanf(arq1, "%d", &numA);
    int lidoB = fscanf(arq2, "%d", &numB);
    
    while (lidoA != EOF && lidoB != EOF) {
        if (numA == numB) {
            quant++;
            lidoA = fscanf(arq1, "%d", &numA); // Avança para o próximo número em arq1
            lidoB = fscanf(arq2, "%d", &numB); // Avança para o próximo número em arq2
        } else if (numA < numB) {
            lidoA = fscanf(arq1, "%d", &numA); // Avança para o próximo número em arq1
        } else {
            lidoB = fscanf(arq2, "%d", &numB); // Avança para o próximo número em arq2
        }
    }
    
    fclose(arq1);
    fclose(arq2);
    
    return quant;
}


