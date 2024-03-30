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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

//#include <stdint.h>

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Statistical funcions>
 *
 * <Statistical functions>
 *
 * @param <names are described in the .c file> <add description here>
 * @param <names are described in the .c file>
 * @param <names are described in the .c file>
 * @param <names are described in the .c file>
 *
 * @return <The "find_" functions return the expected value, while the "print_" functions return "0">
 */

/* A function that prints the statistics of an array including minimum, maximum, mean, and median */
unsigned char print_statistics (unsigned char*, unsigned char);

/* Given an array of data and a length, prints the array to the screen */
unsigned char print_array (unsigned char*, unsigned char); // Tested and OK;

/* Given an array of data and a length, returns the median value */
unsigned char find_median (unsigned char*, unsigned char); // Tested and OK;

/* Given an array of data and a length, returns the mean */
unsigned char find_mean (unsigned char*, unsigned char); // Tested and OK;

/* Given an array of data and a length, returns the maximum */
unsigned char find_maximum (unsigned char*, unsigned char); // Tested and OK;

/* Given an array of data and a length, returns the minimum */
unsigned char find_minimum (unsigned char*, unsigned char); // Tested and OK;

/* Given an array of data and a length, sorts the array from largest to smallest.
(The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. ) */
unsigned char sort_array(unsigned char*, unsigned char); // Tested and OK;

#endif /* __STATS_H__ */
