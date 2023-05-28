// Silvano30.cpp
// 20220930
// Silvano Oliveira

#include <iostream>
using namespace std;

int main()
{
	//declaração variaveis
	char op;
	int listanumeros[5] = { 236,8,134,81,176 };
	int listaoriginal[5] = { 236,8,134,81,176 };
	int i;
	int maior;
	int contaimpares;
	bool existenegativos;
	int n;
	int contan;
	int maiorpar;
	int menor;
	double soma;
	double media;
	bool existeimparmenormedia;


	//Introduçao informacao programa e o que faz
	cout << "Escolha uma opcao:\n"
		<< "I - Inicializa o array com os numeros originais\n"
		<< "L - Lista o array\n"
		<< "D - Informar o numero maior\n"
		<< "A - Quantidade de numeros impares no array\n"
		<< "Z - Colocar todas as posicoes a 0\n"
		<< "C - Ha ou nao numeros negativos?\n"
		<< "B - Ler numero e indicar quantas vezes existe no array\n"
		<< "F - Qual o maior numero par?\n"
		<< "S - SAIR\n"
		<< "------------------------------------------------------\n"
		<< "G - Exclui o maior e o menor e calcula a media dos restantes\n"
		<< "J - Recebe um numero e coloca-o na posicao que o utilizador referir\n"
		<< "H - Ha algum numero impar menor que a media dos 5 numeros?\n";


	//ciclo para correr programa infinitamente exceto colocado o 's'
	do
	{
		//Texto para informar o utilizador a inserir uma opcao
		cout << "\nEscolha uma das opcoes a executar: ";
		cin >> op;

		switch (op)	//fazer determinadas intrucoes mediante a opcao escolhida
		{
		case 'i':
		case 'I':	//Inicializa o array com os numeros originais
			for ( i = 0; i <=4; i++)
			{
				listanumeros[i] = listaoriginal[i];
			}
			cout << "O array foi iniciado com os numeros originais!\n";
			break;

		case 'l':
		case 'L':	//Lista o array
			for (i = 0; i <= 4; i++)
			{
				cout << listanumeros[i] << " ";
			}
			break;

		case 'd':
		case 'D':	//Informar o numero maior
		{
			maior = listanumeros[0];	//assume que o maior é o primeiro sempre que esta opcao for escolhida
			for (i = 0; i <= 4; i++)
			{
				if (maior < listanumeros[i])
				{
					maior = listanumeros[i];
				}
			}
			cout << "Numero maior encontrado: " << maior << endl;
			break;
		}

		case 'a':
		case 'A':	//Quantidade de numeros impares no array
		{
			contaimpares = 0;	//assume que existem sempre 0 todas as vezes (se o array for alterado ele assume 0 de novo)
			for (i = 0; i <= 4; i++)
			{
				if (listanumeros[i] % 2 == 1)
				{
					contaimpares++;
				}
			}
			cout << "Quantidades de numeros impares existentes: " << contaimpares << endl;
			break;
		}

		case 'z':
		case 'Z':	//Colocar todas as posicoes a 0
			for ( i = 0; i <=4; i++)
			{
				listanumeros[i] = 0;
			}
			cout << "Foram inseridos zeros em toda as posicoes!\n";
			break;

		case 'c':
		case 'C':	//Ha ou nao numeros negativos?
		{
			existenegativos = false;	//Assume sempre de novo que nao existem
			for ( i = 0; i <=4; i++)
			{
				if (listanumeros[i] < 0)
				{
					existenegativos = true;
				}
			}
			if (existenegativos)	//Consoante verde ou false faz o respetivo output
			{
				cout << "Sim, ha numeros negativos!\n";
			}
			else
			{
				cout << "Nao, nao ha numeros negativos!\n";
			}
			break;
		}

		case 'b':
		case 'B':	//Ler numero e indicar quantas vezes existe no array
		{
			contan = 0; //Zera o contador todas as vezes.

			//Informa o utilizador para inserir um numero
			cout << "Insira um numero: ";
			cin >> n;

			for ( i = 0; i <=4; i++)
			{
				if (listanumeros[i] == n)
				{
					contan++;
				}
			}
			cout << "O numero inserido existe " << contan << " vezes no array!" << endl;
			break;
		}

		case 'f':
		case 'F':	//Informar o maior numero par
		{
			//ciclo para atribuir o primeiro numero par do array à variavel (maiorpar)
			for (i = 4; i >= 0; i--)
			{
				if (listanumeros[i] % 2 == 0) //Começamos a trabalhar so com os pares
				{
					maiorpar = listanumeros[i];	//assume que o maior é o numero par a aparecer sempre que esta opcao for escolhida
				}
			}
			
			//ciclo para comparar os numeros pares com a variavel (maior par)
			for ( i = 0; i <= 4; i++)
			{
				if (listanumeros[i] % 2 == 0) //Trabalhamos so com os pares
				{
					if (maiorpar < listanumeros[i])
					{
						maiorpar = listanumeros[i];
					}
				}
			}
			cout << "O maior numero par encontrado foi: " << maiorpar << endl;
			break;
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 'g':
		case 'G':	//Excluindo o maior e o menor e calcula a media dos restantes
		{
			//processamento o menor e o maior ao escolher esta opcao
			menor = listanumeros[0]; //assume que o menor é o primeiro sempre que esta opcao for escolhida
			maior = listanumeros[0]; //assume que o maior é o primeiro sempre que esta opcao for escolhida
			soma = 0; //zera a soma sempre que esta opcao for escolhida
			media = 0; //

			for (i = 0; i <= 4; i++)
			{
				if (menor > listanumeros[i])
				{
					menor = listanumeros[i];
				}
				if (maior < listanumeros[i])
				{
					maior = listanumeros[i];
				}
			}

			for (i = 0; i <= 4; i++)
			{
				soma = soma + listanumeros[i];
			}

			//retira da soma o maior e o menor
			soma = soma - maior - menor;

			//faz a media  a partir da soma a dividir por tres
			media = soma / 3;

			cout << "Excluindo o maior e o menor a media dos restantes da: " << media << endl;
			break;
		}

		case 'j':
		case 'J': //Recebe um numero e coloca-o na posicao que o utilizador referir
			cout << "Introduza um numero: ";
			cin >> n;

			cout << "Indique em qual posicao o quer colocar: ";
			cin >> i;
		
			//Insere o numero na posiçao pedida e informa
			listanumeros[i - 1] = n;
			cout << "O numero foi inserido com sucesso!\n";
			break;

		case 'h':
		case 'H': //Ha algum numero impar menor que a media dos 5 numeros?"
		{
			//zera variaveis
			existeimparmenormedia = false;
			soma = 0;
			media = 0;

			for (i = 0; i <= 4; i++) //ciclo para calcular soma
			{
				soma = soma + listanumeros[i];
			}
			media = soma / i; // calcula a media

			for (i = 0; i <= 4; i++) //ciclo para verificar se é impar e ao mesmo tempo menor que a media
			{
				if (listanumeros[i] % 2 == 1)
				{
					if (listanumeros[i] < media)
					{
						existeimparmenormedia = true;
					}
				}
			}

			if (existeimparmenormedia) //output consoante condiçao verdadeira ou false
			{
				cout << "Sim ha\n";
			}
			else
			{
				cout << "Nao, nao ha\n";
			}
			break;
		}

		default:
			break;
		}

	} while (op != 'S' && op!='s');
}