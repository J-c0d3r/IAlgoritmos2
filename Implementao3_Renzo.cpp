#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;

//cria a struct
struct noh
{

	int info;
	struct noh *esq;
	struct noh *dir;

};
typedef struct noh arvore;

//cria arvore
arvore * arv_criavazia()
{
	return NULL;
}

//verifica se arvore ta vazia
int arv_vazia(arvore *a)
{
	return a == NULL;
}

//insere elemento na arvore
arvore * abb_insere(arvore *a, int v)
{
	if(a == NULL)
	{
		a = (arvore*) malloc(sizeof(arvore));
		a->info = v;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(v < a->info)
	{
		a->esq = abb_insere(a->esq, v);
	}
	else
	{
		a->dir = abb_insere(a->dir, v);
	}
	return a;
}

//exluir elementos
arvore * abb_retira(arvore *r, int v)
{
	if(r == NULL)
	{
		cout << "Valor não encontrado!" << endl << endl;
		return NULL;
	}
	else if(r->info > v)
	{
		r->esq = abb_retira(r->esq, v);
	}
	else if(r->info < v)
	{
		r->dir = abb_retira(r->dir, v);
	}
	else
	{
		if(r->esq == NULL && r->dir == NULL)
		{
			free(r);
			r = NULL;
		}
		else if(r->esq == NULL)
		{
			arvore *t = r;
			r = r->dir;
			free(t);
		}
		else if(r->dir == NULL)
		{
			arvore *t = r;
			r = r->esq;
			free(t);
		}
		else
		{
			arvore *f = r->esq;
			while(f->dir != NULL)
			{
				f = f->dir;
			}
			r->info = f->info;
			f->info = v;
			r->esq = abb_retira(r->esq, v);
		}
	}
	return r;
}
//imprime
void arv_imprime(arvore *a)
{
	//imprime em ordem
	if(!arv_vazia(a))
	{
		arv_imprime(a->esq); //mostra saE
		cout << a->info << " "; //mostra raiz
		arv_imprime(a->dir); //mostra saD
	}

}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	arvore *a = arv_criavazia();

	int op = 0, x = 0, qntd = 0;

	do
	{
		cout << "Entre com a opção desejada:" << endl;
		cout << "1)Imprimir em ordem os elementos da árvore " << endl;
		cout << "2)Inserir elementos na árvore " << endl;
		cout << "3)Excluir elementos da árvore " << endl;
		cout << "4)Sair do programa " << endl;
		cin >> op;
		cout << endl;
		switch(op)
		{
		case 1:
			if(arv_vazia(a) == 0)
			{
				cout << "Será impresso em Ordem" << endl;
				arv_imprime(a);
				cout << endl << endl;
			}
			else
			{
				cout << "Árvore vazia!" << endl << endl;
			}
			break;

		case 2:
			cout << "Quantos valores desejas inserir, caro usuário?" << endl;
			cin >> qntd;
			cout << "Entre com os valores que deseja inserir na arvore" << endl;
			for(int i = 0; i < qntd; i++)
			{
				cin >> x;
				a = abb_insere(a, x);
			}
			cout << endl;
			break;

		case 3:
			if(arv_vazia(a) == 0)
			{
				cout << "Entre com o valor que deseja retirar da arvore" << endl;
				cin >> x;
				a = abb_retira(a, x);
				cout << endl;
			}
			else
			{
				cout << "Árvore vazia!" << endl << endl;
			}
			break;
		}
	}
	while(op != 4);

	cout << "Adeus!" << endl;

	return 0;
}
