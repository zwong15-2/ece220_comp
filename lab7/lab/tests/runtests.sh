#!/bin/bash

score=0
out=("goldout1" "goldout2" "goldout3")
tests=("9 13" "15 3" "9 10")

end=$((${#tests[@]}-1))
for i in $(seq 0 1 $end); do
  ./bin/lca <<< ${tests[i]} | diff -wb tests/${out[i]} -
  res=$?

  if [[ $res -eq 0 ]]; then
    echo "Test" $((i + 1))": passed"
    ((score += 1))
  else
    echo "Test" $((i + 1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
