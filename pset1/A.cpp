// Solved

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void baby_bites() {
    int r = 1;
    
    int n; cin >> n;
    for (size_t i = 0; i < n; i++) {
        string bf; cin >> bf;
        
        // something is fishy if the number spoken doesn't match the right number
        if (bf != "mumble" && stoi(bf) != r) {
            cout << "something is fishy" << "\n";
            return;
        }

        r++;
    }

    cout << "makes sense";

}

int main() {
    baby_bites();
}
