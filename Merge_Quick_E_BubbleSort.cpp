# Atividade-Sobre-Ordena-o
Ordenação com arquivo externo de modo dinâmico: Bubble, Quick e Merge Sort

#include<stdio.h>
#include<stdlib.h>


/*================ORDENAÇÃO MERGE SORT===============*/
void mistura(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim -inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc (tamanho*sizeof(int));

    if (temp != NULL){
        for (i=0; i<tamanho; i++){
            if (!fim1 && !fim2){
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if (p1>meio) fim=1;
                if (p2>fim) fim2=1;
            }else{
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        for (j=0, k=inicio; j<tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp);

}

void mergeSort (int *V, int inicio, int fim){
    int meio;
    if (inicio < fim){
        meio = floor ((inicio + fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        mistura(V, inicio, meio, fim);
    }


}

/*================ORDENAÇÃO QUICK SORT===============*/


void particiona(int *Q, int inicio, int finish){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = finish;
    pivo = Q[inicio];
    while (esq < dir){
        while (Q[esq] <= pivo)
            esq++;
        while (Q[dir] > pivo)
            dir--;
        if (esq < dir){
            aux = Q[esq];
            Q[esq] = Q[dir];
            Q[dir] = aux;
        }
    }
    Q[inicio] = Q[dir];
    Q[dir] = pivo;
    return dir;


}
void quickSort(int *Q, int inicio, int fim){
    int pivo;
    if (fim > inicio){
        pivo = particiona (Q, inicio, fim);
        quickSort(Q, inicio, pivo-1);
        quickSort(Q, pivo+1, fim);
    }
}

