#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;

//struct
struct noh
{
	int info;
	struct noh * esq;
	struct noh * dir;
	int altura;
};
typedef struct noh arvore;

//verifica se arvore é vazia
int arv_vazia(arvore *a)
{
	return a == NULL;
}

//pega altura
int altura(arvore * a)
{
	if(a == NULL)
	{
		return 0;
	}
	return a->altura;
}

//cria arvore nó
arvore * novoNo(int n)
{
	arvore * p = (arvore * )malloc(sizeof(arvore));
	p->info = n;
	p->esq = NULL;
	p->dir = NULL;
	p->altura = 1;
	return p;
}

//retorna o menor nó mais proximo
arvore *maxprox(arvore *a)
{
	arvore *atual = a;
	while(atual->dir != NULL)
	{
		atual = atual->dir;
	}
	return atual;
}

//rotação a esquerda
arvore *rotacaoEsquerda(arvore *x)
{
	arvore *y = x->dir;
	arvore *T2 = y->esq;

	//realiza a rotação
	y->esq = x;
	x->dir = T2;

	//atualiza as alturas
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	//retorna nova raiz
	return y;
}

//rotação a direita
arvore *rotacaoDireita(arvore *y)
{
	arvore *x = y->esq;
	arvore *T2 = x->dir;

	//realiza a rotação
	x->dir = y;
	y->esq = T2;

	//atualiza as alturas
	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;

	//retorn a nova raiz
	return x;
}

//calcula o fator de balanceamento
int pegaBalanceamento(arvore *a)
{
	if(a == NULL)
	{
		return 0;
	}
	return altura(a->esq) - altura(a->dir);
}

//pega o maximo entre 2 inteiros
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//insere na arvore
arvore *insere(arvore *a, int valor)
{
	//1.Inserindo normalmente
	if(a == NULL)
	{
		return (novoNo(valor));
	}

	if(valor < a->info)
	{
		a->esq = insere(a->esq, valor);
	}
	else if(valor > a->info)
	{
		a->dir = insere(a->dir, valor);
	}
	else
	{
		return a;
	}

	//2.Atualiza a altura do nó pai
	a->altura = 1 + max(altura(a->esq), altura(a->dir));
	altura(a->dir);

	//3.Fator de balanceamento
	int fb = pegaBalanceamento(a);

	//se houver desbalanceamento

	//3.1.Rotação a Direita
	if(fb > 1 && valor < a->esq->info)
	{
		return rotacaoDireita(a);
	}
	//3.2.Rotacao a Esquerda
	if(fb < -1 && valor > a->dir->info)
	{
		return rotacaoEsquerda(a);
	}
	//3.3.Rotacao Esquerda Direita
	if(fb > 1 && valor > a->esq->info)
	{
		a->esq = rotacaoEsquerda(a->esq);
		return rotacaoDireita(a);
	}
	//3.4.Rotacao Direita Esquerda
	if(fb < -1 && valor < a->dir->info)
	{
		a->dir = rotacaoDireita(a->dir);
		return rotacaoEsquerda(a);
	}

	return a;
}

//exclui na arvore
arvore * remove(arvore *a, int valor)
{
	//1.Removendo normalmente
	if(a == NULL)
	{
		return a;
	}

	//se o valor for menor que na raiz
	if(valor < a->info)
	{
		a->esq = remove(a->esq, valor);
	}
	//se o valor for maior que na raiz
	else if(valor > a->info)
	{
		a->dir = remove(a->dir, valor);
	}
	//se o valor for igual
	else
	{
		//caso com nó sem filho ou apenas um
		if(a->esq == NULL || a->dir == NULL)
		{
			arvore *temp = a->esq ? a->esq : a->dir;

			//caso sem filho
			if(temp == NULL)
			{
				temp = a;
				a = NULL;
			}
			//caso com um filho
			else
			{
				*a = *temp;
			}

			free(temp);
		}
		else
		{
			//caso com nó com dois filhos
			//encontre o sucessor do nó
			arvore *temp = maxprox(a->esq);
			//troca o sucessor com o nó
			a->info = temp->info;
			//exclui
			a->esq = remove(a->esq, temp->info);
		}
	}

	//se a arvore tem apenas um nó
	if(a == NULL)
	{
		return NULL;
	}

	//2.atualiza a altura do nó Atual
	a->altura = 1 + max(altura(a->esq), altura(a->dir));

	//3.Pega o fator de balanceamento deste nó
	int fb = pegaBalanceamento(a);

	//se houver desbalanceamento
	//3.1.Rotacao a Direita
	if(fb > 1 && pegaBalanceamento(a->esq) >= 0)
	{
		return rotacaoDireita(a);
	}
	//3.2.Rotacao a Esquerda
	if(fb < -1 && pegaBalanceamento(a->dir) <= 0)
	{
		return rotacaoEsquerda(a);
	}
	//3.3.Rotacao a Esquerda Direita
	if(fb > 1 && pegaBalanceamento(a->esq) < 0)
	{
		a->esq = rotacaoEsquerda(a->esq);
		return rotacaoDireita(a);
	}
	//3.4.Rotacao Direita Esquerda
	if(fb < -1 && pegaBalanceamento(a->dir) > 0)
	{
		a->dir = rotacaoDireita(a->dir);
		return rotacaoEsquerda(a);
	}

	return a;

}

//imprime em pre-ordem
void arv_imprime_pre(arvore *a)
{
	if(!arv_vazia(a))
	{
		cout << a->info << endl;
		arv_imprime_pre(a->esq);
		arv_imprime_pre(a->dir);
	}
}

int main()
{

	setlocale(LC_ALL, "Portuguese");

	arvore *a = NULL;
	
	int op = 0, x = 0, qntd = 0;

	do
	{
		cout << "Entre com a opção desejada:" << endl;
		cout << "1)Imprimir em Pré-Ordem os elementos da árvore " << endl;
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
				cout << "Será impresso em Pré-Ordem" << endl;
				arv_imprime_pre(a);
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
				a = insere(a, x);
			}
			cout << endl;
			break;

		case 3:
			if(arv_vazia(a) == 0)
			{
				cout << "Entre com o valor que deseja retirar da arvore" << endl;
				cin >> x;
				a = remove(a, x);
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
