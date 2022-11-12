#ifndef baseDeDados_H
#define baseDeDados_H
#include <iostream>
#include <cstdlib>
#include<iterator> // for iterators
#include<vector>
//#include "funcoesSistema.h"
#include "funcaoBaseDeDados.h"
using std::stoi;
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt

class baseDeDados {
	private:
		string *nome, *AGAT, *AATG, *TATC; //ponteiro para os elementos armazenados na baseDeDados
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
baseDeDados::baseDeDados()
{
	tamanho = 0;
	capacidade = 100;
	nome = new string [capacidade];
	AGAT = new string [capacidade];
	AATG = new string [capacidade];
	TATC = new string [capacidade];

	/*
	nAGAT = atof(AGAT);
	nAGAT = atof(AATG);
	nAGAT = atof(TATC);*/
}

baseDeDados::~baseDeDados()
{
	delete[] nome;
	delete[] AGAT;
	delete[] AATG;
	delete[] TATC;
	std::cout<<"Entrei no destrutor"<<std::endl;
}

int baseDeDados::size()
{
	return tamanho;
}

int baseDeDados::armazenar(string diretorioAux){

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

int baseDeDados::pop()
{
	tamanho--;
	return 1;
}



vector <string> baseDeDados::realizarBusca(vector <int> nSTRS){

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
for (int dado = 1; dado <tamanho; dado++){
	nSTRAGAT[dado]=stoi(AGAT[dado]);
	nSTRAATG[dado]=stoi(AATG[dado]);
	nSTRTATC[dado]=stoi(TATC[dado]);
	cout <<nSTRAGAT[dado] <<endl;
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
