T = int(input())
for it in xrange(T):
    N = int(input())
    X = []
    Y = []
    M = []
    for i in xrange(N):
        x, y = map(int, raw_input().split(' '))
        X.append(x)
        Y.append(y)
        M.append({})
    for i in xrange(N):
        for j in xrange(i + 1, N):
            a = (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])
            if a in M[i]:
                M[i][a]+=1
            else:
                M[i][a]=1
            if a in M[j]:
                M[j][a]+=1
            else:
                M[j][a]=1
    ans = 0
    for i in xrange(N):
        for j in M[i].values():
            if j > 1:
                ans += j*(j-1)/2
    print "Case:", ans
