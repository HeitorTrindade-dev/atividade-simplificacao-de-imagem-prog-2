#include <stdio.h>

#define MAX_LINHAS 10
#define MAX_COLUNAS 10
#define NUMERO_CORES 7

int matriz_original[MAX_LINHAS][MAX_COLUNAS] = {
    { 12,  45,  78, 123, 200, 255,  34,  89, 167, 210},
    { 56,  91, 134, 178, 223,  17,  68, 145, 190, 240},
    {  3,  39,  72, 110, 156, 201,  28,  84, 132, 245},
    { 64, 102, 149, 187, 230,  21,  53, 118, 174, 216},
    {  8,  47,  95, 137, 169, 212,  31,  76, 125, 158},
    { 71, 113, 143, 199, 242,  15,  62, 107, 181, 225},
    { 25,  58,  87, 121, 155, 194,  42,  98, 147, 236},
    {  6,  36,  69, 104, 141, 185,  52, 116, 163, 218},
    { 19,  49,  81, 129, 172, 205,  27,  93, 151, 233},
    {  0,  43,  74, 119, 160, 198,  38,  86, 136, 255}
};

int matriz_simplificada [MAX_LINHAS][MAX_COLUNAS];
int cores[NUMERO_CORES];
int intervalo = 255/(NUMERO_CORES - 1)  ; //ESSE -1 É PRA FAZER APRECER CORES MAIS ESCURAS


void gerarVetorDeCores(){
    int n = NUMERO_CORES;
    int contador = 0;

    for(int i = 0; i < n; i++){
      cores[i] = contador;
      contador += intervalo;
    }
}

int descobrirCorMaisProxima(int cor){
    int meio;
    for(int i = 0; i < NUMERO_CORES - 1; i++){
        meio = (cores[i] + cores[i + 1])/2;
        if (cor < meio){
            return cores[i];
        }
        else if(cor >= meio && cor < cores[i+1]){
            return cores[i+1];
        }

    }
    return cores[NUMERO_CORES - 1];
}

void gerarMatrizSimplificada(){
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            matriz_simplificada[i][j] = descobrirCorMaisProxima(matriz_original[i][j]);
        }
    }
}
void exibirMatriz(int matriz[][MAX_COLUNAS]) {
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas = MAX_LINHAS;
    int colunas = MAX_COLUNAS;

    gerarVetorDeCores();
    gerarMatrizSimplificada();
    exibirMatriz(matriz_simplificada);

}
