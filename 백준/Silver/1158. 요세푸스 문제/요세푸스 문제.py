from collections import deque


N,K = map(int, input().split())
# Queue =[]
# for now in range(1,N+1):
#     Queue.append(now)
Queue=deque(range(1,N+1))

print('<', end='')

while len(Queue) > 1:
    for _ in range(K-1):
        Queue.append(Queue.popleft())
    print(Queue.popleft(), end=', ')
print(Queue.popleft(), end='')

print('>') 