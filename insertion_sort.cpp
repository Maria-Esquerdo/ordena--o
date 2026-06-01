// Algoritmo de inserção
#include <iostream>
using namespace std;

// A partir do segundo item do vetor:
// Selecionar o item e compará-lo com os anteriores 
// Se satisfaz a condição de ordenação, insere o novo item no lugar do anterior, empurrando os demais

// DESLOCAR todos os elementos maiores que o pivô para a direita, abrindo espaço para inserir o pivô

void insertion_sort (int vet[], int n)
{
    for (int i=1; i<n; i++) // Começa do segundo elemento. Loop que delimita o elemento pivô
    {
        int atual = vet[i];  //Define o elemento pivô
        int j = i-1;    //Contador para os elementos anteriores ao pivô.
        while (( j >= 0 ) && (vet[j] > atual))   //A condição começa no item anterior ao pivô e, enquanto o
        {                                      //elemento anterior for maior que o pivô, eles vão sendo 
            vet[j+1] = vet[j];                //empurrados pra frente
            j--;
        }
        vet[j+1] = atual;  //Insere o elemento atual (menor que os da frente) na posiçãp
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
    insertion_sort(vet, n);
    cout << "O vetor ordenado eh: " << endl;
    for (int i=0; i<n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
    return 0;
}