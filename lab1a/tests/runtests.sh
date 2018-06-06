#!/bin/bash

score=0
out=('Hello')
tests=(tests/test1)

for i in {0..0}; do
  res=$(lc3sim -s ${tests[i]} | grep -c "^${out[i]}")

  if [[ $res -eq 1 ]]; then
    echo "Test" $((i+1))": passed"
    ((score+=1))
  else
    echo "Test" $((i+1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
