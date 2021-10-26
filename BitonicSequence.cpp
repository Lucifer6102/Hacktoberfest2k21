#include <bits/stdc++.h>
using namespace std;

int findLongBitonic(vector<int> &input) {
    //Firstly to find LIS and LDS
    // for each i LIS till arr[i] and LDS from arr[i]
    int n = input.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            //firstly to check is ith is larger than jth and if lis[j]+1 is larger than lis[i]
            if (input[i] > input[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    vector<int> lds(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            //firstly to check is ith is larger than jth and if lds[j]+1 is larger than lds[i]
            if (input[i] > input[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }

    int answer = lis[0] + lds[0] - 1; //-1 to because current element will be in both lis and lds
    for (int i = 1; i < n; i++) {
        if (answer < (lis[i] + lds[i] - 1))
            answer = lis[i] + lds[i] - 1;
    }
    return answer;
}
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++)
            cin >> input[i];
        cout << findLongBitonic(input) << endl;
    }
    return 0;
}
