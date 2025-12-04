#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define LIMITE 100000
// Función para intercambiar dos elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Esta función toma el último elemento como pivote,
  coloca el pivote en su posición correcta en el array ordenado,
  y coloca todos los elementos menores (menores que el pivote)
  a la izquierda del pivote y todos los elementos mayores a la derecha del pivote */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Pivote
    int i = (low - 1);  // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual que el pivote
        if (arr[j] <= pivot) {
            i++; // Incrementar índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* La función principal que implementa Quicksort
 arr --> Array a ser ordenado,
 low  --> Índice de inicio,
 high  --> Índice de fin */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi es el índice de partición, arr[p] está ahora en el lugar correcto
        int pi = partition(arr, low, high);

        // Se ordena recursivamente antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir el array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void lee_datos(int *vector, int n){
    int i;
    int dato;
    for (i = 0; i < n; i++){
        scanf("%d", &dato);
        vector[i] = dato;
    }
}

// Código de ejemplo de uso
int main() {
    time_t t_1, t_2;
    int arr[LIMITE];
    int n = sizeof(arr) / sizeof(arr[0]);
    lee_datos(arr, LIMITE);


    t_1=time(NULL);
    quickSort(arr, 0, LIMITE);
    t_2=time(NULL);
    //printArray(arr, LIMITE);
    printf("\n\nEstadistica del programa: Ordenamiento .... ");   
    printf("\n\nTiempo 1 = %ld",t_1);
    printf("\n\nTiempo 2 = %ld",t_2);
    printf("\n\nTiempo Total = %lf\n",difftime(t_2, t_1));
    return 0;
}
