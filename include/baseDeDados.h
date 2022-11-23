#ifndef baseDeDados_H
#define baseDeDados_H
#include "cabecalho.h"

class baseDeDados {
	private:
		string *nome, *AGAT, *AATG, *TATC; //ponteiro para os elementos armazenados na baseDeDados
		int tamanho, capacidade;  // quantidade atual de elementos e capacidade.
		fstream arquivoBaseDados;
	public:
		baseDeDados();
		~baseDeDados();
		string push_ID(int ID);
		bool armazenarBase(string diretorioAux);
		int realizarBusca(vector<int> nSTRS);
};
//Construtor com alocação dinâmica
baseDeDados::baseDeDados()
{
	tamanho = 0;
	capacidade = 100;
	nome = new string [capacidade];
	AGAT = new string [capacidade];
	AATG = new string [capacidade];
	TATC = new string [capacidade];
}
// Destrutor de ponteiros
baseDeDados::~baseDeDados() {
	delete[] nome;
	delete[] AGAT;
	delete[] AATG;
	delete[] TATC;
}
// Abrir arquivo csv e armazenar nos ponteiros.
bool baseDeDados::armazenarBase(string diretorioAux){

arquivoBaseDados.open(diretorioAux, std::ios::in); //abrir o direitorio .csv
if (!arquivoBaseDados.is_open()){ // caso o diretorio nao esteja aberto, retornar false e reportar erro
		return false;
	}
while (arquivoBaseDados.peek()!=EOF){ // Enquanto o documento não estiver no fim da leitura
    string linhas[4];
	for (int i = 0; i < 4; i++){
		getline(arquivoBaseDados, linhas[i], ','); // pega dados que estão separados por "," e adiciona no vetor
	}
// organizando do vetor e adicionado em cada ponteiro;
	nome[tamanho] = linhas[0];
	AGAT[tamanho] = linhas[1];
	AATG[tamanho] = linhas[2];
	TATC[tamanho] = linhas[3];
	tamanho++;
	}
	return true;
	}
//---------BASEDADOS::REALIZARBUSCA----------------------------
// Realizar busca de perfil em todos os dados do banco de dados.
int baseDeDados::realizarBusca(vector <int> nSTRS){

int nSTREntrada[3];
int nSTRAGAT[tamanho], nSTRAATG[tamanho], nSTRTATC[tamanho];
int i=0, usuarioEncontrado=0;
vector<int>::iterator ptr;
vector <string> saida;
string nameUsuario;
string nSaidaAux;

//colocando STRs de entrada de VECTOR para VETOR
for (ptr = nSTRS.begin(); ptr < nSTRS.end(); ptr++){
		nSTREntrada[i]=*ptr;
		i++;
	 }

//colocando STRs de vetor de STRING para vetor de INT
for (int dado = 1; dado <tamanho; dado++){
	nSTRAGAT[dado]=stoi(AGAT[dado]);
	nSTRAATG[dado]=stoi(AATG[dado]);
	nSTRTATC[dado]=stoi(TATC[dado]);
}

 int entrada = 0; //entrada de cada STR que estamos procurando

 // realização da busca em cada banco de dados de cada STR.
 for (int dado = 1; dado <tamanho; dado++){
	if (nSTREntrada[entrada] == nSTRAGAT[dado]){
		entrada++;
		 for (int dado = 1; dado <tamanho; dado++){ 
			if (nSTREntrada[entrada] == nSTRAATG[dado]){
			entrada++;
			for (int dado = 1; dado <tamanho; dado++){ 
				if (nSTREntrada[entrada] == nSTRTATC[dado]){
					usuarioEncontrado = dado;
					return usuarioEncontrado; // caso o usuario seja identificado, é enviado seu ID.
					}  // caso não seja identificado, é enviado 0 e reportado a falta de dados.
				}
			} 
		}
	} 
 }
	 return 0; 	 
}

// retorna o nome a partir do ID buscado.
string baseDeDados::push_ID(int ID){
string name;
for (int i = 1; i <tamanho; i++){
	if (i == ID ){
		name = nome[i];
	}
}
return name;
}
#endif
