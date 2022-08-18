class Automaton {

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    string state = "start";
    unordered_map<string, vector<string>> table = { // state machine
        {"start", {"start", "signed", "in_number", "end"}}, // 0: space, 1: +/-, 2: num, 3:other
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};


class Solution {
public:
    int myAtoi(string s) {
       Automaton automaton;
       for (char c : s) {
            automaton.get(c);
            if (automaton.state == "end"){
                break;
            }
       }
        return automaton.sign * automaton.ans;
    }
};