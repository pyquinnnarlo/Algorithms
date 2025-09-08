/* 2051D Counting Pair: Two pointer 
* Platform: Codeforce
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long x, y;
        std::cin >> n >> x >> y;

        std::vector<long long> a(n);
        long long S = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            S += a[i];
        }

        std::sort(a.begin(), a.end());

        long long result = 0;
        for (int i = 0; i < n - 1; i++) {
            long long L = S - y - a[i];
            long long R = S - x - a[i];

            auto left = std::lower_bound(a.begin() + i + 1, a.end(), L);
            auto right = std::upper_bound(a.begin() + i + 1, a.end(), R);

            result += (right - left);
        }

        std::cout << result << "\n";
    }
    return 0;
}
