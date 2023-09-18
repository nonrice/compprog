#!/bin/zsh

clear

trap "rm -r a.out a.out.dSYM 2>/dev/null" SIGINT EXIT

echo "===BEGIN COMPILE==="
if clang++ $1 -std=c++17 -O2 -Wall -Wextra -fsanitize=address,undefined -g -DLOCAL
then
    echo "===BEGIN RUN==="
    if grep -Fxq "#define INTERACTIVE" $1
    then
		gtime -f'Avgmem (kb): %K Mem (kb): %M Realtime (s): %r' ./a.out
    else
		gtime -f'Avgmem (kb): %K Mem (kb): %M Realtime (s): %r' ./a.out < ~/.in
    fi 
fi

