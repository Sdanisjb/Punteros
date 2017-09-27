#include <iostream>

using namespace std;

void inicializarMatriz(int**ptrMatriz,int filas,int columnas){


    for(int i=0;i<filas;i++){
        *(ptrMatriz+i)= new int[columnas];
    }
}

void limpiarMatriz(int**ptrMatriz,int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            *(*(ptrMatriz+i)+j)=j;
        }
    }
}

int main()
{
    int**matriz1=new int*[3];
    int**matriz2=new int*[3];
    int**matriz3=new int*[3];


    inicializarMatriz(matriz1,3,3);
    limpiarMatriz(matriz1,3,3);

    inicializarMatriz(matriz2,3,3);
    limpiarMatriz(matriz2,3,3);

    inicializarMatriz(matriz3,3,3);
    limpiarMatriz(matriz3,3,3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                *(*(matriz3+i)+j)=*(*(matriz3+i)+j) + (*(*(matriz1+i)+k) * *(*(matriz2+k)+j));
            }
        }
    }


    cout<<matriz3[1][1];



}
