/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0048_file.cpp
 * Author: thanh
 *
 * Created on July 10, 2020, 11:24 AM
 */

#include <cstdlib>
#include <stdlib.h>  /* For exit() function */
#include <stdio.h>
#include <string.h>
using namespace std;

 * 
 */
int main(int argc, char** argv) {
   char sentence[1000];
   FILE *fptr;
 
   fptr = fopen("program.txt", "a");
//   if(fptr == NULL)
//   {
//      printf("Error!");
//      exit(1);
//   }
   printf("Enter a sentence:\n");
   fgets(sentence,1000,stdin);
 
   fprintf(fptr,"%s", sentence);
   printf("Add success\n");
   printf("%s",sentence);// display sentence
   fclose(fptr);
   // doc file 
    if ((fptr =  fopen("program.txt","r")) == NULL){
       printf("Error! opening file");
       exit(1);
    }
   
   fscanf(fptr,"%s",&sentence);
   printf("The sentence in file: %s",sentence);
   fclose(fptr);
   
   
//   int num;
//    if ((fptr = fopen("program.txt","r")) == NULL){
//       printf("Error! opening file");
// 
//       // Program exits if the file pointer returns NULL.
//       exit(1);
//   }
// 
//   fscanf(fptr,"%d", &num);
// 
//   printf("Value of n=%d", num);
//   fclose(fptr); 
   
   return 0;
   
/*
   
}

