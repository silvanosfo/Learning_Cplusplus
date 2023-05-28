// Produção sobre manipulação de ficheiros de texto
// Feito por Silvano Oliveira 
// 2022-11-07

#include <iostream>
#include <string>		// stoi (), getline
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
	system("cls"); //Limpa a consola, same as "clear" on linux
	cout << "1 - Inicializar ficheiro nomes.txt com 16 nomes\n";
	cout << "2 - Inicializar ficheiro localidades.txt com 16 localidades\n";
	cout << "3 - Listar nomes e respectivas localidades\n";
	cout << "4 - Ler localidade e contar ocorrencia, lista quem vive nessa respetiva localidade\n";
	cout << "5 - Trocar localidade de um nome\n" << endl;

	cout << "ESC - Sair\n\n\n";
}
void fCaso1InicializaNomes()
{
	ofstream fpd("nomes.txt");
	fpd << "Ana Rita Cunha" << "\n";
	fpd << "Bela Costa Silva" << "\n";
	fpd << "Carlos Alberto Costa" << "\n";
	fpd << "Carlos Ferreira" << "\n";
	fpd << "Daniel Bastos Gomes" << "\n";
	fpd << "Diogo Silva Ferraz" << "\n";
	fpd << "Elvira Gomes Pendes" << "\n";
	fpd << "Fernanda Maria Silva" << "\n";
	fpd << "Fernando Barros" << "\n";
	fpd << "Gilherme Barros" << "\n";
	fpd << "Hilda Fonseca Silva" << "\n";
	fpd << "José Manuel Carvalho" << "\n";
	fpd << "José Alberto Gomes" << "\n";
	fpd << "Maria Silva Bastos" << "\n";
	fpd << "Sofia Bastos Torres" << "\n";
	fpd << "Telmo Armando Matos" << "\n";
	fpd.close();
	cout << "Inicializado!"; intermitencia(100);
}
void fCaso2InicializaLocalidades()
{
	ofstream fpl("localidades.txt");
	fpl << "Braga" << "\n";
	fpl << "Barcelos" << "\n";
	fpl << "Viana do Castelo" << "\n";
	fpl << "Caminha" << "\n";
	fpl << "Póvoa de Varzim" << "\n";
	fpl << "Porto" << "\n";
	fpl << "Esposende" << "\n";
	fpl << "Santo Tirso" << "\n";
	fpl << "Lisboa" << "\n";
	fpl << "Valença" << "\n";
	fpl << "Braga" << "\n";
	fpl << "Aveiro" << "\n";
	fpl << "Espinho" << "\n";
	fpl << "Chaves" << "\n";
	fpl << "Vila Real" << "\n";
	fpl << "Braga" << "\n";
	fpl.close();
	cout << "Inicializado!"; intermitencia(100);
}
string BuscarLocalidade(int n)
{
	string s, localidade;
	int p = 1;

	ifstream fp2("localidades.txt");
	while (getline(fp2, s))
	{
		//se o inteiro recebido for igual ao numero da linha do ciclo entao devolver o conteudo da linha
		if (p == n)
		{
			localidade = s;
		}
		p++;
	}
	fp2.close();
	return localidade;
}
void fCaso3ListarNomesLocalidades()
{
	system("cls");
	string s;
	int linha = 0; //acumulador para ser lançado para funçao de acordo com a linha em questão
	ifstream fp1("nomes.txt");
	ifstream fp2("localidades.txt");

	if (!fp1 || !fp2) //if (!getline(fpl, s))
	{
		cout << "Ficheiros vazios ou inexistentes!";
	}
	else
	{
		while (getline(fp1, s))
		{
			linha++;
			cout << s << "   " << "\t" << BuscarLocalidade(linha) << endl;
		}
		fp1.close();
		fp2.close();
	}
	intermitencia(1000);
}
void fCaso4ContarOcorrenciaLocal()
{
	string s, s1, s2, localidade;
	int contador = 0;
	ifstream fpn1("nomes.txt");
	ifstream fpl2("localidades.txt");

	if (!fpn1 || !fpl2) //if (!getline(fpl, s))
	{
		cout << "Ficheiro vazio ou inexistente!";
	}
	else
	{
		cout << "Introduza uma localidade a procurar: ";
		getline(cin, localidade);

		while (getline(fpl2, s))
		{
			if (s == localidade)
			{
				contador++;
			}
		}
		fpl2.close();
		cout << "Essa localidade aparece " << contador << " vezes.\n";

		if (contador >= 1)
		{
			ifstream fpl2("localidades.txt");
			cout << "Pessoas que vivem nessa localidade: ";
			while (getline(fpn1, s1) && getline(fpl2, s2))
			{
				//se a localidade inserida for igual à da linha, entao lista o nome respetivo do ciclo;
				if (localidade == s2)
				{
					cout << s1 << ", ";
				}
			}
			cout << endl;
		}
		fpn1.close();
		fpl2.close();
	}
	intermitencia(500);
}
void fCaso5TrocarLocalidade()
{
	string s, s2, nome, localidade_nova;
	bool existe = false;
	ifstream fpl1("nomes.txt");
	ifstream fpl20("localidades.txt");

	if (!fpl1 || !fpl20) //if (!getline(fpl, s))
	{
		cout << "Ficheiros vazios ou inexistentes!";
	}

	else //o ficheiro existe
	{
		cout << "Introduza um nome a procurar: ";
		getline(cin, nome);

		while (getline(fpl1, s))
		{
			if (s == nome)
			{
				existe = true;
			}
		}
		fpl1.close();

		if (existe)
		{
			//fazer a substituição
			cout << "Nome encontrado! Insira a nova localidade: ";
			getline(cin, localidade_nova);
			ifstream fpl1("nomes.txt");
			ofstream fptemp("localidadestemp.txt", ofstream::app);

			while (getline(fpl1, s) && getline(fpl20, s2))
			{
				if (s != nome)
				{
					fptemp << s2 << "\n";
				}
				else //s==nome
				{
					fptemp << localidade_nova << "\n";
				}
			}
			cout << "Sucesso! Alterada localidade de " << nome;
			fpl1.close();
			fpl20.close();
			fptemp.close();
			remove("localidades.txt");
			rename("localidadestemp.txt", "localidades.txt");
		}

		else
		{
			cout << "Impossivel substituir, nome nao encontrado!";
		}
	}
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
	SetConsoleTitle(TEXT("CONSOLA - Produção Silvano Oliveira"));

	char op;
	do
	{
		desenha_menu();
		op = _getwch();
		switch (op)
		{
		case '1':fCaso1InicializaNomes();		break;
		case '2':fCaso2InicializaLocalidades();	break;
		case '3':fCaso3ListarNomesLocalidades();break;
		case '4':fCaso4ContarOcorrenciaLocal();	break;
		case '5':fCaso5TrocarLocalidade();		break;
		default: beep_erro(op);					break;
		}
	} while (op != 27);
	cout << "\tAté breve.\n\n\n"; intermitencia(50);
}
