// not finished lol

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string complete_the_word(string s) {
    
    // Initially process the array (for the first 25 characters)
    vector<char> alph(27, 0);
    for (int i = 0; i < 26; i++) {
        char c = s[i];
        if (c == '?') {
            alph[26]++;
        } else {
            alph[c - 65]++;
            if (alph[c-65] > 1) {
                return "-1";
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += alph[i];   
    }
    if (26 - sum != alph[26]) {
        return "-1";
    }



    return "hello";
}

int main() {
    string s_in;
    cin >> s_in;
    if (s_in.size() < 26) {
        cout << -1;
    }
    cout << complete_the_word(s_in);
}