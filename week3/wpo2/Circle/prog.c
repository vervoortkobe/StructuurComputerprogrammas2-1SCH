//
//  main.c
//  circle_example
//
//  Created by Elisa Gonzalez Boix on 24/09/15.
//  Copyright (c) 2015 Elisa Gonzalez Boix. All rights reserved.
//
//  Example from Dirk Derrider Struct 2

#include <stdio.h>
#include "circle.h"

int main() {
	double r = 70; //local variable definition
	printf("circle area %g\n",circle_area(r));
	return 0;  /* exit (0 => success) */
}
