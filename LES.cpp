#include <iostream>
#include <cstdio>
using namespace std;

class Lista {
    private:
        int quantidade;
        int tamanho;
        int *v;
    public:
        Lista(int q);
        void inserir(int n, int i);
        void excluir(int n, int i);
        void Imprimir(int i);
        void deslocaE(int i);
        void deslocaD(int i, int j);
        void setQuantidade(int q);
        void setTamanho(int t);
        void setV(int n, int i);
        int getQuantidade();
        int getTamanho();
        int getV(int i);
  
};

void lerEscolher (int i, Lista *l);

int main() {
    int q;
    cin >> q;
    Lista *l = new Lista(q);
    lerEscolher(0, l);
    l->Imprimir(0);
    return 0;
}

void lerEscolher (int i, Lista *l){
    int n;
    char c;
    if (i < l->getTamanho()){
        cin >> c >> n;
        if (c == 'I'){
            l->inserir(n, 0);
        }
        else {
            l->excluir(n, 0);
        }
        lerEscolher(i + 1, l);
    }
}

Lista::Lista(int q){
    this->setQuantidade(0);
    this->setTamanho(q);
    this->v = new int[q];
}

int Lista::getQuantidade(){
    return this->quantidade;
}

int Lista::getTamanho(){
    return this->tamanho;
}

void Lista::setQuantidade(int q){
    this->quantidade = q;
}

void Lista::setTamanho(int t){
    this->tamanho = t;
}

void Lista::setV(int n, int i){
    this->v[i] = n;
}

int Lista::getV(int i){
    return this->v[i];
}

void Lista::Imprimir(int i){
    if(i < this->getQuantidade()){
        cout << this->v[i] << endl;
        this->Imprimir(i + 1);
    }
}

void Lista::inserir (int n, int i) {
    int aux;
    if(i < this->getQuantidade() || this->getQuantidade() == 0){
        if(n < this->getV(i) || this->getQuantidade() == 0){ 
            aux = this->getQuantidade() + 1;
            this->setQuantidade(aux);
            this->deslocaD(i, aux);
            this->setV(n, i);
        }
        else{
            if(n > this->getV(i))
                this->inserir(n, i + 1);
            else;
        }
    }
    else{
        if(n > this->getV(i - 1))
            aux = this->getQuantidade() + 1;
            this->setQuantidade(aux);
            this->deslocaD(i, aux);
            this->setV(n, i);
    }
}

void Lista::deslocaD(int i, int j){
    if (i == j - 1)
        this->setV(this->getV(i), j);
    else {
        this->setV(this->getV(j - 1), j);
        this->deslocaD(i , j - 1);
    }
}

void Lista::deslocaE(int i){
    this->setV(this->getV(i + 1), i );
    if (i < this->getQuantidade() - 1)
        this->deslocaE(i + 1);
}

void Lista::excluir (int n, int i){
    int aux;
    if (i < getQuantidade()){
        if (n == getV(i)){
                this->deslocaE(i);
                aux = this->getQuantidade() - 1;
                this->setQuantidade(aux);
        }
        else
            this->excluir(n , i + 1);
    }
}