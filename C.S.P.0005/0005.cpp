/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   0005.cpp
 * Author: thanh
 *
 * Created on May 29, 2020, 8:22 PM
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
    int input;
    printf("Enter number(1 - 9): ");
    do {
        __fpurge(stdin);
        input = scanf("%d%c", &n, &c);
        if (input == 2 && c == '\n') {
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

char getChar() {
    char c1, c2;
    printf("Choose 'y' to continue, 'n' to exit: ");
    do {
        __fpurge(stdin);
        if (scanf("%c%c", &c1, &c2) == 2 && c2 == '\n') {
            if (c1 == 'y' || c1 == 'n') {
                break;
            } else {
                printf("Choose 'y' or 'n': ");
            }
        } else {
            printf("Choose 'y' or 'n': ");
        }
    } while (true);
    return c1;
}

void Table() {
    int i = 1;
    int n;
    n = getInt(1, 9);
    while (i <= 10) {
        printf("%d x %d = %d\n", n, i, n * i);
        i++;
    }
}

int main(int argc, char** argv) {
    while (true) {
        Table();
        if (getChar() == 'y') {
            continue;
        } else{
            break;
        }
    }
    return 0;
}


