#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"
#include "producao.h"

using namespace std;

int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    //Create an array with all capes values
    int* rules = loadAllRules("csv/regras/regraComp",22);

    //A binary search tree for producoes (it uses docenteId as key)
    producao* producoes = loadAllProducoes ("csv/producao_V2.csv");

    //=========================================================================
    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");
    //=========================================================================
    
    destroyAllDocentes(&docentes);
    //destroyAllPeriodicos(&periodicos);



    return 0;

}
