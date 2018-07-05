#!/bin/bash

score=0
tests=("3 3 3" "9 17 14" "0 0 0")

end=$((${#tests[@]}-1))
for i in $(seq 0 1 $end); do
  ./bin/mat_mult ${tests[i]} | grep -q 'Correct!'
  res=$?

  if [[ $res -eq 0 ]]; then
    echo "Test" $((i + 1))": passed"
    ((score += 1))
  else
    echo "Test" $((i + 1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
