#!/bin/zsh

DIR=$(dirname `which $0`)
cd $DIR

echo "Testing leaks with all maps..."
for f in $(find ../../maps -type f -name "*"); do
	echo $f
	leaks --atExit -- ../../lem-in < $f &> res
	if tail -n2 res | head -n1 | grep -q '0 leaks for 0 total leaked bytes.'; then
		echo "No leaks."
    else
		echo "LEAKS!!!"
	fi
done;

/bin/rm res
