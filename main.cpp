#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int checkIfFileExistAtRoot(const char* filename);
int checkIfFileExistAtThisPath(const char* filename, const char* path);

int main (int argv, char* argc[]){

    
    return 0;
}


int checkIfFileExistAtRoot(const char* filename){
  //Função ID: 01

  //O nome do arquivo foi realmente passado?
  if(filename != NULL){
    //Evite procurar por arquivos com nomes maiores que 256 chars
    if(strlen(filename) < 256){

      //Tenta abrir o arquivo
      ifstream file;
      file.open(filename);

      //Se o arquivo existir
      if(file.is_open()){
        file.close();
        return 1;
      }else{
        return 0;
      }
    }
    cerr << "ID:01, Erro #2" << endl;
    return 0;
  }
  cerr << "ID:01, Erro #1" << endl;
  return 0;
}

int checkIfFileExistAtThisPath(const char* filename, const char* path){

}
