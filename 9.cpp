//FUNCAO:
// gerar uma funcao recursiva para verificar se dois vetores X e Y de n (1 <= n <= 10) elementos inteiros são iguais.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define TMAX 10 // tamanho maximo dos vetores
using namespace std;

int leiaN(); // le e valida N
void leiaVetores(int n, int vetorX[], int vetorY[]); // le e valida o vetorX e vetorY
bool verificarIdentidade(int n, int vetorX[], int vetorY[]); // verifica se os vetores sao iguais
void mostrarVetores(int n, int vetorX[], int vetorY[]); // mostra os vetores

int main()
{
	int n = 0, vetorX[TMAX] = { 0 }, vetorY[TMAX] = { 0 };
	bool x = false;
	n = leiaN();
	system("CLS");
	leiaVetores(n, vetorX, vetorY);
	system("CLS");
	x = verificarIdentidade(n, vetorX, vetorY);
	mostrarVetores(n, vetorX, vetorY);
	if (x)
		cout << "Os vetores X e Y sao iguais." << endl;
	else
		cout << "Os vetores X e Y nao sao iguais." << endl;
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
				for (int i = 0; i < info.size(); i++) // verifica posicao a posicao
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
void leiaVetores(int n, int vetorX[], int vetorY[]) {
	string info = "";
	bool validado;
	for (int i = 0; i < n; i++) {
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " elemento do vetor X: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) { // se nao for digito
							validado = false;
							break;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		vetorX[i] = stoi(info.c_str());
	}
	system("CLS");
	info = "";
	for (int i = 0; i < n; i++) {
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " elemento do vetor Y: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) { // se nao for digito
							validado = false;
							break;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		vetorY[i] = stoi(info.c_str());
	}
}
bool verificarIdentidade(int n, int vetorX[], int vetorY[]) {
	if (n == 0)
		return true;
	if (vetorX[n - 1] != vetorY[n - 1])
		return false;
	return verificarIdentidade(n - 1, vetorX, vetorY);
}

void mostrarVetores(int n, int vetorX[], int vetorY[]) {
	cout << "Vetor X:\n";
	for (int i = 0; i < n; i++)
		cout << "[" << vetorX[i] << "]";
	cout << endl;
	cout << "Vetor Y:\n";
	for (int i = 0; i < n; i++)
		cout << "[" << vetorY[i] << "]";
	cout << endl;
	cout << endl;
}