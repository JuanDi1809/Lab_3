#include <iostream>
#include <string>
#include <fstream>
#include "Codificar.h"

using namespace std;

string verifyFile(){

    string name;

    while(true){
        try{
            cout << "Ingrese el nombre del archivo de (formato .txt): ";
            getline(cin, name);

            if(name.substr(name.size() - 4, 4 ) != ".txt"){
                throw "formato no valido";
            }

            ifstream archivo(name); //Intenta abrir el archivo en modo lectura

            if(!archivo.good()){
                throw runtime_error("el archivo no existe");
            }

            break;
        }
        catch(const exception &ex){
            cerr << "Error: " << ex.what() << endl;
        }
        catch(const char *msg){
            cerr << "Error: " << msg << endl;
        }
    }

    return name;
}

string fileBinary(string name){

    ifstream file;
    string binaryText = "";

    file.open(name, ios::in);

    try{
        if(!file.is_open()){
            throw runtime_error("no se logor abrir el archivo");
        }

        char c;
        while(file.get(c)){
            string valueBinary = convertBinary(c);
            binaryText += valueBinary;
        }

    }
    catch(const exception &ex){
        cerr << "Error " << ex.what();
        return "1";
    }

    file.close();

    return binaryText;
}

void writeFile(string data){

    string name;

    while(true){
        cout << "Ingrese el nombre del archivo de salida (formato .txt): ";
        getline(cin, name);

        if(name.substr(name.size() - 4, 4) == ".txt" ) break;
    }

    ofstream file;
    file.open(name, ios::out);

    try{
        if(!file.is_open()){
            throw runtime_error("no se pudo crear o abrir el archivo");
        }

        file << data;

    }catch(const exception &ex){
        cerr << "Error: " << ex.what() << endl;
    }

    file.close();

}
