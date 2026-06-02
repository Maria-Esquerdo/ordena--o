#include <iostream>
using namespace std;

// Algoritmo de  ordenação Quick Sort:
// 1. Função de partição: 
    //1.1 -> escolhe um pivô e passa ele pra primeira posição
    //1.2 -> compara o pivô com o resto do vetor, se um elemento for menor, a troca é feita e o contador é
    //atualizado para acompanhar o elemento do pivô
    //1.3 -> volta o pivô para sua posição original 


void imprime(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
}

void troca (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}

// Função de partição e ordenação a partir do pivô:
void partition (int vet[], int esq, int dir)
{
    int pivo = (esq+dir) / 2;
    int i = esq;
    troca(&pivo, &i);
    
    


    return i;
}

//Funções para dividir o vetor, através dos pivôs, recursivamente
void aux_quick_sort (int vet[], int esq, int dir)
{
    

}

void quick_sort (int vet[], int n)
{


}


int main()
{
    int vet[10] = {6, 9, 1, 8, 15, 4, 13, 9, 2, 2};
    quick_sort(vet, 10);
    cout << "O vetor ordenado eh: " << endl;
    imprime(vet, 10);
    return 0;
}