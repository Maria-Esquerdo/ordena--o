// Ordenação por intercalação
#include <iostream>
using namespace std;

void imprime(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
    }
}

// Função que junta, ordenadamente, os subvetores:
void merge(int vet[], int esq, int meio, int dir)
{
    int i = esq;      // Define contador para a primeira metade
    int j = meio + 1; // Define contador para a segunda metade
    int k = 0;        // Contador para o vetor auxiliar
    int aux[dir - esq + 1];
    // Percorre as duas metades, copiando, para o vetor auxiliar, os menores, primeiro, depois o que sobrar (maiores)
    while ((i <= meio) && (j <= dir))
    {
        if (vet[i] <= vet[j])
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    }
    // Copia o resto dos elementos que sobraram, os maiores, para as posições finais do vetor
    while (i <= meio)
    {
        aux[k++] = vet[i++];
    }
    while (j <= dir)
    {
        aux[k++] = vet[j++];
    }
    // Copia o vetor auxiliar para o vetor original
    for (int m = esq; m <= dir; m++)
    {
        vet[m] = aux[m - esq];
    }
}

// Algoritmos de recursão:
void aux_merge_sort(int vet[], int esq, int dir)
{
    if (esq >= dir)
        return;
    else
    {
        int meio = (dir + esq) / 2;
        aux_merge_sort(vet, esq, meio);
        aux_merge_sort(vet, meio + 1, dir);
        merge(vet, esq, meio, dir);
    }
}

void merge_sort(int vet[], int n)
{
    aux_merge_sort(vet, 0, n - 1);
}

int main()
{
    int vet[10] = {6, 9, 1, 8, 15, 4, 13, 9, 2, 2};
    merge_sort(vet, 10);
    cout << "O vetor ordenado eh: " << endl;
    imprime(vet, 10);
    return 0;
}