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
#include "funcoesSistema.h"


int main(int argc, char* argv[]) {
fstream baseDados;
fstream sequencia;

lerEntradas(argv[1],argv[2],argv[3], argv[4]);
armazenarDados(baseDados);
baseDados.open(base, std::ios::in);
vector<string> row;

while (baseDados.peek()!=EOF){
    string linhas;
    getline(baseDados, linhas, ',');
    cout<<linhas<<endl;
    }

    return 0;
}

   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt