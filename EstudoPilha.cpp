#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;

struct Pilha
{
	int topo; //posição do topo
	int capacidade; //capacidade
	float *pElem;
};

void criaPilha(struct Pilha *p, int c)
{
	p->topo = -1;
	p->capacidade = c;
	p->pElem = (float*) malloc (c * sizeof(float));
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

int estaCheia(struct Pilha *p){
	if(p->topo == p->capacidade -1){
		return 1;
	}else{
		return 0;
	}
}

void push(struct Pilha *p, float v){
	p->topo++;
	p->pElem [p->topo] = v;
}

float pop(struct Pilha *p){
	float aux = p->pElem [p->topo];
	p->topo--;	
	return aux;
}

float retornaTopo(struct Pilha *p){
	return p->pElem[p->topo];
}

void retornaPos(struct Pilha *p, int pos){
	if(pos > p->topo-1){
		cout << "Posição inexistente!" << endl;
		return;
	}else{
		cout << "Numero da posição(" << pos << "): " << p->pElem[pos] << endl;
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	struct Pilha pilha;
	int tam = 0, op = 0;

	cout << "Entre com o tamanho da pilha" << endl;
	cin >> tam;
	cout << endl;

	criaPilha(&pilha, tam);

	do
	{

		cout << "O que desejas, caro usuário?" << endl;
		cout << "1) Empilhar(Push) números na pilha" << endl;
		cout << "2) Desempilhar(Pop) números na pilha" << endl;
		cout << "3) Mostrar o número no topo da pilha" << endl;
		cout << "4) Mostrar a elemento da posição que desejas" << endl;
		cout << "5) Sair do programa" << endl;

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
				cout << "Topo da pilha: " << retornaTopo(&pilha) << endl << endl;;
			}
			break;
		
		case 4:
			int pos;
			cout << "Entre com a posição" << endl;
			cin >> pos;
			retornaPos(&pilha, pos);
			break;
		
		case 5:
				cout << "Adeus!" << endl;
			break;
		
		default:
			cout << "Opção inválida! Escolha outra opção!" << endl << endl;
		}

	}
	while(op != 5);
	
	return 0;
}
