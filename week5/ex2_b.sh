#!/bin/bash
while true; do
    if ! ln input.txt input.txt.lock
    then
       sleep 1
    else
        if [ ! -f input.txt ]; then echo 0 > input.txt; fi
        count=0
        touch input.txt
        while [[ $count != 10000 ]]; do
            count=`expr $count + 1`
            n=`tail -1 input.txt`
            expr $n + 1 >> input.txt
        done
        rm input.txt.lock
        break
    fi
done
