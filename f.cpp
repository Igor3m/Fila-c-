#include <iostream>

using namespace std;

class Noh{
	friend class Fila;
	private:
	    int dado;
	    int chave;
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
	    int tamanho;
	    Noh* inicio;
	    Noh* fim;
	public:
	    Fila();
	    void enfileirar(int v);
	    int desenfileirar();
	    void limpafila();
	    ~Fila();
};
Fila::Fila(){
	tamanho = 0;
	inicio = NULL;
	fim = NULL;
}
void Fila::enfileirar(int v){
	Noh* novo = new Noh(v);
	if (tamanho == 0){
		inicio = novo;
	}
	else{
		fim->proximo = novo;
	}
	fim = novo;
	tamanho++;
}
int Fila::desenfileirar(){
	Noh* aux;
	int valor;
	aux = inicio;
	valor = aux->dado;
	inicio = aux->proximo;
	delete aux;
	tamanho--;
	if (tamanho == 0){
		fim = NULL;
	}
	return valor;
}
void Fila::limpafila(){
	while (tamanho > 0){
		cout << desenfileirar() << endl;
	}
}
Fila::~Fila(){
	limpafila();
}

int main (){
	Fila* f1;
	f1 = new Fila();
	int v;
	cin >> v;
	while (v > 0){
		f1->enfileirar(v);
		cin >> v;
	}
	cout << f1->desenfileirar() << endl;
	cout << f1->desenfileirar() << endl;
	cout << f1->desenfileirar() << endl;
	return 0;
}
