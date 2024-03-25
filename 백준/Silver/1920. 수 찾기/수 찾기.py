N = int(input())
A = list(map(int, input().split()))
M = int(input())
arr = list(map(int, input().split()))

A.sort()

for num in arr:
    left, right = 0, N-1
    found = 0
    while left <= right:
        mid = (left + right) //2
        if num == A[mid]:
            found = 1
            break;
        elif num > A[mid]:
            left = mid +1
        else:
            right=mid-1
    print(found)