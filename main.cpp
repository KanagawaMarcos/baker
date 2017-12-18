#include "buffer.h"
#include <iostream>
#include <string.h>

using namespace std;

int main (int argv, char* argc[]){
    character* letra = createChar('a');
    cout << letra->text << endl;
    return 0;
}
