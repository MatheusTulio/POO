#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

class Fila{
	private:
		int *itens;
		int inicio, fim;
		int quantidade;
	public:
		Fila(int q);
		void enfileirar(int n);
		void desenfileirar();
		bool vazia();
		bool cheia();
		void setInicio(int n);
		void setFim(int n);
		void setItens(int n, int i);
		void setQuantidade(int n);
		int getInicio();
		int getFim();
		int getItens(int i);
		int getQuantidade();
};

int main() {
    int q, n, aux;
    char c;    
    cin >> q;
    Fila *f = new Fila(q);
    cin >> c;
    aux = c;
    while(aux != EOF){
    	switch(c){
		case 'E':
			if (!f->cheia()){
				cin >> n;
				f->enfileirar(n);
			}
		    break;
		case 'D':
			if (!f->vazia()){
				f->desenfileirar();
				if (f->getInicio() == f->getQuantidade()){
					f->setInicio(-1);
					f->setFim(-1);
				}
			}
			break;
		}
		cin >> c;
    	aux = c;
	}
	return 0;
}


Fila::Fila(int q){
	this->setInicio(-1);
	this->setFim(-1);
	this->itens = new int[q];
	this->setQuantidade(q);
}

void Fila::setInicio(int n){
	this->inicio = n;
}

void Fila::setFim(int n){
	this->fim = n;
}

void Fila::setQuantidade(int n){
	this->quantidade = n;
}

void Fila::setItens(int n, int i){
	this->itens[i] = n;
}

int Fila::getInicio(){
	return this->inicio;
}

int Fila::getFim(){
	return this->fim;
}

int Fila::getQuantidade(){
	return this->quantidade;
}

int Fila::getItens(int i){
	return this->itens[i];
}

bool Fila::vazia(){
	if(this->getFim() == -1 && this->getInicio() == -1)
		return true;
	else
		return false;
}

bool Fila::cheia(){
	if(this->getFim() == this->getQuantidade() - 1)
		return true;
	else
		return false;
}

void Fila::enfileirar(int n){
	if(this->vazia())
		this->setInicio(0);
	this->setFim(this->getFim() + 1);
	this->setItens(n, this->getFim());
}

void Fila::desenfileirar(){
	cout << getItens(this->getInicio()) << endl;
	this->setInicio(this->getInicio() + 1);
}