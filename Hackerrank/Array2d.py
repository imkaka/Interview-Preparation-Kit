"""
Topic - Array
Problem Link - https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

"""


#!/bin/python3

import math
import sys

# Complete the hourglassSum function below.


def hourglassSum(arr):
    maxSum = -63
    for i in range(4):
        for j in range(4):
            maxSum = max(maxSum, sum(arr[i][j:j + 3]) + arr[i + 1][j + 1] + sum(arr[i + 2][j:j + 3]))

    return (maxSum)


if __name__ == '__main__':

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    print(str(result) + '\n')
