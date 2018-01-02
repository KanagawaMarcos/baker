#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    //Create an array with all capes values
    int* rules = loadAllRules("csv/regras/regraComp",22);

    //Create an two dimensional array with all capes codes
    const char* rulesTypes[22];
    //Periódicos            //Congressos
    rulesTypes[0] = "A1";   rulesTypes[9] = "A1";
    rulesTypes[1] = "A2";   rulesTypes[10] = "A2";
    rulesTypes[2] = "B1";   rulesTypes[11] = "B1";
    rulesTypes[3] = "B2";   rulesTypes[12] = "B2";
    rulesTypes[4] = "B3";   rulesTypes[13] = "B3";
    rulesTypes[5] = "B4";   rulesTypes[14] = "B4";
    rulesTypes[6] = "B5";   rulesTypes[15] = "B5";
    rulesTypes[7] = "C";    rulesTypes[16] = "C";
    rulesTypes[8] = " ";    rulesTypes[17] = " ";

    //


    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");

    //destroyAllPeriodicos(&periodicos);
    destroyAllDocentes(&docentes);



    return 0;

}
