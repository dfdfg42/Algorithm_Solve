K, N = map(int, input().split())
Data = []
for i in range(K):
    height = int(input())
    Data.append(height)

Data.sort()

def cutting(mid):
    counting = 0
    for i in Data:
        counting += i // mid
    return counting

def binary_search(start, end, target):
    if start > end:
        return end

    mid = (start + end) // 2
    now = cutting(mid)

    if now >= target:
        return binary_search(mid + 1, end, target)  
    else:
        return binary_search(start, mid - 1, target) 

maxH = max(Data)
result = binary_search(1, maxH, N)
print(result)
