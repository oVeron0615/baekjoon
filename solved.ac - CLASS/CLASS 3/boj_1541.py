equation = input().split('-')
ans = sum(map(int, equation[0].split('+')))
for eq in equation[1:]:
    plus = sum(map(int, eq.split('+')))
    ans -= plus
print(ans)