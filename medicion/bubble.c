#include <stdio.h>
#define LIMITE 10

void muestra(int []);

int main(){
    int i, j, temp;
    int cont = 0;
    //int vector[LIMITE] = {7, 3, 1, 8, 5, 9, 0, 2, 4, 6};
    //int vector[LIMITE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vector[LIMITE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    //muestra(vector);
    
    // Ordenamiento
    for (i = 1; i < LIMITE; i++){
        for (j = 0; j < LIMITE - 1; j++){
            cont++;
            if (vector[j] > vector[j+1]) {
                temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
        }
    }

    //muestra(vector);
    printf("Para ordenar %d elementos se realizan comparaciones: %d\n", LIMITE, cont);
    return 0;
}

void muestra(int vector[]){
    printf("\nMuestra datos\n");
    for(int i = 0; i < LIMITE; i++){
        printf("%d\n", vector[i]);
    }
}