#include <iostream>
#include "buffer.h"
#include "docente.h"
#include "producao.h"
#include <ctype.h>
using namespace std;
int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    //A binary search tree for producoes (key = docenteId/ Value = list of producao)
    producao* producoes = loadAllProducoes("csv/producao_V2.csv");

    //Create an array with all capes values
    int* rules = loadAllRules("csv/regras/regraComp",22);

    //Buffer files contain all valid "capes" and "orientações"
    character* orientacoes = createBufferFile("csv/qualis_capes_congressos.csv");
    character* congressos = createBufferFile("csv/qualis_capes_congressos.csv");
    character* periodicos = createBufferFile("csv/qualis_capes_periodicos.csv");

    //Will fill all give a pontuation to all variables of type "docente"
    //int e = baker(&docentes, &producoes, rules, orientacoes, congressos, periodicos);
    const char* array = "1415899X";

    //cout << atoi(array) << endl;

    //cout << "Error code : " << e << end;

    destroyAllProducoes(&producoes);
    destroyAllDocentes(&docentes);

    destroyBufferFile(&orientacoes);
    destroyBufferFile(&congressos);
    destroyBufferFile(&periodicos);

    return 0;

}
