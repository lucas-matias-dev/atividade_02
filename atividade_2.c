#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long comparacoes;
    long movimentos;
} Operacoes;

void bubble_sort(int lista[], int tamanho, Operacoes *op) {
    int i, j, troca;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            op->comparacoes++;
            if (lista[j] > lista[j + 1]) {
                troca = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = troca;
                op->movimentos++;
            }
        }
    }
}

int separar(int lista[], int inicio, int fim, Operacoes *op) {
    int pivo = lista[fim];
    int i = inicio - 1;
    int j, troca;

    for (j = inicio; j < fim; j++) {
        op->comparacoes++;
        if (lista[j] <= pivo) {
            i++;
            troca = lista[i];
            lista[i] = lista[j];
            lista[j] = troca;
            op->movimentos++;
        }
    }

    troca = lista[i + 1];
    lista[i + 1] = lista[fim];
    lista[fim] = troca;
    op->movimentos++;
    return i + 1;
}

void quick_sort(int lista[], int inicio, int fim, Operacoes *op) {
    if (inicio < fim) {
        int posicao_pivo = separar(lista, inicio, fim, op);
        quick_sort(lista, inicio, posicao_pivo - 1, op);
        quick_sort(lista, posicao_pivo + 1, fim, op);
    }
}

void testar_ordenacao(int tamanho) {
    int *original = malloc(tamanho * sizeof(int));
    int *lista_bubble = malloc(tamanho * sizeof(int));
    int *lista_quick = malloc(tamanho * sizeof(int));
    Operacoes bubble = {0, 0};
    Operacoes quick = {0, 0};
    int i;

    for (i = 0; i < tamanho; i++) {
        original[i] = rand() % 10000;
        lista_bubble[i] = original[i];
        lista_quick[i] = original[i];
    }

    bubble_sort(lista_bubble, tamanho, &bubble);
    quick_sort(lista_quick, 0, tamanho - 1, &quick);
    printf("%-8d | %-18ld | %-14ld | %-17ld | %ld\n", tamanho,
           bubble.comparacoes, bubble.movimentos,
           quick.comparacoes, quick.movimentos);

    free(original);
    free(lista_bubble);
    free(lista_quick);
}

int buscar_matriz(int linhas, int colunas, int valor, int *linha, int *coluna) {
    int i, j, comparacoes = 0;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            comparacoes++;
            if (i * colunas + j + 1 == valor) {
                *linha = i;
                *coluna = j;
                return comparacoes;
            }
        }
    }
    *linha = -1;
    *coluna = -1;
    return comparacoes;
}

void testar_busca(int linhas, int colunas) {
    int linha, coluna;
    int total = linhas * colunas;
    int inicio = buscar_matriz(linhas, colunas, 1, &linha, &coluna);
    int final = buscar_matriz(linhas, colunas, total, &linha, &coluna);
    int inexistente = buscar_matriz(linhas, colunas, total + 1, &linha, &coluna);
    printf("%-8s | %-10d | %-6d | %-5d | %d\n",
           linhas == 2 ? "2 x 2" : linhas == 10 ? "10 x 10" : "100 x 100",
           total, inicio, final, inexistente);
}

void investigar_temperaturas(void) {
    float temperatura[10], soma = 0, maior, menor, media;
    int i, indice_maior = 0, indice_menor = 0, acima = 0;

    printf("\nDigite 10 temperaturas:\n");
    for (i = 0; i < 10; i++) {
        scanf("%f", &temperatura[i]);
        soma += temperatura[i];
    }
    maior = menor = temperatura[0];
    for (i = 1; i < 10; i++) {
        if (temperatura[i] > maior) { maior = temperatura[i]; indice_maior = i; }
        if (temperatura[i] < menor) { menor = temperatura[i]; indice_menor = i; }
    }
    media = soma / 10;
    for (i = 0; i < 10; i++) {
        printf("Índice %d: %.1f\n", i, temperatura[i]);
        if (temperatura[i] > media) acima++;
    }
    printf("Média: %.2f | Maior: %.1f (índice %d) | Menor: %.1f (índice %d)\n",
           media, maior, indice_maior, menor, indice_menor);
    printf("Valores acima da média: %d | Percursos: aproximadamente 30 | Complexidade: O(n)\n", acima);
}

void monitorar_sensores(void) {
    float sensores[5][24], soma_geral = 0, maior, limite;
    int i, j, sensor_maior = 0, horario_maior = 0, acima = 0;

    printf("\nDigite as 24 medições de cada um dos 5 sensores:\n");
    for (i = 0; i < 5; i++) {
        float soma_sensor = 0;
        for (j = 0; j < 24; j++) {
            scanf("%f", &sensores[i][j]);
            soma_sensor += sensores[i][j];
            soma_geral += sensores[i][j];
            if ((i == 0 && j == 0) || sensores[i][j] > maior) {
                maior = sensores[i][j];
                sensor_maior = i;
                horario_maior = j;
            }
        }
        printf("Média do sensor %d: %.2f\n", i, soma_sensor / 24);
    }
    printf("Informe o limite de temperatura: ");
    scanf("%f", &limite);
    for (i = 0; i < 5; i++)
        for (j = 0; j < 24; j++)
            if (sensores[i][j] > limite) acima++;

    printf("Maior temperatura: %.1f | Sensor: %d | Horário: %d\n", maior, sensor_maior, horario_maior);
    printf("Média geral: %.2f | Leituras acima do limite: %d\n", soma_geral / 120, acima);
    printf("Os loops aninhados percorrem os 5 sensores e suas 24 horas.\n");
    printf("[i][j] indica sensor e horário; são percorridas 120 posições, ou linhas x colunas.\n");
}

int main(void) {
    srand(7);
    printf("Tamanho  | Bubble comparações | Bubble trocas | Quick comparações | Quick movimentos\n");
    testar_ordenacao(10);
    testar_ordenacao(20);
    testar_ordenacao(1000);

    printf("\nMatriz   | Elementos  | Início | Final | Inexistente\n");
    testar_busca(2, 2);
    testar_busca(10, 10);
    testar_busca(100, 100);

    investigar_temperaturas();
    monitorar_sensores();
    return 0;
}
