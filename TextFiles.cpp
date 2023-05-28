#include <iostream>
#include <string>		// stoi (), getline
#include <conio.h>		// _getch ()
#include <locale>		// para usar carateres nacionais
#include <iomanip>		// para a formatação do output 
#include <Windows.h>	// para o temporizador ou marca_passo
#include <algorithm>	// para usar a transform string function
#include <fstream>		// para trabalhar com file
using namespace std;

// ##################################################### PEQUENAS FUNÇÕES COMPLEMENTARES
void intermitencia(int t)
{
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t);
}
void beep_erro(char op)
{
	if (op != 27)
	{
		cout << "Opcao incorreta!" << "\7";
		//Beep(440, 1000); //frequência, tempo
		Sleep(500); //tempo
	}
}

// ##################################################### FUNÇÕES DOS 'cases' DO PROGRAMA
void desenha_menu()
{
	system("cls");
	cout << "  \nExercício prático - algoritmos diversos, com text file, funcões, matriz, ...\n\n" << endl;
	cout << "  L - (L)istar ficheiro               D - (D)eletar ficheiro\n";
	cout << "  N - Escrever (N)o início do fich.   A - (A)crescentar nome no fim \n";
	cout << "  S - (S)ubstituir nome no ficheiro   P - (P)rocurar nome no ficheiro\n";
	cout << "  C - (C)ontar nomes no ficheiro      1 - (1) Contar ocorrência de certo nome\n" << endl;

	cout << "  J - a(J)uda\n" << endl;

	cout << "  ESC - sair\n\n\n";
}
void fCasoAAjuda()
{
	int i;
	for (i = 7; i >= 1; i--)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t" << "ah!... faça mas é os algoritmos!";
		cout << "\n\n\n\n\t";
		cout << "  " << i << "...";
		Sleep(600);
	}
}
void fCasoZInicializaFicheiroCom16()
{
	ofstream fpd("lista.txt");
	fpd << "Ana Rita Cunha" << "\n";
	fpd << "Bela Costa Silva" << "\n";
	fpd << "Carlos Alberto Costa" << "\n";
	fpd << "Carlos Serafim Ferreira" << "\n";
	fpd << "Daniel Bastos Gomes" << "\n";
	fpd << "Diogo Silva Ferraz" << "\n";
	fpd << "Elvira Gomes Pendes" << "\n";
	fpd << "Fernanda Maria Silva" << "\n";
	fpd << "Fernando Gomes Barros" << "\n";
	fpd << "Gilherme Alexandre Barros" << "\n";
	fpd << "Hilda Fonseca Silva" << "\n";
	fpd << "José Manuel Carvalho" << "\n";
	fpd << "José Alberto Gomes" << "\n";
	fpd << "Maria Silvéria Bastos" << "\n";
	fpd << "Anabela Bastos Torres" << "\n";
	fpd << "Teodoro Armando Matos" << "\n";
	fpd.close();
	cout << "Inicializado!"; intermitencia(100);
}
void fCasoLListarNomes()
{
	system("cls");
	string s;
	ifstream fpl("lista.txt");
	cout << "\n";

	if (!fpl) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}
	else {
		while (getline(fpl, s))
		{
			cout << s << endl;
		}
		fpl.close();
	}
	intermitencia(100);
}
void fCasoAAppendNomes()
{
	string nome;
	ofstream fp("lista.txt", ofstream::app);

	cout << "Introduza um nome: ";
	getline(cin, nome);
	fp << nome << "\n";
	cout << "Adicionado no final";
	fp.close();
	intermitencia(100);
}
void fCasoNInsereInicioNomes()
{
	string nome;
	ofstream fp("lista.txt", ofstream::out);

	cout << "Introduza um nome: ";
	getline(cin, nome);
	fp << nome << "\n";
	cout << "Adicionado no inicio";
	fp.close();
	intermitencia(100);
}
void fCasoCContarNomes()
{
	string s;
	int contador = 0;
	ifstream fp("lista.txt");
	

	if (!fp) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}
	else 
	{
		while (getline(fp, s))
		{
			contador++;
		}
		fp.close();
	}
	cout << "Quantidade de nomes existente: " << contador;
	intermitencia(100);
}
void fCaso1ContarOcorrenciaNome()
{
	string s, nome;
	int contador = 0;
	ifstream fp("lista.txt");

	cout << "Introduza um nome: ";
	getline(cin, nome);

	if (!fp) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}
	else
	{
		while (getline(fp, s))
		{
			if (s == nome)
			{
				contador++;
			}
		}
		fp.close();
	}
	cout << "Esse nome aparece " << contador << " vezes.";
	intermitencia(100);
}
void fCasoPProcuraNome()
{
	string s, nome;
	bool existe = false;
	ifstream fp("lista.txt");

	cout << "Introduza um nome: ";
	getline(cin, nome);

	if (!fp) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}
	else
	{
		while (getline(fp, s))
		{
			if (s == nome)
			{
				existe = true;
			}
		}
		fp.close();
	}

	if (existe)
	{
		cout << "O nome foi encontrado!";
	}
	else
	{
		cout << "O nome nao foi encontrado!";
	}
	intermitencia(100);
}
void fCasoDDeleteFile()
{
	int del;
	del = remove("lista.txt");

	if (del == 0)
		cout << "Ficheiro Removido!";
	else
		cout << "\nFicheiro Inexistente!";
	intermitencia(100);
}
void fCasoSSubstituirNome()
{
	string s, nome, novonome;
	bool existe = false;
	ifstream fp("lista.txt");

	if (!fp) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}

	else //o ficheiro existe
	{
		cout << "Introduza um nome a procurar: ";
		getline(cin, nome);

		while (getline(fp, s))
		{
			if (s == nome)
			{
				existe = true;
			}
		}
		fp.close();

		if (existe)
		{
			//fazer a substituição
			cout << "Nome encontrado! Insira o nome substituto: ";
			getline(cin, novonome);
			ifstream fp("lista.txt");
			ofstream fp2("lista2.txt", ofstream::app);

			while (getline(fp, s))
			{
				if (s != nome)
				{
					fp2 << s << "\n";
				}
				else //s==nome
				{
					fp2 << novonome << "\n";
				}
			}
			fp.close();
			fp2.close();
			fCasoDDeleteFile();
			rename("lista2.txt", "lista.txt");
		}

		else
		{
			cout << "Impossivel substituir, nome nao encontrado!";
		}
	}
	intermitencia(100);
}
string BuscarNome(int n)
{
	string s, nome;
	int p = 1;

	ifstream fpo("lista.txt");
	while (getline(fpo,s))
	{
		if (p == n)
		{
			nome = s;
		}
		p++;
	}
	fpo.close();
	return nome;
}
void fCasoY5UltimosNomesInvert()
{
	string s;
	int contador = 0;
	ifstream fp("lista.txt");

	while (getline(fp, s))
	{
		contador++;
	}
	fp.close();

	ofstream fpi("listainvert.txt", ofstream::app);

	for ( int i = contador; i > contador - 5; i--)
	{
		s = BuscarNome(i);
		fpi << s << "\n";
	}
	fpi.close();

	intermitencia(100);
}
// ##################################################### FUNÇÃO PRINCIPAL OU MAIN
int main()
{
	//locale::global(std::locale(""));
	//1252 é o codepage LATIN1 que parece funcionar para nós (Portugal)
	//1253 Greek, 1255 Hebrew, etc...
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	SetConsoleTitle(TEXT("	    - OPERAÇÕES COM FICHEIRO DE TEXTO E OUTRAS - "));
	
	char op;
	do
	{
		desenha_menu();
		op = _getch();
		switch (op)
		{
			case 'a': case 'A':fCasoAAppendNomes();				break;
			case 'l': case 'L':fCasoLListarNomes();				break;
			case 'n': case 'N':fCasoNInsereInicioNomes();		break;
			case 'z': case 'Z':fCasoZInicializaFicheiroCom16();	break;
			case 'c': case 'C':fCasoCContarNomes();				break;
			case 'd': case 'D':fCasoDDeleteFile();				break;
			case 's': case 'S':fCasoSSubstituirNome();			break;
			case 'p': case 'P':fCasoPProcuraNome();				break;
			case '1':fCaso1ContarOcorrenciaNome();				break;
			case 'j': case 'J':fCasoAAjuda();					break;
			case 'y': case 'Y':fCasoY5UltimosNomesInvert();		break;
			default: beep_erro(op);								break;
		}
	} while (op != 27);
	cout << "\tAté breve.\n\n\n"; intermitencia(50);
}
