#!/bin/bash
FNAME=./tasks_current/task3.out
NSWEEP=10
jBetaCritical=0.2216544
#rm $FNAME
for i in 20 30 40 50 80 100
do
	#echo "Output of: ./ising3D $jBetaCritical $i $NSWEEP 1 1000" >> $FNAME
	echo "Now doing LATLEN: $i"
	echo "Command: ./ising3D $jBetaCritical $i $NSWEEP 1 $(( 5 * $i * $i * $i)) 1"  
	./ising3D $jBetaCritical $i $NSWEEP 1 $(( 5 * $i * $i * $i)) 1 >> $FNAME
	#echo "----------------------------\n" >> $FNAME
done
