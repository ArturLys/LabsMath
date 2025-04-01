#include <bits/stdc++.h>
using namespace std;

// Shorter type names and macros
#define pb push_back
typedef long long ll;

// Structure to represent a node in the expression tree.
struct Node {
    string v;
    Node* l, * r;
    Node(const string& s) : v(s), l(nullptr), r(nullptr) {}
};

// Global variables used for recursive descent parsing.
vector<string> tokens;
int pos;

// Forward declarations for recursive descent functions.
Node* expr();
Node* term();
Node* factor();

// expr = term { ("+" | "-") term }
Node* expr() {
    Node* n = term();
    while (pos < tokens.size() && (tokens[pos] == "+" || tokens[pos] == "-")) {
        Node* cur = new Node(tokens[pos++]);
        cur->l = n;
        cur->r = term();
        n = cur;
    }
    return n;
}

// term = factor { ("*" | "/") factor }
Node* term() {
    Node* n = factor();
    while (pos < tokens.size() && (tokens[pos] == "*" || tokens[pos] == "/")) {
        Node* cur = new Node(tokens[pos++]);
        cur->l = n;
        cur->r = factor();
        n = cur;
    }
    return n;
}

// factor = number | "(" expr ")"
Node* factor() {
    if (tokens[pos] == "(") {
        pos++; // skip '('
        Node* n = expr();
        pos++; // skip ')'
        return n;
    }
    return new Node(tokens[pos++]);
}

// Tree traversal functions
string toInfix(Node* n) {
    if (!n->l && !n->r) return n->v;
    return "(" + toInfix(n->l) + " " + n->v + " " + toInfix(n->r) + ")";
}

string toPrefix(Node* n) {
    if (!n) return "";
    string res = n->v;
    if (n->l || n->r) {
        res += " " + toPrefix(n->l) + " " + toPrefix(n->r);
    }
    return res;
}

string toPostfix(Node* n) {
    if (!n) return "";
    string res;
    if (n->l || n->r)
        res = toPostfix(n->l) + " " + toPostfix(n->r) + " " + n->v;
    else
        res = n->v;
    return res;
}

// Build tree from prefix notation (Polish)
Node* buildPrefixTree(const vector<string>& t, int& i) {
    string token = t[i++];
    Node* node = new Node(token);
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        node->l = buildPrefixTree(t, i);
        node->r = buildPrefixTree(t, i);
    }
    return node;
}

// Build tree from postfix notation (Reverse Polish) using a stack
Node* buildPostfixTree(const vector<string>& t) {
    stack<Node*> st;
    for (auto& s : t) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            Node* r = st.top(); st.pop();
            Node* l = st.top(); st.pop();
            Node* node = new Node(s);
            node->l = l;
            node->r = r;
            st.push(node);
        }
        else {
            st.push(new Node(s));
        }
    }
    return st.top();
}

// Utility function to split a string into tokens by whitespace.
vector<string> split(const string& s) {
    istringstream iss(s);
    vector<string> res;
    string token;
    while (iss >> token)
        res.pb(token);
    return res;
}

// Main function
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //getline(cin, a);
    //string s = "-5 + 5-(-4*6)-12* (-2.5)";
    string s = "- 6 5";
    s.push_back(' ');

    vector<string> exprTokens;
    int numCnt = 0;
    bool canNeg = true, isNeg = false;
    // normalize
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) || s[i] == '.') {
            numCnt++;
            continue;
        }
        else if (numCnt > 0) {
            string num = s.substr(i - numCnt, numCnt);
            if (isNeg) num = "-" + num;
            exprTokens.pb(num);
            numCnt = 0;
            canNeg = false;
            isNeg = false;
        }
        if (s[i] == ' ') {
            canNeg = false;
            isNeg = false;
            continue;
        }
        if (s[i] == '-' && canNeg) {
            if (s[i+1] == ' ') {
                exprTokens.pb(string(1, s[i]));
                continue;
            }
            isNeg = true;
            continue;
        }
        exprTokens.pb(string(1, s[i]));
        if (s[i] != ')') canNeg = true;
    }
    for (auto& i : exprTokens) {
        cout << i << " ";
    }
    auto isNumber = [](const string& s) { char* p; return strtod(s.c_str(), &p), * p == 0; };
    if (isNumber(exprTokens[0])&&isNumber(exprTokens[1])) cout << "post";
    else if (!isNumber(exprTokens[0]) && exprTokens[0] != "(") cout << "pre";
    else cout << "in";

    // Build tree from infix tokens using recursive descent parsing.
    tokens = exprTokens;
    pos = 0;
    Node* infixTree = expr();

    // Convert tree to different notations.
    string infixStr = toInfix(infixTree);
    string prefixStr = toPrefix(infixTree);
    string postfixStr = toPostfix(infixTree);

    cout << "Infix: " << infixStr << "\n";
    cout << "Prefix: " << prefixStr << "\n";
    cout << "Postfix: " << postfixStr << "\n";

    // Reconstruct trees from prefix and postfix notations.
    vector<string> preTokens = split(prefixStr);
    vector<string> postTokens = split(postfixStr);
    int idx = 0;
    Node* preTree = buildPrefixTree(preTokens, idx);
    Node* postTree = buildPostfixTree(postTokens);

    cout << "Infix from Prefix: " << toInfix(preTree) << "\n";
    cout << "Infix from Postfix: " << toInfix(postTree) << "\n";
}
