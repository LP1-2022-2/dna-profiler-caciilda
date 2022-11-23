#ifndef funcaoBaseDNA_H
#define funcaoBaseDNA_H

#include "cabecalho.h"
#include "funcaoBaseDNA.h"
vector<int> separador;

vector <int> contarSTR(string sequencia, string STR){
separador.clear(); //limpa separador para não acumular informação de outros STRs
int listaFounds[50];
size_t found = sequencia.find(STR, 0); // find() retornará o índice da primeira ocorrência do STR no DNA
int f = 0;
int contador = 0; //histórico de founds encontrados

   if (found != string::npos){ // se ainda não chegou no fim de find, continuar adicionando
       listaFounds[f] = found;
	   separador.push_back(found);
	   contador++; // contador de STRs
	   f++;
    }
    while (found != string::npos){	 // se ainda não chegou no fim de find, continuar adicionando
        int foundAnterior = found; //guardar o foundAnterior para controlar a distancia de STRs
		found = sequencia.find(STR, found+1);
        if ((foundAnterior)+4 == (int)found){
			listaFounds[f] = found;
		    separador.push_back(listaFounds[f]); 
            contador++;
            f++;
        } else {break;}
        }
        separador.push_back(contador);
        return separador;
    }

int a= 0, b=0, c = 0;

void dnaFinal (string DNA,int tamDNA, int indAGAT[], int indAATG[], int indTATC[]){
	for (int ind = 0; ind <=tamDNA;ind++){
	if (ind != indAGAT[a] && (ind != indAATG[b]) && ind != indTATC[c]){
		cout << RESET<< DNA[ind];
	} else{
		if (indAGAT[a]==ind){
			a++;
			for (int q = 0; q <4;q++){
				cout << GREEN << DNA[ind+q];
			}
			ind=ind+3;
			
		} else if (indAATG[b]==ind){
			b++;
			for (int q = 0; q <4;q++){
				cout << GREEN << DNA[ind+q];
			}
			ind=ind+3;
		}
		else {
			c++;
			for (int q = 0; q <4;q++){
				cout << GREEN << DNA[ind+q];
				
			};
			ind=ind+3;
		}
		
	}}
}

   #endif