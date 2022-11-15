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
#include "funcaoBaseDNA.h"

class baseDNA {
	private:
		string sequencia; //ponteiro para os elementos armazenados na baseDNA
		int nAGAT, nAATG, nTATC; 
		fstream arquivoDNA; // arquivo 
		vector <int> indicesAGAT;
		vector <int> indicesAATG;
		vector <int> indicesTATC;

	public:
		baseDNA();
		~baseDNA();
		int armazenarDNA(string diretorioAux);
		vector<int> pushNSTRS();
		vector<int> push_indicesAGAT();
		vector<int> push_indicesAATG();
		vector<int> push_indicesTATC();
		string pushDNA();
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
	//std::cout<<"Entrei no destrutor"<<std::endl;
}

vector<int> baseDNA::pushNSTRS ()
{
    vector<int> nSTRS;
    nSTRS.reserve(3);
	nSTRS.push_back(nAGAT);
    nSTRS.push_back(nAATG);
	nSTRS.push_back(nTATC);
    return nSTRS;
}

int baseDNA::armazenarDNA(string diretorioAux){
	string linhaDNA;
	arquivoDNA.open(diretorioAux, std::ios::in);
	getline(arquivoDNA, sequencia, ' ');
	//cout<<sequencia<<endl;
	return 1;
}

string baseDNA::pushDNA ()
{
    return sequencia;
}

void baseDNA::separaSequencia(){
	vector <int> separador;

	indicesAATG.clear();
	indicesAATG.clear();
	indicesTATC.clear();
	vector<int>::iterator ptr, ptr2;

//colocando STRs de entrada de VECTOR para VETOR

	separador = contarSTR(sequencia, "AGAT");
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesAGAT.push_back(*ptr);
	} 
	nAGAT = indicesAGAT.back();
	//cout <<endl<<"quantidade de AGAT: "<<nAGAT<<endl;

	for (int j = 0; j <nAGAT;j++){
	//cout <<"indice NAGAT:" <<indices[j]<<endl;
	}

	//cout<< endl;
	
	separador = contarSTR(sequencia, "AATG");
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesAATG.push_back(*ptr);
	} 
	nAATG =  indicesAATG.back();

	//cout<< endl;

	separador = contarSTR(sequencia, "TATC");
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesTATC.push_back(*ptr);
	} 
	nTATC = indicesTATC.back();
	//cout <<endl<<"quantidade de nTATC: "<<nTATC<<endl;

	//cout<< endl;
/*for (ptr2 = indicesTATC.begin(); ptr2 < indicesTATC.end(); ptr2++){
		cout <<endl<<"indice indicesTATC:" <<*ptr2;
	}
	cout <<endl<<"quantidade de nAATG: "<<nTATC<<endl;*/

}


vector<int> baseDNA::push_indicesAATG ()
{
    return indicesAATG;
}

vector<int> baseDNA::push_indicesAGAT ()
{
    return indicesAGAT;
}

vector<int> baseDNA::push_indicesTATC ()
{
    return indicesTATC;
}
#endif
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt