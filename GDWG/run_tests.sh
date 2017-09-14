#!/bin/sh
#Written by Costa Paraskevopoulos in September 2017
#Run all tests for the Generic Directed Weighted Graph

for t in tests/*.cpp
do
	t=`echo $t | egrep -o '[0-9]{1,2}[mc]?'`
	printf "$t: "
	make test=$t | tail -1
done
