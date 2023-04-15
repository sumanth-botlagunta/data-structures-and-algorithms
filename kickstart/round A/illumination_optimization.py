INF = float('inf')

def minimum_lightbulbs(M, R, streetlights):
    DP = [INF] * (M + 1)
    DP[0] = 0

    for i in range(1, M + 1):
        for j in reversed(streetlights):
            if i - j > R:
                break
            DP[i] = min(DP[i], DP[max(0, j - R)] + 1)
    
    if DP[M] == INF:
        return 'IMPOSSIBLE'
    else:
        return DP[M]

t = int(input())
for i in range(1, t + 1):
    M, R, N = map(int, input().split())
    streetlights = list(map(int, input().split()))
    ans = minimum_lightbulbs(M, R, streetlights)
    print(f'Case #{i}: {ans}')
