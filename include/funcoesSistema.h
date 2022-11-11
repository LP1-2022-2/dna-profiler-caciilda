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
#include <vector>
using std::vector;
#include <sstream>
#include <map>
using std::map;
using std::stringstream;
#include "baseDeDados.h"
#include "baseDNA.h"

string d, base, s, archSequencia;
string DNA, linhaDNA;
baseDeDados<string> Base;
baseDNA usuario;
fstream baseDados, sequencia;

void lerEntradas(string dAux, string diretorioAux, string sAux, string seqAux){
cout<<"entrou em lerEntradas()"<<dAux<<endl;
 d= dAux;
 base = diretorioAux;
 cout<<"base: "<<base<<endl;
 s= sAux;
 archSequencia = seqAux;
}

void armazenarDados(){
baseDados.open(base, std::ios::in);

while (baseDados.peek()!=EOF){
    string linhas[4];
	string dado;
	for (int i = 0; i < 4; i++){
	getline(baseDados, linhas[i], ',');
    cout<<linhas[i]<<endl;
	}
    cout<<"fim de for"<<endl;
    //cout<<"base.push: "<<linhas[0]<<" " << linhas[1]<<" "<< linhas[2]<< "" << linhas [3]<<endl;
    Base.push(linhas[0],linhas[1],linhas[2],linhas[3]);
    }
}

void lerDNA(){
   sequencia.open(archSequencia, std::ios::in);
	getline(sequencia, linhaDNA, ' ');
    cout<<linhaDNA<<endl;
    cout<<"fim de for"<<endl;
    //cout<<"base.push: "<<linhas[0]<<" " << linhas[1]<<" "<< linhas[2]<< "" << linhas [3]<<endl;
    usuario.push(linhaDNA);
    usuario.separaSequencia();
    }


   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt