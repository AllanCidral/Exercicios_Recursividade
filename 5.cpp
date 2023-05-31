//FUNCAO:
// gerar o calculo do MDC (Algoritmo de Euclides) de forma recursiva.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
using namespace std;

int leiaN(); // le e valida N
int leiaM(); // le e valida M
int euclides(int m, int n); // gera o MDC
char leiaResp(); // le a resposta do usuario para continuar o programa

int main()
{
	int n = 0, m = 0, x = 0;
	char resp = 'S';
	do {
		n = leiaN();
		system("CLS");
		m = leiaM();
		system("CLS");
		x = euclides(m, n);
		cout << "O MDC entre " << m << " e " << n << ": " << x << endl;
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
		validado = true;
		cout << "Informe N: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		else
			if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
				validado = false;
			else
				for (int i = 1; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) { // se nao for digito
						validado = false;
						break;
					}
		if (!validado)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (!validado);
	x = stoi(info.c_str()); // converte string para inteiro
	return x;
}
int leiaM() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		validado = true;
		cout << "Informe M: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		else
			if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
				validado = false;
			else
				for (int i = 1; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) { // se nao for digito
						validado = false;
						break;
					}
		if (!validado)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (!validado);
	x = stoi(info.c_str()); // converte string para inteiro
	return x;
}
int euclides(int m, int n) {
	if (n == 0)
		return m;
	else
		return euclides(n, m % n);
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		validado = true;
		cout << "Deseja gerar outro MDC? (S/N): ";
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

