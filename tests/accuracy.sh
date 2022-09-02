#!/bin/bash

ECHO_PERCENT () {
				echo "($1 / $2) * 100" | bc -l
}

RUN_TEST () {
				SIZE=1000
				SAME_OR_LESS=0
				ONE_MORE=0
				TWO_MORE=0
				THREE_OR_MORE=0
				echo "Running $SIZE tests with $1 option"
				for ((INDEX = 0; INDEX < $SIZE; INDEX++))
				do
								../generator $1 > tmp
								RES=`(../lem-in -q < tmp)`
								RES=`(echo $RES | grep -Eo '[0-9]{1,}')`
								TEST=`(cut -d' ' -f2 <<< $RES)`
								SAMPLE=`(cut -d' ' -f3 <<< $RES)`
								DIFF=$(echo "$SAMPLE - $TEST" | bc)
								if [ $DIFF -le 0 ]
								then
												SAME_OR_LESS=$(echo "$SAME_OR_LESS + 1" | bc)
								elif [ $DIFF -eq 1 ]
								then
												echo $RES
												ONE_MORE=$(echo "$ONE_MORE + 1" | bc)
								elif [ $DIFF -eq 2 ]
								then
												TWO_MORE=$(echo "$TWO_MORE + 1" | bc)
								else
												THREE_OR_MORE=$(echo "$THREE_OR_MORE + 1" | bc)
								fi
				done
				echo "Same or less: $SAME_OR_LESS"
				ECHO_PERCENT $SAME_OR_LESS $SIZE
				echo "one more: $ONE_MORE"
				ECHO_PERCENT $ONE_MORE $SIZE
				echo "two more: $TWO_MORE"
				ECHO_PERCENT $TWO_MORE $SIZE
				echo "three or more: $THREE_OR_MORE"
				ECHO_PERCENT $THREE_OR_MORE $SIZE
				rm tmp
}

RUN_TEST --big-superposition
