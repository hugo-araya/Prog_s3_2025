#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIMITE 10

void muestra(int []);

int main(){
    time_t t_1, t_2;
    int i, j, k, p, v, temp;
    int limit = LIMITE - 1;
    int cont = 0, cont1 = 0;
    int vector[LIMITE] = {7, 3, 1, 8, 5, 9, 0, 2, 4, 6};
    //int vector[LIMITE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int vector[LIMITE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    //muestra(vector);
    
    t_1=time(NULL);
    // Ordenamiento
    k = LIMITE / 2;
    while (k >= 1){
        for (i = k; i < LIMITE; i++){
            v = vector[i];
            j = i - k;
            while (j >= 0 && vector[j] > v){
                vector[j + k] = vector[j];
                j = j - k;
            }
            vector[j + k] = v;
        }
        k = k/2;
    }
    t_2=time(NULL);

    printf("\n\nEstadistica del programa: Ordenamiento .... ");   
    printf("\n\nTiempo 1 = %ld",t_1);
    printf("\n\nTiempo 2 = %ld",t_2);
    printf("\n\nTiempo Total = %lf\n",difftime(t_2, t_1));
//    muestra(vector);
 //   printf("Para ordenar %d elementos se realizan comparaciones: %d\n", LIMITE, cont);
 //   printf("Para ordenar %d elementos se realizan intercambios : %d\n", LIMITE, cont1);
    return 0;
}

void muestra(int vector[]){
    printf("\nMuestra datos\n");
    for(int i = 0; i < LIMITE; i++){
        printf("%d\n", vector[i]);
    }
}