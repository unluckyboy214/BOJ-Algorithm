
N,M = map(int, input().split())
address_pwd={}

for _ in range(N):
    address, pwd = input().split()
    address_pwd[address] = pwd

for _ in range(M):
    address = input()
    print(address_pwd[address])