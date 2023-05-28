// Produ��o sobre manipula��o de ficheiros de texto
// Feito por Silvano Oliveira 
// 2022-11-07

#include <iostream>
#include <string>		// stoi (), getline
#include <locale>		// para usar carateres nacionais
#include <iomanip>		// para a formata��o do output 
#include <Windows.h>	// para o temporizador ou marca_passo
#include <algorithm>	// para usar a transform string function
#include <fstream>		// para trabalhar com file
using namespace std;

// ##################################################### TIPIFICA��O E DECLARA��O ESTRUTURA DE DADOS
struct dados
{
	string banco;
	double saldo;
};
dados conta[8];
// ##################################################### FUN��ES COMPLEMENTARES
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
		//Beep(440, 1000); //frequ�ncia, tempo
		Sleep(500); //tempo
	}
}
void desenha_menu()
{
	system("cls"); //Limpa a consola, same as "clear" on linux
	cout << "1 - Inicializar informa��es banc�rias\n";
	cout << "2 - Listar dados das minhas contas banc�rias\n";
	cout << "3 - Levantar de dinheiro\n";
	cout << "4 - Transferir dinheiro\n";
	cout << "5 - Depositar dinheiro\n";
	cout << "6 - Pagar impostos, retirar 15%\n";
	cout << "7 - Mostrar saldo total\n";
	cout << "B - Fazer backup do array de structs\n";
	cout << "M - Mostrar backup\n";
	cout << "R - Consultar registo de opera��es\n" << endl;
	cout << "ESC - Sair\n\n\n";
}
// ##################################################### FUN��ES DE PROCESSAMENTO
bool VerificaSeBancoExiste(string nomeBanco) {
	bool EXISTE = false;
	for (int i = 0; i <= 7; i++)
	{
		if (conta[i].banco == nomeBanco)
		{
			EXISTE = true;
		}
	}
	return EXISTE;
}
bool VerificaValidadeValor(double x) {
	if (x > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int ObtemPosicao(string s) {
	int posicao;
	for (int i = 0; i <= 7; i++)
	{
		if (conta[i].banco == s)
		{
			posicao = i;		
		}
	}
	return posicao;
}
int ObtemSaldo(string s) {
	double saldo;
	for (int i = 0; i <= 7; i++)
	{
		if (conta[i].banco == s)
		{
			saldo = conta[i].saldo;
		}
	}
	return saldo;
}
void GuardaEmFicheiros() {
	ofstream fp1("bancos.txt", ofstream::app);
	ofstream fp2("saldos.txt", ofstream::app);
	for (int i = 0; i <= 7; i++)
	{
		fp1 << conta[i].banco << "\n";
		fp2 << conta[i].saldo << "\n";
	}
	cout << "Sucesso! Guardado altera��es em ficheiro";
	fp1.close();
	fp2.close();
}
// ##################################################### FUN��ES SWITCHCASE
void RegistaContasBancarias() {
	conta[0].banco = "Santander";		conta[0].saldo = 1000;
	conta[1].banco = "Millenium";		conta[1].saldo = 5000;
	conta[2].banco = "Banif"; conta[2].saldo = 3200;
	conta[3].banco = "BPI";				conta[3].saldo = 4000;
	conta[4].banco = "BancoCTT";		conta[4].saldo = 11500;
	conta[5].banco = "Montepio";		conta[5].saldo = 7250;
	conta[6].banco = "Moey";			conta[6].saldo = 15450;
	conta[7].banco = "Caixa";			conta[7].saldo = 3200;
	cout << "Inicializado!";			intermitencia(100);
}
void ListarContasBancarias() {
	system("cls");
	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		cout << "CONTAS BANC�RIAS PESSOAIS:\n##########################";
		for (int i = 0; i <= 7; i++)
		{
			cout << "\nBanco: " << conta[i].banco << endl << "Saldo: " << conta[i].saldo << "�\n##########################";
		}
	}
	else
	{
		cout << " -> Inicialize os dados Primeiro!";
	}
	intermitencia(500);
}
void LevantarDinheiro() {
	string nomeBanco;
	int p;
	double valorLevantar;

	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		cout << " � Qual o banco em que vai levantar dinheiro? ";
		cin >> nomeBanco;
		if (VerificaSeBancoExiste(nomeBanco))
		{
			cout << " � Qual o montante que quer levantar? ";
			cin >> valorLevantar;
			if (VerificaValidadeValor(valorLevantar))
			{
				p = ObtemPosicao(nomeBanco);

				if (ObtemSaldo(nomeBanco) - valorLevantar > 0)
				{

					conta[p].saldo -= valorLevantar;
					cout << "\n -> Opera��o realizada com sucesso!";
					ofstream fp3("registos.txt", ofstream::app);
					fp3 << "Levantou " << valorLevantar << "� do banco " << nomeBanco << "\n";
					fp3.close();

				}
				else
				{
					cout << "\n -> Impossivel realizar opera��o!\n -> O montante que introduziu � superior ao seu saldo!";
					cout << "\n -> Saldo da conta " << conta[p].banco << ": " << conta[p].saldo << "�";
					cout << "\n -> Introduza um valor inferior ao seu saldo OU introduza outro banco para realizar o levantamento\n\n";
					LevantarDinheiro();
				}
			}
			else
			{
				cout << "\n-> Impossivel continuar opera��o, insira um valor positivo v�lido!";
				// ao escrever letras no montante, na proxima vez ele nao l� o nome do banco e assume como errado, tentar com if(nome == "")
			}
		}
		else
		{
			cout << "\n -> Impossivel continuar opera��o!\n -> N�o tem conta neste banco OU inseriu incorretamente o nome do banco!\n\n";
			LevantarDinheiro();
		}
	}
	else
	{
		cout << " -> Inicialize os dados Primeiro!";
	}
	intermitencia(300);
}
void TransfereDinheiro() {
	string nomeBancoEnvia, nomeBancoRecebe;
	int pE, pR;
	double valorTransf;

	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		cout << " � Qual o banco em que vai realizar a transferencia? ";
		cin >> nomeBancoEnvia;
		if (VerificaSeBancoExiste(nomeBancoEnvia))
		{
			cout << " � Para que banco vai fazer a transferencia? ";
			cin >> nomeBancoRecebe;
			if (VerificaSeBancoExiste(nomeBancoRecebe))
			{
				if (nomeBancoEnvia != nomeBancoRecebe)
				{
					cout << " � Qual o montante que quer enviar? ";
					cin >> valorTransf;
					if (VerificaValidadeValor(valorTransf))
					{
						pE = ObtemPosicao(nomeBancoEnvia);
						pR = ObtemPosicao(nomeBancoRecebe);

						if (ObtemSaldo(nomeBancoEnvia) - valorTransf > 0)
						{

							conta[pE].saldo -= valorTransf;
							conta[pR].saldo += valorTransf;
							cout << "\n -> Opera��o realizada com sucesso!";
							ofstream fp3("registos.txt", ofstream::app);
							fp3 << "Transferiu " << valorTransf << "� do banco " << nomeBancoEnvia << " para o banco " << nomeBancoEnvia << "\n";
							fp3.close();
						}
						else
						{
							cout << "\n -> Impossivel realizar opera��o!\n -> O montante que introduziu � superior ao seu saldo!";
							cout << "\n -> Saldo da conta " << conta[pE].banco << ": " << conta[pE].saldo << "�";
							cout << "\n -> Introduza um valor inferior ao seu saldo OU introduza outro banco para realizar o a Transferencia!\n\n";
							TransfereDinheiro();
						}
					}
					else
					{
						cout << "\n-> Impossivel continuar opera��o, insira um valor positivo v�lido!";
						// ao escrever letras no montante, na proxima vez ele nao l� o nome do banco e assume como errado, tentar com if(nome == "")
					}
				}
				else
				{
					cout << "\n -> Impossivel continuar opera��o!\n -> N�o pode enviar a trasferencia para o mesmo banco de onde a realiza!\n\n";
					TransfereDinheiro();
				}

			}
			else
			{
				cout << "\n -> Impossivel continuar opera��o!\n -> N�o tem conta neste banco OU inseriu incorretamente o nome do banco!\n\n";
				TransfereDinheiro();
			}
		}
		else
		{
			cout << "\n -> Impossivel continuar opera��o!\n -> N�o tem conta neste banco OU inseriu incorretamente o nome do banco!\n\n";
			TransfereDinheiro();
		}
	}
	else
	{
		cout << " -> Inicialize os dados Primeiro!";
	}
	intermitencia(300);
}
void DepositarDinheiro() {
	string nomeBanco;
	int p;
	double valorDeposito;

	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		cout << " � Qual o banco em que vai depositar dinheiro? ";
		cin >> nomeBanco;
		if (VerificaSeBancoExiste(nomeBanco))
		{
			cout << " � Qual o montante que vai depositar? ";
			cin >> valorDeposito;

			if (VerificaValidadeValor(valorDeposito))
			{
				p = ObtemPosicao(nomeBanco);
				conta[p].saldo += valorDeposito;
				cout << "\n -> Opera��o realizada com sucesso!";
				ofstream fp3("registos.txt", ofstream::app);
				fp3 << "Depositou " << valorDeposito << "� no banco " << nomeBanco << "\n";
				fp3.close();
			}
			else
			{
				cout << "\n-> Impossivel continuar opera��o, insira um valor positivo v�lido!\n";
				// ao escrever letras no montante, na proxima vez ele nao l� o nome do banco e assume como errado, tentar com if(nome == "")
			}
		}
		else
		{
			cout << "\n -> Impossivel continuar opera��o!\n -> N�o tem conta neste banco OU inseriu incorretamente o nome do banco!\n\n";
			DepositarDinheiro();
		}
	}
	else
	{
		cout << " -> Inicialize os dados Primeiro!";
	}
	intermitencia(300);
}
void PagarImpostos() {
	double flatTax = 0.15;
	{
		if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
		{
			for (int i = 0; i <= 7; i++)
			{
				conta[i].saldo -= (conta[i].saldo * flatTax);
			}
			cout << "Concluido!\nEncarecidamente,\nAutoridade Tributaria";
			ofstream fp3("registos.txt", ofstream::app);
			fp3 << "Pagou Impostos\n";
			fp3.close();
		}
		else
		{
			cout << " -> Inicialize os dados Primeiro!";
		}
		intermitencia(300);
	}
}
void MostraSaldo() 
{
	double saldo = 0;
	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		for (int i = 0; i <= 7; i++)
		{
			saldo += conta[i].saldo;
		}
		cout << "Saldo total das contas: " << saldo << endl;
	}
	else
	{
		cout << " -> Inicialize os dados Primeiro!";
	}
	intermitencia(300);
}
void FazerBackup() {
	string s;
	ofstream fp1("bancos.txt");
	ofstream fp2("saldos.txt");

	if (conta[0].saldo != NULL)	//Se este estiver vazio, toda a estrutura estar� tambem.
	{
		if (!fp1 || !fp2) //nao existe
		{
			GuardaEmFicheiros();
		}
		else //existe
		{
			remove("bancos.txt");
			remove("saldos.txt");
			GuardaEmFicheiros();
		}
	}
	else
	{
		cout << " -> Nao existe dados para fazer backup!\n -> Inicialize os dados Primeiro!";
	}
	intermitencia(200);
}
void MostrarBackup() {
	string s1, s2;
	ifstream fp1("bancos.txt");
	ifstream fp2("saldos.txt");

	if (conta[0].saldo != NULL)
	{
		if (!fp1 || !fp2) //if (!getline(fpl, s))
		{
			cout << "Fa�a primeiro o backup!";
		}
		else
		{
			system("cls");
			cout << "------------------------\n";
			while (getline(fp1, s1) && getline(fp2, s2))
			{
				cout << "Banco: " << s1 << endl << "Saldo: " << s2 << "\n------------------------\n";
			}
			fp1.close();
			fp2.close();
		}
	}
	else
	{
		cout << "Inicialize os dados primeiro";
	}
	intermitencia(500);
}
void MostraRegistoOperacoes() {
	string registo;
	ifstream fp3("registos.txt");

	if (!fp3) //if (!getline(fpl, s))
	{
		cout << "N�o foram encontradas opera��es realizadas!";
	}
	else
	{
		system("cls");
		cout << "=================================================\n";
		while (getline(fp3, registo))
		{
			cout << registo << endl;
		}
		cout << "=================================================\n";
		fp3.close();
	}
	intermitencia(500);
}
// ##################################################### FUN��O PRINCIPAL OU MAIN
int main()
{
	//locale::global(std::locale(""));
	//1252 � o codepage LATIN1 que parece funcionar para n�s (Portugal)
	//1253 Greek, 1255 Hebrew, etc...
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	SetConsoleTitle(TEXT("Gestor de contas banc�rias pessoais"));
	system("Color A"); //cor do texto da consola

	//sempre que abre o programa remove/limpa os ficheiros
	remove("bancos.txt");
	remove("saldos.txt");
	remove("registos.txt");

	char op;
	do
	{
		desenha_menu();
		op = _getwch();
		switch (op)
		{
		case '1':RegistaContasBancarias();	break;
		case '2':ListarContasBancarias();	break;
		case '3':LevantarDinheiro();		break;
		case '4':TransfereDinheiro();		break;
		case '5':DepositarDinheiro();		break;
		case '6':PagarImpostos();			break;
		case '7':MostraSaldo();				break;
		case 'B':							break;
		case 'b':FazerBackup();				break;
		case 'M':							break;
		case 'm':MostrarBackup();			break;
		case 'R':;							break;
		case 'r':MostraRegistoOperacoes();	break;
		default: beep_erro(op);				break;
		}
	} while (op != 27);
	cout << "\tAt� breve.\n\n\n"; intermitencia(50);
}
