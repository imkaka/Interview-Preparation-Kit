#!/bin/python3

import re
import sys

# Complete the rotLeft function below.


def rotLeft(a, d):
    d = d % len(a)
    return a[d:] + a[0:d]


if __name__ == '__main__':

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    result = rotLeft(a, d)

    print(' '.join(map(str, result)))
