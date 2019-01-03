#!/bin/python3

import math
import os
import random
import re
import sys


def minimumBribes(Q):

    moves = 0

    Q = [P - 1 for P in Q]

    # Loop through each person (P) in the queue (Q)
    for i, P in enumerate(Q):
        # i is the current position of P, while P is the
        # original position of P.
        #
        # First check if any P is more than two ahead of
        # its original position
        if P - i > 2:
            print("Too chaotic")
            return

        # Count the no of bribes recieved by P
        for j in range(max(P - 1, 0), i):
            if Q[j] > P:
                moves += 1
    print(moves)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
