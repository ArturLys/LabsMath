//#include "List.h"
//template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
//#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl
//
//
//int32_t main() {
//    Node* stackTop = nullptr;
//    Node* queueFront = nullptr;
//    Node* queueRear = nullptr;
//    Node* listHead = nullptr;
//    int choice, value, key;
//
//    while (true) {
//        cout << "\nChoose an operation:\n";
//        cout << "1. Stack Push\n2. Stack Pop\n3. Show Stack\n\n";
//        cout << "4. Queue Enqueue\n5. Queue Dequeue\n6. Show Queue\n\n";
//        cout << "7. Add to List (Begin)\n8. Add to List (End)\n9. Show List\n";
//        cout << "10. Delete from List (Begin)\n11. Delete from List (End)\n";
//        cout << "12. Add to List (Mid)\n13. Delete from List (Mid)\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:  // Stack Push
//            cout << "Enter value to push: ";
//            cin >> value;
//            push(stackTop, value);
//            break;
//        case 2:  // Stack Pop
//            value = pop(stackTop);
//            cout << "Popped value: " << value << endl;
//            break;
//        case 3:  // Show Stack
//            cout << "Stack: ";
//            showStack(stackTop);
//            break;
//        case 4:  // Queue Enqueue
//            cout << "Enter value to enqueue: ";
//            cin >> value;
//            enqueue(queueFront, queueRear, value);
//            break;
//        case 5:  // Queue Dequeue
//            value = dequeue(queueFront, queueRear);
//            cout << "Dequeued value: " << value << endl;
//            break;
//        case 6:  // Show Queue
//            cout << "Queue: ";
//            showQueue(queueFront);
//            break;
//        case 7:  // Add to List (Begin)
//            cout << "Enter value to add at the beginning: ";
//            cin >> value;
//            add_begin(listHead, value);
//            break;
//        case 8:  // Add to List (End)
//            cout << "Enter value to add at the end: ";
//            cin >> value;
//            add_end(listHead, value);
//            break;
//        case 9:  // Show List
//            cout << "List: ";
//            showList(listHead);
//            break;
//        case 10:  // Delete from List (Begin)
//            del_begin(listHead);
//            cout << "Deleted from the beginning of the list.\n";
//            break;
//        case 11:  // Delete from List (End)
//            del_end(listHead);
//            cout << "Deleted from the end of the list.\n";
//            break;
//        case 12:  // Add to List (Mid)
//            cout << "Enter key to add after: ";
//            cin >> key;
//            cout << "Enter value to add: ";
//            cin >> value;
//            add_mid(listHead, key, value);
//            break;
//        case 13:  // Delete from List (Mid)
//            cout << "Enter key to delete: ";
//            cin >> key;
//            del_mid(listHead, key);
//            break;
//        case 0:  // Exit
//            cout << "Exiting program...\n";
//            return 0;
//        default:
//            cout << "Invalid choice. Try again.\n";
//        }
//    }
//}