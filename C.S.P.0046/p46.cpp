/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p46.cpp
 * Author: thanh
 *
 * Created on July 13, 2020, 11:24 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <stdio_ext.h>
#include <limits.h>
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

bool checkPrime(int n){
    if(n == 0 || n == 1){
        return false;
    }
    for(int i = 2; i <=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void primeNumbers(){
    int n, i = 2, count = 0;
    printf("Number of primes(1 - 50): ");
    n = getInt(1,50);
    
    while(count < n){
        if(checkPrime(i)){
            printf("%d ", i);
            count ++;
        }
        i++;
    }
}

void fibonacciNumber(){
    int n, fn;
    int f1 = 0;
    int f2 = 1;
    printf("Number tested (1-1000): ");
    n = getInt(1,1000);
    while(fn < n){
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    if(fn == n){
        printf("It's a  Fibonacci term");
    }else printf("It's a not Fibonacci term");
}

void sumDigits(){
    int sum = 0,n,i;
    printf("Enter an integer: ");
    n = getInt(INT_MIN,INT_MAX);
    while (n != 0){
        i = n%10;//
        n = n/10;
        sum +=i;
    }
    printf("Sum of it's digits: %d",sum);
}

int main(int argc, char** argv) {
    int n;
    while(1){
        printf("\n1 - The first primes\n");
        printf("2 - Fibonacci element\n");
        printf("3 - Sum of digits\n");
        printf("Choose an option: ");
        scanf("%d" , &n);
        switch(n){
            case 1: primeNumbers(); 
                    break;
            case 2: fibonacciNumber();
                    break;
            case 3: sumDigits();
                    break;
        }
    }
    return 0;
}

