#include <stdio.h>
#include <iostream>
using namespace std;

const int TAMANHO = 16 + 1;

int contagem(int *array, int tamanho, int multiplo)
    { 
        int contador = 0;
        if(  array != NULL )
        {
             for(int pos = 0; pos < tamanho; pos++)
             {
                if(array[pos] % multiplo == 0)
                { 
                    contador++;
                }
            }
        }
        else
        {
            return -1;
        }
    return contador; 
}
int main()
{
    const int MULTIPLO = 16;

    // ALOCAÇÂO DE ESPAÇO para o array
    int *array_numeros = (int *)malloc(sizeof(int) * TAMANHO);

    // Lê do teclado X números e guarda-os no array;
    for(int pos = 0; pos < TAMANHO; pos++)
    { 
        cin >> array_numeros[pos];
    }
    // MOSTRA o resultado no ecra
    int n_multiplos = contagem(array_numeros, TAMANHO, MULTIPLO);
    if(n_multiplos >= 0)
    {
        cout << "Contagem de multiplos: " << contagem(array_numeros, TAMANHO, MULTIPLO) << endl;
    }
    else
    {
        cout << "Erro: tamanho inválido" << endl; 
    }
    return 0; 
}