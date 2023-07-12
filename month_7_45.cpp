#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, a[maxn], sum;
// check函数用于验证每个fajo月的开销设为num是否可行
bool check(int num) {
    int id = 1, tot = 0;
    for (int i = 0; i < n; i ++) {
        if (num - tot >= a[i]) tot += a[i];
        else if (a[i] > num) return false;
        else {
            id ++;
            tot = a[i];
            if (id > m) return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    int L = 0, R = sum, res;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << res << endl;
    return 0;
}
