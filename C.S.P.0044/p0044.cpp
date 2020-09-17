/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0044.cpp
 * Author: thanh
 *
 * Created on May 31, 2020, 3:11 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
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
                printf("Out of range, re-enter: ");
            }
        } else {
            printf("Invalid value, re-enter: ");
        }
    } while (true);
    return n;
}

void add(int *arr, int &size) {
    if (size > 100) {
        printf("Size over 100");
        return;
    } else {
        printf("Enter a value to add: ");
        int value = getInt(INT_MIN, INT_MAX);
        arr = (int*) realloc(arr,(++size) * sizeof(int));
        arr[size - 1] = value;
    }
}

void display(int arr[], int size) {
    printf("All array element: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void search(int arr[], int size){
    printf("Enter element to search: ");
    int value = getInt(INT_MIN, INT_MAX);
    bool a = false;
    int j = 0;
    for(int j ; j< size; j++){
        if(value == arr[j]){
            a = true;
            printf("Index of element: ");
            break;
        }
    }
    for(int i = j; i< size; i++){
        if(value == arr[i]){
            a = true;
            printf("%d ",i);
        }
    } 
    if(a == false){
        printf("Don't have this element in array\n");
    }
}

void displayRange(int arr[], int size){
    int min,max;
    do{    
        printf("Enter min(min < max): ");
        min = getInt(INT_MIN, INT_MAX);
        printf("Enter max: ");
        max = getInt(INT_MIN, INT_MAX);
    }while(min > max);
    printf("Element from %d to %d: ",min,max);
    for(int i = 0; i< size; i++){
        if(arr[i] >= min && arr[i] <= max){
            printf("%d ",arr[i]);
        }
    }
}

void sort(int arr[],int size){
    int temp;
    for(int i = 0; i < size - 1; i++){ 
        for(int j = i + 1;j < size; j++){
            if(arr[j] < arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("Array after sorting: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(int argc, char** argv) {
    int size = 0;
    int *arr = (int *) malloc(size * sizeof(int));

    while (true) {
        int choose;

        printf("\n========Array Manipulations=========\n");
        printf("1. Add a value\n");
        printf("2. Search a value\n");
        printf("3. Print out the array\n");
        printf("4. Print out values in a range of inputted min and max values\n");
        printf("5. Sort the array in ascending order\n");
        printf("6. Others to Quit\n");
        printf("Your choice(1-6): ");
        choose = getInt(1, 6);
        
        if(choose == 6){
            break;
        }
        switch (choose) {
            case 1:{
                add(arr, size);
                break;
            }
            case 2:{
                search(arr,size);
                break;
            }
            case 3:{
                display(arr, size);
                break;
            }
            case 4:{
                displayRange(arr,size);
                break;
            }
            case 5:{
                sort(arr,size);
                break;
            }
        }
    }
}





