//Algoritmo de ordenação por seleção
#include <iostream>
using namespace std;

//Seleciona o menor elemento do vetor e troca com a primeira posição
//Depois repete o processo para o subvetor


void selection_sort (int vet[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        int menor = i;
        for (int j=1; j<n; j++)
        {
            if (vet[j] < vet[menor])
            {
                int aux = 0;
                aux = vet[j];
                vet[j] = vet[menor];
                vet[menor] = aux;
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
    selection_sort(vet, n);
    cout << "O vetor ordenado eh: " << endl;
    for (int i=0; i<n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
    return 0;
}