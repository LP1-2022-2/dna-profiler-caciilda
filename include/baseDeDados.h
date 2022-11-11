#ifndef baseDeDados_H
#define baseDeDados_H

#include <iostream>

template <class T>
class baseDeDados {
	private:
		T* nome;
		T* AGAT;
		T* AATG;
		T* TATC;//ponteiro para os elementos armazenados na baseDeDados
		int tamanho; 
		int capacidade;//qtdade atual de elementos
		int nAGAT, nAATG, nTATC;
		fstream baseDados;
		string d, base;
		
	public:
		baseDeDados();
		~baseDeDados();
		bool empty();
		int armazenar(string dAux, string diretorioAux);
		bool full();
		int size();
		//int push(T nome, T AGAT, T AATG, T TATC);
		int pop();
		int realizarBusca(int nAGAT, int nAATG, int nTATC);
		T& top();
};


//Construtor
template<class T>
baseDeDados<T>::baseDeDados()
{
	tamanho = 0;
	nome = new T [tamanho];
	AGAT = new T [tamanho];
	AATG = new T [tamanho];
	TATC = new T [tamanho];

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
int baseDeDados<T>::size()
{
	return tamanho;
}

/*template<class T>
int baseDeDados<T>::push(T novoNome, T novoAGAT, T novoAATG, T novoTATC)
{
	
}*/

template <class T>
int baseDeDados<T>::armazenar(string dAux, string diretorioAux){

cout<<"entrou em armazenar()"<<dAux<<endl;
 d = dAux;
 base = diretorioAux;


baseDados.open(base, std::ios::in);

while (baseDados.peek()!=EOF){
    string linhas[4];
	tamanho++;
	for (int i = 0; i < 4; i++){
	
	getline(baseDados, linhas[i], ',');
    cout<<linhas[i]<<endl;
	cout<< tamanho<<endl;
	}
    cout<<"fim de for"<<endl;

	nome[tamanho] = linhas[0];
	AGAT[tamanho] = linhas[1];
	AATG[tamanho] = linhas[2];
	TATC[tamanho] = linhas[3];
	
    }
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

/*template <class T>
int baseDeDados<T>::realizarBusca(int nAGAT, int nAATG, int nTATC){
	 string::iterator it;

	 for (int i = 0; i <4; i++){


	 }*/



#endif
