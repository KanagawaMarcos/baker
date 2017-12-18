#include "lista.h"
#include <iostream>

using namespace std;

int main() {
    //cab = cabeça
    lista *cab=NULL;
    int dado = 1;

    while (dado > 0) {
        cin >> dado;
        inserirInicio(&cab, dado);
        imprimir(cab);
    }

    desalocar(&cab);
    cout << "Desespero :";
    imprimir(cab);
}
