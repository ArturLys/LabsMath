#include "List.h"
template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl


int32_t main() {
    Node* stack = nullptr;
    Node* queueFront = nullptr;
    Node* queueRear = nullptr;
    Node* list = nullptr;

    int choice, value, key;
    do {
        cout << "1. Push (Stack)\n2. Pop (Stack)\n3. Show Stack\n";
        cout << "4. Enqueue (Queue)\n5. Dequeue (Queue)\n6. Show Queue\n";
        cout << "7. Add Begin (List)\n8. Add End (List)\n9. Del Begin (List)\n";
        cout << "10. Del End (List)\n11. Search (List)\n12. Add Mid (List)\n";
        cout << "13. Del Mid (List)\n14. Show List\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            push(stack, value);
            break;
        case 2:
            cout << "Popped: " << pop(stack) << endl;
            break;
        case 3:
            showStack(stack);
            break;
        case 4:
            cout << "Enter value: ";
            cin >> value;
            enqueue(queueFront, queueRear, value);
            break;
        case 5:
            cout << "Dequeued: " << dequeue(queueFront, queueRear) << endl;
            break;
        case 6:
            showQueue(queueFront);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> value;
            add_begin(list, value);
            break;
        case 8:
            cout << "Enter value: ";
            cin >> value;
            add_end(list, value);
            break;
        case 9:
            del_begin(list);
            break;
        case 10:
            del_end(list);
            break;
        case 11:
            cout << "Enter key: ";
            cin >> key;
            cout << (search(list, key) ? "Found\n" : "Not found\n");
            break;
        case 12:
            cout << "Enter key and value: ";
            cin >> key >> value;
            add_mid(list, key, value);
            break;
        case 13:
            cout << "Enter key: ";
            cin >> key;
            del_mid(list, key);
            break;
        case 14:
            showList(list);
            break;
        default:
            cout << "Invalid ♿\n";
            break;
        }
    } while (choice != 0);
}
