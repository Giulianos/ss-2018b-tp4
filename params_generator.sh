#!/bin/bash
N=0
for (( v=150; v<=170; v+=1 ))
do
  for (( L=3500; L<=4500; L+=10 ))
  do
    N=`expr $N + 1`
    echo -e "v0="$v"E2\nL="$L"E3\ndt=60\ntotal_time=94608000\nmin_jupiter_dist_file=distance_out/min_distance_"$v"_"$L".csv\novito_output_filename=ovito_out/ovito_"$v"_"$L".xyz" > params/$N.param
  done
done