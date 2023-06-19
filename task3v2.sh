#!/bin/bash
FNAME=./tasks_current/task3v2.out
NSWEEP=1000
jBetaCritical=0.2216544
updates=(15 22 30 37 61 77)
#rm $FNAME
for i in 20 30 40 50 80 100
do
	#echo "Output of: ./ising3D $jBetaCritical $i $NSWEEP 1 1000" >> $FNAME
	echo "Now doing LATLEN: $i"
	echo "Command: ./ising3D $jBetaCritical $i $NSWEEP 1 ${updates[$i]} 1"  
	./ising3D $jBetaCritical $i $NSWEEP 1 ${updates[$i]} 1 >> $FNAME
	#echo "----------------------------\n" >> $FNAME
done
