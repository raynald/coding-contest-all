import sys
import numpy as np
from fractions import lcm

T = int(sys.stdin.readline())
for testcase in xrange(1, T+1):
    B, N = sys.stdin.readline().strip().split(' ')
    B = int(B)
    N = int(N)
    lis = np.array(sys.stdin.readline().strip().split(' '), dtype=int)
    print 'Case #%d:' % (testcase),
    ans = 1
    for item in lis:
        ans = lcm(ans, item)
    sum = 0
    for item in lis:
        sum += ans / item
    N = N % sum

