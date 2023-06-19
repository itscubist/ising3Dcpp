#!/bin/bash
FNAME1p1=./tasks_current/task2_1p1.out
FNAME0p9=./tasks_current/task2_0p9.out
NSWEEP=10
jBetaCritical0p9=0.199489896
jBetaCritical1p1=0.2438198
#rm $FNAME1p1
#rm $FNAME0p9
echo "Doing 0.9 Jbeta_critical"
for i in 20 30 40 50
do
	#echo "Output of: ./ising3D $jBetaCritical0p9 $i $NSWEEP 1 1000" >> $FNAME0p9
	echo "Now doing LATLEN: $i"
	./ising3D $jBetaCritical0p9 $i $NSWEEP 1 $(($i * $i * $i)) 1 >> $FNAME0p9
	#echo "----------------------------\n" >> $FNAME0p9
done
echo "Doing 1.1 Jbeta_critical"
for i in 20 30 40 50
do
	#echo "Output of: ./ising3D $jBetaCritical1p1 $i $NSWEEP 1 1000" >> $FNAME1p1
	echo "Now doing LATLEN: $i"
	./ising3D $jBetaCritical1p1 $i $NSWEEP 1 $(($i * $i * $i)) 1 >> $FNAME1p1
	#echo "----------------------------\n" >> $FNAME1p1
done
