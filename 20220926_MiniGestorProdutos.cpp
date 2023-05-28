// 20220926_MiniGestorProdutos.cpp : Silvano Oliveira
/*	declarar array de 5 strings, para conter designa��es de
	produtos;
�e inicializ�-lo na declara��o com �Bola, Sapato,
	Camisa, Casaco, Chap�u�
�declarar array de 5 inteiros, para conter os pre�os dos
	produtos
�e inicializ�-lo na declara��o com �12, 15, 16, 7, 4�
	Considerar que o programa ter� as seguintes op��es:
1-Encontrar o pre�o mais elevado
2-Calcular o pre�o m�dio dos produtos
3-Encontrar o (nome do) produto mais caro
4-Mudar um produto
	pedir a posi��o do array que vai ser modificada
	pedir a designa��o do novo produto
	pedir o respetivo pre�o
	atualizar nos 2 arrays essas informa��es
5-LISTAR os 2 arrays no ecr�
0-SAIR*/

#include <iostream>
using namespace std;

int main()
{
	//declara��o variaveis
	int op;
	string produtos[5] = { "Bola","Sapato","Camisa","Casaco","Chapeu" };
	int precos[5] = { 12,15,16,7,4 };
	int i;
	int precomaiscaro;
	string produtomaiscaro;


	//Introdu�ao informacao programa
	cout << "Escolha uma opcao:\n"
		 << "1 - Encontrar o preco mais elevado\n"
		 << "2 - Calcular o preco medio dos produtos\n"
		 << "3 - Encontrar o (nome do) produto mais caro\n"
		 << "4 - Mudar um produto\n"
		 << "5 - LISTAR os 2 arrays no ecra\n"
		 << "0 - SAIR\n\n";

	//ciclo para correr programa infinitamente exceto colocado o 0
	do
	{
		cout << "\nInsira o numero correspondente da opcao a executar: ";
		cin >> op;

		switch (op)
		{
			case 1:  //preco mais caro
				precomaiscaro = precos[0]; //assume preco mais caro como o primeiro
				for ( i = 1; i <= 4; i++)  //ciclo para analisar se ha precos maiores que o primeiro
				{
					if (precos[i] > precomaiscaro) //condi�ao para atribuir valor ao precomaiscaro quando este for menor
					{
						precomaiscaro = precos[i];
					}
				}
				cout << "O preco mais elevado e: " << precomaiscaro << endl;
				break;

			case 2:  //Calcular o pre�o m�dio dos produtos
				{
					double media = 0;
					double soma = 0;
					for (i = 0; i <= 4; i++) //ciclo para calcular a soma
					{
						soma = soma + precos[i];
					}
					media = soma / i; //calcula a media atraves da soma a dividir pelo i que sera 5 no final.
					cout << "A media dos precos dos produtos da: " << media << endl;
					break;
				}

			case 3:  //NOME PRODUTO MAIS CARO
				precomaiscaro = precos[0]; //assume preco mais caro como o primeiro
				produtomaiscaro = produtos[0]; //assume o nome do primeiro
				for (i = 1; i <= 4; i++)  //ciclo para analisar se ha precos maiores que o primeiro
				{
					if (precos[i] > precomaiscaro) //condi�ao para atribuir o nome ao produtomaiscaro quando este for menor de preco
					{
						produtomaiscaro = produtos[i];
					}
				}
				cout << "O produto mais caro e: " << produtomaiscaro << endl;

				break;

			case 4: //MUDAR UM PRODUTO
					//pedir a posi��o do array que vai ser modificada
					//pedir a designa��o do novo produto
					//pedir o respetivo pre�o
					//atualizar nos 2 arrays essas informa��es
				cout << "Introduza o numero da posicao a ser modificado: ";
				cin >> i;
				i = i - 1;
				cout << "Escreva o nome do novo produto a inserir: ";
				cin >> produtos[i];
				cout << "Insira o respetivo preco do produto designado: ";
				cin >> precos[i];
				
				break;

			//listar arrays no ecra
			case 5:
				//ciclo para listar produtos e precos
				cout << "Lista de produtos e dos precos: \n";
				for (i = 0; i <= 4; i++)
				{
					cout << produtos[i] << " - " << precos[i] << endl;
				}
				break; 

		default:
			break;
		}
	} while (op != 0);
}