#include <iostream>
using namespace std;


void imprime(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "   " << vet[i] << "    ";
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