#include <iostream>
#include <fstream>
#include "docente.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    //Load the docente.csv file into a Buffer File
    character* docenteCSV = createBufferFile("csv/docentes.csv");

    //Remove the first line of the text (it is useless)
    character* currentLine = removeFirstBufferLine(&docenteCSV);
    destroyBufferFile(&currentLine);

    //A double linked list of type "docente"
    docente* docentes = NULL;

    //Create each "docente" based on the Buffer File
    while(currentLine = removeFirstBufferLine(&docenteCSV)){

      //Get docente's ID
      long id = stringToLong(getNthColumnData(currentLine, 1));
      //Get docente's name
      char* name = getNthColumnData(currentLine, 2);

      //Destroy the removed line (Only the text inside of it)
      destroyBufferFile(&currentLine);

      //Create a docente with the given data and add it to a list
      addDocente(&docentes, id, name);
    }

    docente* i = docentes;
    while(i->next != NULL){
      cout << "======================="<<endl;
      cout << "ID: " << i->id << endl;
      cout << "Name: " << i->name << endl;
    }

    destroyAllDocente(&docentes);
    return 0;
}
