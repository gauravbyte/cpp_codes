/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 * Parsing A Boolean Expression
Category	Difficulty	Likes	Dislikes
algorithms	Hard (58.63%)	1069	54
Tags
Companies
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
Discussion | Solution
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool parse_or(string &s, int &i) {
        i += 2;
        bool ret = false;
        ret |= handle(s, i);
        while (s[i] != ')') {
            if (s[i] == ',') i++;
            ret |= handle(s, i);
        }
        i++; // Move past ')'
        return ret;
    }

    bool parse_and(string &s, int &i) {
        i += 2;
        bool ret = true;
        ret &= handle(s, i);
        while (s[i] != ')') {
            if (s[i] == ',') i++;
            ret &= handle(s, i);
        }
        i++; 
        return ret;
    }

    bool parse_not(string &s, int &i) {
        i += 2;
        bool ret = !handle(s, i);
        i++; 
        return ret;
    }

    bool handle(string &s, int &i) {
        if (s[i] == 'f') {
            i++;
            return false;
        }
        if (s[i] == 't') {
            i++;
            return true;
        }
        if (s[i] == '&') {
            return parse_and(s, i);
        }
        if (s[i] == '|') {
            return parse_or(s, i);
        }
        if (s[i] == '!') {
            return parse_not(s, i);
        }
        return false;
    }

    bool parseBoolExpr(string s) {
        int i = 0;
        return handle(s, i);
    }
};
// @lc code=end