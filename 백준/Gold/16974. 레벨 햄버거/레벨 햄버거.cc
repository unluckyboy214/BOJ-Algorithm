#include <iostream>
#include <vector>

using namespace std;

// 패티와 전체 버거의 개수를 미리 계산
vector<long long> burger_layers(51, 0);
vector<long long> patty_counts(51, 0);

void calculate_layers_and_patties() {
    burger_layers[0] = 1; // 레벨-0 버거는 패티만 1개
    patty_counts[0] = 1;  // 패티는 1개

    for (int i = 1; i <= 50; ++i) {
        burger_layers[i] = 1 + burger_layers[i - 1] + 1 + burger_layers[i - 1] + 1; // B + (L-1) + P + (L-1) + B
        patty_counts[i] = patty_counts[i - 1] + 1 + patty_counts[i - 1]; // (L-1) + P + (L-1)
    }
}

long long eaten_patties(int level, long long x) {
    if (level == 0) {
        // 레벨-0 버거는 패티 1개
        return x == 0 ? 0 : 1;
    }

    if (x == 0) return 0; // 아무 것도 먹지 않음

    long long previous_layers = burger_layers[level - 1];
    long long previous_patties = patty_counts[level - 1];

    // 각 부분을 분석
    if (x == 1) {
        // B 만 먹음
        return 0;
    }
    else if (x <= 1 + previous_layers) {
        // B + (L-1)의 일부를 먹음
        return eaten_patties(level - 1, x - 1);
    }
    else if (x == 2 + previous_layers) {
        // B + (L-1) + P까지 먹음
        return previous_patties + 1;
    }
    else if (x <= 2 + 2 * previous_layers) {
        // B + (L-1) + P + (L-1)의 일부를 먹음
        return previous_patties + 1 + eaten_patties(level - 1, x - 2 - previous_layers);
    }
    else {
        // 전체를 다 먹음
        return 2 * previous_patties + 1;
    }
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    // 레벨별로 버거와 패티의 수를 계산
    calculate_layers_and_patties();

    // X장 만큼 먹었을 때 먹은 패티의 수 계산
    cout << eaten_patties(N, X) << endl;

    return 0;
}
