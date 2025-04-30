#include "Converter.h"

auto isNumber = [](const string& s) { char* p; return strtod(s.c_str(), &p), * p == 0; };

vector<string> Tokenize(string s) {
    vector<string> tokens;
    int numCnt = 0;
    bool canNeg = true, isNeg = false;

    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i]) || s[i] == '.') {
            numCnt++;
            canNeg = false;
            continue;
        }

        else if (numCnt > 0) {
            string num = s.substr(i - numCnt, numCnt);
            if (isNeg) num = "-" + num;
            tokens.push_back(num);
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
            if (i + 1 < s.size() && isdigit(s[i + 1])) {
                isNeg = true;
                continue;
            }
            tokens.push_back(string(1, s[i]));
            canNeg = false;
            continue;
        }


        if (s[i] != ' ') {
            tokens.push_back(string(1, s[i]));
            canNeg = true;
        }
    }


    if (numCnt > 0) {
        string num = s.substr(s.size() - numCnt, numCnt);
        if (isNeg) num = "-" + num;
        tokens.push_back(num);
    }

    return tokens;
}


int precedence(const string& op) {
    if (op == "^") return 3;
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}


string InfixToPostfix(vector<string> tokens) {
    stack<string> s;
    string res = "";

    for (string& a : tokens) {

        if (isNumber(a)) {
            res += a + " ";
        }

        else if (a == "(") {
            s.push(a);
        }

        else if (a == ")") {
            while (!s.empty() && s.top() != "(") {
                res += s.top() + " ";
                s.pop();
            }
            s.pop();
        }

        else {

            if (a == "^") {
                s.push(a);
            }

            else if (a == "*" || a == "/") {
                while (!s.empty() && (s.top() == "*" || s.top() == "/" || s.top() == "^")) {
                    res += s.top() + " ";
                    s.pop();
                }
                s.push(a);
            }

            else if (a == "+" || a == "-") {
                while (!s.empty() && (s.top() == "*" || s.top() == "/" || s.top() == "^" || s.top() == "+" || s.top() == "-")) {
                    res += s.top() + " ";
                    s.pop();
                }
                s.push(a);
            }
        }
    }


    while (!s.empty()) {
        res += s.top() + " ";
        s.pop();
    }

    return res;
}
string InfixToPrefix(vector<string> tokens) {
    reverse(all(tokens));

    stack<string> s;
    string res = "";

    for (auto& token : tokens) {
        if (token == "(") {
            token = ")";
        }
        else if (token == ")") {
            token = "(";
        }

        if (isNumber(token)) {
            res = token + " " + res;
        }
        else if (token == "(") {
            s.push(token);
        }
        else if (token == ")") {
            while (!s.empty() && s.top() != "(") {
                res = s.top() + " " + res;
                s.pop();
            }
            s.pop();
        }
        else {
            if (token == "^") {
                s.push(token);
            }
            else if (token == "*" || token == "/") {
                while (!s.empty() && (s.top() == "^" || s.top() == "*" || s.top() == "/")) {
                    res = s.top() + " " + res;
                    s.pop();
                }
                s.push(token);
            }
            else if (token == "+" || token == "-") {
                while (!s.empty() && (s.top() == "^" || s.top() == "*" || s.top() == "/" || s.top() == "+" || s.top() == "-")) {
                    res = s.top() + " " + res;
                    s.pop();
                }
                s.push(token);
            }
        }
    }

    while (!s.empty()) {
        res = s.top() + " " + res;
        s.pop();
    }

    return res;
}

string PostfixtoInfix(vector<string> tokens) {
    stack<string> s;

    for (string& token : tokens) {
        if (isNumber(token)) {
            s.push(token);
        }
        else {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push("(" + operand1 + " " + token + " " + operand2 + ")");
        }
    }

    return s.top();
}


string PrefixtoInfix(vector<string> tokens) {
    stack<string> s;

    for (int i = tokens.size() - 1; i >= 0; --i) {
        string& token = tokens[i];

        if (isNumber(token)) {
            s.push(token);
        }
        else {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            s.push("(" + operand1 + " " + token + " " + operand2 + ")");
        }
    }
    string a = s.top();
    a.erase(0, 1);
    a.pop_back();
    return a;
}


int Solve(vector<string> tokens) {
    stack<double> s;

    for (string& token : tokens) {
        if (isNumber(token)) {
            s.push(stof(token));
        }
        else {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            if (token == "+") {
                s.push(operand1 + operand2);
            }
            else if (token == "-") {
                s.push(operand1 - operand2);
            }
            else if (token == "*") {
                s.push(operand1 * operand2);
            }
            else if (token == "/") {
                s.push(operand1 / operand2);
            }
            else if (token == "^") {
                s.push(pow(operand1, operand2));
            }
        }
    }

    return s.top();
}