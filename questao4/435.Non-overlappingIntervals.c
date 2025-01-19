#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os intervalos
typedef struct {
    int start;
    int end;
} Interval;

// Função de comparação para ordenar os intervalos pelo horário de término
int compareIntervals(const void* a, const void* b) {
    Interval* intervalA = (Interval*)a;
    Interval* intervalB = (Interval*)b;
    return intervalA->end - intervalB->end;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;
    
    // Converter o array 2D para uma estrutura de Interval
    Interval* intervalArray = (Interval*)malloc(sizeof(Interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        intervalArray[i].start = intervals[i][0];
        intervalArray[i].end = intervals[i][1];
    }
    
    // Ordenar os intervalos pelo horário de término
    qsort(intervalArray, intervalsSize, sizeof(Interval), compareIntervals);
    
    int count = 0;       // Contador para intervalos selecionados
    int lastEnd = intervalArray[0].end; // Horário de término do último intervalo selecionado
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervalArray[i].start < lastEnd) {
            // Se o intervalo atual se sobrepõe, incrementa o número de remoções
            count++;
        } else {
            // Atualiza o horário de término do último intervalo selecionado
            lastEnd = intervalArray[i].end;
        }
    }
    
    free(intervalArray);
    return count;
}