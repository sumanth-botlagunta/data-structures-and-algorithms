t = int(input())

for i in range(1, t+1):
    mapping = list(map(int, input().split()))
    n = int(input())

    words = set()
    has_collision = False

    for _ in range(n):
        word = input().strip()
        code = ''
        for c in word:
            code += str(mapping[ord(c)-ord('A')])

        if code in words:
            has_collision = True

        words.add(code)

    print("Case #{}: {}".format(i, "YES" if has_collision else "NO"))
