#include<iostream>
#include <string>
#include <fstream>
#include "manejoArchivos1.h"

using namespace std;

string validOption(){
    string value;

    while(true){

        try{
            cout << "Ingrese el metodo de codificacion (1 o 2): ";
            getline(cin, value);

            if(value.size() > 1){
                throw "muchos valores o valores no validos";
            }

            if(value != "1" && value != "2"){
                throw "opcion no valida";
            }

            break;
        }
        catch(const char* msg){
            cerr << "Error: " << msg << endl;
        }
    }

    return value;
}

int validSeed(int tam){
    int num;
    string value;

    while(true){
        try{
            cout << "Ingrese el valor de la semilla, debe ser un numero mayor a 2 y menor a " << tam << " :";
            getline(cin, value);

            for(char c : value){
                if(!isdigit(c)){
                    throw invalid_argument("el valor debe ser numerico");
                }
            }

            num = stoi(value);

            if(num <= 2 || num > tam){
                throw out_of_range("valor fuera del rango permitido");
            }

            break;
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return num;
}

string convertBinary(char character){
    int value = character;
    int residue;
    string binary = "";

    while(value > 0){
        residue = value % 2;
        value /= 2;
        binary = to_string(residue) + binary;
    }

    binary = "0" + binary;

    return binary;

}

int contCharacter(char caracter, string text){
    int cont = 0;

    for(char c : text){
        if(c == caracter) cont++;
    }

    return cont;
}

string rule1(string data, int num){

    int crease = num + 1;
    int limit = data.size();

    for(int i = num; i < limit; i += crease){
        if(data[i] == '1'){
            data[i] = '0';
        }
        else if(data[i] == '0'){
            data[i] = '1';
        }
    }

    return data;
}


string encodedMethod1(const string text, int value){
    int modify = (text.size() / value) ;
    int pos = 0;
    string codify = "";
    string auxBlock;


    for(int i = 0; i < modify; i++){

        string modifyBinary;
        string block = text.substr(pos, value) ;

        if(i == 0){
            modifyBinary = rule1(block, 0);
        }
        else{
            int cantOne = contCharacter('1', auxBlock);
            int cantZero = value - cantOne; //Recordar que value es la semilla

            if(cantOne == cantZero){
                modifyBinary = rule1(block, 0);
            }
            else if(cantZero > cantOne){
                modifyBinary = rule1(block, 1);
            }
            else{
                modifyBinary = rule1(block, 2);
            }
        }

        codify += modifyBinary;
        auxBlock = block;
        pos += value;
    }

    int res = text.size() % value ;

    if(res != 0){
        codify += text.substr(text.size() - res, res);
        return codify;
    }

    return codify;
}

//Para el metodo de codificacion2
string rule2(string data){
    int tam = data.size();
    string auxData = data;

    data[0] = auxData[tam - 1];

    for(int i = 1; i < tam; i++){
        data[i] = auxData[i -1];
    }

    return data;
}

string encodeMethod2(const string text, int value){
    int modify = text.size() / value;
    int posInicial = 0;
    string codify = "";
    string modifyBinary;

    for(int i = 0; i < modify; i++){
        string block = text.substr(posInicial, value);
        modifyBinary = rule2(block);

        codify += modifyBinary;
        posInicial += value;
    }

    int res = text.size() % value;

    if( res != 0){
        codify += text.substr(text.size() - res, res);
        return codify;
    }

    return codify;

}

void firstProgram(){

    string method = validOption();
    string inputFileName = verifyFile();

    string dataBinary = fileBinary(inputFileName);
    int seed = validSeed(dataBinary.size());
    string encoded;

    if(method == "1"){
        encoded = encodedMethod1(dataBinary, seed);
    }
    else {
        encoded = encodeMethod2(dataBinary, seed);
    }

    writeFile(encoded);
}
