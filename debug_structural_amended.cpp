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

// Debug for basic type element
template <typename T>
int ELEMENT_WIDTH(T& e) {
    int width;
    stringstream ss;
    ss << e;
    width = ss.str().size();
    if (ss.str() == to_string(Debug::get_INF())) width = "INF"s.size();
    if (ss.str() == to_string(-Debug::get_INF())) width = "-INF"s.size();
    return width;
}

template <typename T>
ostream& operator<<(ostream& os, T* e) {
    stringstream ss;
    ss << *e;
    if (ss.str() == to_string(Debug::get_INF())) os << "INF"s;
    else if (ss.str() == to_string(-Debug::get_INF())) os << "-INF"s;
    else os << ss.str();
    return os;
}
ostream& operator<<(ostream& os, char* e) {
    os << *e;
    return os;
}
ostream& operator<<(ostream& os, const char* e) {
    string s = e;
    os << s;
    return os;
}

// Debug for pair
template <typename T, typename U>
int ELEMENT_WIDTH(pair<T, U>& p) {
    return ELEMENT_WIDTH(p.first) + ELEMENT_WIDTH(p.second) + "(, )"s.size();
}

template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>* p) {
    os << "("s << &((*p).first) << ", "s << &((*p).second) << ")"s;
    return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>* p) {
    pair<T, U> p_not_const = *p;
    os << &p_not_const;
    return os;
}

// Debug for tuple
template<int N, class Tuple>
int WIDTH_TUPLE(Tuple& t){
    return 0;
}
template<int N, class Tuple, class Head, class... Tail>
int WIDTH_TUPLE(Tuple& t) {
    int width = 0;
    if (N) width += ", "s.size();
    width += ELEMENT_WIDTH(get<N>(t)) + WIDTH_TUPLE<N + 1, Tuple, Tail...>(t);
    return width;
}
template<class... Ts>
int ELEMENT_WIDTH(tuple<Ts...>& t) {
    return WIDTH_TUPLE<0, tuple<Ts...>, Ts...>(t) + "()"s.size();
}

template<int N, class Tuple>
void OUT_TUPLE(ostream& os, Tuple* t){}
template<int N, class Tuple, class Head, class... Tail>
void OUT_TUPLE(ostream& os, Tuple* t) {
    if (N) os << ", "s;
    os << &get<N>(*t);
    OUT_TUPLE<N + 1, Tuple, Tail...>(os, &(*t));
}
template<class... Ts>
ostream& operator<<(ostream& os, tuple<Ts...>* t) {
    os << "("s;
    OUT_TUPLE<0, tuple<Ts...>, Ts...>(os, &(*t));
    os << ")"s;
    return os;
}
template<class... Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>* t) {
    tuple<Ts...> t_not_const = *t;
    os << &t_not_const;
    return os;
}

// Debug for vector (1-dimensional)
template <typename T>
ostream& operator<<(ostream& os, vector<T>* v) {
    os << "["s;
    bool flg = true;
    for (auto e : *v) {
        os << (flg ? ""s : ", "s);
        if (Debug::get_IS_MATRIX()) {
            string space = "";
            for (int i = 0; i < Debug::get_MAX_WIDTH() - ELEMENT_WIDTH(e); ++i) space += " ";
            os << space;
        }
        os << &e;
        flg = false;
    }
    os << "]"s;
    return os;
}

// Debug for vector (2-dimensional)
template <typename T>
ostream& operator<<(ostream& os, vector<vector<T>>* v) {
    Debug::set_IS_MATRIX(true);
    int width = 0;
    for (unsigned int i = 0; i < (*v).size(); ++i) {
        for (unsigned int j = 0; j < ((*v)[i]).size(); ++j) {
            width = max(width, ELEMENT_WIDTH((*v)[i][j]));
        }
    }
    Debug::set_MAX_WIDTH(width);
    string space = "";
    for (int i = 0; i < Debug::get_NAME_LENGTH() + 7; ++i) space += " ";
    os << "["s;
    bool flg = true;
    for (auto e : *v) {
        os << (flg ? ""s : "\n" + space);
        os << &e;
        flg = false;
    }
    os << "]"s;
    Debug::set_IS_MATRIX(false);
    return os;
}

// Debug for set
template <typename T>
ostream& operator<<(ostream& os, set<T>* s) {
    os << "{"s;
    bool flg = true;
    for (auto e : *s) {
        os << (flg ? ""s : ", "s);
        os << &e;
        flg = false;
    }
    os << "}"s;
    return os;
}

// Debug for multiset
template <typename T>
ostream& operator<<(ostream& os, multiset<T>* s) {
    os << "{"s;
    bool flg = true;
    for (auto e : *s) {
        os << (flg ? ""s : ", "s);
        os << &e;
        flg = false;
    }
    os << "}"s;
    return os;
}

// Debug for map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>* mp) {
    os << "{"s;
    bool flg = true;
    for (auto e : *mp) {
        os << (flg ? ""s : ", "s);
        os << &(e.first) << ": "s << &(e.second);
        flg = false;
    }
    os << "}"s;
    return os;
}

// Debug for queue
template <typename T>
ostream& operator<<(ostream& os, queue<T>* que) {
    queue<T> que_cp = *que;
    os << "["s;
    bool flg = true;
    while (!que_cp.empty()) {
        os << (flg ? ""s : ", "s);
        os << &(que_cp.front());
        que_cp.pop();
        flg = false;
    }
    os << "]"s;
    return os;
}

// Debug for deque
template <typename T>
ostream& operator<<(ostream& os, deque<T>* que) {
    os << "["s;
    bool flg = true;
    for (auto e : *que) {
        os << (flg ? ""s : ", "s);
        os << &e;
        flg = false;
    }
    os << "]"s;
    return os;
}

// Debug assistant
#define DUMP(...) INTERNAL_DUMP(#__VA_ARGS__, __VA_ARGS__)

void REMOVE_SPACE(string& s) {
    while (s[0] == ' ') {
        s = s.substr(1);
    }
    while (s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
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
    REMOVE_SPACE(first_name);
    REMOVE_SPACE(other_names);
    return pair<string, string>(first_name, other_names);
}

// Debug main
void INTERNAL_DUMP(string name) {}
template <class Head, class... Tail>
void INTERNAL_DUMP(string name, Head&& head, Tail&&... tail) {
    pair<string, string> p = GET_NAME(name);
    Debug::set_NAME_LENGTH(p.first.size());
    cerr << ">> "s << &(p.first) << " = "s << &head << endl;
	INTERNAL_DUMP(p.second, move(tail)...);
}

// End of Debug parts
//------------------------------------------------------------------------------


int main() {
    // サンプル
    int x = 114, y = -514;
    string s = "RAISE A SUILEN";
    DUMP(x, y, max(x, y), s);
    using T = tuple<string, int, bool>;
    vector<T> v{T("Rinko", 1017, true), T("Moka", 93, false)};
    DUMP(v);
    vector<vector<int>> dp(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) dp[i][j] = 10 * i + j;
    const int INF = 1 << 30;
    Debug::set_INF(INF);  // INF は桁が大きくて見にくいので "INF" と表示させたいとき
    dp[1][1] = -INF;
    DUMP(dp);

    // 出力画面
    // >> x = 114
    // >> y = -514
    // >> max(x, y) = 114
    // >> s = RAISE A SUILEN
    // >> v = [(Rinko, 1017, 1), (Moka, 93, 0)]
    // >> dp = [[   0,    1,    2]
    //          [  10, -INF,   12]
    //          [  20,   21,   22]]
}
