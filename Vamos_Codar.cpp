//Juan

#include <iostream>
#include <string.h>
#include <cstring>
#include <strings.h>
#include <string>
#include <fstream>
#include <locale.h>

using namespace std;

void  preencherMat(char MAT[][26])
{
	char a = 'a';

	for(int i = 0; i < 26; i++)
	{
		if(i > 0)
		{
			a = MAT[i - 1][0];
			a++;
		}
		for(int j = 0; j < 26; j++)
		{

			MAT[i][j] = a;
			a++;
			if(a > 'z')
			{
				a = 'a';
			}
		}

	}
	return;

}

void gravarL(string t)
{

	ofstream arqOUT;

	arqOUT.open("Criptografou.txt", ofstream::out | ofstream::app);

	arqOUT << t << endl;

	arqOUT.close();

	return;
}

void criptografar(string key, string TXT, char MAT[][26])
{

	int pc = 0, ms = 0, l = 0, cont = 0, c = 0, j = 0;
	char b, d;
	string p;
	int k1 = key.size();
	int TXT1 = TXT.size();

	for(j = 0; j < TXT1; j++)
	{

		if(pc >= k1)
		{
			pc = 0;
		}

		b = key[pc];

		while(b != MAT[cont][0])
		{

			l++;
			cont++;

		}

		cont = 0;
		d = TXT[ms];

		if(d == ' ')
		{

			p = p + " ";
			ms++;
			d = TXT[ms];
			j++;
		}

		while(d != MAT[0][cont])
		{

			c++;
			cont++;

		}

		p = p + MAT[l][c];
		pc++;
		ms++;

		cont = 0;
		l = 0;
		c = 0;

	}
	gravarL(p);
	return;
}


void leitura(char MAT[][26])
{

	ifstream arqIN;
	string txt;
	string chave;

	arqIN.open("teste.txt", ifstream::in);

	getline(arqIN, chave);

	while(getline(arqIN, txt))
	{
		criptografar(chave, txt, MAT);
	}

	arqIN.close();
	return;
}


int main()
{
	setlocale(LC_ALL, "Portuguese");

	cout << "SEJA BEM VINDO AO PROGRAMA DE CRIPTOGRAFIA!" << endl;
	cout << "APENAS MANTENHA A CALMA E SEU ARQUIVO SERÁ CRIPTOGRAFADO" << endl;
	cout << "ENQUANTO ESPERA, OBSERVA ESSA OBRA DE ARTE ;)" << endl;
	cout << "E A MÁGICA ESTÁ SENDO FEITA :)" << endl;
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


	char mat[26][26];

	preencherMat(mat);
	leitura(mat);

	cout << "CRIPTOGRAFADO COM SUCESSO" << endl;

	return 0;
}
