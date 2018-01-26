#include <bits/stdc++.h>

using namespace std;

bool can_be_extended(const vector<int> &x) {
    int y = x.size() - 1;
    for(int i=0; i < y; i++) {
        if(y - i == abs(x[y] - x[i])) return false;
    }
    return true;
}

void extend(vector<int> &x, int n) {
    if(x.size() == n) {
        cout << "solution:";
        for(auto&i: x) {
            cout << i << ' ';
        } 
        cout << '\n';
        exit(0);
    }

    for(int i=0; i < n; i++) {
        if(find(begin(x), end(x), i) == end(x)) {
            x.push_back(i);
            if(can_be_extended(x)) extend(x, n);

            x.pop_back();
        }
    }
}

int main() {
    std::vector<int> x;
    extend(x, 30);
}
