/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Practice with pointers, parameters, header files and loop instructions.>
 *
 * Functions:
 * main ()
 * print_statistics ()
 * print_array ()
 * find_median ()
 * find_mean ()
 * find_maximum ()
 * find_minimum ()
 * sort_array ()
 *
 * @author <David Tutusaus>
 * @date <2024-02-17>
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned int main (void) {
  /* Variable Declarations Go Here */

  unsigned char array_test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                            114, 88,   45,  76, 123,  87,  25,  23,
                            200, 122, 150, 90,   92,  87, 177, 244,
                            201,   6,  12,  60,   8,   2,   5,  67,
                              7,  87, 250, 230,  99,   3, 100,  90};

  unsigned char array_sorted[SIZE] = {0};

  /* Statistics and Printing Functions Go Here */

  printf ("Holar Caracola\n");

  printf ("\nPrint original array\n");
  printf   ("--------------------\n");
  print_array (array_test, SIZE);

  printf ("\nPrint statistics\n");
  printf   ("----------------\n");

  print_statistics (array_test, SIZE);

  printf ("\nPrint sorted array\n");
  printf   ("------------------\n");
  sort_array (array_test, SIZE);
  print_array (array_test, SIZE);

  return 0;
}

/* Implementation File Code Here */

/* print_statistics*/
unsigned char print_statistics (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char var_tmp = 0;

  var_tmp = find_maximum (array_ptr, array_lenght);
  printf ("Printing Maximum: %u\n", var_tmp);

  var_tmp = find_minimum (array_ptr, array_lenght);
  printf ("Printing Minimum: %u\n", var_tmp);

  var_tmp = find_mean (array_ptr, array_lenght);
  printf ("Printing Mean: %u\n", var_tmp);

  var_tmp = find_median (array_ptr, array_lenght);
  printf ("Printing Median: %u\n", var_tmp);

  return 0;
}

unsigned char find_median (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index = 0;
  unsigned int var_tmp = 0;

  var_tmp = array_lenght % 2;
  array_index = array_lenght / 2;

  if (var_tmp == 0) {
    var_tmp = (array_ptr[array_index-1] + array_ptr[array_index]) / 2;
  }
  else {
    var_tmp = array_ptr[array_index-1];
  }

  return (unsigned char) var_tmp;
}

unsigned char find_mean (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index = 0;
  unsigned int var_tmp = 0;

  for (array_index = 0; array_index < array_lenght; array_index ++) {
    var_tmp += array_ptr[array_index];
  }

  var_tmp = var_tmp / array_lenght;

  return (unsigned char) var_tmp;
}

unsigned char find_minimum (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index = 0;
  unsigned char var_tmp = 0;

  var_tmp = array_ptr[array_index];

  for (array_index = 1; array_index < array_lenght; array_index ++) {
    if (var_tmp > array_ptr[array_index]) {
      var_tmp = array_ptr[array_index];
    }
  }

  return var_tmp;
}

unsigned char find_maximum (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index = 0;
  unsigned char var_tmp = 0;

  var_tmp = array_ptr[array_index];

  for (array_index = 1; array_index < array_lenght; array_index ++) {
    if (var_tmp < array_ptr[array_index]) {
      var_tmp = array_ptr[array_index];
    }
  }

  return var_tmp;
}

/* sort_array function*/
unsigned char sort_array (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index_highest = 0;
  unsigned char array_index_dyn = 0;
  unsigned char var_tmp = 0;

  for (array_index_highest = 0; array_index_highest < array_lenght; array_index_highest ++) {
    for (array_index_dyn = array_index_highest + 1; array_index_dyn < array_lenght; array_index_dyn ++) {
      if (array_ptr[array_index_highest] < array_ptr[array_index_dyn]) {
        var_tmp = array_ptr[array_index_highest];
        array_ptr[array_index_highest] = array_ptr[array_index_dyn];
        array_ptr[array_index_dyn] = var_tmp;
      }
    }
  }

  return 0;
}

/* print_array function*/
unsigned char print_array (unsigned char* array_ptr, unsigned char array_lenght) {
  unsigned char array_index = 0;

  for (array_index = 0; array_index < array_lenght; array_index ++) {
    printf ("%.2u. %u\n", array_index, array_ptr[array_index]);
  }

  return 0;
}