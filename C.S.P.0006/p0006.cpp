/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0006.cpp
 * Author: thanh
 *
 * Created on June 2, 2020, 1:53 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <stdio_ext.h>

using namespace std;

/*
 * 
 */

int getInt(int min, int max) {
    int n;
    char c;
    do {
        __fpurge(stdin);
        if (scanf("%d%c", &n, &c) == 2 && c == '\n') {
            if (n >= min && n <= max) {
                break;
            } else {
                printf("Re-enter size of array: ");
            }
        } else {
            printf("Invalid value, re-enter: ");
        }
    } while (1);
    return n;
}

void ascending(int arr[], int size){
    int temp;
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j< size; j++){
            if(arr[i]> arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]  = temp;
            }
        }
    }
    
    for(int i = 0; i<size; i++){
        printf("%d\t",arr[i]);
    }
}

void descending(int arr[], int size){
    int temp;
    for(int i = 0; i<size-1; i++){
        for(int j = i +1; j< size; j++){
            if(arr[i] < arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i]  = temp;
            }
        }
    }
    
    for(int i = 0; i<size; i++){
        printf("%d\t",arr[i]);
    }
}


int main(int argc, char** argv) {
    printf("Please enter size of array: ");
    int size = getInt(1,20);
    int arr[size];
    for(int i = 0; i < size; i++){
        printf("Enter element[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("The array sorted in ascending:\n");
    ascending(arr,size);
    printf("\nThe array sorted in descending:\n");
    descending(arr,size);
    return 0;
}

