#include <iostream>
using namespace std;

// Algoritmo de  ordenação Quick Sort:
// 1. Função de partição:
// 1.1 -> escolhe um pivô e passa ele pra primeira posição
// 1.2 -> compara o pivô com o resto do vetor, se um elemento for menor, a troca é feita e o contador é
// atualizado para acompanhar o elemento do pivô
// 1.3 -> volta o pivô para sua posição original

void imprime(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
    return;
}

// Função de partição e ordenação a partir do pivô:
int partition(int vet[], int esq, int dir)
{
    int pivo = (esq + dir) / 2;
    int i = esq;
    troca(&vet[pivo], &vet[esq]);
    // Percorrendo o vetor, da segunda posição, até o final, comparando o elemento atual (j) com o pivô
    // e trocando o elemento da frente do pivô (i) em diante, se for menor
    for (int j = esq + 1; j <= dir; j++)
    {
        if (vet[j] < vet[esq]) // compara elemento atual com pivô
        {
            i++;                     // Se satisfizer à condição, adiciona 1 ao contador de início e o elemento j (atual)
            troca(&vet[i], &vet[j]); ////é trocado com o elemento mais à esquerda (sem ser o primeiro, que é o pivô)
        }
    }
    // por fim, o contador i aponta para o último elemento do vetor que é maior que o pivô
    // então o pivô, que está no começo, é trocado com i
    troca(&vet[esq], &vet[i]);
    return i; // retorna a posição do pivô original
}

// Funções para dividir o vetor, através dos pivôs, recursivamente
void aux_quick_sort(int vet[], int esq, int dir)
{
    if (esq >= dir)
        return;
    else
    {
        int pi; 
        pi = partition(vet, esq, dir); //Chama a função para os valores iniciais, definindo pi como 
        //a posição do pivô (local de partição)
        //A ideia agora é partir o vetor á direita e a esquerda do pivô, excluindo ele, já que está ordenado.
        // da mesma forma, até chegar em vetores de tam 1
        aux_quick_sort(vet, esq, pi-1); //p1-1 é o índice do elemento anterior ao vetor
        aux_quick_sort(vet, pi+1, dir); //pi+1 é o elemento à frente do pivô
        //aqui, excluímos o pivõ da chamada recursiva. ordenamos o vetor de elementos menores que o pivô e o vetor 
        //de elementos maiores que o pivô
    }
    return;
}

void quick_sort(int vet[], int n)
{
    aux_quick_sort(vet, 0, n-1);
}

int main()
{
    int vet[10] = {6, 9, 1, 8, 15, 4, 13, 9, 2, 2};
    quick_sort(vet, 10);
    cout << "O vetor ordenado eh: " << endl;
    imprime(vet, 10);
    return 0;
}