# Atividade 2 — Arrays, matrizes, ordenação e busca

## Pesquisa e comparação

O Bubble Sort compara pares vizinhos e troca os que estão fora de ordem. A cada passagem, um dos maiores valores chega ao final. É simples e adequado para listas pequenas ou quase ordenadas, mas não é recomendado para grandes volumes.

O Quick Sort escolhe um pivô, separa os menores e maiores valores e repete o processo em cada parte. Normalmente é rápido para listas grandes, mas uma escolha ruim de pivôs pode produzir o pior caso.

| Característica | Bubble Sort | Quick Sort |
|---|---|---|
| Princípio | Comparações entre vizinhos | Divisão da lista por um pivô |
| Melhor caso | O(n) com interrupção antecipada; nesta implementação, O(n²) | O(n log n) |
| Caso médio | O(n²) | O(n log n) |
| Pior caso | O(n²) | O(n²) |
| Memória | O(1) | O(log n), em média, pela recursão |
| Vantagem | Simplicidade | Bom desempenho médio |
| Limitação | Muitas operações | Depende da escolha do pivô |
| Uso recomendado | Poucos elementos | Quantidades maiores de dados |

## Experimentos

As tabelas são exibidas pelo programa `atividade_2.c`. Os arrays são gerados uma vez para cada tamanho e copiados, garantindo os mesmos dados nos dois algoritmos.

No experimento de ordenação, o Quick Sort tende a realizar menos operações nos tamanhos 10 e 20, e a diferença aumenta muito com 1.000 elementos. O Bubble Sort apresenta maior crescimento. Isso é coerente com O(n²) do Bubble Sort e O(n log n), em média, do Quick Sort. Eu escolheria Bubble Sort em uma lista muito pequena, pela simplicidade, e Quick Sort em listas maiores.

Na busca, o início exige uma comparação. O último valor e o valor inexistente exigem comparar todas as posições. O pior caso ocorre quando o valor está no final ou não existe. Para uma matriz de `m` linhas e `n` colunas, a complexidade é O(m × n).

O array de temperaturas é percorrido aproximadamente três vezes, mantendo complexidade O(n). Na matriz de sensores, loops aninhados são necessários porque cada sensor possui 24 horários. Os índices `[i][j]` representam a linha do sensor e a coluna do horário. São percorridas 120 posições e o total de operações cresce de acordo com linhas × colunas.

## Conclusão

O aumento das estruturas aumenta a quantidade de operações. Bubble Sort e Quick Sort não crescem da mesma maneira: no caso médio, o crescimento do Quick Sort é menor. Observar apenas a lista ordenada não basta, pois algoritmos que chegam ao mesmo resultado podem fazer quantidades muito diferentes de comparações e movimentações.
