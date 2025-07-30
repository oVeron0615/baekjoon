from collections import deque

def solve():
    p = input()
    n = int(input())
    str = input()[1:-1].split(',')

    if(str == ['']): X = deque()
    else: X = deque(str)
    
    isFront = True
    for c in p:
        if(c == 'R'): isFront = not isFront
        else:
            if(len(X) == 0):
                print("error")
                return
            else:
                if(isFront): X.popleft()
                else: X.pop()
    
    if(isFront == False): X.reverse()
    print('[', end='')
    print(','.join(X), end='')
    print(']')

T = int(input())
for t in range(T):
    solve()