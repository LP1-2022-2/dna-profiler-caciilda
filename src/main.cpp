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
#include "funcoesSistema.h"


int main(int argc, char* argv[]) {
baseDeDados<string> Base;
baseDNA usuario;

Base.armazenar(argv[1],argv[2]); 

//cout <<"TAMANHO BASE: "<<  Base.size()<<endl;
//lerDNA();
//contarSTRs();



return 0;
}
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt