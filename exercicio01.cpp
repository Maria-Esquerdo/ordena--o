#include <iostream>
using namespace std;

/* Considere a sequencia S = [6, 9, 1, 8, 15, 4, 13, 9, 2, 2].
Ilustre a execucao dos algoritmos de ordenacao a seguir, exibindo os estados intermediarios de S.
▶ Bubble sort
▶ Selection sort
▶ Insertion sort */

//Bubble Sort: comparação par a par
void bubble_sort (int vet[], int n)
{
    for (int i=1; i<n; i++) 
    {
        for (int j=0; j<i; j++)
        {
            if (vet[i] < vet[j])
            {
                int aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}

// Selection Sort: seleciona o menor elemento do vetor e troca de posição com o priemeiro elemento
void selection_sort (int vet[], int n)
{
    for (int i=0; i<(n-1); i++) //Percorre o vetor inteiro
    {
        int menor = i;
        for (int j=i; j<n; j++) //Compara do elemento i em diante para achar o menor
        {
            if (vet[j] < vet[menor])
            {
                vet[menor] = vet[j];
            }
        }
    }
}

// Insertion Sort: Começa do segundo elemento, o pivô, se for menor, empurra os outros pra frente, abrindo
// espaço para o pivô entrar na posição mais à esquerda
void insertion_sort (int vet[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int atual = vet[i]; //Define o pivô
        int j = i-1; //Define o contador dos elementos anteriores
        while ((j>=0) && (vet[j] > atual)) //condição 1: deve percorrer os anteriores a i, até chegar na posição 0
        {                                 //condição 2: enquando o elemento anterior a vet[i] for maior que ele
            vet[j+1] = vet[j];  //Empurra os elementos maiores que vet[i] pra frente
            j--;               // Assim, abre-se uma posção vaga 
        }
        vet[j+1] = atual;  //Nessa posição, o vet[i] é inserido
    }
}


void imprime (int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
    
}

int main()
{
    int n=10;
    int vet[10] = {6, 9, 1, 8, 15, 4, 13, 9, 2, 2};
    cout << "Vetor ordenado com Bubble Sort: " << endl;
    bubble_sort(vet, n);
    imprime(vet, n);
    cout << endl;
    cout << "Vetor ordenado com Selection Sort: " << endl;
    selection_sort(vet, n);
    imprime(vet, n);
    cout << endl;
    cout << "Vetor ordenado com Insertion Sort: " << endl;
    insertion_sort(vet, n);
    imprime(vet, n);
    cout << endl;
    return 0;
}