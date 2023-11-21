#include <iostream>
#include <time.h>
#include <cstdlib>
#include <locale>

using namespace std;

void funcaoBUBBLE(int VETB[], int y);
void funcaoINSERTION(int VETI[], int y);
void funcaoSELECTION(int VETS[], int y);

int main()
{

	setlocale(LC_ALL, "Portuguese");
	int x;
	//int x = 100;
	//int x = 500;
	//int x = 1000;
	//int x = 5000;
	//int x = 10000;
	//int x = 50000;
	//int x = 100000;

	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "SEJA BEM VINDO AO NOSSO PROGRAMA CONTADOR DE TEMPO DE ORDENAÇÃO DE VETOR!!!" << endl;
	cout << "1º PASSO ANTES DE TUDO, PRECISO QUE VOCÊ MEU CARO AMIGO USUÁRIO, ESCOLHA ALGUM DESSES NÚMEROS QUE O SENHOR DESEJA" << endl;
	cout << "ANALISAR O TEMPO QUE CADA ALGORITMO DE ORDENAÇÃO LEVARÁ \nPARA ORDERNAR O NOSSO VETOR" << endl << endl;
	cout << " 100 \n 500 \n 1000 \n 5000 \n 10000 \n 50000 \n 100000" << endl << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;


	cout << "Escreva o número que deseja: ";
	cin >> x;

	cout << endl << endl;

	if(x >= 100000)
	{

		cout << "OLOKO USUÁRIO, VC GOSTA DE VER O PROCESSADOR TRABALHAR \\O/" << endl;
		cout << "ENTÃO, PARA NÃO TE DEIXAR ESPERANDO, APRECIE ESSA OBRA DE ARTE" << endl;

		cout << "                                               ,---. " 		  << endl;
		cout << "                                              /    | " 		  << endl;
		cout << "                                             /     | " 		  << endl;
		cout << "                         Gandalf            /      | " 		  << endl;
		cout << "                                           /       | " 		  << endl;
		cout << "                                      ___,'        | " 		  << endl;
		cout << "                                    <  -'          : " 	      << endl;
		cout << "                                     `-.__..--'``-,_\\_ "       << endl;
		cout << "                                        |o/ <o>` :,.)_`> "     << endl;
		cout << "                                        :/ `     ||/) " 		  << endl;
		cout << "                                        (_.).__,-` |\\ "        << endl;
		cout << "                                        /( `.``   `| : " 	  << endl;
		cout << "                                        \\'`-.)  `  ; ; " 	  << endl;
		cout << "                                        | `       /-< "        << endl;
		cout << "                                        |     `  /   `. "      << endl;
		cout << "                        ,-_-..____     /|  `    :__..-'\\ "     << endl;
		cout << "                       /,'-.__\\\\  ``-./ :`      ;       \\ "    << endl;
		cout << "                       `\\ `\\  `\\\\  \\ :  (   `  /  ,   `. \\ "   << endl;
		cout << "                         \\` \\   \\\\   |  | `   :  :     .\\ \\ "  << endl;
		cout << "                          \\ `\\_  ))  :  ;     |  |      ): : " << endl;
		cout << "                         (`-.-'\\ ||  |\\ \\   ` ;  ;       | | " << endl;
		cout << "                          \\-_   `;;._   ( `  /  /_       | |	 "	<< endl;
		cout << "                           `-.-.// ,'`-._\\__/_,'         ; | " << endl;
		cout << "                              \\:: :     /     `     ,   /  |	"  << endl;
		cout << "                               || |    (        ,' /   /   | " << endl;
		cout << "                               ||                ,'   / "	  << endl;
		
		cout << endl << endl << "AGUARDE...";

	}



	cout << endl;
	cout << endl;
	cout << endl;

	int vetB[x];
	int vetI[x];
	int vetS[x];

	for(int i = 0; i < x; i++)
	{

		vetB[i] = rand() % 10000;
		vetI[i] = vetB[i];
		vetS[i] = vetB[i];

	}

	cout << "OBSERVE OS RESULTADOS:" << endl;

	funcaoBUBBLE(vetB, x);
	funcaoINSERTION(vetI, x);
	funcaoSELECTION(vetS, x);


	return 0;
}

void funcaoBUBBLE(int VETB[], int y)
{

	clock_t tIni, tFim, tFinal;

	tIni = clock();

	int temp, i, j;

	for(i = y - 1; i >= 1; i--)
	{
		for(j = 0; j < i; j++)
		{

			if(VETB[j] > VETB [j + 1])
			{
				temp = VETB[j];
				VETB[j] = VETB[j + 1];
				VETB[j + 1] = temp;
			}
		}
	}

	tFim = clock();

	tFinal = ((tFim - tIni) / (CLOCKS_PER_SEC / 1000));

	cout << "Tempo de ordenção do BUBBLE: " << tFinal << " ms" << endl;

	return;

}

void funcaoINSERTION(int VETI[], int y)
{

	clock_t tIni, tFim, tFinal;

	tIni = clock();

	int CHAVE, i, j;

	for(j = 1; j <= y; j++)
	{
		CHAVE = VETI[j];
		i = j - 1;
		while(i >= 0 && VETI[i] > CHAVE)
		{
			VETI[i + 1] = VETI[i];
			i = i - 1;
		}
		VETI[i + 1] = CHAVE;
	}

	tFim = clock();

	tFinal = ((tFim - tIni) / (CLOCKS_PER_SEC / 1000));

	cout << "Tempo de ordenação do INSERTION: " << tFinal << " ms" << endl;

	return;
}

void funcaoSELECTION(int VETS[], int y)
{

	clock_t tIni, tFim, tFinal;

	tIni = clock();

	int min, x, i, j;

	for(i = 0; i < y; i++)
	{
		min = i;
		for(j = i + 1; j <= y; j++)
		{
			if(VETS[j] < VETS[min])
			{
				min = j;
			}
		}
		x = VETS[min];
		VETS[min] = VETS[i];
		VETS[i] = x;
	}

	tFim = clock();

	tFinal = ((tFim - tIni) / (CLOCKS_PER_SEC / 1000));

	cout << "Tempo de ordenação do SELECTION: " << tFinal << " ms" << endl;

	return;

}
