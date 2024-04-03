/******************************************************************************
 * @file C1M1 stats.c
 * @brief Assigment Week 1
 * 
 * @author David Tutusaus
 * @date 2024-02-17
 *
 * A simple C-Programming example that exhibits a handful of basic c-programming
 * features to show how to calculate some statistics on a set of numbers:
 *     -Print Statistics
 *     -Print Array
 *     -Find the Median
 *     -Find the Mean
 *     -Find the Maximum
 *     -Find the Minimum
 *     -Sort the Data Array
 *
 *    Note: This program is meant to be compiled in order to verify the 
 *          results.
 *
 *****************************************************************************/
/******************************************************************************
 * Copyright (C) 2024 by David Tutusaus - Student
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. David Tutusaus is not liable for any misuse of this material. 
 *
 *****************************************************************************/

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/******************************************************************************
 * Function: print_statistics
 * Description:
 *     This function prints all the returned values from the statistics
 *     functions.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return:
 *     0
 *****************************************************************************/
unsigned char print_statistics (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: find_median
 * Description:
 *     This function takes a set of numbers and finds the median of the set.
 *     The function works with both "even" and "odd" sizes.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     Truncated unsigned char: with the calculated median
 *****************************************************************************/
unsigned char find_median (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: find_mean
 * Description:
 *     This function takes a set of numbers and finds the mean of the set.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     Truncated unsigned char: with the calculated mean
 *****************************************************************************/
unsigned char find_mean (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: find_minimum
 * Description:
 *     This function takes a set of numbers and finds the minimum of the set.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     unsigned char: with the found minimum
 *****************************************************************************/
unsigned char find_minimum (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: find_maximum
 * Description:
 *     This function takes a set of numbers and finds the maximum of the set.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     unsigned char: with the found maximum
 *****************************************************************************/
unsigned char find_maximum (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: sort_array
 * Description:
 *     This function takes a set of numbers sorts it, in a descending order.
 *     Descending order means that the first array's position (0) contains the
 *     highest number, and the last array's position contains the lowest number.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     0
 * 
 * Note: since the function is accessing the original data set via pointers,
 *       there is no need to return anything.
 *****************************************************************************/
unsigned char sort_array (unsigned char* array_ptr, unsigned char array_lenght);

/******************************************************************************
 * Function: print_array
 * Description:
 *     This function takes a set of numbers and print them in the default output.
 *     The function includes a numeration in front.
 * Parameters:
 *     unsigned char * array_ptr: Pointer to the sample data set
 *     unsigned char array_lenght: Number of items in data set
 * Return: 
 *     0
 * 
 *****************************************************************************/
unsigned char print_array (unsigned char* array_ptr, unsigned char array_lenght);


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
    // If "even" amount of entries
    var_tmp = (array_ptr[array_index-1] + array_ptr[array_index]) / 2;
  }
  else {
    // If "odd" amount of entries
    var_tmp = array_ptr[array_index-1];
  }

  // Truncates from "unsigned int" to "unsigned char" to secure "type compatibility"
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
