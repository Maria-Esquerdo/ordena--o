#include <iostream>
using namespace std;


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

void heap_max (int vet[], int n, int i) //i é o índice do nó atual
{
    int maior = i; //define maior elemento como raiz
    int esq = (2*i) + 1; //filho esquerdo do nó
    int dir = (2*1) + 2; //filho direito do nó
    //verifica se o filho esquerdo existe e se é maior que o pai
    if ((esq<n) && (vet[esq] > vet[maior]))
    {
        maior = esq;
    }
    //Verifica se o filho direito existe e se ele é maior que o maior atual
    if ((dir<n) && (vet[dir] > vet[maior]))
    {
        maior = dir;
    }
    //Se o maior for diferente do nó pai, troca-se o elemento maior com o elemento pai
    if (maior != i)
    {
        troca(&vet[i], &vet[maior]);
    }
    heap_max(vet, n, maior); //chama a função recursivamente para organizar a árvore, assumindo o 
    //elemento maior como o maior
}

// constrói a Max Heap. chama heap_max de baixo para cima. troca a raiz (maior elemento) com o último
// reduz o tamanho da heap e chama heap_max para reorganizar. repete até que  todos  os elementos estejam
// ordenados

void heap_sort (int vet[],int n)
{
    // o for começa no último nó que tem filho (n/2 - 1) e vai até a raiz (0) e constrói a heap
    for (int i = (n/2)-1; i>=0; i++)
    {
        heap_max(vet, n, i); // i indica o nó atual 
    } // depois disso, o vetor eh um heap maximo valido
    // aqui o vetor é de fato ordenado, indica o tamanho atual do vetor e vai diminuindo
    for (int i = n-1; i>0; i--)
    {
    troca(&vet[0], &vet[i]); // troca a raiz (maior) com o último atual elemento
    heap_max(vet, i, 0); // chama a função para repetir o processo, com i sendo o novo tamanho 
    // (exclui o elemento já ordenado)
    }
}

int main()
{
    int vet[10] = {6, 9, 1, 8, 15, 4, 13, 9, 2, 2};
    heap_sort(vet, 10);
    cout << "O vetor ordenado eh: " << endl;
    imprime(vet, 10);
    return 0;
}