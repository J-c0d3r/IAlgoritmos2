#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

struct Pilha
{

	int topo;
	int capacidade;
	int *pElem;

};

void capacidadePilha(struct Pilha *p, int c)
{

	p->topo = -1;
	p->capacidade = c;
	p->pElem = (int*) malloc (c * sizeof(int));

}

int estaCheia(struct Pilha *p)
{

	if(p->topo == p->capacidade - 1)
	{

		return 1;

	}
	else
	{
		return 0;

	}
}

void push(struct Pilha *p, int v)
{

	p->topo++;
	p->pElem[p->topo] = v;

}

int estaVazia(struct Pilha *p)
{

	if(p->topo == -1)
	{

		return 1;

	}
	else
	{

		return 0;
	}

}

int pop(struct Pilha *p)
{

	int aux = p->pElem[p->topo];
	p->topo--;
	return aux;

}

int topo(struct Pilha *p)
{

	return p->pElem[p->topo];

}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	struct Pilha pilha;
	int tam = 0, op = 0;

	cout << "Entre com o tamanho da pilha" << endl;
	cin >> tam;
	cout << endl;

	capacidadePilha(&pilha, tam);

	do
	{

		cout << "O que desejas, caro usuário?" << endl;
		cout << "1) Empilhar(Push) números na pilha" << endl;
		cout << "2) Desempilhar(Pop) números na pilha" << endl;
		cout << "3) Mostrar o número no topo da pilha" << endl;
		cout << "4) Sair do programa" << endl;

		cout << "Opção: ";
		cin >> op;
		cout << endl;

		switch(op)
		{

		case 1:
			if(estaCheia(&pilha))
			{
				cout << "Pilha cheia, escolha outra opção!" << endl << endl;;
			}
			else
			{
				int num;
				cout << "Entre com o número que desejas empilhar:" << endl;
				cin >> num;
				push(&pilha, num);
				cout << "Empilhado!" << endl << endl;;
			}
			break;

		case 2:
			if(estaVazia(&pilha))
			{
				cout << "Pilha vazia, escolha outra opção!" << endl << endl;;
			}
			else
			{
				cout << "Valor Desempilhado: " << pop(&pilha) << endl << endl;;
			}
			break;

		case 3:
			if(estaVazia(&pilha))
			{
				cout << "Não existe topo, pois a pilha está vazia!" << endl << endl;;
			}
			else
			{
				cout << "Topo da pilha: " << topo(&pilha) << endl << endl;;
			}
			break;

		case 4:
				cout << "Adeus!" << endl;
			break;
		
		default:
			cout << "Opção inválida! Escolha outra opção!" << endl << endl;
		}

	}
	while(op != 4);

	return 0;
}