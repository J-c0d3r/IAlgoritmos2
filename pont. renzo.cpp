#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	/*
	int a = 10;

	int *p; //ponteiro

	p = &a;

	cout << "Valor de a: " << *p << endl;
	*/

	//(*p)++; soma do conte�do

	// p printa o endere�o pq � uma variavel que armazena o endere�o
	// *p printa o valor que est� armazenado

	/*
	int v[3] = {10, 20, 30};

	//int *p;
	//p = &v[0];

	cout << "V[0] " << v << endl;

	*/
	
	int a = 10;
	int *p;
	int **pp;
	
	p = &a;
	
	pp = &p;
	
	cout << "1 p: " << *p << endl;
	cout << "2 p: " << **pp << endl;
	// a = p = pp	
	cout << endl << endl;
	
	cout << "1 p: " << p << endl;
	cout << "2 p: " << *pp << endl;

	return 0;
}
