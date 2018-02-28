#include <iostream>
#include <cstdio>
using namespace std;

class DataJuliana{
	private:
		int diaJuliano;
	public:
		DataJuliana(int d);
		DataJuliana(DataGregoriana datag);
		void setDiaJuliano(int d);
		int getDiaJuliano();
		operator DataGregoriana();
};

class DataGregoriana{
	private:
		int dia, mes, ano;
	public:
		//DataGregoriana(DataJuliana dataj);
		DataGregoriana(int d, int m, int a);
		void setDia(int d);
		void setMes(int m);
		void setAno(int a);
		int getDia();
		int getMes();
		int getAno();
		operator DataJuliana();
};

int main(){
	int d, m, a;
	DataGregoriana datag;
	DataJuliana dataj;
	while(2>1){
		cin >> d >> m >> a;
		datag = new DataGregoriana(d, m, a);
		dataj = new DataJuliana(datag):
		cout >> dataj.diaJuliano >> endl;
	}
}

DataGregoriana::DataGregoriana(int d, int m, int a){
	this->setDia(d);
	this->setMes(m);
	this->setAno(a);
}

DataJuliana::DataJuliana(int d){
	this->setDiaJuliano(d);
}

DataJuliana::DataJuliana(DataGregoriana datag){
	this = DataJuliana(datag);
}

void DataGregoriana::setDia(int d){
	this->dia = d;
}

void DataGregoriana::setMes(int m){
	this->mes = m;
}

void DataGregoriana::setAno(int a){
	this->ano = a;
}

int DataGregoriana::getDia(){
	return this->dia;
}

int DataGregoriana::getMes(){
	return this->mes;
}

int DataGregoriana::getAno(){
	return this->ano;
}

void DataJuliana::setDiaJuliano(int d){
	this->diaJuliano = d;
}

int DataJuliana::getDiaJuliano(){
	return this->diaJuliano;
}

DataGregoriana::operator DataJuliana(){
	int A, B, C = 0, D, E;
	if (this->getMes() < 3 ){
		this->setMes(this->getMes() + 12);
		this->setAno(this->getAno() - 1);
	}
	if(this->getAno() + 1 > 1582 || (this->getAno() + 1 == 1582 && this->getMes() > 10) || (this->getAno() + 1 == 1582 && this->getMes() == 10 && this->getDia() >= 15)){
		A = this->getAno() / 100;
		B = A / 4;
		C = 2 - A + B;
	}

	D = 365,25 * (this->getAno() + 4716);
	E = 30,6001 * (this->getMes() + 1);

	return D + E + this->getDia() + C - 1524;
}