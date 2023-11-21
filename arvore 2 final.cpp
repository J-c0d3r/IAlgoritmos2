#include <iostream>
#include <stdlib.h>

using namespace std;


struct noh
{
	int info ;
	struct noh *esq;
	struct noh *dir;
};
typedef struct noh arvore;


arvore* abb_busca (arvore* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		return abb_busca (r->esq, v);
	else if (r->info < v)
		return abb_busca (r->dir, v);
	else return r;
}


void sep ()
{
	cout << endl;
	cout << "_______________________________________________________________" << endl;
	cout << endl;
}

arvore *arv_criavazia( arvore* a)
{
	return NULL;
}

int arv_vazia(arvore* a)
{
	return a == NULL ;
}

void imp_ord(arvore* a)
{
	if (!arv_vazia(a))
	{
		imp_ord(a->esq);
		cout << a->info << "  ";
		imp_ord(a->dir);
	}

}

arvore* abb_insere (arvore* a, int v)
{
	if (a == NULL)
	{
		a = (arvore*) malloc(sizeof(arvore));
		a->info = v;
		a->esq = a->dir = NULL;

	}
	else if (v < a->info)
		a->esq = abb_insere( a->esq, v);
	else
		a->dir = abb_insere( a->dir, v);

	return a;

}

arvore* abb_retira (arvore* r, int v)
{
	if (r == NULL)
	{
		cout << "Valor nao enconteado" << endl;
		return NULL;
	}

	else if (r->info > v)
		r->esq = abb_retira(r->esq , v);
	else if (r->info < v)
		r->dir = abb_retira(r->dir, v);
	else   //achou o nó a remover
	{
		// nó sem filhos
		if (r->esq == NULL && r->dir == NULL)
		{
			free (r);
			r = NULL;
		}
		// nó só tem filho à direita * /
		else if (r->esq == NULL)
		{
			arvore* t  = r;
			r = r->dir;
			free (t);

		}
		else if (r->dir == NULL)
		{
			arvore*t = r ;
			r = r->esq;
			free(t);
		}
		//nó com 2 filhos
		else
		{
			arvore* f = r->esq;
			while(f->dir != NULL)
			{
				f = f->dir;
			}
			r->info = f->info;
			f->info = v;
			r-> esq = abb_retira(r->esq, v);
		}

	}
	return r;
}


int main()
{
	int op, val, q	;
	arvore* a = NULL ;
	cout << endl;
	cout << "  Entre com :" << endl;
	cout << "    _1 para imprimir os elementos da arvore em ordem " << endl;
	cout << "    _2 para inserir um elemento na arvore " << endl;
	cout << "    _3 para excluir um elemento da arvore " << endl;
	cout << "    _4 para excluir toda a arvore " << endl;
	cout << "    _  outro valor para finalizar o programa " << endl;
	sep();
	while(true)
	{

		cin >> op;

		switch(op)
		{
		case 1:
			imp_ord(a);
			break;
		case 2:
			cout << "Quantos numeros deseja inserir?" << endl;
			cin >> q;
			if (q != 0) cout << "entre com o valor" << endl;
			for (int i = 0 ; i < q ; i++)
			{
				cin >> val;
				a = abb_insere(a, val);

			}
			break;
		case 3:
			cout << "qual valor deseja deletar?" << endl;
			cin >> val;
			a = abb_retira(a, val);
			break;
		case 4:
			a = NULL;
			break;
		default:
			return 0;
			break;
		}
		sep();
	}
}
