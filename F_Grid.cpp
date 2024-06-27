#include <iostream>
#include <string>
#include <vector>

#define int long long

int maxLengthNonDecreasingSubstring(int n, std::string s) {
    int count00 = 0, count01 = 0, count11 = 0, count10 = 0, res = 0;

    for(int i = 0; i < n; i += 2){
        if (s[i] == '0' and s[i + 1] == '0') 
            count00++;
            //cout<< count00;
        else if (s[i] == '1' and s[i + 1] == '1') 
            count11++;
            //cout<< count11;
        else if (s[i] == '0' and s[i + 1] == '1') 
            count01++;
            //cout<< count11;
        else 
            count10++;
            //cout<< count11;
    }
    if (count10!=0) {
        res = 1;
        count10--;
    }
    res += 2 * count00;
    if (count01!=0) {
        res += 2;
    }

    res += 2 * count11;
    if (count10!=0) {
        res++;
    }
    return res;
}

int32_t main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::cout << maxLengthNonDecreasingSubstring(n, s) << std::endl;
    }
    return 0;
}
