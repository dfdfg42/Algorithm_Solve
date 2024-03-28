
K,N = map(int,input().split())
Data = []
maxH = 0
maxN = 0
def cutting(mid):
    counting = 0
    for i in range(len(Data)):
        counting += Data[i] // mid

    return counting

for  i in range(int(K)):
    height = int(input())
    Data.append(height)
    maxH = max(maxH,Data[-1])

Data.sort()

start = 1; end = maxH
mid = (end+start)//2


while start <= end:
    mid = (end + start) // 2
    now = cutting(mid)
    if now >= N:
        start = mid + 1
        maxN = mid
    elif now < N:
        end = mid -1


print(maxN)


