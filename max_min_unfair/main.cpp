#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> arr) {

    sort(arr.begin(), arr.end());

    int fairest = INT_MAX;

    //sliding window
    for (int i = 0; i < arr.size() - k + 1; ++i) {
        vector<int> window(arr.begin() + i, arr.begin() + i + k);
        int maxi = window.back();
        int mini = window.front();
        fairest = min(fairest, maxi - mini);
    }

    return fairest;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string n_temp;
//    getline(cin, n_temp);
//
//    int n = stoi(ltrim(rtrim(n_temp)));
//
//    string k_temp;
//    getline(cin, k_temp);
//
//    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> arr = {7, 3, 100, 200, 300, 350, 400, 401, 402};

//    for (int i = 0; i < n; i++) {
//        string arr_item_temp;
//        getline(cin, arr_item_temp);
//
//        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));
//
//        arr[i] = arr_item;
//    }

    int result = maxMin(3, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
