#!/bin/sh

for link in \
"spec.html" \
"diagram.pdf" \
"https://en.wikipedia.org/wiki/Bucket_sort" \
"https://en.wikipedia.org/wiki/Radix_sort" \
"http://parallelcomp.uw.hu/ch09lev1sec5.html" \
"https://homepages.math.uic.edu/~jan/mcs572/parallelsorting.pdf" \
"http://15418.courses.cs.cmu.edu/spring2015content/lectures/102_parallelsort/102_parallelsort_slides.pdf"
do
	firefox "$link"
done
