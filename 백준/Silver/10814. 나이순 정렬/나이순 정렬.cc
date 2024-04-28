#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator to sort by age only, maintaining original order for equal ages
bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first;  // Only compare the ages
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, string>> vec(n);

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        vec[i] = { age, name };
    }

    // Stable sort using the custom comparator
    stable_sort(vec.begin(), vec.end(), compare);

    // Output the sorted results
    for (int i = 0; i < n; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }

    return 0;
}
