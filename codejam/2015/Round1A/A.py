import sys
import numpy as np

T = int(sys.stdin.readline())
for testcase in xrange(1, T+1):
    N = int(sys.stdin.readline())
    lis = np.array(sys.stdin.readline().strip().split(' '), dtype=int)
    print 'Case #%d:' % (testcase),
    ans1 = ans2 = 0
    gap = 0
    for ind in xrange(1, len(lis)):
        tmp = lis[ind-1] - lis[ind]
        if tmp > 0:
            ans1 += tmp
            if tmp > gap:
                gap = tmp
    for ind in xrange(1, len(lis)):
        if lis[ind-1] >= gap:
            ans2 += gap
        else:
            ans2 += lis[ind-1]
    print ans1, ans2
