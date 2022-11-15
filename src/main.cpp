#include<iostream>
#include <windows.h>
#include "baseDNA.h"
#include "baseDeDados.h"
#include "saida.h"
#include "cabecalho.h"

int main(int argc, char* argv[]) {
cout<<AZUL;
saida console;
cout<<RESET;
console.cabecalho();
if(!console.load_paths(argv[2], argv[4])){
		cout<<RED<<"ERROR. Verifique os seus arquivos."<<RESET;
		return 1;
	}
   if (console.buscar()!=false){
      console.resposta();
   } else { 
      cout<<RED<<">>> Sorry, no match in our database."<<RESET;
   }

return 0;
}
   //g++ -o teste -Iinclude -Wall src/*.cpp
   //teste.exe -d data/data.csv -s data/sequence_alice.txt