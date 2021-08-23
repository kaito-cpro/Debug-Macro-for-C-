#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

class Debug {
private:
    static int DISPLAYED_LENGTH, MAX_WIDTH;
    static bool IS_MATRIX;
    static long long INF;
public:
    static void set_DISPLAYED_LENGTH(int l) { DISPLAYED_LENGTH = l; }
    static int get_DISPLAYED_LENGTH() { return DISPLAYED_LENGTH; }
    static void set_MAX_WIDTH(int w) { MAX_WIDTH = w; }
    static int get_MAX_WIDTH() { return MAX_WIDTH; }
    static void set_IS_MATRIX(bool f) { IS_MATRIX = f; }
    static bool get_IS_MATRIX() { return IS_MATRIX; }
    static void set_inf(long long i) { INF = i; }
    static long long get_inf() { return INF; }
};

int Debug::DISPLAYED_LENGTH = 0;
int Debug::MAX_WIDTH = 0;
bool Debug::IS_MATRIX = false;
long long Debug::INF = numeric_limits<long long>::max() / 2;

// Debug for basic type element
template <typename T>
int ELEMENT_WIDTH(T e) {
    int width;
    stringstream ss;
    ss << e;
    width = ss.str().size();
    if (ss.str() == to_string(Debug::get_inf())) width = "INF"s.size();
    if (ss.str() == to_string(-Debug::get_inf())) width = "-INF"s.size();
    return width;
}
int ELEMENT_WIDTH(bool e) {
    return (e ? "true"s.size() : "false"s.size());
}

template <typename T>
ostream& operator<<(ostream& os, T* e) {
    stringstream ss;
    ss << *e;
    if (ss.str() == to_string(Debug::get_inf())) os << "INF"s;
    else if (ss.str() == to_string(-Debug::get_inf())) os << "-INF"s;
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
ostream& operator<<(ostream& os, bool* e) {
    os << (*e ? "true"s : "false"s);
    return os;
}

// Debug for ACL::modint
int ELEMENT_WIDTH(modint e) {
    return ELEMENT_WIDTH(e.val());
}
int ELEMENT_WIDTH(modint998244353 e) {
    return ELEMENT_WIDTH(e.val());
}
int ELEMENT_WIDTH(modint1000000007 e) {
    return ELEMENT_WIDTH(e.val());
}

ostream& operator<<(ostream& os, modint* e) {
    os << (*e).val();
    return os;
}
ostream& operator<<(ostream& os, modint998244353* e) {
    os << (*e).val();
    return os;
}
ostream& operator<<(ostream& os, modint1000000007* e) {
    os << (*e).val();
    return os;
}

// Debug for pair
template <typename T, typename U>
int ELEMENT_WIDTH(pair<T, U> p) {
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
int WIDTH_TUPLE(Tuple t){
    return 0;
}
template<int N, class Tuple, class Head, class... Tail>
int WIDTH_TUPLE(Tuple t) {
    int width = 0;
    if (N) width += ", "s.size();
    width += ELEMENT_WIDTH(get<N>(t)) + WIDTH_TUPLE<N + 1, Tuple, Tail...>(t);
    return width;
}
template<class... Ts>
int ELEMENT_WIDTH(tuple<Ts...> t) {
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

// Debug for ACL::mf_graph
int ELEMENT_WIDTH(mf_graph<int>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow);
    return ELEMENT_WIDTH(t);
}
int ELEMENT_WIDTH(mf_graph<long long>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow);
    return ELEMENT_WIDTH(t);
}

ostream& operator<<(ostream& os, mf_graph<int>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow);
    os << &t;
    return os;
}
ostream& operator<<(ostream& os, mf_graph<long long>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow);
    os << &t;
    return os;
}

// Debug for ACL::mcf_graph
int ELEMENT_WIDTH(mcf_graph<int, int>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow, e.cost);
    return ELEMENT_WIDTH(t);
}
int ELEMENT_WIDTH(mcf_graph<int, long long>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow, e.cost);
    return ELEMENT_WIDTH(t);
}
int ELEMENT_WIDTH(mcf_graph<long long, int>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow, e.cost);
    return ELEMENT_WIDTH(t);
}
int ELEMENT_WIDTH(mcf_graph<long long, long long>::edge e) {
    auto t = make_tuple(e.from, e.to, e.flow, e.cost);
    return ELEMENT_WIDTH(t);
}

ostream& operator<<(ostream& os, mcf_graph<int, int>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow, (*e).cost);
    os << &t;
    return os;
}
ostream& operator<<(ostream& os, mcf_graph<int, long long>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow, (*e).cost);
    os << &t;
    return os;
}
ostream& operator<<(ostream& os, mcf_graph<long long, int>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow, (*e).cost);
    os << &t;
    return os;
}
ostream& operator<<(ostream& os, mcf_graph<long long, long long>::edge* e) {
    auto t = make_tuple((*e).from, (*e).to, (*e).flow, (*e).cost);
    os << &t;
    return os;
}

// Debug for vector (1-dimensional)
template <typename T>
int ELEMENT_WIDTH(vector<T> v) {
    int width = 0;
    for (auto e : v) {
        width += ELEMENT_WIDTH(e) + ", "s.size();
    }
    width += "[]"s.size() - ", "s.size();
    return width;
}

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
int ELEMENT_WIDTH(vector<vector<T>> v) {
    int max_element_width = 0, max_length = 0;
    for (auto ve : v) {
        for (auto e : ve) {
            max_element_width = max(max_element_width, ELEMENT_WIDTH(e));
        }
        max_length = max(max_length, (int)ve.size());
    }
    return (max_element_width + ", "s.size()) * max_length + "[]"s.size();
}

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
    os << "["s;
    string space = "";
    for (int i = 0; i < Debug::get_DISPLAYED_LENGTH() + "["s.size(); ++i) space += " ";
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

// Debug for unordered_map
template <typename T, typename U>
ostream& operator<<(ostream& os, unordered_map<T, U>* mp) {
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

// Debug for stack
template <typename T>
ostream& operator<<(ostream& os, stack<T>* st) {
    stack<T> st_cp = *st;
    vector<T> stock;
    while (!st_cp.empty()) {
        stock.push_back(st_cp.top());
        st_cp.pop();
    }
    reverse(stock.begin(), stock.end());
    os << "["s;
    bool flg = true;
    for (auto e : stock) {
        os << (flg ? ""s : ", "s);
        os << &e;
        flg = false;
    }
    os << "]"s;
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

// Debug for priority-queue
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T>* que) {
    priority_queue<T> que_cp = *que;
    os << "["s;
    bool flg = true;
    while (!que_cp.empty()) {
        os << (flg ? ""s : ", "s);
        os << &(que_cp.top());
        que_cp.pop();
        flg = false;
    }
    os << "]"s;
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>>* que) {
    priority_queue<T, vector<T>, greater<T>> que_cp = *que;
    os << "["s;
    bool flg = true;
    while (!que_cp.empty()) {
        os << (flg ? ""s : ", "s);
        os << &(que_cp.top());
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

// sub-vevtor
template <typename T>
vector<T> subvec(vector<T> v, int l, int r) {
    assert(0 <= l && l < v.size());
    assert(0 < r && r <= v.size());
    vector<T> res;
    for (int i = l; i < r; ++i) {
        res.push_back(v[i]);
    }
    return res;
}
template <typename T>
vector<vector<T>> subvec(vector<vector<T>> v, int l0, int r0, int l1, int r1) {
    assert(0 <= l0 && l0 < v.size());
    assert(0 < r0 && r0 <= v.size());
    assert(0 <= l1 && 0 < r1 && l0 < r0 && l1 < r1);
    vector<vector<T>> res(r0 - l0);
    int out_of_range = 0;
    for (int i = l0; i < r0; ++i) {
        for (int j = l1; j < r1; ++j) {
            if (0 <= j && j < v[i].size()) res[i].push_back(v[i][j]);
            else {
                ++out_of_range;
                break;
            }
        }
    }
    assert(out_of_range < res.size());
    return res;
}

// transposed-vector
template <typename T>
vector<vector<T>> transpose(vector<T> v) {
    int n = v.size();
    vector<vector<T>> res(n, vector<T>(1));
    for (int i = 0; i < n; ++i) res[i][0] = v[i];
    return res;
}
template <typename T>
vector<vector<T>> transpose(vector<vector<T>> v) {
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; ++i) {
        assert(v[i].size() == v[0].size());
    }
    vector<vector<T>> res(m, vector<T>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = v[j][i];
        }
    }
    return res;
}

// Debug assistant
#define debug(...) INTERNAL_DUMP(#__VA_ARGS__, __VA_ARGS__)
#define debugs(...) INTERNAL_DUMPS(#__VA_ARGS__, 0, __VA_ARGS__)

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
    cerr << ">> " << &(p.first) << " = ";
    Debug::set_DISPLAYED_LENGTH(">> "s.size() + p.first.size() + " = "s.size());
    cerr << &head << endl;
	INTERNAL_DUMP(p.second, move(tail)...);
}

void INTERNAL_DUMPS(string name, int displayed_length) {
    cerr << ")" << endl;
}
template <class Head, class... Tail>
void INTERNAL_DUMPS(string name, int displayed_length, Head&& head, Tail&&... tail) {
    bool first_call = displayed_length == 0;
    if (first_call) {
        cerr << ">> " << "(";  displayed_length += ">> "s.size() + "("s.size();
        pair<string, string> p;
        while (!name.empty()) {
            pair<string, string> p = GET_NAME(name);
            cerr << &(p.first);  displayed_length += ELEMENT_WIDTH(p.first);
            if (!p.second.empty()) {
                cerr << ", ";  displayed_length += ", "s.size();
            }
            name = p.second;
        }
        cerr << ")" << " = ";  displayed_length += ")"s.size() + " = "s.size();
    }
    if (first_call) {
        cerr << "(";  displayed_length += "("s.size();
        Debug::set_DISPLAYED_LENGTH(displayed_length);
        cerr << &head;  displayed_length += ELEMENT_WIDTH(head);
    } else {
        cerr << ", ";  displayed_length += ", "s.size();
        Debug::set_DISPLAYED_LENGTH(displayed_length);
        cerr << &head;  displayed_length += ELEMENT_WIDTH(head);
    }
	INTERNAL_DUMPS("", displayed_length, move(tail)...);
}

// End of Debug parts
//------------------------------------------------------------------------------


int main() {
    // DUMP() サンプル -------------------------------------------------------------------------------------------------
    int x = -114, y = 514;
    string s = "RAISE A SUILEN";
    debug(x, max(x, y), s);  // max(x, y) 等も, きちんと演算結果が表示される
    // 出力画面
    // ---debug---
    // >> x = -114
    // >> max(x, y) = 514
    // >> s = RAISE A SUILEN

    using T = tuple<string, int, bool>;
    vector<T> v{T("Rinko", 1017, true), T("Moca", 93, false)};
    debug(v);  // 内部実装が階層的になっているので, 基本的にどんな複雑なデータ構造も表示可能(C言語由来の配列は先頭要素のみ出力されてしまう)
    // 出力画面
    // >> v = [(Rinko, 1017, true), (Moca, 93, false)]

    vector<vector<int>> dp(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) dp[i][j] = 10 * i + j;
    const int INF = 1 << 30;
    Debug::set_inf(INF);  // INF は桁が大きくて見にくいので "INF" と表示させたいとき
    dp[1][1] = -INF;
    debug(dp, subvec(dp, 0, 2), subvec(dp, 0, 3, 1, 3));  // subvec() で部分行列を取り出せる
    // 出力画面
    // >> dp = [[   0,    1,    2]
    //          [  10, -INF,   12]
    //          [  20,   21,   22]]
    // >> subvec(dp, 0, 2) = [[   0,    1,    2]
    //                        [  10, -INF,   12]]
    // >> subvec(dp, 0, 3, 1, 3) = [[   1,    2]
    //                              [-INF,   12]
    //                              [  21,   22]]

    // DUMPS() サンプル ------------------------------------------------------------------------------------------------
    // debug(x, y) でも x と y を表示できるが複数行にまたがるので, 組 (x, y) として 1 行に表示できるようにしたのが DUMPS()
    // つまり, debug(make_tuple(x, y)) のような表示形態となる
    // また, 2 次元 vector の場合は見やすくインデントされる仕様になっている
    debugs(x, s);
    // 出力画面
    // >> (x, s) = (-114, RAISE A SUILEN)

    debugs(dp, s);
    // 出力画面
    // >> (dp, s) = ([[   0,    1,    2]
    //                [  10, -INF,   12]
    //                [  20,   21,   22]], RAISE A SUILEN)

    debugs(s, dp);
    // 出力画面
    // >> (s, dp) = (RAISE A SUILEN, [[   0,    1,    2]
    //                                [  10, -INF,   12]
    //                                [  20,   21,   22]])

    // AC-Library サンプル ---------------------------------------------------------------------------------------------
    using mint = modint1000000007;
    mint a = 1000000008;
    debugs(a, a.val());  // .val() を付けると int で解釈されて, 付けない場合は内部で m.val() に自動で変換される
    // 出力画面
    // >> (a, a.val()) = (1, 1)

    mf_graph<int> g(5);
    g.add_edge(3, 4, 16);
    g.add_edge(0, 3, 4);
    g.flow(0, 4);
    auto edges = g.edges();
    debug(transpose(edges));  // edges は vector<edge> の 1 次元 vector なので, transpose() で転置して見やすくしてみた
    debug(transpose(subvec(dp, 0, 2)));  // subvec() で部分行列を取り出して, それを transpose() で転置したりも可能
    // 出力画面
    // >> transpose(edges) = [[(3, 4, 4)]
    //                        [(0, 3, 4)]]
    // >> transpose(subvec(dp, 0, 2)) = [[   0,   10]
    //                                   [   1, -INF]
    //                                   [   2,   12]]
}
