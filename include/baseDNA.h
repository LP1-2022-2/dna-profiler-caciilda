#ifndef baseDNA_H
#define baseDNA_H

#include "cabecalho.h"
#include "funcaoBaseDNA.h"

class baseDNA {
	private:
		string sequencia; // sequencia de DNA não identificado
		int nAGAT, nAATG, nTATC; // quantidade de cada STR
		fstream arquivoDNA; // arquivo de entrada do DNA 
		vector <int> indicesAGAT; // indices do AGAT
		vector <int> indicesAATG; // indices do AATG
		vector <int> indicesTATC; // indices do TATC

	public:
		baseDNA();
		~baseDNA(){};
		bool armazenarDNA(string diretorioAux);
		vector<int> push_NSTRS();
		vector<int> push_indicesAGAT();
		vector<int> push_indicesAATG();
		vector<int> push_indicesTATC();
		string pushDNA();
		void separaSequencia();
		
};

// Construtor
baseDNA::baseDNA(){
	nAGAT = 0;
	nAATG = 0;
	nTATC = 0;
}

// Armazena o DNA de entrada na string sequencia
bool baseDNA::armazenarDNA(string diretorioAux){
	string linhaDNA;
	arquivoDNA.open(diretorioAux, std::ios::in);
	if (!arquivoDNA.is_open()){ 
		return false;
	}
	getline(arquivoDNA, sequencia, ' ');
	return true;
}


// retorna o DNA não identificado
string baseDNA::pushDNA (){
    return sequencia;
}

// separa sequências de SRT do DNA, assim como guarda os indices e retorna a quantidade de cada SRT
void baseDNA::separaSequencia(){

	vector <int> separador;
	indicesAATG.clear();
	indicesAATG.clear();
	indicesTATC.clear();
	vector<int>::iterator ptr;

	separador = contarSTR(sequencia, "AGAT"); //Enviando AGAT para o contador de STR
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesAGAT.push_back(*ptr); //adicionando os indices no vector indicesAGAT
	} nAGAT = indicesAGAT.back(); //O ultimo elemento do vetor é o nAGAT

	separador = contarSTR(sequencia, "AATG"); //Enviando AGAT para o contador de STR
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesAATG.push_back(*ptr); //adicionando os indices no vector indicesAATG
	} nAATG =  indicesAATG.back(); //O ultimo elemento do vetor é o nAATG

	separador = contarSTR(sequencia, "TATC");//Enviando AGAT para o contador de STR
	for (ptr = separador.begin(); ptr < separador.end(); ptr++){
		indicesTATC.push_back(*ptr); //adicionando os indices no vector indicesTATC
	} nTATC = indicesTATC.back(); //O ultimo elemento do vetor é o nTATC
}

// Retorna a quantidade de cada STR presente no DNA 
vector<int> baseDNA::push_NSTRS ()
{
    vector<int> nSTRS;
    nSTRS.reserve(3);
	nSTRS.push_back(nAGAT);
    nSTRS.push_back(nAATG);
	nSTRS.push_back(nTATC);
    return nSTRS;
}

// Retorna o índice de AATG
vector<int> baseDNA::push_indicesAATG ()
{
    return indicesAATG;
}

// Retorna o índice de AGAT
vector<int> baseDNA::push_indicesAGAT ()
{
    return indicesAGAT;
}

// Retorna o índice de TATC
vector<int> baseDNA::push_indicesTATC ()
{
    return indicesTATC;
}

#endif