#include <iostream>
#include <fstream>
#include <string.h>
#include "docente.h"
#include "buffer.h"

#define FLOW_SIZE 257

using namespace std;

int main (int argv, char* argc[]){

    //Loads all ".csv" files into Buffers Files
    character* docenteCSV = createBufferFile("csv/docentes.csv");
    printBufferFile(docenteCSV);

    destroyBufferFile(&docenteCSV);

    return 0;
}
