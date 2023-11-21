//Juan

#include <iostream>
#include <string.h>
#include <cstring>
#include <strings.h>
#include <string>
using namespace std;

int main()
{
	//sei que meu codigo nao está intuitivo, mas tenta entender a partir do primeiro cin(linha 40), comentei tudo lá em baixo
	//talvez consiga entender melhor
	char mat[26][26];
	char a = 'a', K[45], b, d;
	int N = 0, k1 = 0, k = 0, l = 0, c = 0, pc = 0, ms = 0, mens1 = 0, j = 0;
	//string mens;
	char mens[100000];

	//está preenchendo a matriz
	for(int i = 0; i < 26; i++)
	{
		if(i > 0)
		{
			a = mat[i - 1][0];
			a++;
		}
		for(int j = 0; j < 26; j++)
		{

			mat[i][j] = a;
			a++;
			if(a > 'z')
			{
				a = 'a';
			}
		}

	}

	cin >> K; //recebe a palavra chave
	cin >> N; //recebe a qntd de mensagens
	cin.ignore();
	k1 = strlen(K); //pega o tamanho da palavra chave

	for(int i = 0; i < N; i++) //for para a qntd de mensagens
	{

		//getline(cin, mens); //recebe a mensagem
		cin.getline(mens, 100000);
		//cin >> mens;
		//cin.ignore();
		mens1 = strlen(mens); //pega o tamanho da mensagem

		for(j = 0; j < mens1; j++) //passa por cada caracter da mensagem
		//while(j < mens1)
		{

			if(pc >= k1) //pc(palavra-chave), contador inicial da palavra chave, condição para quando estiver no ultimo
				//caracter da pc
			{
				pc = 0; //quando estiver no ultimo, receberá o valor 0
			}

			b = K[pc]; //recebe o respectivo caracter da palavra chave

			while(b != mat[k][0])//verifica se o caracter é igual ao da matriz
			{

				l++; //soma a linha
				k++; //soma o contador

			}

			k = 0; //reseta o contador
			d = mens[ms]; //recebe o respectivo caracter da mensagem

			if(d == ' ') //caso o caracter seja espaço
			{
				cout << " "; //irá imprimir o espaço
				ms++; //contador da ms(mensagem) vai somar +1 para pegar o proximo caracter
				d = mens[ms]; //recebe o respectivo caracter da mensagem
				j++;
			}

			while(d != mat[0][k]) //verifica se o caracter é igual ao da matriz
			{

				c++; //soma a coluna
				k++; //soma o contador

			}

			cout << mat[l][c]; //imprime o caracter da matriz
			pc++; //soma o contador da pc(palavra-chave)
			ms++; //soma o contador da ms(mensagem)
			//reseta todas as variaveis de busca das variaveis
			k = 0;
			l = 0;
			c = 0;
			//j++;
		}

		pc = 0;
		ms = 0;
		cout << endl; //pula a linha para a proxima mensagem

	}


	return 0;
}
