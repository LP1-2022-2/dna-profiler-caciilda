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


int main(int argc, char* argv[])
{
fstream baseDados;
fstream sequencia;

string d = argv[1];
string base = argv[2];
string s = argv[3];
string seq = argv[4];
string linha;
int nLinhas;
baseDados.open(argv[2], std::ios::in,std::ios::out);
vector<string> row;
istringstream line_stream;

while (baseDados.peek()=!EOF){
    string linhas;
    getline(baseDados, linhas, ',');
    cout<<linhas<<endl;
    line_stream.
}

}

   //g++ -o teste -Iinclude -Wall src/*.cpp