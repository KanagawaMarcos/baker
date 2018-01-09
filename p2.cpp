#include <iostream>
#include <stdlib.h>


using namespace std;

//char* primeira(char**trajetoria, int rows, int collumns, int i, int j);
int primeira(char**trajetoria, int rows, int collumns);
int estaNoVetor(int* vet, int size, int num);
//char** segunda(char*** trajetorias, int* linhas, int* colunas, int numeroTrajetorias);

int main (int argv, char* argc[]){

  //char trajetoria[8][10] = {'5','5','4','0','0','0','0','0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','4','4','0','0','0','0','0','0','0','0','0','0',3,'0','0','0','0','0','0','0','0','0','0',3,3,'0','0','0','0','0','0','0','0','0',3,'0','0','0','0','0','0','0','0','0',3,'0','0','0','0','0','0','0','0','0',3,'4'};

  //char trajetoria[2][3] = {'1','1','1','0','0','0'};
  char** trajetoria = new char*[2];
  for(int i=0; i<2; i++)
    trajetoria[i] = new char[3];

  trajetoria[0][0] = '1'; trajetoria[0][1] = '1'; trajetoria[0][2] = '0';
  trajetoria[1][0] = '0'; trajetoria[1][1] = '0'; trajetoria[1][2] = '1';


  cout << "return = " << primeira(trajetoria, 2, 3) << endl;
  char* trajetoriaReduzida; //3:0 1:7 2:0 1:7 2:0 3:6 1:0
  //trajetoriaReduzida = primeira(trajetoria, 8,10, 0, 0);
  return 0;
  
  /*
  *   3   2   1
  *   4       0
  *   5   6   7
  */
}

int primeira(char**trajetoria, int rows, int collumns){
  int size = rows*collumns;
  int* pilhaI = new int[size];
  int* pilhaJ = new int[size];
  int top = 0;

  //Itera pela matriz trajetoria criando a pilha do caminho feito
  for( pilhaI[0] = 0; pilhaI[top] < rows; ){
    // cout << "primeiro for" << endl;
    for( pilhaJ[0] = 0; pilhaJ[top] < collumns; ){
      // cout << "segundo for" << endl;

      //Tenta mover para frente (PUSH)
      for(int dir=0; dir<7; dir++){

        switch (dir) {
          //Testa para direita
          case 0:{

            //Se é possível mover para direita
            if((pilhaJ[top]+1) < collumns && trajetoria[pilhaI[top]][(pilhaJ[top]+1)] != '0' && !estaNoVetor(pilhaJ,size,(pilhaJ[top]+1)) ){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)];
              pilhaJ[top] = pilhaJ[(top-1)] + 1;

              cout << "direita" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para diagonal direita superior
          case 1:{

            //Se é possível mover para diagonal direita superior
            if((pilhaJ[top]+1) < collumns && (pilhaI[top]-1) > -1 && trajetoria[(pilhaI[top]-1)][(pilhaJ[top]+1)] != '0' && !estaNoVetor(pilhaJ,size,(pilhaJ[top]+1)) && !estaNoVetor(pilhaI,size,(pilhaI[top]-1))  ){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] - 1;
              pilhaJ[top] = pilhaJ[(top-1)] + 1;

              cout << "diagonal direita superior" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para cima
          case 2:{

            //Se é possível mover para cima
            if((pilhaI[top]-1) > -1 && trajetoria[(pilhaI[top]-1)][(pilhaJ[top])] != '0' && !estaNoVetor(pilhaI,size,(pilhaI[top]-1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] - 1;
              pilhaJ[top] = pilhaJ[(top-1)];

              cout << "cima" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para diagonal esquerda superior
          case 3:{

            //Se é possível mover para diagonal esquerda superior
            if((pilhaJ[top]-1) > -1 && (pilhaI[top]-1) > -1 && trajetoria[(pilhaI[top]-1)][(pilhaJ[top]-1)] != '0' && !estaNoVetor(pilhaI,size,(pilhaI[top]-1)) && !estaNoVetor(pilhaJ,size,(pilhaJ[top]-1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] - 1;
              pilhaJ[top] = pilhaJ[(top-1)] - 1;

              cout << "diagonal esquerda superior" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para esquerda
          case 4:{

            //Se é possível mover para esquerda
            if((pilhaJ[top]-1) > -1 && trajetoria[pilhaI[top]][(pilhaJ[top]-1)] != '0' && !estaNoVetor(pilhaJ,size,(pilhaJ[top]-1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)];
              pilhaJ[top] = pilhaJ[(top-1)] - 1;

              cout << "esquerda" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para diagonal esquerda inferior
          case 5:{

            //Se é possível mover para diagonal esquerda inferior
            if((pilhaJ[top]-1) > -1 && (pilhaI[top]+1) < rows && trajetoria[(pilhaI[top]+1)][(pilhaJ[top]-1)] != '0' && !estaNoVetor(pilhaI,size,(pilhaI[top]+1)) && !estaNoVetor(pilhaJ,size,(pilhaJ[top]-1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] + 1;
              pilhaJ[top] = pilhaJ[(top-1)] - 1;

              cout << "diagonal esquerda inferior" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para baixo
          case 6:{

            //Se é possível mover para baixo
            if((pilhaI[top]+1) < rows && trajetoria[(pilhaI[top]+1)][(pilhaJ[top])] != '0' && !estaNoVetor(pilhaI,size,(pilhaI[top]+1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] + 1;
              pilhaJ[top] = pilhaJ[(top-1)];

              cout << "baixo" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
          //Testa para diagonal direita inferior
          case 7:{
            //Se é possível mover para diagonal direita inferior
            if((pilhaJ[top]+1) < collumns && (pilhaI[top]+1) < rows && trajetoria[(pilhaI[top]+1)][(pilhaJ[top]+1)] != '0' && !estaNoVetor(pilhaI,size,(pilhaI[top]+1)) && !estaNoVetor(pilhaJ,size,(pilhaJ[top]+1))){

              //Push nova posicao
              top++;
              pilhaI[top] = pilhaI[(top-1)] + 1;
              pilhaJ[top] = pilhaJ[(top-1)] + 1;

              cout << "diagonal direita inferior" << endl;
              cout << "saindo da posicao i=" << pilhaI[(top-1)] << " j=" << pilhaJ[(top-1)] << " para posicao i=" << pilhaI[top] << " j=" << pilhaJ[top] << endl;
              cout << "======================" << endl;
              //Reseta a seta de verificação de posicao
              dir = 0;
            }
            break;
          }
        }
      }

      //Move para trás (POP)
      top--;
      cout << "pop, newTop=" << top <<endl;

    }
  }

  return 1;
}

int estaNoVetor(int* vet, int size, int num){
  int esta = 0;
  if(vet != NULL){
    if(size > 0){
      for(int i=0; i<size; i++){
        if(num == vet[i]){
          esta = 1;
          break;
        }
      }
    }
  }
  return esta;
}
/*
char** segunda(char*** trajetorias, int* linhas, int* colunas, int numeroTrajetorias){
  char** trajetoriaRes = NULL;
  int maiorNumLinhas = 0;
  int maiorNumColunas = 0;

  //Calcula as dimensões da trajetoria resultante
  for(int i=0; i<numeroTrajetorias; i++){

    if(linhas[i] > maiorNumLinhas)
      maiorNumLinhas = linhas[i];

    if(colunas[i] > maiorNumColunas)
      maiorNumColunas = colunas[i];
  }

  //Aloca a trajetoria resultante
  trajetoriaRes = new char*[maiorNumLinhas];
  for(int i=0; i<maiorNumLinhas; i++)
    trajetoriaRes[i] = new char[maiorNumColunas];

  //Limpa os valores da matriz resultante
  for(int i=0; i<maiorNumLinhas; i++){
    for(int j=0; j<maiorNumColunas; j++){
      trajetoriaRes[i][j] = '0';
    }
  }

  //Itera pelas trajetorias somando elas
  for(int n=0; n < numeroTrajetorias; n++){

    //Soma a matriz atual à resultante
    for(int i=0; i<linhas[n]; i++){
      for(int j=0; j<colunas[n]; j++){
        trajetoriaRes[i][j] = '0' + atoi(trajetoriaRes[i][j]) + atoi(trajetorias[n][i][j]);
      }
    }
  }

  return trajetoriaRes;
}

*/
