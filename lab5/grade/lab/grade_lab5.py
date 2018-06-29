#!/usr/bin/python3

import sys
from io import StringIO
from sh import Command, grep, make

def _compile():
    make()

def _grade(late_deduction):
    # Variables
    score = 0
    max_score = 3
    tests = [['4', '4', '4'],
             ['19', '10', '12'],
             ['23', '20', '6']]
    executable = Command('./bin/mat_mult')

    # Grade submission
    comments = []
    for i, test in enumerate(tests):
        out = StringIO()
        executable(test, _out=out, _timeout=3)

        if out.getvalue().find('Correct!') >= 0:
            comments.append('Test' + str(i) + ': passed')
            score += 1
        else:
            comments.append('Test' + str(i) + ': failed')

    if score == max_score and late_deduction <= 0:
        comments.append('Total: 15')
    else:
        comments.append('Total: 0')

    # Write grade.txt file
    comments = '\n'.join(comments)
    with open('grade.txt', 'w') as file:
        file.write(comments)

if __name__ == '__main__':
    _compile()
    _grade(float(sys.argv[1]))
