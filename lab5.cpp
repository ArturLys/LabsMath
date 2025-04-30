#include "Converter.h"
template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl

int32_t main() {
    auto isNumber = [](const string& s) { char* p; return strtod(s.c_str(), &p), * p == 0; };
    
    //string s;
    //getline(cin, s);
    
    //string s = "-5 + 5-(4*6) - 12*2.5";
    //string s = "(((5 + 8) * 2)/3-4)^6";
    string s = "- ^ + 4 3 2 * + 7 8 5";
    //string s = "* + 5 3 2"; //prefix
    //string s = "5 3 + 2 *"; //postfix
    s.push_back(' ');

    vector<string> tokens = Tokenize(s);

    short op;
    if (isNumber(tokens[0]) && isNumber(tokens[1])) op = 0;//cout << "post";
    else if (!isNumber(tokens[0]) && tokens[0] != "(") op = 1;//cout << "pre";
    else op = 2;//cout << "in";

    string post = "";

    switch (op)
    {
    case 0:
        post = InfixToPrefix(Tokenize(PostfixtoInfix(tokens)));
        cout << "prefix: " << post << "\n";
        cout << "infix: " << PostfixtoInfix(tokens) << "\n";
        cout << "evaluated: " << Solve(tokens) << "\n";
        break;

    case 1:
        post = InfixToPostfix(Tokenize(PrefixtoInfix(tokens)));
        cout << "postfix: " << post << "\n";
        cout << "infix: " << PrefixtoInfix(tokens) << "\n";
        cout << "evaluated: " << Solve(Tokenize(post)) << "\n";
        break;

    case 2:
        post = InfixToPostfix(tokens);
        cout << "postfix: " << post << "\n";
        cout << "prefix: " << InfixToPrefix(tokens) << "\n";
        cout << "evaluated: " << Solve(Tokenize(post)) << "\n";
        break;

    default:
        break;
    }


}
