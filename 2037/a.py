def solve(a_array):
    a_dict = {}
    for a in a_array:
        a_dict[a] = a_dict.get(a, 0) + 1
    
    max_score = 0
    for a in a_dict:
        max_score += a_dict[a] // 2
    
    return max_score

count = int(input())

for i in range(count):
    input()
    a_array = list(map(int, input().split()))
    print(solve(a_array))