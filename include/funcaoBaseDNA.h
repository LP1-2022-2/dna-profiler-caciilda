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

vector<int> separador;


vector <int> contarSTR(string sequencia, string STR){
separador.clear();
    size_t found = sequencia.find(STR);
    int f = 0;
    int listaFounds[100];
   //histórico de founds encontrados
    int contador = 0;
   // cout <<endl;
   if (found != string::npos){
        listaFounds[f] = found;
        //cout <<found<<" ";
        separador.push_back(found);
        contador++;
        f++;
       // cout<<"encontrado em: "<<found<<endl;
    }

    while (found != string::npos){	 
		found = sequencia.find(STR, found+1);
        //cout <<found<<" ";
       // cout<<"found funcao: "<<found<<endl;
        listaFounds[f] = found;
        separador.push_back(found);
      // cout << "founds f: "<<listaFounds[f]<< " founds f-1: " << listaFounds[f-1]<<endl;
        //cout << "First occurrence is " << found << endl;
		if (found == string::npos){
			break;
		} else{ 
            if (listaFounds[f] == listaFounds[f-1]+4){
            contador++;
            f++;
           // cout<<"encontrado em: "<< found<<endl;
            }
        }

        }
        separador.push_back(contador);
        return separador;
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