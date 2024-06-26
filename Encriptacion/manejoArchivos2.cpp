#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>

using namespace std;

char* verifyFile2() {
    char name[100]; // Tamaño máximo del nombre del archivo
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        try {
            cout << "Ingrese el nombre del archivo de entrada (formato .txt): ";
            cin.getline(name, sizeof(name)); // Leer el nombre del archivo

            int len = strlen(name);
            if (len < 4 || strcmp(name + len - 4, ".txt") != 0) {
                throw "formato no valido";
            }

            ifstream archivo(name); // Intenta abrir el archivo en modo lectura

            if (!archivo.good()) {
                throw runtime_error("el archivo no existe");
            }

            break;
        } catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        } catch (const char* msg) {
            cerr << "Error: " << msg << endl;
        }
    }

    char* nameOficial = new char[strlen(name) + 1];
    strncpy(nameOficial, name, strlen(name));
    nameOficial[strlen(name)] = '\0';

    return nameOficial;
}

char* readFile(const char* name) {
    ifstream file;
    char* binaryText = nullptr;

    file.open(name, ios::in);

    try {
        if (!file.is_open()) {
            throw runtime_error("no se logro abrir el archivo");
        }

        // Obtener el tamaño del archivo
        file.seekg(0, ios::end);
        int fileSize = file.tellg();
        file.seekg(0, ios::beg);

        // Asignar memoria para almacenar el contenido del archivo
        binaryText = new char[fileSize + 1]; // +1 para el caracter nulo
        binaryText[fileSize] = '\0';

        // Leer el contenido del archivo
        char c;
        int pos = 0;
        while(file.get(c)){
            binaryText[pos] = c;
            pos++;
        }

    } catch (const exception &ex) {
        cerr << "Error: " << ex.what() << endl;
        return nullptr; // Retorna "1" para indicar un error
    }

    file.close();

    return binaryText;
}

void writeFile2(const char* data) {
    char name[100];  // Se asume que el nombre del archivo no excederá los 100 caracteres
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    while (true) {
        cout << "Ingrese el nombre del archivo de salida (formato .txt): ";
        cin.getline(name, 100);

        if (strlen(name) >= 4 && strcmp(name + strlen(name) - 4, ".txt") == 0) {
            break;
        }
    }

    ofstream file(name, ios::binary);

    try {
        if (!file.is_open()) {
            throw runtime_error("No se pudo crear o abrir el archivo");
        }

        file.write(data, strlen(data));

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    file.close();
}

