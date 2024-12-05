#include <iostream>
using namespace std;

const int MOD = 100000007;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 3 << endl; // กรณี n = 1 มีแค่ 3 แบบ: {0, 1, 2}
        return 0;
    }

    // ตัวแปรเก็บค่า DP
    long long prev0 = 1, prev1 = 1, prev2 = 1; // dp[1][0], dp[1][1], dp[1][2]
    long long curr0, curr1, curr2;

    for (int i = 2; i <= n; ++i) {
        curr0 = (prev0 + prev1 + prev2) % MOD;
        curr1 = (prev0 + prev1) % MOD;
        curr2 = (prev0 + prev2) % MOD;

        // อัปเดตค่าไปยังรอบถัดไป
        prev0 = curr0;
        prev1 = curr1;
        prev2 = curr2;
    }

    // คำตอบคือผลรวมของ dp[n][0], dp[n][1], dp[n][2]
    cout << (prev0 + prev1 + prev2) % MOD << endl;

    return 0;
}
