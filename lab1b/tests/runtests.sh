#!/bin/bash

score=0
out=(50FA CA75 5010)
tests=(tests/test1 tests/test2 tests/test3)

for i in {0..2}; do
  res=$(lc3sim -s ${tests[i]} | grep -wc ${out[i]})

  if [[ $res -eq 1 ]]; then
    echo "Test" $((i+1))": passed"
    ((score+=1))
  else
    echo "Test" $((i+1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
