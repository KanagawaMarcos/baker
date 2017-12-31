#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"
#include "regra.h"

using namespace std;

int main (int argv, char* argc[]){
    char* qualis = new char[3];
    qualis[0] = 'B';
    qualis[1] = '5';
    qualis[2] = '\0';


    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");
    regra* tmp = createRegra(qualis,25);

    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");

    //destroyAllPeriodicos(&periodicos);
    destroyAllDocentes(&docentes);
    return 0;
}
