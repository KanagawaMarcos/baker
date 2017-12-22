#include <iostream>
#include <fstream>
#include <string.h>
#include "docente.h"
#include "buffer.h"

#define FLOW_SIZE 257

using namespace std;

int main (int argv, char* argc[]){

    character* docenteCSV = createBufferFile("docentes.csv");

    //Get the reference to the first character
    character* iterator = docenteCSV;
    
    return 0;
}
