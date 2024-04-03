/******************************************************************************
 * Copyright (C) 2024 by David Tutusaus - Student
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. David Tutusaus is not liable for any misuse of this material. 
 *
 *****************************************************************************/

/* @file stats.h 
 * @brief Header file of the statistical analytics program.
 *
 * stats program analyze an array of unsigned char data items and report analytics on the maximum, 
 * minimum, mean, and median of the data set. In addition, it will reorder this data set from large to small.
 * All statistics should be rounded down to the nearest integer. After analysis and sorting is done, it will 
 * print that data to the screen in nicely formatted presentation.
 * 
 * @author David Tutusaus
 * @date 2024.02.17
 */

#ifndef __STATS_H__
#define __STATS_H__

//#include <stdint.h>


unsigned char print_statistics (unsigned char*, unsigned char);
/* @brief Prints data array 
 *
 * Given an array of data and a length, prints the median, mean, maximum
 * and minimum.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Zero value (just to have a controlled return value) which is 
 * unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char print_array (unsigned char*, unsigned char);
/* @brief Prints data array 
 *
 * Given an array of data and a length, prints the array to the screen.
 * Function uses a loop and prints the array.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Zero value (just to have a controlled return value) which is 
 * unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char find_median (unsigned char*, unsigned char);
/* @brief Finds data's median value.
 *
 * Given an sorted array of data and a length, returns the median value
 * Function takes sorted data. If data length is odd number then median 
 * is in the middle of sorted array. If data length is not odd then 
 * median is the mean of two middle data.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Median value which is unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char find_mean (unsigned char*, unsigned char);
/* @brief Finds data's mean value.
 *
 * Given an array of data and a length, returns the mean.
 * Mean of n numbers is the sum of those n numers divided the
 * data length (n)
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Mean which is unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char find_maximum (unsigned char*, unsigned char);
/* @brief Finds the maximum value in the data.
 *
 *  Given an array of data and a length, returns the maximum.
 *	For find the maximum value we will use the linear search.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Maximum value which is unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char find_minimum (unsigned char*, unsigned char);
/* @brief Finds the minimum value in the data.
 *
 *  Given an array of data and a length, returns the minimum.
 *  For find the minimum value we will use the linear search.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Minimum value which is unsigned char type.
 *
 * Test:
 * OK
 */


unsigned char sort_array (unsigned char*, unsigned char); // Tested and OK;
/* @brief Sorts largest to smalleset.
 *
 *  Given an array of data and a length, sorts the array from largest 
 *  to smallest. (The zeroth Element should be the largest value, 
 *  and the last element (n-1) should be the smallest value. )
 *	We will use buble sort method.
 *
 * Inputs:
 * @param unsigned char * data - pointer to the data array 
 * @param int dataLength - length of the data array
 *
 * Outputs:
 * @return Array which is sorted and unsigned char type.
 *
 * Test:
 * OK
 */

#endif /* __STATS_H__ */
