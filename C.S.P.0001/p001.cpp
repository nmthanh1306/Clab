/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p001.cpp
 * Author: thanh
 *
 * Created on July 16, 2020, 2:15 PM
 */
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char s[100];
    char newS[100];
    char demiter = ' ';
    char strDemiter[2];
    char key;
    strDemiter[0] = demiter;
    strDemiter[1] = 0;
    do {
        printf("Please enter string:");
         __fpurge(stdin);
        fgets(s,100,stdin);
        // gets(s);
        printf("\nThe old string:  %s",s);
        for (int i = strlen(s); i >= 0; i--) {
            if (s[i] == demiter) {
                strcat(newS, &s[i + 1]);
                strcat(newS, strDemiter);
                s[i] = 0;
            }
        }
        strcat(newS, s);
        printf("\nThe reversed string:  %s\n", newS);
        printf("Press enter to continue another reverse, ESC to exit");
        key = getchar();
        if (key == 27) break;
        newS[0] = 0;
    } while (1);
    return 0;
}
