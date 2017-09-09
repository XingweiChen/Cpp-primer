#include<iostream>
#include<algorithm>
#include<string>
#include<array>
// string longestPalindrome(string s) {
//     if (s.empty())
//         return "";
//     if (s.size() == 1)
//         return s;
//
//     int start = 0, max_len = 1;
//     for (auto i = 0U; i < s.size();) { //O(n^2)
//         if (s.size() - i <= max_len / 2)
//             break;
//         auto j = i, k = i;
//         while (k < s.size()-1 && s[k+1] == s[k])
//             ++k; // Skip duplicate characters.
//         i = k+1;
//         while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) {
//             ++k;
//             --j;
//         } // Expand.
//         int new_len = k - j + 1;
//         if (new_len > max_len) {
//             start = j;
//             max_len = new_len;
//         }
//     }
//     return s.substr(start, max_len);
// }
using std::string;
string longestPalindrome(string s) {
    auto length = s.size();
    if(length == 0 || length == 1) return s;
    string rs;
    std::copy(s.rbegin(), s.rend(), std::back_insert_iterator<string>(rs));
    int arr[length][length];
    int max = 0, end = 0;
    for(auto i =0U; i < length; ++i){
        for(auto j =0U; j < length; ++j){
            if(s[j] == rs[i]){
                arr[i][j] = (i >= 1 && j >= 1) ? arr[i-1][j-1] + 1 : 1;
                if(arr[i][j] > max){
                    max = arr[i][j];
                    end = j;
                }
            }else{
                arr[i][j] = 0;
            }
        }
    }
    std::cout << max << " " << end;
    return s.substr(end-max+1, max);
}

int main(){
    std::cout << longestPalindrome("babad") << "\n";
    std::cout << longestPalindrome("bb") << "\n";
    string s = "abc";
    std::cout << s.substr(0,2) << "\n";
}
