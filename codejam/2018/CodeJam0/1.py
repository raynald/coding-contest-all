import sys

f = sys.stdin

T = int(f.readline())
for it in range(1, T + 1):
    D, P = f.readline().strip().split(' ')
    D = int(D)
    a = 1
    l = []
    for ch in P:
        if ch == 'C':
            a *= 2
        else:
            l += [a]
    action = 0
    print "Case #{}:".format(it),
    if len(l) > D:
        print "IMPOSSIBLE"
    else:
        while sum(l) > D:
            l.sort()
            l[-1] /= 2
            action += 1
        print action
