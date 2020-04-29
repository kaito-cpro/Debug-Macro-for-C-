#include <bits/stdc++.h>
using namespace std;

class Debug {
private:
    static int NAME_LENGTH, MAX_WIDTH;
    static bool IS_MATRIX;
    static long long INF;
public:
    static void set_NAME_LENGTH(int l) { NAME_LENGTH = l; }
    static int get_NAME_LENGTH() { return NAME_LENGTH; }
    static void set_MAX_WIDTH(int w) { MAX_WIDTH = w; }
    static int get_MAX_WIDTH() { return MAX_WIDTH; }
    static void set_IS_MATRIX(bool f) { IS_MATRIX = f; }
    static bool get_IS_MATRIX() { return IS_MATRIX; }
    static void set_INF(long long i) { INF = i; }
    static long long get_INF() { return INF; }
};

int Debug::NAME_LENGTH = 0;
int Debug::MAX_WIDTH = 0;
bool Debug::IS_MATRIX = false;
long long Debug::INF = LLONG_MAX;

// Debug for vector (1-dimensional template)
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : ", ");
        if (Debug::get_IS_MATRIX()) {
            os << right << setw(Debug::get_MAX_WIDTH());
        }
        os << e;
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for vector (1-dimensional int ovreload)
ostream& operator<<(ostream& os, const vector<int>& v) {
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : ", ");
        if (Debug::get_IS_MATRIX()) {
            os << right << setw(Debug::get_MAX_WIDTH());
        }
        if (e == Debug::get_INF()) os << "INF";
        else os << e;
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for vector (1-dimensional long long ovreload)
ostream& operator<<(ostream& os, const vector<long long>& v) {
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : ", ");
        if (Debug::get_IS_MATRIX()) {
            os << right << setw(Debug::get_MAX_WIDTH());
        }
        if (e == Debug::get_INF()) os << "INF";
        else os << e;
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for vector (1-dimensional pair ovreload)
template <typename T, typename U>
ostream& operator<<(ostream& os, const vector<pair<T, U>>& v) {
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : ", ");
        if (Debug::get_IS_MATRIX()) {
            int width = (int)("(, )"s.size());
            if (e.first == Debug::get_INF()) width += (int)("INF"s.size());
            else width += (int)to_string(e.first).size();
            if (e.second == Debug::get_INF()) width += (int)("INF"s.size());
            else width += (int)to_string(e.second).size();
            string space = "";
            for (int i = 0; i < Debug::get_MAX_WIDTH() - width; ++i) space += " ";
            os << space;
            if (e.first == Debug::get_INF()) os << "(" << "INF" << ", ";
            else os << "(" << e.first << ", ";
            if (e.second == Debug::get_INF()) os << "INF" << ")";
            else os << e.second << ")";
        }
        else {
            if (e.first == Debug::get_INF()) os << "(" << "INF" << ", ";
            else os << "(" << e.first << ", ";
            if (e.second == Debug::get_INF()) os << "INF" << ")";
            else os << e.second << ")";
        }
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for vector (2-dimensional template)
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    Debug::set_IS_MATRIX(true);
    int width = 0;
    for (unsigned int i = 0; i < v.size(); ++i) {
        for (unsigned int j = 0; j < v[i].size(); ++j) {
            if (v[i][j] == Debug::get_INF()) width = max(width, (int)("INF"s.size()));
            else width = max(width, (int)to_string(v[i][j]).size());
        }
    }
    Debug::set_MAX_WIDTH(width);
    string space = "";
    for (int i = 0; i < Debug::get_NAME_LENGTH() + 7; ++i) space += " ";
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : "\n" + space);
        os << e;
        flg = false;
    }
    os << "]";
    Debug::set_IS_MATRIX(false);
    return os;
}

// Debug for vector (2-dimensional pair overload)
template <typename T, typename U>
ostream& operator<<(ostream& os, const vector<vector<pair<T, U>>>& v) {
    Debug::set_IS_MATRIX(true);
    int width = 0;
    for (unsigned int i = 0; i < v.size(); ++i) {
        for (unsigned int j = 0; j < v[i].size(); ++j) {
            int w = (int)("(, )"s.size());
            if (v[i][j].first == Debug::get_INF()) w += (int)("INF"s.size());
            else w += (int)to_string(v[i][j].first).size();
            if (v[i][j].second == Debug::get_INF()) w += (int)("INF"s.size());
            else w += (int)to_string(v[i][j].second).size();
            width = max(width, w);
        }
    }
    Debug::set_MAX_WIDTH(width);
    string space = "";
    for (int i = 0; i < Debug::get_NAME_LENGTH() + 7; ++i) space += " ";
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : "\n" + space);
        os << e;
        flg = false;
    }
    os << "]";
    Debug::set_IS_MATRIX(false);
    return os;
}

// Debug for pair
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// Debug for set
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool flg = true;
    for (auto e : s) {
        os << (flg ? "" : ", ");
        os << e;
        flg = false;
    }
    os << "}";
    return os;
}

// Debug for multiset
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{";
    bool flg = true;
    for (auto e : s) {
        os << (flg ? "" : ", ");
        os << e;
        flg = false;
    }
    os << "}";
    return os;
}

// Debug for map
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool flg = true;
    for (auto e : mp) {
        os << (flg ? "" : ", ");
        os << e.first << ": " << e.second;
        flg = false;
    }
    os << "}";
    return os;
}

// Debug for queue
template <typename T>
ostream& operator<<(ostream& os, const queue<T>& que) {
    queue<T> que_cp = que;
    os << "[";
    bool flg = true;
    while (!que_cp.empty()) {
        os << (flg ? "" : ", ");
        os << que_cp.front();
        que_cp.pop();
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for deque
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& que) {
    os << "[";
    bool flg = true;
    for (auto e : que) {
        os << (flg ? "" : ", ");
        os << e;
        flg = false;
    }
    os << "]";
    return os;
}

// Debug assistant
#define DUMP(...) INTERNAL_DUMP(#__VA_ARGS__, __VA_ARGS__)

string REMOVE_SPACE(string s) {
    while (s[0] == ' ') {
        s = s.substr(1);
    }
    while (s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
    return s;
}

pair<string, string> GET_NAME(string s) {
    int bracket = 0, idx = 0;
    while ((unsigned)idx < s.size() && !(s[idx] == ',' && bracket == 0)) {
        if (s[idx] == '(') ++bracket;
        else if (s[idx] == ')') --bracket;
        ++idx;
    }
    string other_names;
    if ((unsigned)idx == s.size()) {
        other_names = "";
    } else {
        other_names = s.substr(idx + 1);
    }
    string first_name = s.substr(0, idx);
    first_name = REMOVE_SPACE(first_name);
    other_names = REMOVE_SPACE(other_names);
    return pair<string, string>(first_name, other_names);
}

// Debug main
void INTERNAL_DUMP(string name) {
    return;
}

template <class Head, class... Tail>
void INTERNAL_DUMP(string name, Head&& head, Tail&&... tail) {
    pair<string, string> p = GET_NAME(name);
    Debug::set_NAME_LENGTH(p.first.size());
    cerr << ">> " << p.first << " = " << head << endl;
	INTERNAL_DUMP(p.second, move(tail)...);
}

// End of Debug parts
//------------------------------------------------------------------------------


int main() {
    // サンプル
    int x = 114, y = -514;
    string s = "RAS";
    DUMP(x, y, max(x, y), s);
    vector<long long> v{1, 2, 3};
    DUMP(v);
    vector<vector<int>> dp(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) dp[i][j] = 10 * i + j;
    const int INF = 1 << 30;
    Debug::set_INF(INF);  // INF は桁が大きくて見にくいので "INF" と表示させたいとき
    dp[1][1] = INF;
    DUMP(dp);

    // 出力画面
    // >> x = 114
    // >> y = -514
    // >> max(x, y) = 114
    // >> s = RAS
    // >> v = [1, 2, 3]
    // >> dp = [[  0,   1,   2]
    //          [ 10, INF,  12]
    //          [ 20,  21,  22]]
}
