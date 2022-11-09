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


int main(int argc, char* argv[]) {
fstream baseDados;
fstream sequencia;
baseDeDados entradaBase;
entradaBase ("name","2","3","4");

string d= argv[1];
string base = argv[2];
string s= argv[3];
string seq= argv[4];
string linha;

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