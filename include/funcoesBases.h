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


int contarSTR(string sequencia, string STR){

    size_t found = sequencia.find(STR);
    int f = 0;
    int listaFounds[100]; //histórico de founds encontrados
    int contador = 0;

    if (found != string::npos){
        listaFounds[f] = found;
        contador++;
        f++;
        //cout<<"encontrado em: "<<found<<endl;
    }
    while (found != string::npos){	 
		found = sequencia.find(STR, found+1);
        listaFounds[f] = found;
       //cout << "founds f: "<<lista[f]<< " founds f-1: " << lista[f-1]<<endl;
        //cout << "First occurrence is " << found << endl;
		if (found == string::npos){
			break;
		} else{ 
            if (listaFounds[f] == listaFounds[f-1]+4){
            contador++;
            f++;
            //cout<<"encontrado em: "<< found<<endl;
            }
        }

        }
        return contador;
    }

void enviarSTRS(){


}


/*
int checarMaiorSequencia(string sequencia, string STR, int nSTR){
    string mixSTR;
    for (int i = 0; i < nSTR;  i++){
        mixSTR.append(STR);
    } 
    size_t found = sequencia.find(mixSTR);
    if ((found != string::npos)){
        return nSTR;
    }else{

    }
}*/

   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt