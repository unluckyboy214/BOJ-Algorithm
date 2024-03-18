
for tc in range(1,11):
    N = int(input())
    Height = list(map(int, input().split()))
    ans = 0

    for i in range(2, N-2):
        curr = Height[i]
        max_height = max(Height[i-2],Height[i-1],Height[i+1],Height[i+2])

        if curr > max_height:
            ans += (curr - max_height)


    print("#%d" %tc, ans)