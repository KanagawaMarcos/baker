#include "buffer.h"
#include "docente.h"
#include "producao.h"
#include <string.h>
#include <iostream>

using namespace std;

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
    cout << baker(&docentes, &producoes, rules, orientacoes, congressos, periodicos, areaAvaliacao) << endl;
    while(docentes->next != NULL){
      cout << docentes->name << endl;
      docentes = docentes->next;
    }
    destroyBufferFile(&orientacoes);
    destroyBufferFile(&congressos);
    destroyBufferFile(&periodicos);

    return 0;

}
