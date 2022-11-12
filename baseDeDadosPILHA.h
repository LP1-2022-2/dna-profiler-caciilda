#ifndef baseDeDados_H
#define baseDeDados_H
#include <iostream>
#include <cstdlib>
#include<iterator> // for iterators
#include<vector>
//#include "funcoesSistema.h"
#include "funcaoBaseDeDados.h"

   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt

template <class T>
class baseDeDados {
	private:
		T* nome;
		T* AGAT;
		T* AATG;
		T* TATC;//ponteiro para os elementos armazenados na baseDeDados
		int tamanho, capacidade;  //qtdade atual de elementos
		int *nAGAT, *nAATG, *nTATC;
		fstream arquivoBaseDados;
		
	public:
		baseDeDados();
		~baseDeDados();
		int armazenar(string diretorioAux);
		int size();
		int pop();
		//int push(T nome, T AGAT, T AATG, T TATC);
		vector<string> realizarBusca(vector<int> nSTRS);
};


//Construtor
template<class T>
baseDeDados<T>::baseDeDados()
{
	tamanho = 0;
	capacidade = 100;
	nome = new T [capacidade];
	AGAT = new T [capacidade];
	AATG = new T [capacidade];
	TATC = new T [capacidade];

	/*
	nAGAT = atof(AGAT);
	nAGAT = atof(AATG);
	nAGAT = atof(TATC);*/
}

template<class T>
baseDeDados<T>::~baseDeDados()
{
	delete[] nome;
	delete[] AGAT;
	delete[] AATG;
	delete[] TATC;
	std::cout<<"Entrei no destrutor"<<std::endl;
}

template<class T>
int baseDeDados<T>::size()
{
	return tamanho;
}

template <class T>
int baseDeDados<T>::armazenar(string diretorioAux){

arquivoBaseDados.open(diretorioAux, std::ios::in);

while (arquivoBaseDados.peek()!=EOF){
    string linhas[4];
	cout<< tamanho <<endl;

	for (int i = 0; i < 4; i++){
		getline(arquivoBaseDados, linhas[i], ',');
		cout<<linhas[i]<<endl;
	}

	nome[tamanho] = linhas[0];
	AGAT[tamanho] = linhas[1];
	AATG[tamanho] = linhas[2];
	TATC[tamanho] = linhas[3];
	tamanho++;
	}
	return 1;
}

template<class T>
int baseDeDados<T>::pop()
{
	tamanho--;
	return 1;
}


template <class T>
vector <string> baseDeDados<T>::realizarBusca(vector <int> nSTRS){

int nSTREntrada [3];
int nSTRAGAT[tamanho],nSTRAATG[tamanho],nSTRTATC[tamanho];
int i=0;
vector<int>::iterator ptr;
int usuarioEncontrado;
string nameUsuario;
vector <string> saida;
string nSaidaAux;

//colocando STRs de entrada de VECTOR para VETOR
for (ptr = nSTRS.begin(); ptr < nSTRS.end(); ptr++){
		//nSTREntrada[i]=*ptr;
		cout << *ptr << " ";
		i++;
	 }

//colocando STRs de vetor de STRING para vetor de INT
for (int dado = 1; dado <tamanho-1; dado++){
int auxiliar;
string auxliar2="2";
	auxiliar = std::stoi(AGAT[tamanho]);
	//nSTRAGAT[tamanho]=;
	//nSTRAATG[tamanho]=std::stoi(AATG[tamanho]);
	//nSTRTATC[tamanho]=std::stoi(TATC[tamanho]);
	cout << auxiliar <<endl;
}

for (int entrada = 0 ; entrada<3; entrada++){ // Para cada dado de STR
	for (int dado = 1; dado <tamanho; dado++){ // verificar em cada STR da BASE DE DADOS
		if(nSTREntrada[entrada] == nSTRAGAT[dado]){ // Se ENTRADA[] == nAGAT[]
			entrada++;
			dado = 0;
			//saida.push_back(nSTRAGAT[dado]);
			if (nSTREntrada[entrada] == nSTRAATG[dado]){
				entrada++;
				dado = 0;
			}
			if (nSTREntrada[entrada] == nSTRTATC[dado]){
				usuarioEncontrado = dado;
				//saida.push_back(usuarioEncontrado)
				cout <<"Match ID:"<< nome[usuarioEncontrado]<<endl;
			}
		} else { 
			cout <<"NOT FOUND"<<endl;
		}
}
	 
}
return saida;
}



#endif
