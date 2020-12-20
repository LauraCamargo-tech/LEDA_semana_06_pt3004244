#include <stdio.h>
#include <stdlib.h>

void countingSort(int *vet, int vetSize, int maior) {
    int *aux = (int *) malloc(sizeof(int) * (maior + 1));
    int i, j;
    for (i = 0; i < vetSize; i++) {
        aux[vet[i]]++;
    }
    for (i = 0, j = 0; i < maior + 1; i++) {
        if (aux[i] != 0) {
            while (aux[i] > 0) {
                vet[j] = i;
                aux[i]--;
                j++;
            }
        }
    }
    free(aux);
}

void bubbleSort(int *vet, int vetSize) {
    int i, j;
    for (i = 0; i < vetSize - 1; i++) {
        for (j = 0; j < vetSize - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int main() {
    int n, t, i, maior = 1;

    printf("Tamanho do primeiro vetor\n");
    scanf("%d", &n);

    printf("Tamanho do segundo vetor\n");
    scanf("%d", &t);

    int v[t + n];
    printf("elementos do primeiro vetor\n");
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    printf("Elementos do segundo vetor\n");
    for(i = n; i < (n + t); i++){
        scanf("%d", &v[i]);
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    bubbleSort(v, n + t);
    for (i = 0; i < n + t; i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}