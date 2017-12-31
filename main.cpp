#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");
    character* regras = createBufferFile("csv/regras/regraComp");

    char* qualis = new char[2];
    qualis[0] = '0';
    qualis[1] = '\0';

    int valor = getRuleValue(regras,qualis);
    cout << "valor: " << valor << endl;
    delete[] qualis;

    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");

    //destroyAllPeriodicos(&periodicos);
    destroyAllDocentes(&docentes);
    destroyBufferFile(&regras);
    return 0;
}
