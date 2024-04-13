#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>

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

int contCharacter2(char caracter, char* text){
    int cont = 0;

    while(text[cont] != '\0'){
        cont++;
    }

    return cont;
}


char* drule1(char* data, int num){

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

    return data;
}

/*
char* decodedMethod1(const char *text, int value){
    int size = strlen(text);
    int modify = size / value;
    int pos = 0;
    char* decode = new char[size + 1];
    char auxBlock[value];

    for(int i = 0; i < modify; i++){
        char valueBinary[value];
        char block[value];
        strncpy(block,text + pos, value);

        if(i == 0){
            valueBinary = rule1(block, 0);
        }
        else{
            int cantOne = contCharacter('1', auxBlock);
            int cantZero = value - cantOne; //Recordar que value es la semilla

            if(cantOne == cantZero){
                valueBinary = rule1(block, 0);
            }
            else if(cantZero > cantOne){
                valueBinary = rule1(block, 1);
            }
            else{
                valueBinary = rule1(block, 2);
            }

        }

        strcat(decode, valueBinary);
        strncpy(auxBlock, valueBinary, value);
        pos += value;
    }

    return decode;

}
*/

void secondProgram(){

    int method = validOption2();
    //char* inputFileName = verifyFile();
    //char* fileCodify =  readFile(inputFileName);
    //int seed = validSeed(strlen(fileCodify));

    /*
    char* decoded;
    if(method == 1){
        decoded = decodedMethod1(fileCodify, seed);
    }

    delete[] inputFileName;
    delete[] fileCodify;
    */
}
