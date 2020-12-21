#include <iostream>
#include <vector>

using namespace std;

bool is_square[1000001];

int main()
{
    long long min, max;

    cin >> min >> max;

    int answer = max - min + 1;

    for (long long i = 2; i * i <= max; i++) {
        long long square = i * i;

        for (long long j = min / square; ; j++) {
            long long num = square * j;

            if (num < min) continue;
            if (max < num) break;

            if (is_square[num-min] == false) {
                is_square[num-min] = true;
                answer--;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
