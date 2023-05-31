//FUNCAO:
// gerar uma funcao recursiva para calcular o produto escalar entre dois vetores.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi, stof
#define TMAX 10 // tamanho maximo dos vetores
using namespace std;

typedef struct {
	float vetorX[TMAX], vetorY[TMAX], escalar;
} Vetores;
int leiaN(); // le e valida o tamanho dos vetores
void leiaVetores(int n, Vetores& xy); // le e valida o vetorX e vetorY
float gerarEscalar(int n, Vetores xy); // gera o produto escalar entre os dois vetores
void relatorio(int n, Vetores xy); // relatorio final

int main()
{
	Vetores xy;
	int n = 0;
	n = leiaN();
	system("CLS");
	leiaVetores(n, xy);
	system("CLS");
	xy.escalar = gerarEscalar(n, xy);
	relatorio(n, xy);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe o tamanho do vetor (1-" << TMAX << "): ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (unsigned short int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) { // se nao for digito
						validado = false;
						break;
					}
			if (!validado)
				cout << "Tamanho invalido invalido, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x == 0 or x > TMAX)
			cout << "Tamanho invalido invalido, tente novamente." << endl;
	} while (x == 0 or x > TMAX);
	return x;
}
void leiaVetores(int n, Vetores& xy) {
	bool validado;
	int ponto;
	for (int i = 0; i < n; i++) {
		string infoX = "";
		xy.vetorX[i] = 0.0;
		do {
			validado = true;
			ponto = 0;
			cout << "Informe o " << i + 1 << " elemento do vetor X: ";
			getline(cin, infoX);
			if (infoX == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(infoX.at(0)) and infoX.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < infoX.size(); j++) // verifica posicao a posicao
						if (!isdigit(infoX.at(j))) { // se nao for digito
							if (isdigit(infoX.at(j - 1)) and infoX.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
								ponto++; // permite somente um ponto
							else
								validado = false;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		xy.vetorX[i] = stof(infoX.c_str());
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		string infoY = "";
		xy.vetorY[i] = 0.0;
		do {
			validado = true;
			ponto = 0;
			cout << "Informe o " << i + 1 << " elemento do vetor Y: ";
			getline(cin, infoY);
			if (infoY == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(infoY.at(0)) and infoY.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < infoY.size(); j++) // verifica posicao a posicao
						if (!isdigit(infoY.at(j))) { // se nao for digito
							if (isdigit(infoY.at(j - 1)) and infoY.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
								ponto++; // permite somente um ponto
							else
								validado = false;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		xy.vetorY[i] = stof(infoY.c_str());
	}
}
float gerarEscalar(int n, Vetores xy) {
	if (n == 0)
		return 0;
	return xy.vetorX[n - 1] * xy.vetorY[n - 1] + gerarEscalar(n - 1, xy);
}
void relatorio(int n, Vetores xy) {
	cout << "Relatorio:\n";
	cout << "-----------------------------------------------\n";
	cout << "Vetor X:\n";
	for (int i = 0; i < n; i++)
		cout << "[" << xy.vetorX[i] << "]";
	cout << endl;
	cout << "-----------------------------------------------\n";
	cout << "Vetor Y:\n";
	for (int i = 0; i < n; i++)
		cout << "[" << xy.vetorY[i] << "]";
	cout << endl;
	cout << "-----------------------------------------------\n";
	cout << "Produto escalar: " << xy.escalar << endl;
	cout << "-----------------------------------------------";
}
