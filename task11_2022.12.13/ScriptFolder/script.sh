#!/bin/bash

./algo1.exe &
./algo2.exe &
./algo3.exe &
./algo4.exe &
./algo5.exe 

if cmp -s result1.txt answer1.txt ; then 
	 echo "algo1 works right" 
else
	echo "algo1 did not works"
fi

if cmp -s result2.txt answer2.txt ; then
         echo "algo2 works right"
else
        echo "algo2 did not works"
fi
if cmp -s result3.txt answer3.txt ; then
         echo "algo3 works right"
else
        echo "algo3 did not works"
fi
if cmp -s result4.txt answer4.txt ; then
         echo "algo4 works right"
else
        echo "algo4 did not works"
fi
if cmp -s result5.txt answer5.txt ; then
         echo "algo5 works right"
else
        echo "algo5 did not works"
fi
