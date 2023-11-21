#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
void troca(int *i, int *j)
{

	int *temp;
	*temp = *i;
	*i = *j;
	*j = *temp;

	cout << *i << " " << *j << endl;
	
}
*/

int main()
{

	/*
	1.A)Sim, o ponteiro nao está recebendo o valor de referência de x

	int x, *p;
	x=100;
	p = &x;

	cout << "Valor de p: " << *p << endl;

	1.B)Tá certo
	int i = 10, j = 20;

	troca(&i, &j);
	
	2)
	
	
	*/
	
	int v[3] = {10,20,30};
	int *p;
	
	p = &v[0];
	
	//cout << "Teste: " << v << endl; //
	cout << "Teste: " << v+2 << endl; //endereço
	cout << "Teste: " << *(v+2) << endl; //conteudo da posição
	cout << "Teste: " << *v+2 << endl; //soma conteudo
	cout << "Teste: " << v+2 << endl; //


	return 0;
}
