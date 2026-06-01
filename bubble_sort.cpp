// Algoritmo de ordenação Bubble Sort
#include <iostream>
using namespace std;

//Compara os elementos de 2 em 2, identificando o menor entre eles e colocando na posição certa
// Isso se repete sucessivamente até o vetor estar ordenado

void bubble_sort (int vet[], int n)
{
    int aux = 0;
    for (int i=0; i<n-1; i++) // Repete o processo de comparação n vezes
    {
        for (int j=0; j<n-1; j++)  // Compara o elemento atual com o próximo
        {
            if (vet[j+1] < vet[j])
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux; 
            }
        }
    }
    return;
}

int main()
{
    int n;
    cout << "Digite o tamanho do vetor: " << endl;
    cin >> n;
    int *vet = new int[n];
    cout << "Inicialize o vetor com valores: " << endl;
    for (int i=0; i<n; i++)
    {
        cin >> vet[i];
    }
    bubble_sort(vet, n);
    cout << "O vetor ordenado eh: " << endl;
    for (int i=0; i<n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
    return 0;
}