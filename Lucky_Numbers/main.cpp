#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

//////////////////////// First Method
ll target;
const int MAX_DIGITS = 18;

ll fun(ll n = 0, ll cnt4 = 0, ll cnt7 = 0, int depth = 0) {
    if (depth > MAX_DIGITS) return LLONG_MAX; // Add a limit on the depth (i.e., the number of digits). Since long long can handle up to 18 digits safely

    if (n >= target && cnt4 == cnt7)
        return n;

    ll ch1 = fun(n * 10 + 4, cnt4 + 1, cnt7, depth + 1);
    ll ch2 = fun(n * 10 + 7, cnt4, cnt7 + 1, depth + 1);

    return min(ch1, ch2);
}



/////////////////// Second Method

vector<long long> v;

// this is responsible to fill the vector with superLuckyNumbers with the same length
void generateSuperLucky(string current, int fours, int sevens, int length) {
    if (current.size() == length) {
        if (fours == sevens) {
            v.push_back(stoll(current));
        }
        return;
    }
    if (fours < length / 2) {
        generateSuperLucky(current + '4', fours + 1, sevens, length);
    }
    if (sevens < length / 2) {
        generateSuperLucky(current + '7', fours, sevens + 1, length);
    }
}

// this is responsible for getting from the vector the min greater or equal number
// if not found as :
// if number= 80  so length=2
// This length Generation =  [47,74]
// No element here is  greater or equal number
// so you need to move to next even length generation and get the least number in them
// ====================================
// Another case : That if length is odd like this number 8
// we need to increase length by 1 to make it even so the  Generation =  [47,74]
// we need to take the first number also
long long findMinSuperLucky(long long n) {
    string numStr = to_string(n);
    int len = numStr.size();

    if (len % 2 != 0) {  // If the length is odd, the next even length is len + 1
        len += 1;
    }
    else {
        // Generate all super lucky numbers of length 'len'
        generateSuperLucky("", 0, 0, len);
        // Check if any of them is >= n
        sort(v.begin(), v.end());
        for (long long num : v) {
            if (num >= n) {
                return num;
            }
        }
        len += 2;  // If none found, proceed to next even length
    }
    // Generate super lucky numbers of the next even length
    v.clear();
    generateSuperLucky("", 0, 0, len);
    sort(v.begin(), v.end());
    return v[0];
}

int main() {
    long long n; cin >> n;
    cout << findMinSuperLucky(n) << endl;
    return 0;
}
