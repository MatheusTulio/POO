#include <iostream>
#include <cstdio>
using namespace std;

class Pilha{
	private:
		int *itens;
		int tamanho;
		int topo;
	public:
		Pilha();
		Pilha(int);
		void empilhar(int n);
		void desempilhar();
		bool vazia();
		bool cheia();
		void printBottomUp(int i);
		void printTopDown(int i);
		void setItens(int n, int i);
		void setTamanho(int t);
		void setTopo(int n);
		int getItens(int i);
		int getTamanho();
		int getTopo();
};

int main(){
	int t, n, aux;
	char c;
	cin >> t;
	cin >> c;
	n = c;
	Pilha *p = new Pilha(t);
	while(aux != EOF){
		switch(c){
			case 'E':
				cin >> n;
				if(!p->cheia())
					p->empilhar(n);
				break;
			case 'D':
				if(!p->vazia())
					p->desempilhar();
				break;
			case 'T':
				if(!p->vazia())
					p->printTopDown(p->getTopo());
				break;
			case 'B':
				if(!p->vazia())
					p->printBottomUp(0);
				break; 
		}
		cin >> c;
		aux = c;
	}
	return 0;

}

Pilha::Pilha(int t){
	this->setTopo(-1);
	this->setTamanho(t);
	this->itens = new int[t];
}

void Pilha::setTamanho(int t){
	this->tamanho = t;
}

void Pilha::setTopo(int n){
	this->topo = n;
}

void Pilha::setItens(int n, int i){
	this->itens[i] = n;
}

int Pilha::getTamanho(){
	return this->tamanho;
}

int Pilha::getTopo(){
	return this->topo;
}

int Pilha::getItens(int i){
	return this->itens[i];
}

bool Pilha::vazia(){
	if(this->getTopo() == -1)
		return true;
	else
		return false;
}

bool Pilha::cheia(){
	if(this->getTopo() == this->getTamanho() - 1)
		return true;
	else
		return false;
}

void Pilha::printBottomUp(int i){
	if (i <= this->getTopo()){
		cout << this->getItens(i) << endl;
		this->printBottomUp(i + 1);
	}
}

void Pilha::printTopDown(int i){
	if (i >= 0){
		cout << this->getItens(i) << endl;
		this->printTopDown(i - 1);
	}
}

void Pilha::empilhar(int n){
	this->setTopo(this->getTopo() + 1);
	this->setItens(n, this->getTopo());
}

void Pilha::desempilhar(){
	this->setTopo(this->getTopo() - 1);
}