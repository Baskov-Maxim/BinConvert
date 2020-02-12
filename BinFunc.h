#ifndef BINFUNC_H
#define BINFUNC_H

void binstart();	// Submain function
int bin_digit();	// Function for entering a number

// Function for converting a number to binary code
void convert_bin(int num, int* arr, const int SIZE);

// The output function of a binary number
void print_bin(int* arr, const int SIZE);

#endif
