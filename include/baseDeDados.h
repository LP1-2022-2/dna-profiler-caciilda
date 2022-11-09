#ifndef baseDeDados
#define baseDeDados

#include <iostream>

template <class T>
class baseDeDados {
	private:
		T* nome,AGAT,AATG,TATC; //ponteiro para os elementos armazenados na baseDeDados
		int tamanho; //qtdade atual de elementos
		int capacidade; //qtdade max de elementos
	public:
		baseDeDados(int n_capacidade = 20);
		~baseDeDados();
		bool empty();
		bool full();
		int size();
		int push(T nome, T AGAT, T AATG, T TATC);
		int pop();
		T& top();
};

/*
//Construtor
template<class T>
baseDeDados<T>::baseDeDados(int n_capacidade)
{
	tamanho=0;
	capacidade=n_capacidade;
	nome = new T[n_capacidade];
	AGAT = new T[n_capacidade];
	AATG = new T[n_capacidade];
	TATC = new T[n_capacidade];
}

template<class T>
baseDeDados<T>::~baseDeDados()
{
	std::cout<<"Entrei no destrutor"<<std::endl;
	delete[] elementos;
}

template<class T>
bool baseDeDados<T>::empty()
{
	/*
	if (tamanho==0)
		return true;
	else
		return false;
		*//*
	return tamanho==0;
}

template<class T>
bool baseDeDados<T>::full()
{*/
	/*
	if (tamanho==capacidade)
		return true;
	else
		return false;
	*//*
	return tamanho==capacidade;
}

template<class T>
int baseDeDados<T>::size()
{
	return tamanho;
}*/
/*
template<class T>
int baseDeDados<T>::push(T nome, T AGAT, T AATG, T TATC)
{
	if (full())
		return 0;

	nome[tamanho] = nome;
	AGAT[tamanho] = AGAT;
	AATG[tamanho] = AATG;
	TATC[tamanho] = TATC;
	tamanho++;

	return 1;
}*/
/*
template<class T>
int baseDeDados<T>::pop()
{
	if(empty())
		return 0;

	tamanho--;
	return 1;
}*/
/*
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
