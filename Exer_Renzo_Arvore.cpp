#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct noh {

	int info;
	noh * esq;
	noh * dir;

};
typedef struct noh arvore;

//cria
arvore * arv_criavazia(void) {
	return NULL;
}

//verifica vazia
int arv_vazia(arvore * a) {
	return a == NULL;
}

//cria nó
arvore * arv_cria(char c, arvore * sae, arvore * sad) {

	arvore * p = (arvore * ) malloc (sizeof(arvore));
	if(p == NULL) exit(1);
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;

}

//busca
int arv_pertence(arvore * a, char c) {
	if(arv_vazia(a)) {
		cout << "Nao encontrado" << endl;
		return 0;
	} else {
		return a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
	}
}

//pre-ordem
void arv_imprimePreO(arvore * a) {
	if(!arv_vazia(a)) {
		cout << a->info << endl;
		arv_imprimePreO(a->esq);
		arv_imprimePreO(a->dir);
	}
}

//pos-ordem
void arv_imprimePosO(arvore * a) {
	if(!arv_vazia(a)) {
		arv_imprimePosO(a->esq);
		arv_imprimePosO(a->dir);
		cout << a->info << endl;
	}
}

//ordem
void arv_imprimeO(arvore * a) {
	if(!arv_vazia(a)) {
		arv_imprimeO(a->esq);
		cout << a->info << endl;
		arv_imprimeO(a->dir);
	}
}

int main() {

	int op;
	
	arvore * a1 = arv_cria('d' , arv_criavazia(), arv_criavazia());
	arvore * a2 = arv_cria('b' , arv_criavazia(), a1);
	arvore * a3 = arv_cria('e' , arv_criavazia(), arv_criavazia());
	arvore * a4 = arv_cria('f' , arv_criavazia(), arv_criavazia());
	arvore * a5 = arv_cria('c', a3, a4);
	arvore * a = arv_cria('a', a2, a5);
	
	

	cout << "Escolha a operacao" << endl;
	cout << "1- Imprimir em Ordem, Pós-ordem, Pré-Ordem" << endl;
	cout << "2- Verifica se o elemento existe" << endl;
	cout << "3- Sair do programa" << endl;
	cin >> op;

	while(op != 3) {

		if(op == 1) {

			//ordem
			cout << "Ordem" << endl;
			arv_imprimeO(a);

			//pos-ordem
			cout << "Pos-Ordem" << endl;
			arv_imprimePosO(a);
			
			//pre-ordem
			cout << "Pre-Ordem" << endl;
			arv_imprimePreO(a);
		}

		if(op == 2) {
			if(arv_vazia(a)) {
				cout << "Arvore vazia!" << endl;
			} else {
				int c;
				cout << "Entre com o valor que deseja procurar" << endl;
				cin >> c;
				arv_pertence(a, c);
			}

		}
		
		cin >> op;

	}
	cout << "Adeus!" << endl;

	return 0;
}
