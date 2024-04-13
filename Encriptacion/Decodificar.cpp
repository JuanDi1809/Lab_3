#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>
#include <cmath>
#include "manejoArchivos2.h"

using namespace std;

int validOption2() {
    int value;

    while (true) {
        try {
            cout << "Ingrese el metodo de decodificacion (1 o 2): ";
            cin >> value;

            if(cin.fail()){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw runtime_error("dato no valido");
            }

            if (value != 1 && value != 2) {
                throw "opcion no valida";
            }

            break;
        }
        catch (const exception &ex) {
            cerr << "Error: " << ex.what() << endl;
        }
        catch (const char *msg) {
            cerr << "Error: " << msg << endl;
        }
    }
    return value;
}

int validSeed2(int tam){
    int num;

    while(true){
        try{
            cout << "Ingrese el valor de la semilla, debe ser un numero mayor a 2 y menor a " << tam << " :";
            cin >> num;

            if(cin.fail()){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw runtime_error("dato no valido");
            }

            if(num < 2 || num > tam){
                throw "opcion no valida";
            }

            break;
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
        catch(const char *msg){
            cerr << "Error: " << msg;
        }
    }

    return num;
}

int contCharacter2(char caracter, char text[]){
    int cont = 0;
    int size = strlen(text);

    for(int i = 0; i < size; i++){
        if(text[i] == caracter) cont++;
    }

    return cont;
}


void drule1(char data[], int num){

    int crease = num + 1;
    int limit = strlen(data);

    for(int i = num; i < limit; i += crease){
        if(data[i] == '1'){
            data[i] = '0';
        }
        else if(data[i] == '0'){
            data[i] = '1';
        }
    }
}


char* decodedMethod1(const char *text, int value){
    int size = strlen(text);
    int modify = size / value;
    int pos = 0;

    char* decode = new char[size + 1];
    char auxBlock[value];

    auxBlock[value] = '\0';
    decode[0] = '\0';

    for(int i = 0; i < modify; i++){
        char block[value];
        strncpy(block,text + pos, value);
        block[value] = '\0';

        if(i == 0){
            drule1(block, 0);
        }
        else{
            int cantOne = contCharacter2('1', auxBlock);
            int cantZero = value - cantOne; //Recordar que value es la semilla

            if(cantOne == cantZero){
                drule1(block, 0);
            }
            else if(cantZero > cantOne){
                drule1(block, 1);
            }
            else{
                drule1(block, 2);
            }

        }

        strncat(decode, block, strlen(block));
        strncpy(auxBlock, block, value);
        pos += value;
    }

    int res =strlen(text) % value ;

    if(res != 0){
        char block[res];
        block[res] = '\0';

        strncpy(block,text + strlen(text) - res, res);
        strncat(decode, block, strlen(block));

        return decode;
    }

    return decode;

}

int binaryToDecimal(char block[]) {
    int decimalValue = 0;
    int power = 0; // Para mantener el valor de 2 elevado a la potencia correspondiente

    // Recorremos la cadena de bits de derecha a izquierda
    for (int i = strlen(block) - 1; i >= 0; i--) {
        if (block[i] == '1') {
            decimalValue += pow(2, power); // Sumamos 2 elevado a la potencia actual
        }
        power++; // Incrementamos la potencia para el siguiente bit
    }

    return decimalValue;
}

char* goToText(char* binary){
    int size = strlen(binary) / 8;
    int pos = 0;

    char block[9];
    char* text = new char[size + 1];
    text[0] = '\0';

    for(int i = 0; i < size; i++){
        strncpy(block,binary + pos, 8);

        int valueDecimal = binaryToDecimal(block);
        char c = valueDecimal;

        text[i] = c;
        pos += 8;
    }

    text[size] = '\0';
    cout << text;

    return text;
}


void secondProgram(){

    int method2 = validOption2();
    char* inputFileName2 = verifyFile2();
    char* fileCodify =  readFile(inputFileName2);
    int seed2 = validSeed2(strlen(fileCodify));

    char* decoded;
    if(method2 == 1){
        decoded = decodedMethod1(fileCodify, seed2);
    }
    else{
        cout << "parte 2";
    }

    char* text = goToText(decoded);




    delete[] inputFileName2;
    delete[] fileCodify;
    delete[] text;
    delete[] decoded;
}
