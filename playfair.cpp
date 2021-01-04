
#include "playfair.h"

// ============================================================================
// I) MAIN FUNCTIONS
// ============================================================================

void prepare(char input[], char output[]){
    char character;
    int output_index = 0;
    for(int i = 0; i < strlen(input); i++){
        character = input[i];
        // Character is a digit or alphabet letter
        if(isalnum(character)){
            character = toupper(character); // uppercase letters
                                            // (has not side affects on digits)
            output[output_index]=character;
            output_index++;
        }
    }

    // Check if length of input is odd for adding an 'X' or not
        if((strlen(output))%2 != 0)
            output[output_index] = 'X';
}

void grid(char codeword[], char square[6][6]){
    
    cleanMatrix(square);
    int square_index = 0;
    int row, col;
    // Adding codeword to matrix
    for(int i = 0; i < strlen(codeword); i++){
        row = square_index%6;
        col = square_index - row*6;
        if(!charAlreadyExist(codeword[i],square)){
            square[row][col] = codeword[i];
            square_index++;
        }
    }
    // Adding letters to matrix
    for(char letter = 'A'; letter <= 'Z'; letter++){
        row = square_index%6;
        col = square_index - row*6;
        if(!charAlreadyExist(letter,square)){
            square[row][col] = letter;
            square_index++;
        }
    }
    // Adding digits
    for(char digit = '0'; digit <= '9'; digit++){
        row = square_index%6;
        col = square_index - row*6;
        if(!charAlreadyExist(digit,square)){
            square[row][col] = digit;
            square_index++;
        }
    }
    
}

void bigram(char square[6][6], char inchar1, char inchar2, char &outchar1, 
    char &outchar2){
    
    int inchar1_row, inchar1_col;
    int inchar2_row, inchar2_col;

    findPosition(inchar1, inchar1_row, inchar1_col, square);
    findPosition(inchar2, inchar2_row, inchar2_col, square);

    outchar1 = square[inchar1_row][inchar2_col];
    outchar2 = square[inchar2_row][inchar1_col];

}

void encode(char square[6][6], char prepared[], char encoded[]){
    
    // Auxiliar variables
    int prepared_lenght = strlen(prepared);
    int last_index = prepared_lenght-1;
    int second_to_last_index = prepared_lenght-2;
    char temp[prepared_lenght];
    strcpy(temp,prepared);

    // Base case
    if(prepared_lenght == 0)
        return;
    // Iterative case
    bigram(square, prepared[last_index], prepared[second_to_last_index],
        encoded[last_index], encoded[second_to_last_index]);
    temp[last_index] = '\0';
    temp[second_to_last_index] = '\0';
    encode(square, temp, encoded);
}

void decode(char square[6][6], char encoded[], char decoded[]){
    
    // Auxiliar variables
    int encoded_lenght = strlen(encoded);
    char prepared[encoded_lenght];
    prepare(encoded, prepared);

    encode(square, prepared, decoded);
    decoded[encoded_lenght] = '\0';

}

// ============================================================================
// II) Auxiliar Functions
// ============================================================================

bool charAlreadyExist(char someChar, char square[6][6]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(someChar == square[i][j]){
                return true;
            }
        }
    }
    return false;
}

void findPosition(char someChar, int &row, int &col, char square[6][6]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(someChar == square[i][j]){
                row = i;
                col = j;
            }
        }
    }
}

void cleanMatrix(char square[6][6]){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            square[i][j] = '\0';
        }
    }
}