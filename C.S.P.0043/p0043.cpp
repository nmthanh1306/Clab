/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0043.cpp
 * Author: thanh
 *
 * Created on June 7, 2020, 4:19 PM
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

void add(int *&arr, int &size) {
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

void delete1(int *&arr, int &size){
    int n,check = 0;
    printf("Enter the number to delete: ");
    scanf("%d",&n);
    int i;
    for(i = 0; i< size; i++){
        if(arr[i] == n){
            check = 1;
            for(int j = i; j < size; j ++){
                arr[j] = arr[j+1];
            }
            size --;
            break;
        }           
    }
    if (check == 0){ 
        printf("don't have this element");
    }
    display(arr,size);
}

void delete2(int *&arr, int &size){
    int n;
    bool a = false;
    printf("Enter n:");
    scanf("%d",&n);
    int i ;
    for(i = 0; i< size; i++){ // 2 3 4 6 5 4
        if (arr[i] == n){
            a = true;
            for(int j = i; j <size; j++){
                    arr[j] = arr[j + 1];
                }
            size --;
            i--; 
        }
    }
    if(a == false){
        printf("Don't have this element");
    }
    
    display(arr, size);
}

void sortAscendingDescending(int arr[],int size, int key){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1;j < size; j++){
            if((arr[j] - arr[i]) * key < 0){ // key = 1, ascending  
                temp = arr[j];               // key = -1, descending
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
        printf("3. Remove the first existence of a value\n");
        printf("4. Remove all existence of a value\n");
        printf("5. Print out the array\n");
        printf("6. Sort the array in ascending order\n");
        printf("7. Sort the array in descending order\n");
        printf("8. Quit\n");
        printf("Your choice(1-6): ");
        choose = getInt(1, 8);
        
        if(choose == 8){
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
                delete1(arr, size);
                break;
            }
            case 4:{
                delete2(arr,size);
                break;
            }
            case 5:{
                display(arr,size);
                break;
            }
            case 6:{
                sortAscendingDescending(arr,size,1);
                break;
            }
            case 7:{
                sortAscendingDescending(arr,size,-1);
                break;
            }
        }
    }
}
