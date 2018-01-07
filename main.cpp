#include "buffer.h"
#include "docente.h"
#include "producao.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main (int argv, char* argc[]){
    int numeroDeArqRegras = 0;
    char** regrasNomeArquivo = NULL;
    int opcao = 0;

    do{
      system("clear");
      cout << "==================BAKER==================" << endl;
      cout << "[1] Importar arquivo de regras           " << endl;
      cout << "[2] Sair                                 " << endl;
      cout << "=========================================" << endl;
      cout << "Opcao: ";
      cin >> opcao;


      switch (opcao) {
        case 1:{
          system("clear");
          int achouArquivo = 1;
          cout << "=============================BAKER=========================================" << endl;
          cout << "Quantos arquivos de regras devem ser importados? (0 = sair)" << endl;
          do{
            int input;
            do{
              cout << "Numero: ";
              cin >> input;
            }while(input < 0);
            if(input == 0 )
              break;
            if(numeroDeArqRegras > 0){
              for(int i=0; i< numeroDeArqRegras;i++){
                delete[]  regrasNomeArquivo[i];
              }
              delete[] regrasNomeArquivo;
            }

            regrasNomeArquivo = new char*[input];
            for(int i=0;i<input;i++){
              regrasNomeArquivo[i] = new char[1024];
              cout << "Nome do arquivo " << (i+1) << " :";
              char* buffer = new char[1024];
              cin >> buffer;

              ifstream arquivo;
              arquivo.open(buffer);
              if(arquivo.is_open()){
                cout << "Arquivo de regras " << buffer << " encontrado!" << endl;
                strcpy(regrasNomeArquivo[i], buffer);
                arquivo.close();
              }else{
                cout << "Arquivo de regras " << buffer << " NÃO foi encontrado!" << endl;
                achouArquivo = 0;
              }
              delete[] buffer;
            }
            if(achouArquivo != 0)
              numeroDeArqRegras = input;

          }while(achouArquivo != 1);
        }
      }
      cin.ignore();
    }while(opcao != 2 && numeroDeArqRegras < 1);

    for(int i=0;i<numeroDeArqRegras;i++){
      //Create a double linked list of all "docentes"
      docente* docentes = loadAllDocentes("csv/docentes.csv");

      //A binary search tree for producoes (key = docenteId/ Value = list of producao)
      producao* producoes = loadAllProducoes("csv/producao_V2.csv");


      //Create an array with all capes values
      int* rules = loadAllRules(regrasNomeArquivo[i],22);

      //Buffer files contain all valid "capes" and "orientações"
      character* orientacoes = createBufferFile("csv/orientacao.csv");
      character* congressos = createBufferFile("csv/qualis_capes_congressos.csv");
      character* periodicos = createBufferFile("csv/qualis_capes_periodicos.csv");
      //Remove the headers
      removeFirstBufferLine(&orientacoes);
      removeFirstBufferLine(&congressos);


      //Load "area de avaliacao"
      //const char* regrasCaminho = "regraComp";
      char* areaAvaliacao = loadAreaAvaliacao(regrasNomeArquivo[i]);

      //Will fill all give a pontuation to all variables of type "docente"
      baker(&docentes, &producoes, rules, orientacoes, congressos, periodicos, areaAvaliacao);

       while(docentes->next != NULL){
         cout << "("<< docentes->id << ") " << docentes->name << endl << " pontos:" << docentes->totalPoints << endl;
         docentes = docentes->next;
       }
      cout << "("<< docentes->id << ") " << docentes->name << endl << " pontos:" << docentes->totalPoints << endl;
      destroyBufferFile(&orientacoes);
      destroyBufferFile(&congressos);
      destroyBufferFile(&periodicos);
    }


  return 0;
}
