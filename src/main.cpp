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
#include "baseDNA.h"


int main(int argc, char* argv[]) {

baseDeDados Base;
baseDNA usuario;
vector <int> nSTRS;

Base.armazenar(argv[2]); 

usuario.armazenarDNA(argv[4]);
usuario.separaSequencia();
nSTRS = usuario.pushNSTRS();
Base.realizarBusca(nSTRS);


return 0;
}
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt