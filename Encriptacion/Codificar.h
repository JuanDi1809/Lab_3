#ifndef CODIFICAR_H
#define CODIFICAR_H

#include<iostream>
using namespace std;

/**
 * @brief validOption
 * @return
 */
string validOption();

/**
 * @brief validSeed
 * @param tam
 * @return
 */
int validSeed(int tam);

/**
 * @brief convertBinary
 * @param character
 * @return
 */
string convertBinary(char character);

/**
 * @brief contCharacter
 * @param caracter
 * @param text
 * @return
 */
int contCharacter(char caracter, string text);

/**
 * @brief rule1
 * @param data
 * @param num
 * @return
 */
string rule1(string data, int num);

/**
 * @brief encodedMethod1
 * @param text
 * @param value
 * @return
 */
string encodedMethod1(const string text, int value);

/**
 * @brief rule2
 * @param data
 * @return
 */
string rule2(string data);

/**
 * @brief encodeMethod2
 * @param text
 * @param value
 * @return
 */
string encodeMethod2(const string text, int value);

/**
 * @brief firstProgram
 */
void firstProgram();

#endif // CODIFICAR_H
