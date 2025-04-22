#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<int, int> v = {{3, 30}, {1, 10}, {4, 40}, {2, 20}};
    vector<pair<int, int>> vec(v.begin(), v.end());
    sort(vec.begin(), vec.end(), [] (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    // Print the sorted vector
    for (const auto& p : vec) {
        std::cout << p.first << ": " << p.second << std::endl;
    }

    return 0;
}
