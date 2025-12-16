#!/bin/sh

rm -f input
touch input
tail -f input | ./stackMachine
