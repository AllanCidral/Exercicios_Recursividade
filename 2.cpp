//FUNCAO:
// gerar uma funcao recursiva para calcular a soma dos numeros naturais de 1 a n.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
using namespace std;

unsigned int leiaN(); // le e valida N
unsigned long int somaNaturais(unsigned int n); // soma os elementos de 1 ate N
char leiaResp(); // verifica se o usuario deseja gerar outra soma

int main()
{
	unsigned int n = 0;
	unsigned long int x = 0;
	char resp = 'S';
	do {
		n = leiaN();
		system("CLS");
		x = somaNaturais(n);
		cout << "Soma de 1 ate " << n << ": " << x << endl;
		resp = leiaResp();
		system("CLS");
	} while (resp == 'S');
	return 0;
}
unsigned int leiaN() {
	string info = "";
	bool validado;
	unsigned int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe N: ";
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
		if (x == 0)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (x == 0);
	return x;
}
unsigned long int somaNaturais(unsigned int n) {
	if (n == 1)
		return 1;
	return n + somaNaturais(n - 1);
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

