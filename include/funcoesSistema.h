#include<iostream>
#include<cstdlib>
#include <cctype>
#include <fstream>
using std::fstream;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
using std::istringstream;
using std::istream;
#include <vector>
using std::vector;
#include "baseDeDados.h"

string d, base, s, seq;
baseDeDados<string> Base;

void lerEntradas(string dAux, string diretorioAux, string sAux, string seqAux){
 d= dAux;
 base = diretorioAux;
 s= sAux;
 seq= seqAux;
}

void armazenarDados(fstream ArquivoBaseDados){
ArquivoBaseDados.open(base, std::ios::in);

while (ArquivoBaseDados.peek()!=EOF){
    string linhas[3];
	string dado;
	for (int i = 0; i <= 3; i++){
	getline(ArquivoBaseDados, linhas[i], ',');
	}
    cout<<linhas<<endl;
    }
}




   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt