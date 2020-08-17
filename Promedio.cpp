//Programa que saca el promedio desde un archivo csv.
//Creado por Camilo Acevedo.
//Inspirado lector de archivos Cesar Aceros.


#include <iostream> // Libreria para leer y escribir desde / hacia archivos.
#include <fstream> //Archivo de la biblioteca que contiene la defincion de constantes, funciones y algunas operaciones.
#include <vector> //Libreria para operar con arreglos unidimensionales de datos
#include <sstream> //Libreria que proporciona plantillas y tipos que permiten la interoperación entre búferes de flujo y objetos de cadena .
#include <string> //Componente de la biblioteca, utilizado para operaciones de entrada / salida.
using namespace std;//Creamos un bloque que asocie nuestras funciones

void parseCSV()//Indicamos el tipo de datos.
{
    ifstream data("Promedio.csv"); //Buscamos nuestro archivo csv para ser leido.
    string line; // secuencia de caracteres guardados como una fila.
    vector<vector<string>> parsedCsv; //Almacenamos nuestros datos de la secuencia de caracteres.
    int rowcount=0; //Declaramos una variable.
    int colcount=0; //Declaramos una variable.
    while (getline(data,line)) //Ciclo para ejecutar nuestars instrucciones.
    {
        stringstream lineStream(line); //Tratamos un string como un stream, eso nos permite la inserción y la extracción desde y a strings
        string cell; //secuencia de caracteres guardados.
        vector<string>parsedRow; //Almacenamos nuestros datos.
        colcount=0; //Miramos la cantidad de columnas del archivo.
        while (getline(lineStream,cell,',')) //Ciclo para ejecutar nuestars instrucciones.
        {
            parsedRow.push_back(cell); // recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector
            colcount++; //Miramos la cantidad de columnas del archivo.
        }
        rowcount++; //Miramos la cantidad de filas del archivo.
        parsedCsv.push_back(parsedRow); //recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector


    }
    float sumatoria=0; //Definimos la variable sumatoria.
    for(int i=0; i<rowcount; i++){ //Ciclo de control para ejecutar nuestro bloque de columnas.
        for(int j=0; j<colcount;j++){ ////Ciclo de control para ejecutar nuestro bloque de filas.
        float suma=std::stof(parsedCsv[i][j=2]); //Convertimos la variable string a float.
        sumatoria=(suma+sumatoria); //Sumatoria es igual a la suma del valor mas la sumatoria que se lleva
        }
        cout << '\n'; //Se imprime nuestro resultado con un salto de linea.


    }float promedio=0;//Definimos la variable promedio
    promedio=sumatoria/rowcount;//Promedio va a ser igual a la variable sumatoria/el tamaño de la columna
    cout<<promedio; //Imprime promedio
}
int main() //Declaramos nuestra variable para iniciar la ejecucion del programa.
{
    parseCSV(); //Analizamos nuestro archivo para determinar su estructura.
    return 0; //Se abandona el main.
}