//FUNCAO:
// gerar uma funcao recursiva para calcular a soma dos multiplos de 5 entre 0 e 1000.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define TMAX 1000 // tamanho maximo de N
using namespace std;

int leiaN(); // le a posicao escolhida entre 0 e TMAX
int somarMultiplo5(int n); // soma os multiplos de 5 ate N
char leiaResp(); // verifica se o usuario deseja gerar outra soma

int main()
{
	int n = 0, x = 0;
	char resp = 'S';
	do {
		n = leiaN();
		system("CLS");
		x = somarMultiplo5(n);
		cout << "Soma dos multiplos de 5 ate " << n << ": " << x << endl;
		resp = leiaResp();
		system("CLS");
	} while (resp == 'S');
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe um numero entre 0 e " << TMAX << ", multiplo de 5: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) // se nao for digito
						validado = false;
			if (!validado)
				cout << "Entrada invalida, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x > TMAX)
			cout << "Entrada nao pode ser maior que " << TMAX << ", tente novamente." << endl;
		if (x % 5 != 0 and x <= TMAX)
			cout << "Entrada deve ser multiplo de 5, tente novamente." << endl;
	} while (x > TMAX or x % 5 != 0);
	return x;
}
int somarMultiplo5(int n) {
	if (n == 0)
		return 0;
	return n + somarMultiplo5(n - 5);
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		cout << endl;
		validado = true;
		cout << "Deseja gerar outra soma? (S/N): ";
		cin.get(info);
		info = toupper(info);
		cin.ignore();
		if (info == ' ') // se a string for vazia
			validado = false;
		if (info != 'S' and info != 'N') // se nao e letra do alfabeto ou S/N
			validado = false;
		if (!validado)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (!validado);
	return info;
}

