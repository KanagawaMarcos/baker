#include <iostream>
#include <fstream>
#include <string.h>
#include "docente.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    //Load the docente text into memory
    character* docenteCSV = createBufferFile("csv/docentes.csv");

    //Remove the first line of the text (it is useless)
    character* currentLine = removeFirstBufferLine(&docenteCSV);


    //Remove the first docente
    currentLine = removeFirstBufferLine(&docenteCSV);
    printBufferFile(currentLine);
    //char* idFirst = getNthCommaData(currentLine, 1);
    //cout << idFirst << endl;


    destroyBufferFile(&currentLine);
    destroyBufferFile(&docenteCSV);


    return 0;
}
