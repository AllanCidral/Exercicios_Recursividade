//FUNCAO:
// gerar uma funcao recursiva para determinar o valor do enesimo termo da sequencia de Fibonacci.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
using namespace std;

int leiaN(); // le a posicao que sera acessada
unsigned long int gerarFibonacci(int n); // calcula a sequencia de Fibonacci
char leiaResp(); // verifica se o usuario deseja acessar outra posicao

int main()
{
	int n = 0;
	unsigned long int x = 0;
	char resp = 'S';
	do {
		n = leiaN();
		system("CLS");
		x = gerarFibonacci(n);
		cout << "Posicao " << n << " de Fibonacci: " << x << endl;
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
			cout << "Informe a posicao de Fibonacci que deseja acessar: ";
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
unsigned long int gerarFibonacci(int n) {
	if (n == 1 or n == 2)
		return 1;
	return gerarFibonacci(n - 1) + gerarFibonacci(n - 2);
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		cout << endl;
		validado = true;
		cout << "Deseja acessar outra posicao de Fibonacci? (S/N): ";
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

