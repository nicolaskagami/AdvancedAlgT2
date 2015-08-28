#!/bin/bash

GENERATION="./Generation"
BENCHMARKS="./Benchmarks"
RESULTFILE="Bench.dat"
TESTS="./Tests"
EXECDIR="./UF"


echo "Balance Compression Sets Links Biggest PathCost" > ${BENCHMARKS}/${RESULTFILE}
i=0
NUM_TESTS=30
while [ $i -lt $NUM_TESTS ]
do
    let "i+=1"
    bash buildTests.sh
    for EXEC in UF0 UF1 UF2;
    do
        for file in ${TESTS}/*.uf;
        do
            ${EXECDIR}/${EXEC} < ${file} >> ${BENCHMARKS}/${RESULTFILE}
        done
    done
    echo "Batch $i Complete"
done
