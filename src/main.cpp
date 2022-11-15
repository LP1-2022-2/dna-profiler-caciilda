#include<iostream>
#include <windows.h>
#include "baseDNA.h"
#include "saida.h"


int main(int argc, char* argv[]) {

saida console;
string DNA;

vector <int> indicesAGAT;
vector <int> indicesAATG;
vector <int> indicesTATC;

console.cabecalho();
console.load_paths(argv[2], argv[1]);


indicesAGAT = usuario.push_indicesAGAT();
indicesAATG = usuario.push_indicesAATG();
indicesTATC = usuario.push_indicesTATC();
//console.resposta(usuarioEncontrado, nSTRS,indicesAGAT, indicesAATG, indicesTATC,DNA);



return 0;
}
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt