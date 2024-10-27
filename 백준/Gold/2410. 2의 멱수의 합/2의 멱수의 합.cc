#include <iostream>
#include <vector>
#include <cmath>
#include <set>

void Init()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main()
{
    Init();

    int TargetNumber = 0;
    std::cin >> TargetNumber;

    std::vector<int> DP(TargetNumber + 1, 0);
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= TargetNumber; i++)
    {
        if (i % 2 == 0)
        {
            DP[i] = DP[i - 1] + DP[i / 2];
        }
        else
        {
            DP[i] = DP[i - 1];
        }

        DP[i] %= 1000000000;
    }

    std::cout << DP[TargetNumber];
    return 0;
}