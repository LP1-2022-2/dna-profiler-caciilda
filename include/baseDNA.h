#ifndef baseDNA_H
#define baseDNA_H
#include<iostream>
#include<cstdlib>
#include <cctype>
#include <fstream>
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
using std::istringstream;
using std::istream;
#include <iostream>
//#include "funcoesSistema.h"
#include "funcoesBases.h"

class baseDNA {
	private:
		string sequencia; //ponteiro para os elementos armazenados na baseDNA
		int nAGAT, nAATG, nTATC;
	public:
		baseDNA();
		~baseDNA();
		int push(string sequencia);
		void separaSequencia();
};


//Construtor
baseDNA::baseDNA(){
	nAGAT = 0;
	nAATG = 0;
	nTATC = 0;
}

baseDNA::~baseDNA()
{
	std::cout<<"Entrei no destrutor"<<std::endl;
}

int baseDNA::push(string sequencia)
{
	this->sequencia = sequencia;
	return 1;
}

void baseDNA::separaSequencia(){
	string STR;

	STR = "AGAT";
	nAGAT = contarSTR(sequencia, STR);
	cout <<"quantidade de AGAT: "<<nAGAT<<endl;
	cout<< endl;

	STR = "AATG";
	nAATG = contarSTR(sequencia, STR);
	cout <<"quantidade de AATG: "<<nAATG<<endl;
	
	cout<< endl;
	STR = "TATC";
	nTATC = contarSTR(sequencia, STR);
	cout <<"quantidade de TATC: "<<nTATC<<endl;
	cout<< endl;
}

#endif
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt