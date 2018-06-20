#!/bin/bash

score=0
out=(xFFFF xFFFF x0001)
tests=(tests/test1 tests/test2 tests/test3)

for i in {0..2}; do
  res=$(lc3sim -s tests/run < ${tests[i]} | grep -E 'R6=x0001|R6=xFFFF')
  val=${res:57:5}

  if [[ "$val" == "${out[i]}" ]]; then
    echo "Test" $((i+1))": passed"
    ((score+=1))
  else
    echo "Test" $((i+1))": failed"
  fi
done

echo "Score: "$score"/"${#tests[@]}
