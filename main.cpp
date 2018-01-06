#include "buffer.h"
#include "docente.h"
#include "producao.h"
#include <string.h>
#include <iostream>


using namespace std;

int baker(docente** docentes, producao** producoes, int* rules, character* orientacoes, character* congressos, character* periodicos, char* curso){
  int sucess = 1;

  if((*docentes) != NULL && (*producoes) != NULL){
    if(rules != NULL && orientacoes != NULL && congressos != NULL && periodicos != NULL){
      dictionary* issnDictionary = NULL;
      docente* currentDocente = NULL;
      char* slashN = new char[2];
      slashN[0] = '\n';
      slashN[1] = '\0';

      //It is here to avoid bug of going non stop through .csv
      int numberOfLinesCongressoCSV = numberOfLinesBufferFile(congressos);

      cout << "======================"<< curso << "=======================" << endl;
      int numDeProducoes = 0;
      //Get the first node from the Double Linked List
      currentDocente = (*docentes);
      //Iterate through all docentes
      while(currentDocente != NULL){
        numDeProducoes = 0;
        cout << "Docente: " << currentDocente->name << endl;

        //Store the every single "producao" from the current docente
        producao* allProducao = NULL;

        //It willcurrentProducao = removeProducao(&allProducao) receive the last "producao" whithing the current docente node at the BST
        allProducao = getAllProducoesFromThatDocente(*producoes, currentDocente->id);

        //If the docente has some producao
        if(allProducao != NULL){
          cout << "Producoes: "<< endl;

          //Iterate through all producoes
          producao* currentProducao = NULL;

          int lastRemaing = 1;
          while((currentProducao = removeProducao(&allProducao))){

            //If the current producao is a normal publicacao
            if((!strcmp(currentProducao->type, "ARTIGO-PUBLICADO")) || (!strcmp(currentProducao->type, "ARTIGO-ACEITO-PARA-PUBLICACAO"))){
              int semEstratoQualis = 1;

              //Iterate through all issn's that match
              character* iterator = periodicos;
              while(iterator = find(iterator, currentProducao->issn)){

                //Check if the type is the same at the rule file
                char* areaAvaliacao = getNthColumnDataFromCur(iterator->prev, 3);

                if(!strcmp(curso,areaAvaliacao)){
                  //Set docente points
                  semEstratoQualis = 0;
                  int pontos = qualisCodePeriodicosToInt(clean(getNthColumnDataFromCur(iterator->prev, 4)),rules);
                  currentDocente->totalPoints += pontos;
                  cout << "\t" << clean(getNthColumnDataFromCur(iterator->prev, 4)) << " (" << pontos << ")"  << " - " << currentProducao->issn << " - " << currentProducao->type << " - " <<currentProducao->title << endl;
                  numDeProducoes++;
                  break;
                }

                iterator = iterator->next;
              }
              if(semEstratoQualis == 1){
                int pontos = rules[8];
                cout << "\t" << "Sem Estrato Qualis" << " (" << pontos << ")"  << " - " << currentProducao->issn << " - " << currentProducao->type << " - " <<currentProducao->title << endl;
                currentDocente->totalPoints += pontos;
                numDeProducoes++;
              }
            }else if(!strcmp(currentProducao->type, "TRABALHO_EM_EVENTO")){
              int hasNoQualis = 1;
              character* iteratorSiglaCongresso = congressos;

              //Separate all words whiting the field LOCAL
              char* siglaProducao = strtok(currentProducao->local, " -.,():");
              char* siglaCSV = getNthColumnDataCongresso(iteratorSiglaCongresso,4);


              //Update siglaCSV value
              while(siglaProducao != NULL){
                while(siglaCSV != NULL){
                  char* siglaUpperCase = convertToUpper(siglaProducao);
                  if(!strcmp(siglaUpperCase,siglaCSV)){
                    delete[] siglaUpperCase;
                    hasNoQualis = 0;
                    int pontos = qualisCodeCongressosToInt(clean(getNthColumnDataCongresso(iteratorSiglaCongresso, 5)),rules);
                    currentDocente->totalPoints += pontos;
                    cout << "\t" << clean(getNthColumnDataCongresso(iteratorSiglaCongresso, 5)) << " (" << pontos << ")"  << " - " << currentProducao->type << " - " <<currentProducao->title << endl;
                    numDeProducoes++;
                    break;
                  }

                  iteratorSiglaCongresso = find(iteratorSiglaCongresso->next,slashN);
                  siglaCSV = getNthColumnDataCongresso(iteratorSiglaCongresso,4);
                }

                if(hasNoQualis == 0)
                  break;
                iteratorSiglaCongresso = congressos;
                siglaCSV = getNthColumnDataCongresso(iteratorSiglaCongresso,4);

                //Separate all words whiting the field take, the next one
                siglaProducao = strtok(NULL, " -.,():");
              }

              if(hasNoQualis == 1){
                int pontos = rules[17];
                cout << "\t" <<" Sem Estrato Qualis" << " (" << pontos << ")"  << " - " << currentProducao->type << " - " <<currentProducao->title << endl;
                currentDocente->totalPoints += pontos;
                numDeProducoes++;
              }
            }
            destroyProducao(&currentProducao);


          }
        }
        currentDocente = currentDocente->next;
        cout << "Numero de producoes = " << numDeProducoes << endl;
        cout << "==============================================" << endl;
      }

    }
  }
  return sucess;
}

int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    //A binary search tree for producoes (key = docenteId/ Value = list of producao)
    producao* producoes = loadAllProducoes("csv/producao_V2.csv");


    //Create an array with all capes values
    int* rules = loadAllRules("csv/regras/regraComp",22);

    //Buffer files contain all valid "capes" and "orientações"
    character* orientacoes = createBufferFile("csv/orientacao.csv");
    character* congressos = createBufferFile("csv/qualis_capes_congressos.csv");
    character* periodicos = createBufferFile("csv/qualis_capes_periodicos.csv");


    //Load "area de avaliacao"
    const char* regrasCaminho = "csv/regras/regraComp";
    char* areaAvaliacao = loadAreaAvaliacao(regrasCaminho);

    //Will fill all give a pontuation to all variables of type "docente"
    baker(&docentes, &producoes, rules, orientacoes, congressos, periodicos, areaAvaliacao);

    // while(docentes->next != NULL){
    //   cout << "("<< docentes->id << ") " << docentes->name << endl << " pontos:" << docentes->totalPoints << endl;
    //   docentes = docentes->next;
    // }
    cout << "("<< docentes->id << ") " << docentes->name << endl << " pontos:" << docentes->totalPoints << endl;
    destroyBufferFile(&orientacoes);
    destroyBufferFile(&congressos);
    destroyBufferFile(&periodicos);

  return 0;
}
