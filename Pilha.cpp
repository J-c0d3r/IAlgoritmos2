#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Pilha
{

	int topo; //guarda posição do top
	int capacidade;	//guarda capacidade
	float *pElem; //ponteiro para float

};

void criarPilha(struct Pilha *p, int c)
{

	p->topo = -1;
	p->capacidade = c;
	p->pElem = (float*) malloc (c * sizeof(float)); //aloca tamanho

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

int main()
{

	struct Pilha minhapilha;
	int d;
	cin >> d;

	criarPilha(&minhapilha, d);
	estaVazia(&minhapilha);



	return 0;
}
