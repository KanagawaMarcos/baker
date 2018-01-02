#include <iostream>
#include <fstream>
#include "docente.h"
#include "periodico.h"
#include "buffer.h"

using namespace std;

int main (int argv, char* argc[]){

    /*character* texto = createBufferFile("csv/docentes.csv");
    character* i = texto;
    while(i->next != NULL){
        if(i->data == '\0')
            cout << "existe\n";
        i = i->next;
    }
    //printBufferFile(texto);
    destroyBufferFile(&texto);

*/
    
    //Create a double linked list of all "docentes"
    docente* docentes = loadAllDocentes("csv/docentes.csv");


    int* rules = loadAllRules("csv/regras/regraComp",23);
    for(int i=0;i<23;i++)
      cout << rules[i] << endl;
    //Create a binary search tree of all "periodicos"
    //periodico* periodicos = loadAllPeriodicos("csv/qualis_capes_periodicos.csv");

    //destroyAllPeriodicos(&periodicos);
    destroyAllDocentes(&docentes);

    

    return 0;

}
