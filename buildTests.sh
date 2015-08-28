#!/bin/bash

GENERATION="./Generation"
TESTS="./Tests"

i=0
NUM_TESTS=20
while [ $i -lt $NUM_TESTS ]
do
    i=$(printf %02d $((10#$i + 1)))
    VERTS=$(bc <<< "scale=0;2^$i")
    EDGES=$(bc <<< "scale=0;$VERTS/2")
    $GENERATION/ufgen $VERTS $EDGES > ${TESTS}/t${i}.uf
done
