//FUNCAO:
// gerar um procedimento recursivo para escrever os n primeiros termos da sequência 1, 4, 3, 16, 5, 36, 7...
// tal que numeros pares sao potencializados ao quadrado e impares nao sao potencializados.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
using namespace std;

int leiaN(); // le a posicao da serie
void gerarSerie(int n); // gera e mostra a serie
char leiaResp(); // verifica se o usuario deseja gerar outra serie

int main()
{
	int n = 0;
	char resp = 'S';
	do {
		n = leiaN();
		system("CLS");
		gerarSerie(n);
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
			cout << "Informe a posicao da serie: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (unsigned short int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) // se nao for digito
						validado = false;
			if (!validado)
				cout << "Posicao invalida, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x == 0)
			cout << "Posicao invalida, tente novamente." << endl;
	} while (x == 0);
	return x;
}
void gerarSerie(int n) {
	if (n == 1) {
		cout << n;
		return;
	}
	if (n % 2 == 0)
		cout << pow(n, 2) << ", ";
	else
		cout << n << ", ";
	gerarSerie(n - 1);
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		cout << endl;
		cout << endl;
		validado = true;
		cout << "Deseja gerar outra serie? (S/N): ";
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
