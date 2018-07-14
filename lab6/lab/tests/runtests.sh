#!/bin/bash

score=0
tests=('tests/goldout')

end=$((${#tests[@]}-1))
for i in $(seq 0 1 $end); do
  ./bin/vector | diff -wb ${tests[i]} - &> /dev/null

  res=$?
  if [[ $res -eq 0 ]]; then
    echo "Test" $((i + 1))": passed"
    ((score += 1))
  else
    echo "Test" $((i + 1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
