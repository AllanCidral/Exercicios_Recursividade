//FUNCAO:
// gerar um procedimento recursivo para verificar a existencia de um determinado valor y em um vetor X.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define TMAX 10 // tamanho maximo do vetor
using namespace std;

int leiaN(); // le e valida o tamanho do vetor
void leiaVetorX(int n, int vetorX[]); // le e valida o vetor
void mostrarVetorX(int n, int vetorX[]); // mostra o vetor
int leiaY(); // le e valida o elemento a ser procurado
void procurarElemento(int n, int vetorX[], int y); // procura e mostra a posicao do elemento caso ele exista
char leiaResp(); // le a opcao para continuar a pesquisa

int main()
{
	int n = 0, vetorX[TMAX] = { 0 }, y = 0;
	char resp = 'S';
	n = leiaN();
	system("CLS");
	leiaVetorX(n, vetorX);
	system("CLS");
	do {
		mostrarVetorX(n, vetorX);
		y = leiaY();
		procurarElemento(n, vetorX, y);
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
				cout << "Tamanho invalido, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x == 0 or x > TMAX)
			cout << "Tamanho invalido, tente novamente." << endl;
	} while (x == 0 or x > TMAX);
	return x;
}
void leiaVetorX(int n, int vetorX[]) {
	bool validado;
	for (int i = 0; i < n; i++) {
		string info = "";
		do {
			validado = true;
			cout << "Informe o " << i+1 << " elemento do vetor X: ";
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
		vetorX[i] = stoi(info.c_str()); // converte string para inteiro
	}
}
void mostrarVetorX(int n, int vetorX[]) {
	cout << "Vetor X:\n";
	for (int i = 0; i < n; i++)
		cout << "[" << vetorX[i] << "]";
	cout << endl;
	cout << endl;
}
int leiaY() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		validado = true;
		cout << "Informe o elemento que deseja procurar: ";
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
			cout << "Elemento invalido, tente novamente." << endl;
	} while (!validado);
	x = stoi(info.c_str()); // converte string para inteiro
	return x;
}
void procurarElemento(int n, int vetorX[], int y) {
	bool achou = false;
	if (n == 0)
		return;
	if (vetorX[n - 1] == y) {
		cout << "O elemento " << y << " foi encontrado na posicao: " << n << endl;
		achou = true;
	}
	if (n == 1 and !achou)
		cout << "O elemento " << y << " nao foi encontrado no vetor X." << endl;
	if (!achou)
		procurarElemento(n - 1, vetorX, y);
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		cout << endl;
		validado = true;
		cout << "Deseja procurar outro elemento? (S/N): ";
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

