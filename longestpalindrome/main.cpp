#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using namespace tr1;

class Solution {
    /**
     * DP solution, we need to remember what the previous palindrome was so we don't have to keep re-calculating
     */
public:
    string longestPalindrome(string s) {

        int biggest = 1;
        int index = 0;

        int start = 0;
        int end = 1; // start and end indices of longest palindrome

        if (s[0] == s[1]) { //edge case
            biggest = 2;
            end = 2;
        }

        for (int i = s.length() - 1; i > 0; i--) {
            int j = i + 1;
            int x = i - 1;

            if (s[i] == s[j]) { // check two letter palindrome
                int palin_length = find_palindrome_length(s, j + 1, x) + 1;
                if (palin_length > biggest) {
                    biggest = palin_length;
                    start = i - palin_length/2 + 1; //plus one for the duplicate character
                    end = palin_length;
                }
            }

            int palin_length = find_palindrome_length(s, j, x) + 1;
            if (palin_length > biggest) {
                biggest = palin_length;
                start = i - palin_length/2;
                end = palin_length;
            }
        }

        return s.substr(start, end);
    }

    int find_palindrome_length(string s, int head_forward, int head_back) {

        while (head_back >= 0 && head_forward != s.length()) {
            if (s[head_forward] == s[head_back]) {
                head_back--;
                head_forward++;
            } else {
                break;
            }
        }

        if (head_back >= 0 && s[head_forward] == s[head_back]) {
            return head_forward - head_back;
        } else {
            head_back++;
            head_forward--;
            return head_forward - head_back;
        }
    }

};

int main() {

    Solution *sol = new Solution();

    auto temp = sol->longestPalindrome("cbbd");
    temp = sol->longestPalindrome("acbbcf");
    temp = sol->longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx");
    temp = sol->longestPalindrome("cadac");
    temp = sol->longestPalindrome("babad");
    temp = sol->longestPalindrome("cbbd");
    temp = sol->longestPalindrome("cadac");

}