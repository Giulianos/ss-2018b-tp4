#!/bin/bash
N=0
for (( v=0; v<=20; v+=2 ))
do
  for (( L=0; L<=10000; L+=1000 ))
  do
    N=`expr $N + 1`
    echo -e "v0="$v"E3\nL="$L"E3\ndt=60\ntotal_time=94608000\nmin_jupiter_dist_file=min_distance_"$v"_"$L".csv\novito_output_filename=ovito_"$v"_"$L".xyz" > params/$N.param
  done
done