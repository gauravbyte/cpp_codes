#include <bits/stdc++.h>

int main() {
    int N, X;
    std::cin >> N >> X;

    // Read scores from input
    std::vector<int> scores(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> scores[i];
    }

    // Check each possible score for the last round
    for (int i = 0; i <= 100; ++i) {
        std::vector<int> all_scores = scores;
        all_scores.push_back(i);
        std::sort(all_scores.begin(), all_scores.end());

        // Calculate the sum excluding the smallest and largest scores
        int sum = std::accumulate(all_scores.begin() + 1, all_scores.end() - 1, 0);
        if (sum >= X) {
            std::cout << i << "\n";
            return 0;
        }
    }

    // If no score allows the target to be reached
    std::cout << "-1\n";
    return 0;
}
