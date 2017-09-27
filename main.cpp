#include <iostream>

using namespace std;

//Funcion que inicializa las matrices asignando espacio de acuerdo a valores dinámicos
void inicializarMatriz(int**matriz,int filas,int columnas,int i=0){
    //Cuando el iterador sea igual a las filas, se detiene la funcion
    if(i==filas){
        return;
    }
    //Asigna N espacios de enteros a cada fila
    *(matriz+i)= new int[columnas];
    //Retorna la funcion con un valor mas en el iterador
    return inicializarMatriz(matriz,filas,columnas,i+1);
}

//Funcion que "limpia" la matriz y asigna a cada posicion de esta el valor de 0
void limpiarMatriz(int**matriz,int filas,int columnas,int i=0,int j=0){
    //EL momento en el que se llena una fila pasa a la siguiente
    if(j==columnas){
        j=0;
        //Retorna la funcion pero ahora trabaja en la siguiente fila
        return limpiarMatriz(matriz,filas,columnas,i+1,j);
    }
    //El momento en el que llena todas las columnas se detiene
    if(i==filas){
        return;
    }
    //El espacio al que apunta eo puntero que apunta a otro puntero se asigna con 0;
    *(*(matriz+i)+j)=0;
    //Retorna la funcion pero ahora trabaja en la siguiente posicion de la fila
    return limpiarMatriz(matriz,filas,columnas,i,j+1);

//Funcion que permite ingresar los elementos de manera recursiva
void ingresarElementos(int**matriz,int filas,int columnas,int i=0, int j=0){
    //Cuando se termina de recorrer una fila
    if(j==columnas){
        j=0;
        //Retorna la funcion pero ahora en la siguiente fila
        return ingresarElementos(matriz,filas,columnas,i+1,j);
    }
    //Cuando se terminan de recorrer todas las filas se detiene
    if(i==filas){
        return;
    }
    //Variable auxiliar que almacena el valor de la matriz
    int elemento;
    cout<<"Ingresar el valor ["<<i<<"] ["<<j<<"] :"<<endl;
    cin>>elemento;
    //El espacio de memoria al que apunta el puntero del puntero se llena con elemento ingresado
    *(*(matriz+i)+j)=elemento;
    //Retorna la funcion pero ahora con el siguiente valor de la fila
    return ingresarElementos(matriz,filas,columnas,i,j+1);
}

//Funcion que multiplica las matrices de manera recursiva
void multiMatrices(int**matriz1,int**matriz2,int**matriz3,int filas,int columnas,int factorcomun,int i=0,int j=0,int k=0){
    //Si se recorren los todos los valores de la fila y columna a multiplicar
    if(k==factorcomun){
        k=0;
        //Se retorna la funcion ahora con la siguiente columna de la segunda matriz
        return multiMatrices(matriz1,matriz2,matriz3,filas,columnas,factorcomun,i,j+1,k);
    }
    //si se recorren todos los espacios de la matriz resultante a multiplicar
    if(j==columnas){
        j=0;
        //se retorna la funcion pero trabajando ahora en la siguiente fila de la primera matriz
        return multiMatrices(matriz1,matriz2,matriz3,filas,columnas,factorcomun,i+1,j,k);
    }
    //Si ya se recorrieron todas las filas de la primera matriz se detiene
    if(i==filas){
        return;
    }

    //Asigna al espacio de memoria que apunta el puntero de puntero la sumatoria del producto de la los
    //elementos de la primera fila por la primera columna
    *(*(matriz3+i)+j)=*(*(matriz3+i)+j) + (*(*(matriz1+i)+k) * *(*(matriz2+k)+j));
    //Retorna la funcion pero trabajando con el siguiente elemetno de la fila de la primera matriz y la columna
    //de la segunda
    return multiMatrices(matriz1,matriz2,matriz3,filas,columnas,factorcomun,i,j,k+1);

}

//Funcion que imprime la matriz de manera recursiva
void printMatriz(int**matriz,int filas,int columnas,int i=0, int j=0){
    //Si se recorren todas las posiciones de una fila
    if(j==columnas){
        j=0;
        cout<<endl;
        //Se retorna la funcion trabajando en la siguiente fila
        return printMatriz(matriz,filas,columnas,i+1,j);
    }
    //Si se recorren todas las filas se detiene
    if(i==filas){
        return;
    }
    cout<<*(*(matriz+i)+j)<<" ";
    //Retorna la funcion trabajando ahora con la siguiente posicion de la fila
    return printMatriz(matriz,filas,columnas,i,j+1);
}

//Funcion que desasigna los espacios asignados a las matrices para no gastar memoria
void borrarMatrices(int**matriz,int filas,int i=0){
    //Si ya se borraron todas las columnas
    if(i==filas){
        //Borra las filas
        delete []matriz;
        return;
    }
    //Borra cada columna
    delete [] matriz[i];
    //Retorna la funcion para borrar la siguiente columna
    return borrarMatrices(matriz,filas,i+1);
}


int main()
{

    //Variables que almacenaran el numero de filas y columnas de cada matriz
    int filas1,columnas1,filas2,columnas2;
    //Se ingresan el numero de filas y columnas de cada matriz
    cout<<"Ingrese el numero de filas de la primera matriz"<<endl;
    cin>>filas1;
    cout<<"Ingrese el numero de columnas de la primera matriz"<<endl;
    cin>>columnas1;
    cout<<"Ingrese el numero de filas de la segunda matriz"<<endl;
    cin>>filas2;
    //Evita que se genere un error en la multiplicacion de matrices por numero de filas y clumnas invalido
    while(columnas1!=filas2){
        cout<<"Numero de filas de la segunda matriz incorrecto. Debe ser igual al numero de columnas de la primera matriz."<<endl;
        cout<<"Vuelva a ingresar numero de filas de la segunda matriz "<<endl;
        cin>>filas2;
    }
    cout<<"Ingrese el numero de columnas de la segunda matriz"<<endl;
    cin>>columnas2;

    //Aqui se declaran las matrices
    int**matriz1=new int*[filas1];
    int**matriz2=new int*[filas2];
    int**matriz3=new int*[filas1];


    //Inicializa, limpia, e ingresan los elementos de la primera matriz
    inicializarMatriz(matriz1,filas1,columnas1);
    limpiarMatriz(matriz1,filas1,columnas1);
    cout<<"Ingresar elementos de la Matriz 1-------------------"<<endl;
    ingresarElementos(matriz1,filas1,columnas1);

    //Inicializa, limpia, e ingresan los elementos de la segunda matriz
    inicializarMatriz(matriz1,filas1,columnas1);
    inicializarMatriz(matriz2,filas2,columnas2);
    limpiarMatriz(matriz2,filas2,columnas2);
    cout<<"Ingresar elementos de la Matriz 2-------------------"<<endl;
    ingresarElementos(matriz2,filas2,columnas2);

    //Inicializa y limpia la matriz resultante
    inicializarMatriz(matriz3,filas1,columnas2);
    limpiarMatriz(matriz3,filas1,columnas2);

    //Multiplica las matrices 1 y 2
    multiMatrices(matriz1,matriz2,matriz3,filas1,columnas2,filas2);

    //Imprime la matriz Resultante
    cout<<"Matriz Resultante -----------"<<endl;
    printMatriz(matriz3,filas1,columnas2);

    //Desasigna todos los espacios asignados a las matrices
    borrarMatrices(matriz1,filas1);
    borrarMatrices(matriz2,filas2);
    borrarMatrices(matriz3,filas1);

    return 0;
}
