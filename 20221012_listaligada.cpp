#include <iostream>
using namespace std;

//tipificação de struct para lista ligada
struct listaligada
{
	int numero;//a lista será ordenada por aqui
	int qualquercoisa; //item genérico; podia ser preço, idade, nome, etc...
	listaligada* proximo; //membro para apontador
};

listaligada* CABECA = NULL; //o primeiro da lista ou head (cabeça)
listaligada* CAUDA = NULL; //o último ou tail (cauda)

int main()
{
	//3 apontadores genéricos para struct:
	listaligada* novo;
	listaligada* atual;
	listaligada* anterior;

	//dados genéricos para o programa:
	char op;
	int n, qqc; //membro 1 n=numero; membro2 qqc=qualquer coisa

	do
	{
		cout << "\nLISTA LIGADA-EXERCICIO DIDATICO (TRABALHO COOPERATIVO) ------------------------------------------\n";
		cout << "[1:listar]\n[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]" << "\n"
			<< "[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]\n"
			<< "[a:limpa lista][b:init lista com 3 nos][c:lista ordenada? (sim/nao)][d:ordena lista][e:conta nos]\n"
			<< "[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor]\n[0:SAIR]\n"
			<< "Insira a opcao: ";
		cin >> op;

		switch (op)
		{
		case '1': //LISTAR	
			if (CABECA == NULL)
			{
				cout << "lista vazia\n";
			}
			else
			{
				//atribui o endereço da CABECA ao atual, pois o atual vai ser usado e atualizado no ciclo. 
				//Pois a cabeca nao pode ser usada no ciclo pois nao pode ser atualizada
				atual = CABECA;

				//percorrer a lista até o atual ser nulo:
				while (atual != NULL)
				{
					//output dos conteudos dos membros, do que é apontado
					cout << endl << (*atual).numero << "\t" << (*atual).qualquercoisa << "\t" << (*atual).proximo;

					//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
					//por forma a continuar o ciclo
					atual = (*atual).proximo;
				}
			}

			//outup endereços cabeca e cauda
			cout << "\nCABECA: " << CABECA << endl;
			cout << "CAUDA:  " << CAUDA << "\n\n";
			break;

		case '2': //INSERE PRIMEIRO
			novo = (listaligada*)malloc(sizeof(listaligada)); //pedir espaço na memoria
			cout << "Insira um numero: ";
			cin >> (*novo).numero;
			cout << "Insira o qualquercoisa: ";
			cin >> (*novo).qualquercoisa;
			(*novo).proximo = NULL; //assume lista vazia e que é o primeiro logo vai ser o unico, logo o apontador para o proximo é nulo.
			CABECA = novo;
			CAUDA = novo;
			break;

		case '3': //INSERE NO FIM
			novo = (listaligada*)malloc(sizeof(listaligada)); //pedir espaço na memoria
			(*CAUDA).proximo = novo; //o endereço apontado na CAUDA.proximo vai tomar o endereço do novo
			cout << "Insira um numero: ";
			cin >> (*novo).numero;
			cout << "Insira o qualquercoisa: ";
			cin >> (*novo).qualquercoisa;
			(*novo).proximo = NULL; //como insere no fim o "proximo" vai ser nulo
			CAUDA = novo;
			break;

		case '4': //INSERE AO MEIO
			novo = (listaligada*)malloc(sizeof(listaligada)); //pedir espaço na memoria

			//atribui valores aos membros do novo
			cout << "Insira um numero: ";
			cin >> (*novo).numero;
			cout << "Insira o qualquercoisa: ";
			cin >> (*novo).qualquercoisa;

			//atribui o endereço da CABECA ao atual, pois o atual vai ser usado e atualizado no ciclo. 
			//Pois a cabeca nao pode ser usada no ciclo pois nao pode ser atualizada
			atual = CABECA;
			anterior = NULL; //inicializa o anterior

			//percorre a lista enquanto que o numero inserido for maior que o da lista.
			while ((*novo).numero > (*atual).numero)
			{
				anterior = atual; //atribui o endereço do atual ao anterior, pois o atual vai ser atualizado antes de ser apagado/libertad

				//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
				//por forma a continuar o ciclo
				atual = (*atual).proximo;
			}

			(*novo).proximo = atual; //o apontador do novo vai apontar para o atual
			(*anterior).proximo = novo; //o apontador do anterior vai apontar para o novo
			break;

		case '5': //INSERE COMPLETO
			novo = (listaligada*)malloc(sizeof(listaligada)); //pedir espaço na memoria

			//atribui valores aos membros do novo
			cout << "Insira um numero: ";
			cin >> (*novo).numero;
			cout << "Insira o qualquercoisa: ";
			cin >> (*novo).qualquercoisa;

			if (CABECA == NULL)
			{
				(*novo).proximo = NULL; //assume lista vazia e que é o primeiro logo vai ser o unico, logo o apontador para o proximo é nulo.
				CABECA = novo;
				CAUDA = novo;
			}

			else if (CABECA == CAUDA || (*CABECA).proximo == CAUDA)
			{
				(*CAUDA).proximo = novo; //o endereço apontado na CAUDA.proximo vai tomar o endereço do novo
				(*novo).proximo = NULL; //como insere no fim o "proximo" vai ser nulo
				CAUDA = novo;
			}

			else
			{
				//atribui o endereço da CABECA ao atual, pois o atual vai ser usado e atualizado no ciclo. 
				//Pois a cabeca nao pode ser usada no ciclo pois nao pode ser atualizada
				atual = CABECA;
				anterior = NULL; //inicializa o anterior

				//percorre a lista enquanto que o numero inserido for maior que o da lista.
				while ((*novo).numero > (*atual).numero)
				{
					anterior = atual; //atribui o endereço do atual ao anterior, pois o atual vai ser atualizado antes de ser apagado/libertad

					//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
					//por forma a continuar o ciclo
					atual = (*atual).proximo;
				}

				(*novo).proximo = atual; //o apontador do novo vai apontar para o atual
				(*anterior).proximo = novo; //o apontador do anterior vai apontar para o novo
			}
			break;

		case '6': // 6:REMOVE CABEÇA
			atual = (*CABECA).proximo;
			free(CABECA);
			CABECA = atual;
			break;

		case '7': //REMOVE CAUDA

			atual = CABECA;
			anterior = NULL;

			//percorrer a lista até o atual ser nulo:
			while ((*atual).proximo != NULL)
			{
				anterior = atual; //atribui o endereço do atual ao anterior, pois o atual vai ser atualizado antes de ser apagado/libertado

				//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
				//por forma a continuar o ciclo
				atual = (*atual).proximo;
			}
			(*anterior).proximo = NULL;
			CAUDA = anterior;
			free(atual);


			break;
			// --------------------------------------------------------------------------------------------------------------------- 8:REMOVE AO MEIO
		case '8':

			break;
			// --------------------------------------------------------------------------------------------------------------------- 9:REMOVE COMPLETO
		case '9':

			break;
		case 'a': //LIMPA LISTA
			//atribui o endereço da CABECA ao atual, pois o atual vai ser usado e atualizado no ciclo. 
			//Pois a cabeca nao pode ser usada no ciclo pois nao pode ser atualizada
			atual = CABECA;

			//percorrer a lista até o atual ser nulo:
			while (atual != NULL)
			{
				anterior = atual; //atribui o endereço do atual ao anterior, pois o atual vai ser atualizado antes de ser apagado/libertado

				//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
				//por forma a continuar o ciclo
				atual = (*atual).proximo;

				free(anterior); //liberta o espaço do atual anterior
			}

			CABECA = NULL;
			CAUDA = NULL;

			break;

		case 'b': //INICIALIZA COM 3 NÓS "fixos"
			//primeiro nó:
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço		
			CABECA = novo;
			(*novo).numero = 1;
			(*novo).qualquercoisa = 1111;
			(*novo).proximo = NULL;
			//segundo nó:
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço		
			(*CABECA).proximo = novo;
			(*novo).numero = 5;
			(*novo).qualquercoisa = 5555;
			(*novo).proximo = NULL;
			//terceiro nó:
			atual = novo; //para atar o último neste (novo vem de trás)
			novo = (struct listaligada*)malloc(sizeof(struct listaligada));//pedir espaço					
			(*atual).proximo = novo;
			(*novo).numero = 9;
			(*novo).qualquercoisa = 9999;
			(*novo).proximo = NULL;
			//antes de terminar, definir o último da lista:
			CAUDA = novo;
			break;

			// --------------------------------------------------------------------------------------------------------------------- c:LISTA ORDENADA? SIM/NÃO
		case 'c':

			break;
			// --------------------------------------------------------------------------------------------------------------------- d:ORDENA LISTA
		case 'd':

			break;

		case 'e': //CONTA NÓS
		{
			int contador = 0;

			//atribui o endereço da CABECA ao atual, pois o atual vai ser usado e atualizado no ciclo. 
			//Pois a cabeca nao pode ser usada no ciclo pois nao pode ser atualizada
			atual = CABECA;

			//percorrer a lista até o atual ser nulo:
			while (atual != NULL)
			{
				anterior = atual; //atribui o endereço do atual ao anterior, pois o atual vai ser atualizado antes de ser apagado/libertado

				//muda o endereço do atual para o endereço do membro "proximo" da struct apontada pelo "*atual"
				//por forma a continuar o ciclo
				atual = (*atual).proximo;

				contador++;
			}
			cout << "Numero de nos existentes na lista: " << contador << endl;
			break;

		}
			// --------------------------------------------------------------------------------------------------------------------- f:LER 2 NUMS; EXISTEM? TROCAR NÓS
		case 'f':

			break;
			// --------------------------------------------------------------------------------------------------------------------- g:INVERTER A LISTA
		case 'g':

			break;
			// --------------------------------------------------------------------------------------------------------------------- H:INVERTER A LISTA
		case 'H':
			cout << "\n\nEXERCICIO PRATICO COM LISTA LIGADA\nO objetivo e elaborar as opcoes 5 e 9.\nPara isso, comecar pelas mais simples:\n"
				<< "Exemplo: 2->3->4->5\n"
				<< "Sera pedido que alguns formandos facam as opcionais, para no final \njuntar tudo e o exercicio ficar completo."
				<< "\nNesse caso: respeitar a organizacao do codigo, nao usar funcoes, \ncomentar todas a linhas relevantes, identificar autor e data.\nObrigado. :)\n\n";

			break;
			// --------------------------------------------------------------------------------------------------------------------- 0:SAIR
		case '0':
			cout << "\n fim do programa...\n";
			break;
			// --------------------------------------------------------------------------------------------------------------------- DEFAULT
		default:
			cout << "\7"; //beep do sistema
			break;
		}
	} while (op != '0');
}