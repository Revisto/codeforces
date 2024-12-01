from collections import Counter

def solve(length, mixed_grids):
    k = length - 2
    counts = Counter(mixed_grids)
    mixed_grids_set = set(mixed_grids)

    for a in range(1, int(k ** 0.5) + 1):
        if k % a == 0:
            b = k // a
            if a in mixed_grids_set and b in mixed_grids_set:
                if a == b and counts[a] < 2:
                    continue
                return f"{a} {b}"


count = int(input())

for i in range(count):
    length = int(input())
    mixed_grids = list(map(int, input().split()))
    print(solve(length, mixed_grids))