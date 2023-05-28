// 20221003_PRODUÇAO3.cpp
// Silvano Oliveira
#include <iostream>
using namespace std;

void Menu()
{
	cout << "I - Inicializar os 4 arrays\n"
		 << "L - Listar tudo\n"
		 << "1 - Encontrar o mais novo\n"
		 << "2 - Listar todos os nomes e respetivas idades\n"
		 << "3 - Quantas meninas ha em lamacaes que sejam menores e idade?\n"
		 << "4 - Dado um ano inicial e um ano final lista todas as pessoas nascidas nesse intervalo\n"
		 << "S - Sair do programa\n\n"
		 << "Escolha uma opcao: ";
}

int main()
{
	//declaração de variaveis e arrays
	string nomes[20] = {};
	string localidades[20] = {};
	char sexo[20] = {};
	int anonascimento[20] = {};																														
	string nomesorig[20] = { "Ana","Jose","Antonio","Lara","Hugo","Marta","Jorge","Cristina","Catarina","Marco","Luis","Joao","Jessica","Sofia","Catia","Sara","Barbara","Miguel","Pedro","Lisa" };
	string localorig[20] = { "Lamacaes","Lamacaes","Barroselas","Mazarefes","Neves","Fragoso","Tregosa","Darque","Aldreu","Arcozelo","Barcelinhos","Gamil","Abelheira","Portela","Mujaes","Durraes","Lamacaes","Panque","Palme","Lamacaes" };
	char sexorig[20] = { 'F','M','M','F','M','F','M','F','F','M','M','M','F','F','F','F','F','M','M','F' };
	int anonascorig[20] = { 2005,2008,1980,1984,1987,1974,1993,1999,1966,2000,1989,1995,2001,1979,1981,1983,1977,1987,1989,2007 };
	int i;
	char op;

	do
	{
		//Mostra o menu e recebe opcao
		Menu();
		cin >> op;
		cout << endl;

		//processamento de opcoes
		switch (op)
		{
		case 'i':
		case 'I': //incializa arrays
			for (i = 0; i <= 19; i++)
			{
				nomes[i] = nomesorig[i];
				localidades[i] = localorig[i];
				sexo[i] = sexorig[i];
				anonascimento[i] = anonascorig[i];
			}
			cout << "-> Os arrays foram iniciados!\n\n";
			break;

		case 'l':
		case 'L': //lista arrays
			for (i = 0; i <= 19; i++)
			{
				cout << "-> " << nomes[i] << " vive em " << localidades[i] << " do sexo " << sexo[i] << " nasceu em " << anonascimento[i] << endl;
			}
			cout << endl;
			break;

		case '1': //Mostra o mais novo
		{
			int maisnovo = anonascimento[0];
			string nomemaisnovo = nomes[0];

			for ( i = 0; i <= 19; i++)
			{
				if (anonascimento[i] > maisnovo)
				{
					maisnovo = anonascimento[i];
					nomemaisnovo = nomes[i];
				}
			}
			cout << "-> Mais novo: " << nomemaisnovo << " com " << 2022 - maisnovo << " anos de idade.\n\n";
			break;
		}

		case '2': //lista todos os nomes e idades
			for ( i = 0; i <= 19; i++)
			{
				cout << "-> " << nomes[i] << " tem " << 2022 - anonascimento[i] << " anos de idade!\n";
			}
			cout << endl;
			break;

		case '3': //quantidade meninas de lamaçoes com menos de 18 anos
		{
			int contador = 0;
			for (i = 0; i <= 19; i++)
			{
				if (localidades[i] == "Lamacaes" && sexo[i] == 'F' && anonascimento[i] >= 2004)
				{
					contador++;
				}
			}
			cout << "-> Quantidades de meninas de menor idade em Lamacaes: " << contador << endl << endl;
			break;
		}

		case '4'://dado um ano inicial e ano final lista todas as pessoas nascidas nesse intervalo
		{
			int ano1, ano2;

			cout << "-> Introduza o ano inicial do intervalo: ";
			cin >> ano1;
			cout << "-> Introduza o ano final do intervalo: ";
			cin >> ano2;

			cout << "-> Pessoas nascidas no intervalo desses anos:\n";
			for ( i = 0; i < 19; i++)
			{
				if (anonascimento[i] >= ano1 && anonascimento[i] <= ano2)
				{
					cout << "-> " << nomes[i] << " mora em " << localidades[i] << " do sexo " << sexo[i] << " nasceu em " << anonascimento[i] << " com " << 2022 - anonascimento[i] << " anos de idade. ";
					if (anonascimento[i] > 2004)
					{
						cout << "Menor de idade.\n";
					}
					else
					{
						cout << "Maior de idade.\n";
					}
				}
			}
			cout << endl;
			break;
		}

		default:
			break;
		}
	} while (op != 's' && op != 'S');
}