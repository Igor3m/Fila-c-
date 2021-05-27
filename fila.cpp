#include <iostream>

using namespace std;

class Noh{
	friend class Fila;
	private:
	    int dado;
	    Noh* proximo;
	public:
	    Noh(int valor);
};
Noh::Noh(int valor){
	dado = valor;
	proximo = NULL;
}

class Fila{
	private:
	    Noh* inicio; 
	    Noh* fim;
	    int tamanho;
	public:
	    Fila();
	    void enfileirar(int valor);
	    int retornaTamanho();
	    int desenfileirar();
	    int primeiro();
};
Fila::Fila(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}
void Fila::enfileirar(int valor){
	Noh* novo;
	novo = new Noh(valor);
	if (tamanho == 0){
		inicio = novo;
	}
	else{
		fim->proximo = novo;
	}
	fim = novo;
	cout << fim->dado << " ";
	tamanho++;
}
int Fila::retornaTamanho(){
	return (tamanho);
}
int Fila::desenfileirar(){
	Noh* aux;
	aux = inicio;
	int dado = aux->dado;
	inicio = aux->proximo;
	delete aux;
	tamanho--;
	if (tamanho == 0){
		fim = NULL;
	}
	return (dado);
}
int Fila::primeiro(){
	return (inicio->dado);
}

int main (){
	Fila f1;
	int v;
	cin >> v;
	while (v > 0){
		f1.enfileirar(v);
		cin >> v;
	}
	cout << endl;
	cout << f1.retornaTamanho() << endl;
	cout << f1.desenfileirar() << " ";
	cout << f1.desenfileirar() << " ";
	cout << f1.desenfileirar() << " ";
	cout << endl;
	cout << f1.retornaTamanho() << endl;
	cout << f1.primeiro() << endl;
	
	return 0;
}
