#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    unordered_map<int, int> freq;

    // Count frequencies
    for (auto it : numbers) {
        freq[it]++;
    }

    cout<<"iterator"<<endl;
    for (auto it : freq) {
        cout << it.first << " " << it.second << endl;
    }
    
    cout<<"second approch"<<endl;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout<<endl;
    return 0;
}
