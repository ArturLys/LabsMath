#include "template.h"
#pragma once

// Utility function to check if a string is a number

// Tokenize the input string into tokens
vector<string> Tokenize(string s);

// Convert infix expression to postfix
string InfixToPostfix(vector<string> tokens);

// Convert infix expression to prefix
string InfixToPrefix(vector<string> tokens);

// Convert postfix expression to infix
string PostfixtoInfix(vector<string> tokens);

// Convert prefix expression to infix
string PrefixtoInfix(vector<string> tokens);

// Solve the expression given in tokenized form
int Solve(vector<string> tokens);

// Helper function for operator precedence (for internal use)
int precedence(const string& op);