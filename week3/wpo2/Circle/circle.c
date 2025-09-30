//
//  circle.c
//  circle_example
//
//  Created by Elisa Gonzalez Boix on 24/09/15.
//  Copyright (c) 2015 Elisa Gonzalez Boix. All rights reserved.
//
//  Example from Dirk Derrider Struct 2

#include "pi.h"
#include "circle.h"

double circle_circumference(double radius) {
	return 2 * pi * radius;
}

double circle_area(double radius) {
	return pi * radius * radius;
}
