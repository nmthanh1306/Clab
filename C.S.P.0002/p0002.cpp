/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0002.cpp
 * Author: thanh
 *
 * Created on June 2, 2020, 7:51 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
#include <stdio_ext.h>

using namespace std;

/*
 * 
 */
char bigger[][10] = {"","Thuosand","million","bilion"};
char tens[][10] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","seventy","eighty","ninety"};
char units[][10] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","forteen","fifteen",
"sixteen","seventeen","eighteen","nineteen"};
int bigNumber[] = {1,(int)1e3,(int)1e6,(int)1e9};
void caculate(int n, int i){
	int t = n%100;
	if(n/100>0){
		printf("%s hundred ", units[n/100]);
	}
	if(t > 19){
		printf("%s %s ", tens[(n%100)/10], units[(n%100)%10]);
	}
	else{
		printf("%s ", units[n%100]);
	}
	printf("%s ", bigger[i]);
}


int getInt(int min, int max) {
    int n;
    char c;
    int input;
    printf("Please enter string in numeric format(1-999): ");
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
char choice(){
    char c1, c2;
    printf("\n\nEnter 'Y' to continue, 'N' to exit: ");
    do {
        __fpurge(stdin);
        if (scanf("%c%c", &c1, &c2) == 2 && c2 == '\n') {
            if (c1 == 'Y' || c1 == 'N' || c1 == 'y' || c1 == 'n'){
                break;
            }else{
                printf("\n Enter 'Y' to continue, 'N' to exit");
            }
        } else {
            printf("\nInvalid, re-enter: ");
        }
    } while (true);
    return c1;
}

int main(int argc, char** argv){
	int n;
	while(1){
		printf("Enter integer num: ");
		n = getInt(INT_MIN,INT_MAX); // -2147483648 --> 2147483647
		printf("Convert: ");
		if(n==0){
			printf("zero");
		}
		else{
			if(n<0){
			n = (-1)*n;
			printf( "minus ");
			}
			for(int i = 3; i >= 0 ;i--){
				int triple = n/bigNumber[i];
				if(triple>0){
					caculate(triple,i);
					n = n%bigNumber[i];
				}
			}
		}
		printf("\n");
		if(choice() == 'y'){
			continue;
		}
		else break;
	}
	return 0;
}
    

