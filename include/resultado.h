#ifndef resultado_H
#define resultado_H

#include <iostream>
#include <string>
using std::string;
using std::getline;
#include "baseDNA.h"

class resultado
{
	private:
		string nome, AGAT, AATG, TATC; //ponteiro para os elementos armazenados na resultadorio
	public:
		resultado(string nome = "usuario", string AGAT = "0",string AATG = "0",string TATC = "0");
		~resultado();
		bool empty();
		bool full();
		int push(string nome, string AGAT, string AATG, string TATC);
};


//Construtor

resultado::resultado(string nome, string AGAT, string AATG, string TATC)
{
	nome = nome;
	AGAT = AGAT;
	AATG = AATG;
	TATC = TATC;
}


resultado::~resultado()
{
	std::cout<<"Entrei no destrutor"<<std::endl;
}


int resultado::push(string nome, string AGAT, string AATG, string TATC)
{
	if (full())
		return 0;

	nome= nome;
	AGAT= AGAT;
	AATG= AATG;
	TATC= TATC;

	return 1;
}

#endif
