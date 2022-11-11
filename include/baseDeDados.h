#ifndef baseDeDados_H
#define baseDeDados_H

#include <iostream>

template <class T>
class baseDeDados {
	private:
		T nome, AGAT, AATG, TATC; //ponteiro para os elementos armazenados na baseDeDados
		int tamanho; //qtdade atual de elementos
		int capacidade; //qtdade max de elementos
		int nAGAT, nAATG, nTATC;
	public:
		baseDeDados();
		~baseDeDados();
		bool empty();
		bool full();
		int size();
		int push(T nome, T AGAT, T AATG, T TATC);
		int pop();
		T& top();
};


//Construtor
template<class T>
baseDeDados<T>::baseDeDados()
{
	/*tamanho=0;
	capacidade=20;
	nome = this->nome;
	AGAT = this->AGAT;
	AATG = this->AATG;
	TATC = this->TATC;*/
	/*nAGAT = new int [n_capacidade];
	nAATG = new int [n_capacidade];
	nAGAT = new int [n_capacidade];
	nTATC = new int [n_capacidade];
	nAGAT = atof(AGAT);
	nAGAT = atof(AATG);
	nAGAT = atof(TATC);*/
}

template<class T>
baseDeDados<T>::~baseDeDados()
{
	std::cout<<"Entrei no destrutor"<<std::endl;
}

template<class T>
bool baseDeDados<T>::empty()
{
	return tamanho==0;
}

template<class T>
bool baseDeDados<T>::full()
{
	return tamanho==capacidade;
}

template<class T>
int baseDeDados<T>::size()
{
	return tamanho;
}

template<class T>
int baseDeDados<T>::push(T nome, T AGAT, T AATG, T TATC)
{
	this->nome = nome;
	this->AGAT = AGAT;
	this->AATG = AATG;
	this->TATC = TATC;
	return 1;
}
/*
template<class T>
int baseDeDados<T>::pop()
{
	if(empty())
		return 0;

	tamanho--;
	return 1;
}

template<class T>
T& baseDeDados<T>::top()
{

	if (empty())
	{
		std::cout<<"Erro: A baseDeDados está vazia"<<std::endl;
		exit(EXIT_FAILURE);	
	}

	return elementos[tamanho-1];
}
*/
#endif
