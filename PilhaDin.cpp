#include <iostream>
#include <cstdio>
using namespace std;

class Pilha{
	private:
		Item *tail;
		Item *head;
	public:
		Pilha();
		Pilha(Item *);
		void empilhar(Item *n);
		Item *desempilhar();
		bool vazia();
		void printTopDown();
};

class Item{
	public:
		int chave;
		Item *proximo;
		Item *anterior;
	private:
		Item(int);
		void setChave(int);
		int getChave();
		void setProximo(Item *);
		Item *getProximo();
		void setAnterior(Item *);
		Item *getAnterior();
};

int main(){
	return 0;

}

Pilha::Pilha(Item *t){
	this->setHead(t);
	this->setTail(t);
}

void Pilha::setHead(Item *h){
	this->head = h;
}

Item *Pilha::getHead(){
	return this->head;
}

void Pilha::setTail(Item *t){
	this->tail = t;
}

Item *Pilha::getTail(){
	return this->tail;
}

bool Pilha::vazia(){
	if(this->getTail()->getProximo() == NULL)
		return true;
	else
		return false;
}


void Pilha::printTopDown(int i){
	if (i >= 0){
		cout << this->getItens(i) << endl;
		this->printTopDown(i - 1);
	}
}

void Pilha::empilhar(Item *i){
	this->
}

Item *Pilha::desempilhar(){
	cout << "[" << this->getChave() << "]" << endl;
	this->setAnterior(NULL);
	this->
}

Item::Item(int c){ 
	this->setChave = c;;
	this->setProximo = NULL;
	this->setAnterior = NULL;
}

int Item::setChave(int c){
	this->chave = c;
}

Item *Item::setProximo(Item *next){
	this->proximo = next;
}

Item *Item::setAnterior(Item *a){
	this->anterior = a;
}

void Item::getChave(){
	return this->chave;
}

void Item::getProximo(){
	return this->proximo;
}

void Item::getAnterior(){
	return this->anterior;
}