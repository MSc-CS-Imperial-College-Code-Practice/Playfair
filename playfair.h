#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>    // cin/cout
#include <cstring>     // strlen
#include <cctype>      // isalnum

// Function Prototypes

// I) MAIN FUNCTIONS
void prepare(char input[], char output[]);
void grid(char codeword[], char square[6][6]);
void bigram(char square[6][6], char inchar1, char inchar2, char &outchar1, 
    char &outchar2);
void encode(char square[6][6], char prepared[], char encoded[]);
void decode(char square[6][6], char encoded[], char decoded[]);

// II) AUXILIAR FUNCTIONS
bool charAlreadyExist(char someChar, char square[6][6]);
void findPosition(char someChar, int &row, int &col, char square[6][6]);
void cleanMatrix(char square[6][6]);

#endif