#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesorth(int a[], int inicio, int fim){
    int meio;

    if(inicio < fim){
        //printf("goamjdfg");
        meio = (inicio + fim) / 2;
            mergesorth(a,inicio,meio);
            mergesorth(a, meio+1 , fim);
            merge(a , inicio , meio , meio+1 , fim);
    }
}

void merge(int a[], int inicio_vetor1, int fim_vetor1 , int inicio_vetor2, int fim_vetor2){
    int aux[50];
    int i , j , var_control;
    i = inicio_vetor1;
    j = inicio_vetor2;
    var_control = 0;

    while (i <= fim_vetor1 && j<= fim_vetor2){
        if(a[i]<a[j]){
            aux[var_control] = a[i];
            var_control++;
            i++;
        }else{
            aux[var_control] = a[j];
            var_control++;
            j++;
        }
    }

    while( i <= fim_vetor1 ){
        aux[var_control] = a[i];
        var_control++;
        i++;
    }
    while (j <= fim_vetor2 ){
        aux[var_control] = a[j];
        var_control++;
        j++;
    }

    for (i = inicio_vetor1, j = 0; i <= fim_vetor2; i++ , j++){
        a[i] = aux[j];
    }

    
}

int main(int argc, char const *argv[]){

    int vmerg[1000];

    printf("\n-----------------x---------------------------\n");

    srand(time(NULL));
    printf("\nAntes da Funcao:\n");
    for (int i = 0; i < 1000; i++){
        vmerg[i] = rand();
        printf("%d ",vmerg[i]);
    }
    printf("\n-----------------x---------------------------\n");
    mergesorth(vmerg,0,1000);

    printf("\nMergeSorth:\n");
    for (int i = 0; i < 1000; i++){
        printf("%d ", vmerg[i]);
    }
    printf("\n-----------------x---------------------------\n");

    
    
    return 0;
}
