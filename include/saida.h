#ifndef saida_H
#define saida_H

#include <iostream>
#include <string>
#include <list>

using std::list;
using std::string;
using std::getline;
#include "baseDeDados.h"
#include "funcaoBaseDeDados.h"
#include "baseDNA.h"
baseDeDados Base;
baseDNA usuario;
class saida
{
	private:
		string nome, AGAT, AATG, TATC; //ponteiro para os elementos armazenados na saidario
	public:
		saida(string nome = "usuario", string AGAT = "0",string AATG = "0",string TATC = "0");
		~saida();
		void resposta(int usuarioID, vector <int> nSTRS, vector <int> indicesAGAT, vector <int> indicesAATG,vector <int> indicesTATC, string DNA);
		int push(string nome, string AGAT, string AATG, string TATC);
		void cabecalho();
		bool load_paths(string data, string dna);
		void read2(string archive);
		void processar();
};


//Construtor

saida::saida(string nome, string AGAT, string AATG, string TATC)
{
	nome = nome;
	AGAT = AGAT;
	AATG = AATG;
	TATC = TATC;
}


saida::~saida()
{
	//std::cout<<"Entrei no destrutor"<<std::endl;
}


int saida::push(string nome, string AGAT, string AATG, string TATC)
{

	nome= nome;
	AGAT= AGAT;
	AATG= AATG;
	TATC= TATC;

	return 1;
}

void saida::resposta(int usuarioID, vector <int> nSTRS, vector <int> indicesAGAT, vector <int> indicesAATG,vector <int> indicesTATC, string DNA){
string usuarie = Base.push_ID(usuarioID);
int nSTR[3], i = 0;
vector<int>::iterator ptr,ptr2,ptr3,ptr4;
list <int> colorir;

for (ptr = nSTRS.begin(); ptr < nSTRS.end(); ptr++){
	nSTR[i]= *ptr;
//	cout<<endl;
//cout<<"quantidade STRS: "<<*ptr;
//	cout<<endl;
	i++;
	}

	int indAGAT[nSTR[0]],indAATG[nSTR[1]],indTATC[nSTR[2]];
	//------
	i=0;
	for (ptr = indicesAGAT.begin(); ptr < indicesAGAT.end()-2; ptr++){
	indAGAT[i]= *ptr;
	colorir.push_back(*ptr);
//	cout<<endl;
//	cout<<"indAGAT: "<<*ptr;
	//cout<<endl;
	i++;
	}
	//------
	i=0;
	for (ptr = indicesAATG.begin(); ptr < indicesAATG.end()-2; ptr++){
	indAATG[i]= *ptr;
	colorir.push_back(*ptr);
	//cout<<endl;
	//cout<<"indAATG: "<<*ptr;
	//cout<<endl;
	i++;
	}
	//------
	i=0;
	for (ptr = indicesTATC.begin(); ptr < indicesTATC.end()-2; ptr++){
	indTATC[i]= *ptr;
	colorir.push_back(*ptr);
	//cout<<endl;
	//cout<<"indAATG: "<<*ptr;
	//cout<<endl;
	i++;
	}
	int primeiro;
	primeiro = verPrimeiro(indAGAT[0], indAATG[0], indTATC[0]);

cout<<"Match ID (99.9%): "<<usuarioID<<endl;
cout<<"DNA Profile: "<<endl;

for (int a=0; a<=primeiro;a++){
	cout<<" ";
}
for (int a=0; a<=nSTR[2]*4;a++){
	cout<<"v";
}
cout<<endl<<"TATC: [x"<<nSTR[2]<<"]"<<endl;

list<int>::iterator it;
int tamDNA = DNA.size();
it = colorir.begin();
//for (int t = 0; t < tamDNA; t++){
	//if (t = *it){
		//*it == 
	//}
	//for (it = colorir.begin(); it != colorir.end(); ++it){
		//if (t == *it){
		//	cout << system ("color 7");
		//}
		cout<<DNA;
//	}
//}
}

void saida::cabecalho(){
cout<<"================================================"<<endl<<"Welcome to the Basic DNA Profiler, v1.0"<<
endl<<"Copyright (C) 2022, Raquel Brena Silva de Lima"<<endl<<"================================================"<<endl;

cout<<endl<<"This program loads a DNA database and an unknown"<<endl
<<"DNA sequence and tries to find a match between"<<endl<<"the input DNA sequencia and the DNA database."<<endl<<endl;

}

bool saida::load_paths(string base, string dna){
int usuarioEncontrado;
vector <int> nSTRS;
Base.armazenar(base);
usuario.armazenarDNA(dna);
cout<<"[+] Preparing to read the DNA Database file ["<<base<<"]"<<endl;
cout<<"[+] Preparting to read the unknown DNA sequence file ["<<dna<<"]"<<endl;
cout<<"[+] Processing data, please wait."<<endl;
cout<<"[+] Input files succesfully read.";
cout<<" Searching the database for a match... please wait."<<endl;
string DNA = usuario.pushDNA();
usuario.separaSequencia();
nSTRS = usuario.pushNSTRS();
usuarioEncontrado = Base.realizarBusca(nSTRS);
return true;
}


#endif
