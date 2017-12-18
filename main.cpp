#include "buffer.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int qtdPalavrasNoArq(const char* nomeArquivo);
int tamMaiorPalavra(const char* nomeArquivo);

int main (int argv, char* argc[]){
    const char* nomeArquivo = "teste.txt";
    character* letra = createChar('a');

    cout << letra->text << endl;

    return 0;
}

int qtdPalavrasNoArq(const char* nomeArquivo){
  ifstream arquivo;
  arquivo.open(nomeArquivo);
  char nomeAtual[257];
  int numeroDePalavras = 0;

  while(arquivo >> nomeAtual){
        numeroDePalavras++;
  }

  arquivo.close();
  return numeroDePalavras;
}

int tamMaiorPalavra(const char* nomeArquivo){
  int maiorTamanho = 0;
  char nomeAtual[257];

  ifstream arquivo;
  arquivo.open(nomeArquivo);

  while(arquivo >> nomeAtual){
    if(maiorTamanho < strlen(nomeAtual)){
      maiorTamanho = strlen(nomeAtual);
    }
  }

  arquivo.close();
  return (maiorTamanho - 1);
}
