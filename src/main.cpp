#include<iostream>
#include <windows.h>
#include "baseDNA.h"
#include "baseDeDados.h"
#include "saida.h"
#include "cabecalho.h"

int main(int argc, char* argv[]) {
saida console;

console.cabecalho();
if(!console.load_paths(argv[2], argv[4])){
		cout<<endl<<red<<"ERROR. Verifique os seus arquivos."<<reset;
		return 1;
	}
   if (console.buscar()!=false){
      console.resposta();
   } else { 
      cout<<endl<<red<<">>> Sorry, no match in our database."<<reset;
   }

return 0;
}
   
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt