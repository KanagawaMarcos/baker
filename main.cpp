#include <iostream>
#include <fstream>
#include "docente.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    //Create a double linked list of all docentes
    docente* docentes = loadAllDocentes("csv/docentes.csv");

    destroyAllDocentes(&docentes);
    return 0;
}
