#!/bin/bash

RUN_TEST () {
				TIMEFORMAT=%R
				TOTAL=0
				SIZE=100
				echo "Running $SIZE tests with $1 option"
				for ((INDEX = 0; INDEX < $SIZE; INDEX++))
				do
								../generator $1 > tmp
								(time ../lem-in < tmp) 1>/dev/null 2>res
								RES=`cat res`
								TOTAL=$(echo "$TOTAL + $RES" | bc)
				done
				FINAL=$(echo "$TOTAL / $SIZE" | bc -l)
				echo "Average time: $FINAL"
				rm tmp res
}

RUN_TEST --big
RUN_TEST --big-superposition
