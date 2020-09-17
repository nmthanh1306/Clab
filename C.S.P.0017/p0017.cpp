/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p0017.cpp
 * Author: thanh
 *
 * Created on July 30, 2020, 2:33 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>


using namespace std;

/*
 * 
 */

void fuelEconomyCal(){
	int time;
	float speed, gallons;
	printf("How many minutes did you drive?\n");
	scanf("%d",&time);
	printf("What was the average speed of the car during that time?\n");
	scanf("%f",&speed);
	printf("How many gallons of gas did your car use?\n");
	scanf("%f",&gallons);
	printf("Your car averaged %.2f miles per gallon.", speed*time/60/gallons); // s = v*t
}

void distanceTraveledCal(){
	float radius;
	int revolutions;
	printf("What is the radius of your tires, in inches?\n");
	scanf("%f",&radius);
	printf("How many revolutions did your car's tires make?\n");
	scanf("%d",&revolutions);
	printf("Your car traveled %.2f miles.",2*M_PI*radius*revolutions*0.000015783);
        // radius of tires = 2*Pi*r
        // 1 inch = 0.000015783 miles
        // s = c * n
}

void revisedFuelEcoCal(){
	float radius,gallons;
	int revolutions;
	printf("What is the radius of your tires, in inches?\n");
	scanf("%f",&radius);
	printf("How many revolutions did your car's tires make?\n");
	scanf("%d",&revolutions);
	printf("How many gallons of gas did your car use?\n");
	scanf("%f",&gallons);
	printf("Your car averaged %.2f miles per gallon.", M_PI*2*radius*revolutions*0.000015783/gallons);
}

int main(int argc, char** argv) {
    	int choice;
	
        while(true){
            printf("1 - Calculating Fuel Economy\n");
            printf("2 - Calculating Distance Traveled\n");
            printf("3 - Revised Fuel Economy Calculation\n");
            printf("4 -  Exit");
            printf("Choice feature: ");
            scanf("%d",&choice);
            if(choice == 4) break;
            switch(choice){
		case 1: fuelEconomyCal(); break;
		case 2: distanceTraveledCal(); break;
		case 3: revisedFuelEcoCal(); break;
            }
        }
    return 0;
}

