#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

struct elemento
{

	int info;
	struct elemento *prox;

};
typedef struct elemento Elemento;

Elemento *lst_cria(void)
{
	return NULL;
}

Elemento *lst_insere(Elemento *lst, int val)
{

	Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = val;
	novo->prox = lst;
	return novo;

}

void lst_imprime(Elemento *lst)
{

	Elemento *p;
	for(p = lst; p != NULL; p = p->prox)
	{
		cout << "Info = " << p->info << endl;
	}

}

int lst_vazia(Elemento *lst)
{

	return (lst == NULL);

}

Elemento *lst_retira(Elemento *lst, int val)
{

	Elemento *a = NULL;
	Elemento *p = lst;
	while(p != NULL && p->info != val)
	{

		a = p;
		p = p->prox;

	}

	if(p == NULL)
	{

		cout << "Não encontrou o elemento" << endl;
		return NULL;
	}
	else if(a == NULL)
	{

		lst = p->prox;

	}
	else
	{
		a->prox = p->prox;

	}

	free(p);
	return lst;

}

Elemento *lst_busca(Elemento *lst, int v)
{

	Elemento *p;
	for(p = lst; p != NULL; p = p->prox)
	{
		if(p->info == v)
		{
			return p;

		}

	}
	return NULL;

}

Elemento *lst_insere_ordenado(Elemento *lst, int val)
{

	Elemento *novo;
	Elemento *a = NULL;
	Elemento *p = lst;
	while(p != NULL && p->info < val)
	{
		a = p;
		p = p->prox;

	}

	novo = (Elemento*) malloc(sizeof(Elemento));
	novo->info = val;

	if(a == NULL)
	{
		novo->prox = lst;
		lst = novo;
	}
	else
	{

		novo->prox = a->prox;
		a->prox = novo;

	}
	return lst;

}


int main()
{
	setlocale (LC_ALL, "Portuguese");

	struct elemento lst;
	int op, val;

	do
	{
		cout << "Insira a operação desejada" << endl;
		cout << "1- Inserir elementos na lista" << endl; //
		cout << "2- Inserir elementos ordenados na Lista" << endl;//
		cout << "3- Buscar elementos na Lista" << endl;//
		cout << "4- Imprimir elementos na Lista" << endl; //
		cout << "5- Excluir elementos da Lista" << endl; //
		cout << "6- Sair do programa" << endl; //
		cout << endl;
		cin >> op;

		switch(op)
		{

		case 1:
			
			cout << "Insira o elemento" << endl;
			cin >> val;
			lst_insere(&lst, val);
			break;

		case 2:
			
			cout << "Insira o valor" << endl;
			cin >> val;
			lst_insere_ordenado(&lst, val);
			break;
		case 3:
			
			cout << "Insira o valor que deseja buscar" << endl;
			cin >> val;
			lst_busca(&lst, val);
			break;

		case 4:
			if(lst_vazia(&lst) == 1)
			{
				cout << "Lista vazia!" << endl;
			}
			else
			{
				lst_imprime(&lst);
			}

			break;

		case 5:
			if(lst_vazia(&lst) == 0){
			cout << "Insira o valor que deseja retirar" << endl;
			cin >> val;
			lst_retira(&lst, val);
			}else{
				cout << "Lista vazia! Impossivel excluir elementos" << endl;
			}
			break;

		case 6:
			cout << "Adeus!" << endl;
			break;

		default:
			cout << "Opção inválida! Escolha outra opção!" << endl << endl;

		}
	}
	while(op != 6);

	return 0;
}
