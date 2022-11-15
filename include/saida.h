#ifndef saida_H
#define saida_H
#include "cabecalho.h"
#include "baseDeDados.h"
#include "baseDNA.h"

baseDeDados Base;
baseDNA usuario;

class saida {
	private:
	string nome; // nome do usuário encontrado
	string DNA; // DNA do usuário encontrado
	int usuarioEncontrado; // ID do usuário encontrado
	vector <int> nSTRS;	// Vetor da quantidade de STRS
	vector <int> indicesAGAT; // Vetor dos índices do AGAT
	vector <int> indicesAATG; // Vetor dos índices do AATG
	vector <int> indicesTATC; // Vetor dos índices do TATC
	public:
		saida(string nome = "usuario");
		~saida(){};
		void resposta();
		void cabecalho();
		bool load_paths(string data, string dna);
		bool buscar();
};

// Construtor
saida::saida(string nome){
	this->nome = nome;

}
// tela de apresentação/início
void saida::cabecalho(){
cout << "\033[1;35m=====================================================" << std::endl;
cout << "\033[1;37m      Welcome to the Basic DNA Profiler, v1.0   " << std::endl;
cout << "\033[1;37m   Copyright (C) 2022, Raquel Brena Silva de Lima   " << std::endl;
cout << "\033[1;35m=====================================================\033[0m"
<< std::endl;

cout<<endl<<WHITE<<"This program loads a"<<ROSA<<" DNA database"<<WHITE<<" and an unknown"<<endl
<<ROSA<<"DNA sequence"<<WHITE<<" and tries to find a "<<GREEN<<"match"<<WHITE<<" between"<<
endl<<"the input DNA sequencia and the DNA database."<<RESET<<
endl<<endl;
}

//carregar arquivos de entrada da base e do DNA desconhecido
bool saida::load_paths(string base, string dna){
if ((Base.armazenarBase(base) && usuario.armazenarDNA(dna))!= false){ //caso o armazenamento dos arquivos falhe é reportado o erro.
cout<<ROSA<<"[+] "<<RESET<<"Preparing to read the DNA Database file ["<<RED<<base<<RESET<<"]"<<endl;
cout<<ROSA<<"[+] "<<RESET<<"Preparting to read the unknown DNA sequence file ["<<RED<<dna<<RESET<<"]"<<endl;
cout<<ROSA<<"[+] "<<RESET<<"Processing data, please wait."<<endl<<endl;
cout<<ROSA<<"[+] "<<RESET<<GREEN<<"Input files succesfully read."<<RESET<<endl;
cout<<ROSA<<"[+] "<<RESET<<AZUL<<"Searching the database for a match... please wait."<<RESET<<endl;
return true;
}else { return false; }
}

// Chamada do buscar usuário no banco de dados.
bool saida::buscar(){
DNA = usuario.pushDNA(); // buscar DNA
usuario.separaSequencia(); // separar sequência
nSTRS.clear();
nSTRS = usuario.push_NSTRS(); // buscar quantidade de cada nSTR
usuarioEncontrado = Base.realizarBusca(nSTRS); //usuario encontrado? 
if (usuarioEncontrado != 0 ){
	return true; // caso usuário encontrado, retorna verdadeiro
} else { return false; } // caso usuário nao encontrado, retorna falso
}

// saída da resposta do DNA final
void saida::resposta(){
string DNA = usuario.pushDNA();
string usuarie = Base.push_ID(usuarioEncontrado);
int nSTR[3], i = 0;
vector<int>::iterator ptr,ptr2,ptr3,ptr4;
indicesAGAT.clear();
indicesAATG.clear();
indicesTATC.clear();
indicesAGAT = usuario.push_indicesAGAT();
indicesAATG = usuario.push_indicesAATG();
indicesTATC = usuario.push_indicesTATC();

//passando de vector para vetor
for (ptr = nSTRS.begin(); ptr < nSTRS.end(); ptr++){
	nSTR[i]= *ptr;
	i++;
	}
	int indAGAT[nSTR[0]],indAATG[nSTR[1]],indTATC[nSTR[2]]; //QUANTIDADE por INDICES

	i=0;
	//passando de vector para vetor e desconsiderando o último elemento (a quantidade de STR)
	for (ptr = indicesAGAT.begin(); ptr < indicesAGAT.end()-1; ptr++){
	indAGAT[i]= *ptr;
	i++;
	}
	i=0;
	//passando de vector para vetor e desconsiderando o último elemento (a quantidade de STR)
	for (ptr2 = indicesAATG.begin(); ptr2 < indicesAATG.end()-1; ptr2++){
	indAATG[i]= *ptr2;
	i++;
	}
	i=0; 
	//passando de vector para vetor e desconsiderando o último elemento (a quantidade de STR)
	for (ptr3 = indicesTATC.begin(); ptr3 < indicesTATC.end()-1; ptr3++){
	indTATC[i]= *ptr3;
	i++;
	}

cout<<"Match ID (99.9%): "<<usuarie<<endl;
cout<<"DNA Profile: "<<endl;;

cout<<"                         AGAT: [x"<<nSTR[0]<<"]"<<"     AATG: [x"<<nSTR[1]<<"]"<<"     TATC: [x"<<nSTR[2]<<"]"<<endl;;
int tamDNA = DNA.length();

dnaFinal(DNA, tamDNA, indAGAT, indAATG, indTATC);

}

#endif
