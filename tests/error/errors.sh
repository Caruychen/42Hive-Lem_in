#!/bin/zsh

DIR=$(dirname `which $0`)
cd $DIR

echo "Testing all error maps..."
for f in $(find ../../maps/error -type f -name "*"); do
	echo ''
	echo $f | cut -d'/' -f 3,4,5
	../../lem-in < $f
done;
