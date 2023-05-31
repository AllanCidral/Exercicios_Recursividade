//FUNCAO:
// gerar o calculo de um polinomio definido como: pn(x) = anxn + an-1xn-1 + an-2xn-2 + ... + a1x + a0.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define TMAX 100
using namespace std;

int leiaGrau(); // le e valida o grau
void leiaCoef(int grau, double coef[]); // le e valida os coeficientes
double leiaX(); // le e valida X
double calcularPolinomio(int grau, double x, double coef[]); // gera o calculo do polinomio

int main()
{
	int grau = 0;
	double coef[TMAX], x = 0.0, rslt = 0.0;
	grau = leiaGrau();
	system("CLS");
	leiaCoef(grau, coef);
	system("CLS");
	x = leiaX();
	system("CLS");
	rslt = calcularPolinomio(grau, x, coef);
	cout << "O valor do polinomio p" << grau << "(x) para x = " << x << ": " << rslt << endl;
	return 0;
}
int leiaGrau() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe o grau do polinomio: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) {  // se nao for digito
						validado = false;
						break;
					}
			if (!validado)
				cout << "Entrada invalida, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x == 0)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (x == 0);
	return x;
}
void leiaCoef(int grau, double coef[]) {
	string info = "";
	bool validado;
	int ponto;
	for (int i = 0; i <= grau; i++) {
		info = "";
		do {
			validado = true;
			ponto = 0;
			cout << "Informe o coeficiente referente a " << i << ": ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				if (!isdigit(info.at(0)) and info.at(0) != '-') // se nao for digito ou sinal negativo
					validado = false;
				else
					for (int j = 1; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) { // se nao for digito
							if (isdigit(info.at(j - 1)) and info.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
								ponto++; // permite somente um ponto
							else
								validado = false;
						}
			if (!validado)
				cout << "Elemento invalido, tente novamente." << endl;
		} while (!validado);
		coef[i] = stod(info.c_str());
	}
}
double leiaX() {
	string info = "";
	bool validado;
	double x = 0;
	do {
		do {
			validado = true;
			cout << "Informe o valor de X: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) {  // se nao for digito
						validado = false;
						break;
					}
			if (!validado)
				cout << "Entrada invalida, tente novamente." << endl;
		} while (!validado);
		x = stod(info.c_str()); // converte string para inteiro
		if (x == 0.0)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (x == 0.0);
	return x;
}
double calcularPolinomio(int grau, double x, double coef[]) {
	if (grau == 0)
		return coef[0];
	else
	{
		double termoAtual = coef[grau] * pow(x, grau);
		double termosAnteriores = calcularPolinomio(grau - 1, x, coef);
		return termoAtual + termosAnteriores;
	}
}