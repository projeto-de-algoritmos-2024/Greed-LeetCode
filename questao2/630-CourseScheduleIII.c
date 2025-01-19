#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int duration;
    int last_day;
} Course;

// Função de comparação para o qsort (ordenar por último dia possível)
int compareCourses(const void* a, const void* b) {
    Course* courseA = (Course*)a;
    Course* courseB = (Course*)b;
    
    return courseA->last_day - courseB->last_day;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    // Copiar cursos para o formato de struct
    Course* sortedCourses = (Course*)malloc(sizeof(Course) * coursesSize);
    for (int i = 0; i < coursesSize; i++) {
        sortedCourses[i].duration = courses[i][0];
        sortedCourses[i].last_day = courses[i][1];
    }
    
    // Ordenar os cursos pelo último dia possível
    qsort(sortedCourses, coursesSize, sizeof(Course), compareCourses);
    
    // Array para armazenar os cursos que podem ser agendados
    int* scheduledCourses = (int*)malloc(sizeof(int) * coursesSize);
    int totalTime = 0;
    int count = 0;
    
    for (int i = 0; i < coursesSize; i++) {
        int duration = sortedCourses[i].duration;
        int last_day = sortedCourses[i].last_day;
        
        // Verificar se podemos alocar o curso (não ultrapassando o último dia)
        if (totalTime + duration <= last_day) {
            scheduledCourses[count++] = i;  // Agendar o curso
            totalTime += duration;  // Atualizar o tempo total utilizado
        } else {
            // Se não for possível, tentamos substituir o curso mais longo
            int maxIndex = -1;
            int maxDuration = 0;
            for (int j = 0; j < count; j++) {
                int idx = scheduledCourses[j];
                if (sortedCourses[idx].duration > maxDuration) {
                    maxDuration = sortedCourses[idx].duration;
                    maxIndex = j;
                }
            }
            
            // Substituir o curso de maior duração se o novo curso for mais eficiente
            if (maxIndex != -1 && duration < maxDuration) {
                totalTime = totalTime - maxDuration + duration;
                scheduledCourses[maxIndex] = i;  // Substitui o curso
            }
        }
    }
    
    free(sortedCourses);
    free(scheduledCourses);
    return count;
}