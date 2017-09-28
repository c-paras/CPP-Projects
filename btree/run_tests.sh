#!/bin/sh
#Written by Costa Paraskevopoulos in September 2017
#Run all tests for the Generic B-Tree

for t in test??.cpp
do
	t=`echo $t | egrep -o '[0-9]+'`
	printf "Test $t: "
	make test$t | tail -1
done
