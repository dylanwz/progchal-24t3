// collaborated w john s.

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> m;

int main () {
    
    ll n;
    cin >> n;

    for(ll i = 0 ; i < n; i++) {
        ll new_m;
        cin >> new_m;
        m.push_back(new_m);
    }

    ll total_below = 0;
    ll cur_marks = 1; // assume nothing below last day (so 1 mark)

    vector<ll> total(n);

    for (ll i = n-1; i >= 0; i--) { // iterate backwards so you know everything
        
        ll cur_below = cur_marks - m[i] - 1;

        if (cur_below < 0) { // the optimal case won't work; we are missing marks
            cur_marks += -1 * cur_below;
        }

        total[i] = cur_marks;
        cur_marks--; // greedily always reduce the marks

    }

    // our total below sum may not be accurate if earlier days had more above marks
    cur_marks =  total[0];
    ll max_seen = cur_marks;
    for (ll i = 0; i < n; i++) {
        if (total[i] > max_seen) max_seen = total[i];
        total_below += max_seen - m[i] - 1;
    }

    cout << total_below << '\n';

}