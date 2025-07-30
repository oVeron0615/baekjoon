N, M = map(int, input().split())
#공백을 단위로 입력을 받아 리스트로 변환하고, 변환한 리스트를 정수형으로 바꾼다.
listen = set(input() for _ in range(N))
#문자열을 한 줄씩 N번 입력받는다.
see = set(input() for _ in range(M))

listenSee = sorted(listen & see)
#교집합을 정렬된 리스트로 바꾼다.

print(len(listenSee))
for name in listenSee:
    print(name)