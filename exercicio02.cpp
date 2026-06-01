#include <iostream>
using namespace std;

/*  Modifique o algoritmo Bubble sort para que o processo deordenacao seja encerrado antecipadamente 
caso o vetor fique ordenado ao fim de uma passagem. */

void imprime (int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
    
}

//Compara dois a dois
void bubble_sort_otimizado (int vet[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        bool trocou = false; //aqui, ainda não ouve troca
        for (int j=0; j<n-1; j++)
        {
            if (vet[j+1] < vet[j]) //Se, para algum j no loop, entrar no if, é pq algum elemento está
            {                     // desordenado
                int aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
                bool trocou = true;
            }
        }
        if (!trocou)  // Se nao trocou =  para o algoritmo
        break;
    }
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
    bubble_sort_otimizado(vet, n);
    cout << "O vetor ordenado eh: " << endl;
    imprime(vet, n);
    return 0;
}