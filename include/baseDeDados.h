#ifndef baseDeDados_H
#define baseDeDados_H
#include <iostream>
#include <cstdlib>
#include<iterator> // for iterators
#include<vector>
using std::fstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::istringstream;
using std::istream;
//#include "funcoesSistema.h"
#include "funcaoBaseDeDados.h"
using std::stoi;
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //
   

class baseDeDados {
	private:
		string *nome, *AGAT, *AATG, *TATC; //ponteiro para os elementos armazenados na baseDeDados
		int tamanho, capacidade;  //qtdade atual de elementos
		int *nAGAT, *nAATG, *nTATC;
		fstream arquivoBaseDados;
	public:
		baseDeDados();
		~baseDeDados();
		string push_ID(int ID);
		int armazenar(string diretorioAux);
		int size();
		int pop();
		//int push(T nome, T AGAT, T AATG, T TATC);
		int realizarBusca(vector<int> nSTRS);
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
	//std::cout<<"Entrei no destrutor"<<std::endl;
}

int baseDeDados::size()
{
	return tamanho;
}

//----------------------------------------------
// Abrir arquivo csv e armazenar nos ponteiros.
int baseDeDados::armazenar(string diretorioAux){

arquivoBaseDados.open(diretorioAux, std::ios::in); //abrir o direitorio .csv

while (arquivoBaseDados.peek()!=EOF){ //enquanto o documento não estiver no fim
    string linhas[4];
	//cout<< tamanho <<endl;

	for (int i = 0; i < 4; i++){
		getline(arquivoBaseDados, linhas[i], ','); // get dados que estão separados por ","
		//cout<<linhas[i]<<endl;// e adiciona no vetor 
	}

// organizando cada dado em um ponteiro
	nome[tamanho] = linhas[0];
	AGAT[tamanho] = linhas[1];
	AATG[tamanho] = linhas[2];
	TATC[tamanho] = linhas[3];
	tamanho++;
	}
	return 1;
}
//----------------------------------------------
// diminuir última linha de dados.
int baseDeDados::pop()
{
	tamanho--;
	return 1;
}
//----------------------------------------------
// Realizar busca
int baseDeDados::realizarBusca(vector <int> nSTRS){

int nSTREntrada [3];
int nSTRAGAT[tamanho], nSTRAATG[tamanho], nSTRTATC[tamanho];
int i=0;
vector<int>::iterator ptr;
int usuarioEncontrado;
string nameUsuario;
vector <string> saida;
string nSaidaAux;

//colocando STRs de entrada de VECTOR para VETOR
for (ptr = nSTRS.begin(); ptr < nSTRS.end(); ptr++){
		//nSTREntrada[i]=*ptr;
		//cout <<"dados de entrada STR: ";
		//cout << *ptr << " "<<endl;
		nSTREntrada[i]=*ptr;
		i++;
	 }

//colocando STRs de vetor de STRING para vetor de INT
for (int dado = 1; dado <tamanho; dado++){
	nSTRAGAT[dado]=stoi(AGAT[dado]);
	nSTRAATG[dado]=stoi(AATG[dado]);
	nSTRTATC[dado]=stoi(TATC[dado]);
	//cout << "nSTRAGAT:";
	//cout <<nSTRAGAT[dado] <<endl;
	//cout <<"nSTRAATG: "<<nSTRAATG[dado] <<endl;
	//cout <<"nSTRTATC: "<< nSTRTATC[dado] <<endl;
}
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt

 // Para cada dado de STR
 int entrada = 0;

 //bool check1, check2, check3;
 
		for (int dado = 1; dado <tamanho; dado++){ 
			if (nSTREntrada[entrada] == nSTRAGAT[dado]){
				//cout<<"primeiro IF ok"<<endl;	
			}
		}
		
		entrada++;
			for (int dado = 1; dado <tamanho; dado++){ 
				//cout<<nSTREntrada[entrada]<<"=="<<nSTRAATG[dado]<<endl;
				if (nSTREntrada[entrada] == nSTRAATG[dado]){
					//cout<<"segundo IF ok"<<endl;	
					}
				}
				entrada++;

			for (int dado = 1; dado <tamanho; dado++){ 
			if (nSTREntrada[entrada] == nSTRTATC[dado]){
				//cout<<"terceiro IF ok"<<endl;	
				usuarioEncontrado = dado;
				//saida.push_back(usuarioEncontrado)
				//cout <<nSTREntrada[entrada] <<"=="<< nSTRAATG[dado]<<endl;
				//cout <<"Match ID:"<< nome[usuarioEncontrado]<<endl;
				return usuarioEncontrado;
			}
	 }
	 return 0;
}

string baseDeDados::push_ID(int ID){
string name="0";
for (int i = 1; i <tamanho; i++){
	if (i = ID ){
		name = nome[i];
	}
}

return name;
}


#endif
