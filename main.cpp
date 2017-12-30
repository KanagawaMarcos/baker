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
    char* id = getNthColumnData(currentLine, 1);
    char* name = getNthColumnData(currentLine, 2);

    cout << "====Source Text====" << endl;
    printBufferFile(currentLine);
    cout << endl << "===Removed Data===" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;


    destroyBufferFile(&currentLine);
    destroyBufferFile(&docenteCSV);


    return 0;
}
