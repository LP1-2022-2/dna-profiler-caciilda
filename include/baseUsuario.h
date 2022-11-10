#ifndef baseUsuario_H
#define baseUsuario_H

#include <iostream>

template <class T>
class baseUsuario {
	private:
		T* nome, AGAT, AATG, TATC; //ponteiro para os elementos armazenados na baseUsuario
	public:
		baseUsuario(T* nome = "usuario", T* AGAT = '0',T* AATG = '0',T* TATC = '0');
		~baseUsuario();
		bool empty();
		bool full();
		int push(T nome, T AGAT, T AATG, T TATC);
};


//Construtor
template<class T>
baseUsuario<T>::baseUsuario(T* nome, T* AGAT, T* AATG, T* TATC)
{
	nome = this->nome;
	AGAT = this->AGAT;
	AATG = this->AGAT;
	TATC = this->TATC;
}

template<class T>
baseUsuario<T>::~baseUsuario()
{
	std::cout<<"Entrei no destrutor"<<std::endl;
	delete[] elementos;
}

template<class T>
bool baseUsuario<T>::empty()
{
	/*
	if (tamanho==0)
		return true;
	else
		return false;
		*/
	return tamanho==0;
}

template<class T>
bool baseUsuario<T>::full()
{
	/*
	if (tamanho==capacidade)
		return true;
	else
		return false;
	*/
	return tamanho==capacidade;
}

template<class T>
int baseUsuario<T>::push(T nome, T AGAT, T AATG, T TATC)
{
	if (full())
		return 0;

	nome[tamanho] = nome;
	AGAT[tamanho] = AGAT;
	AATG[tamanho] = AATG;
	TATC[tamanho] = TATC;
	tamanho++;

	return 1;
}

#endif
