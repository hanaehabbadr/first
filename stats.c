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
 * @file Week1_Programming_Assignment_stats.C
 * @brief A simple application That Perform statistical analytics on data set
 *
 * Analyzing an array of unsigned char data items and report analytics on the 
 * Maximum, Minimum, Mean, and median of the data set Rounded down to the 
 * nearest interger.
 * After analysis and sorting is doen, data will be printed on the screen in 
 * nicely formatted presentation.
 *
 * @author Hana Ehab Badr 
 * @date   9-7-2021
 *
 */
#include <stdio.h>
#include "stats.h"

#define SIZE (40)

void main() {

  unsigned char num[SIZE] =  { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  //Round the unsigned array to int array 
  int num_int[SIZE],i;
  for(i =0;i < SIZE;i++){
    num_int[i] = (int)num[i];
  }
  
  //Print the Original array
  printf("The main  array :\n");
  print_array(num_int,SIZE);

  //Functions implementation

  //Sort Process Descendingly
  sort_array(num_int, SIZE);
  printf("The array after sorting process descendingly is : \n");
  print_array(num_int, SIZE);

  //Maximum Value
  int T =  find_maximum(num_int, SIZE);
  printf("The Maximum Value is : ");
  print_statistics(T);

  //The minimum Value
  T = find_minimum(num_int, SIZE);
  printf("The Minimum Value is : ");
  print_statistics(T);

  //THe Median Value if the array
  T = find_median(num_int, SIZE);
  printf("The Median Value  is : ");
  print_statistics(T);

  //The Mean Value of the array
  T = find_mean(num_int, SIZE);
  printf("The Mean Value  is : ");
  print_statistics(T);

}


//Function Definition
/**
 * Print unsigned Char
 *
 * Function to print Median, Mean, Max, Mini
 *
 * int Value  
 *  
 *  return None
 */
void print_statistics(int stats){
  printf("%d\n",stats);
  for(int i = 1; i <= 60; i++){
    printf("/");
    if(i == 60 ){
      printf("\n");
    }
  }
}
/**
 *  Print array of char
 *
 * Function to print an array of char
 *
 *  Pointer to an array 
 *  int size of array 
 *  
 * return None
 */
void print_array(int* array, int size){
  int i;
  for(i =0;i < size;i++){
    if(i == 0){
      printf("%d\t", *(array + i));
      continue;
    }
    else if((i+1)%5 == 0){
      printf("%d\n", *(array + i));
      continue;
    }
    else{
      printf("%d\t", *(array + i));
    }
  }
  for(i = 1; i <= 60; i++){
    printf("*");
    if(i == 60 ){
      printf("\n");
    }
  }
}
/**
 *  Find the Median 
 *
 * Function to find the Median 
 *
 * Pointer to an array 
 * int size of array 
 *  
 * return Median value
 */

int find_median(int* array, int size){
  int median;

  /*
   *Note: The median calculation take a place after sorting processe
   */
  median = (*(array+ ((size - 1)/2)) + *(array + (size/2)))/2;
  return median;
}

/**
 * Find the Mean
 *
 * Function to find the Mean 
 *
 *  Pointer to an array 
 *  int size of array 
 *  
 * return Mean value
 */
int find_mean(int* array, int size){
  int i;
  int mean = 0;
  for(i =0;i < size;i++){
    mean += *(array + i);
  }
  mean = mean /size;
  return mean;
}

/**
 * Find the Maximum
 *
 * Function to find the Maximum 
 *
 * Pointer to an array 
 *  int size of array 
 *  
 * return Maximum value
 */
int find_maximum(int* array, int size){
  int max;
  int i;
  for(i =0;i < size;i++){
    if(i == 0){
      max = *(array + i);
    }
    if(*(array + i) > max){
      max = *(array + i);
    }
  }
  return max;
}

/**
 * Find the minimum
 *
 * Function to find the minimum 
 *
 * Pointer to an array 
 *  int size of array 
 *  
 * return minimum value
 */
int find_minimum(int* array, int size){
  int mini;
  int i;
  for(i = 0;i < size;i++){
    if(i == 0){
      mini = *(array + i);
    }
    if(*(array + i) < mini){
      mini = *(array + i);
    }
  }
  return mini;
}
/**
 *  Sort an array descendingly
 *
 * Given an array of data and length, Sort the array from largest to smalles
 *
 * Pionter to an array 
 *  int size of array 
 *  
 * return None
 */

void sort_array(int* array, int size){
  int i,j;
  for(i = 0; i < size; i++){
    int temp;
    for(j = i+1 ; j < size; j++){
      if(*(array + i) < *(array + j)){
        temp = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = temp;
      }
    }
  }
}

