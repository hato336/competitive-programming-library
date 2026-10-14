#include <bits/stdc++.h>
using namespace std;
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#define OVERLOAD_REP(_1, _2, _3, _4, name, ...) name
#define REP1(n) for(ll i=0;i<(n);i++)
#define REP2(i, n) for (ll i=0;i<(n);i++)
#define REP3(i, a, n) for (ll i=a;i<(n);i++)
#define REP4(i, a, b, n) for(ll i=a;i<(n);i+=b)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define OVERLOAD_RREP(_1, _2, _3, _4, name, ...) name
#define RREP1(n) for(ll i=(n)-1;i>=0;i--)
#define RREP2(i, n) for(ll i=(n)-1;i>=0;i--)
#define RREP3(i, a, n) for(ll i=(n)-1;i>=(a);i--)
#define RREP4(i, a, b, n) for(ll i=(n)-1;i>=(a);i-=(b))
#define rrep(...) OVERLOAD_RREP(__VA_ARGS__, RREP4, RREP3, RREP2, RREP1)(__VA_ARGS__)
#define len(n) (long long)(n).size()
template<class T>
void uniq(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using vvs = vector<vs>;
using vvvs = vector<vvs>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

ll intpow(ll a,ll b){
    ll ans = 1;
    while (b){
        if (b & 1){
            ans *= a;
        }
        b /= 2;
        if (b) a *= a;
    }
    return ans;
}
ll modpow(ll a,ll b,ll c){
    ll ans = 1;
    while (b){
        if (b & 1){
            ans *= a;
            ans %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return ans;
}

template <typename T>
inline T floor(T a, T b) {
    T q = a / b;
    T r = a % b;
    if (r != 0 && ((r < 0) != (b < 0))) q--;
    return q;
}

template <typename T>
inline T ceil(T a, T b) {
    T q = a / b;
    T r = a % b;
    if (r != 0 && ((r < 0) == (b < 0))) q++;
    return q;
}

template <typename T>
inline T bmod(T a, T b) {
    if constexpr (std::is_signed_v<T>) {
        if (b == T(-1)) return 0;
    }
    T r = a % b;
    if (r < 0) r = b > 0 ? r + b : r - b;
    return r;
}

inline ll isqrt(ll n) {
    ll r = static_cast<ll>(std::sqrt(static_cast<ld>(n)));
    while (r > 0 && r > n / r) --r;
    while (r + 1 <= n / (r + 1)) ++r;
    return r;
}

template<class... T>
void input(T&... a){
    (cin >> ... >> a);
}

#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; input(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; input(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; input(__VA_ARGS__)
#define CHA(...) char __VA_ARGS__; input(__VA_ARGS__)
#define VLL(name,length) vll name(length);rep(i,length){cin >> name[i];}
#define VVLL(name,h,w) vvll name(h,vll(w));rep(i,h)rep(j,w){cin >> name[i][j];}
#define VVVLL(name,a,b,c) vvvll name(a,vvll(b,vll(c)));rep(i,a)rep(j,b)rep(k,c){cin >> name[i][j][k];}
#define VI(name,length) vi name(length);rep(i,length){cin >> name[i];}
#define VVI(name,h,w) vvi name(h,vi(w));rep(i,h)rep(j,w){cin >> name[i][j];}
#define VVVI(name,a,b,c) vvvi name(a,vvi(b,vi(c)));rep(i,a)rep(j,b)rep(k,c){cin >> name[i][j][k];}
#define VLD(name,length) vld name(length);rep(i,length){cin >> name[i];}
#define VVLD(name,h,w) vvld name(h,vld(w));rep(i,h)rep(j,w){cin >> name[i][j];}
#define VVVLD(name,a,b,c) vvvld name(a,vvld(b,vld(c)));rep(i,a)rep(j,b)rep(k,c){cin >> name[i][j][k];}
#define VC(name,length) vc name(length);rep(i,length){cin >> name[i];}
#define VVC(name,h,w) vvc name(h,vc(w));rep(i,h)rep(j,w){cin >> name[i][j];}
#define VVVC(name,a,b,c) vvvc name(a,vvc(b,vc(c)));rep(i,a)rep(j,b)rep(k,c){cin >> name[i][j][k];}
#define VS(name,length) vs name(length);rep(i,length){cin >> name[i];}
#define VVS(name,h,w) vvs name(h,vs(w));rep(i,h)rep(j,w){cin >> name[i][j];}
#define VVVS(name,a,b,c) vvvs name(a,vvs(b,vs(c)));rep(i,a)rep(j,b)rep(k,c){cin >> name[i][j][k];}
#define PLL(name) pll name;cin>>name.first>>name.second;
#define VPLL(name,length) vpll name(length);rep(i,length){cin>>name[i].first>>name[i].second;}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream&, const std::pair<T1, T2>&);
template<typename T>
std::ostream& operator<<(std::ostream&, const std::vector<T>&);
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream&, const std::vector<std::pair<T1, T2>>&);
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream&, const std::vector<std::vector<std::pair<T1, T2>>>&);
template<typename T>
std::ostream& operator<<(std::ostream&, const std::set<T>&);
template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const std::map<K, V>&);
template<typename T, typename Container, typename Compare>
std::ostream& operator<<(std::ostream&, std::priority_queue<T, Container, Compare>);
template<typename T, size_t N>
std::ostream& operator<<(std::ostream&, const std::array<T, N>&);
template<typename... Ts>
std::ostream& operator<<(std::ostream&, const std::tuple<Ts...>&);
template<typename T>
std::ostream& operator<<(std::ostream&, const std::unordered_set<T>&);
template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const std::unordered_map<K, V>&);
template<typename T>
std::ostream& operator<<(std::ostream&, const std::multiset<T>&);
template<typename K, typename V>
std::ostream& operator<<(std::ostream&, const std::multimap<K, V>&);
template<typename T>
std::ostream& operator<<(std::ostream&, const std::deque<T>&);
template<typename T, typename Container>
std::ostream& operator<<(std::ostream&, std::queue<T, Container>);
template<typename T, typename Container>
std::ostream& operator<<(std::ostream&, std::stack<T, Container>);

void print(){cout << "\n";}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i + 1 < vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<T1, T2>>& a) {
    os << "[";
    for (size_t j = 0; j < a.size(); ++j) {
        os << "(" << a[j].first << ", " << a[j].second << ")";
        if (j + 1 < a.size()) os << ", ";
    }
    os << "]";
    return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<std::pair<T1, T2>>>& mat) {
    os << "[";
    for (size_t i = 0; i < mat.size(); ++i) {
        os << "[";
        for (size_t j = 0; j < mat[i].size(); ++j) {
            os << "(" << mat[i][j].first << ", " << mat[i][j].second << ")";
            if (j + 1 < mat[i].size()) os << ", ";
        }
        os << "]";
        if (i + 1 < mat.size()) os << ", ";
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    os << "}";
    return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& [key, val] : m) {
        if (!first) os << ", ";
        os << key << ": " << val;
        first = false;
    }
    os << "}";
    return os;
}

template <typename T, typename Container, typename Compare>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T, Container, Compare> pq) {
    os << "[";
    bool first = true;
    while (!pq.empty()) {
        if (!first) os << ", ";
        os << pq.top();
        pq.pop();
        first = false;
    }
    os << "]";
    return os;
}

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& a) {
    os << "[";
    bool first = true;
    for (const auto& x : a) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    os << "]";
    return os;
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
    os << "(";
    std::apply([&os](const auto&... xs) {
        [[maybe_unused]] bool first = true;
        ((os << (first ? "" : ", ") << xs, first = false), ...);
    }, t);
    os << ")";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& a) {
    os << "{";
    bool first = true;
    for (const auto& x : a) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    os << "}";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& a) {
    os << "{";
    bool first = true;
    for (const auto& x : a) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    os << "}";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& a) {
    os << "[";
    bool first = true;
    for (const auto& x : a) {
        if (!first) os << ", ";
        os << x;
        first = false;
    }
    os << "]";
    return os;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& [key, val] : m) {
        if (!first) os << ", ";
        os << key << ": " << val;
        first = false;
    }
    os << "}";
    return os;
}

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::multimap<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& [key, val] : m) {
        if (!first) os << ", ";
        os << key << ": " << val;
        first = false;
    }
    os << "}";
    return os;
}

template<typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::queue<T, Container> q) {
    os << "[";
    bool first = true;
    while (!q.empty()) {
        if (!first) os << ", ";
        os << q.front();
        q.pop();
        first = false;
    }
    os << "]";
    return os;
}

template<typename T, typename Container>
std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) {
    std::vector<T> elements;
    while (!s.empty()) {
        elements.push_back(s.top());
        s.pop();
    }
    os << "[";
    bool first = true;
    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        if (!first) os << ", ";
        os << *it;
        first = false;
    }
    os << "]";
    return os;
}

#ifdef LOCAL
void debug() { std::cerr << "\n"; }

template<class T, class... Ts>
void debug(const T& a, const Ts&... b) {
    std::cerr << a;
    (std::cerr << ... << (std::cerr << ' ', b));
    std::cerr << '\n';
}

void debug_space() {}

template<class T, class... Ts>
void debug_space(const T& a, const Ts&... b) {
    std::cerr << a;
    (std::cerr << ... << (std::cerr << ' ', b));
}
#else
#define debug(...) (void)0
#define debug_space(...) (void)0
#endif

void write(){cout << "\n";}
template<class T, class... Ts>
void write(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
void write(vll x){rep(i,len(x)){cout << x[i];if(i!=len(x)-1){cout << " ";}else{cout << '\n';}}}
void write(vvll x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j];if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}
void write(vi x){rep(i,len(x)){cout << x[i];if(i!=len(x)-1){cout << " ";}else{cout << '\n';}}}
void write(vvi x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j];if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}
void write(vvvi x){rep(i,len(x))rep(j,len(x[i]))rep(k,len(x[i][j])){cout << x[i][j][k];if(k!=len(x[i][j])-1){cout << " ";}else if(j!=len(x[i])-1){cout << " | ";}else{cout << '\n';}}}
void write(vld x){rep(i,len(x)){cout << x[i];if(i!=len(x)-1){cout << " ";}else{cout << '\n';}}}
void write(vvld x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j];if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}
void write(vvvld x){rep(i,len(x))rep(j,len(x[i]))rep(k,len(x[i][j])){cout << x[i][j][k];if(k!=len(x[i][j])-1){cout << " ";}else if(j!=len(x[i])-1){cout << " | ";}else{cout << '\n';}}}
void write(vc x){rep(i,len(x)){cout << x[i];if(i!=len(x)-1){cout << " ";}else{cout << '\n';}}}
void write(vvc x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j];if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}
void write(vvvc x){rep(i,len(x))rep(j,len(x[i]))rep(k,len(x[i][j])){cout << x[i][j][k];if(k!=len(x[i][j])-1){cout << " ";}else if(j!=len(x[i])-1){cout << " | ";}else{cout << '\n';}}}
void write(vs x){rep(i,len(x)){cout << x[i];if(i!=len(x)-1){cout << " ";}else{cout << '\n';}}}
void write(vvs x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j];if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}
void write(vvvs x){rep(i,len(x))rep(j,len(x[i]))rep(k,len(x[i][j])){cout << x[i][j][k];if(k!=len(x[i][j])-1){cout << " ";}else if(j!=len(x[i])-1){cout << " | ";}else{cout << '\n';}}}
void write(pll x){cout << x.first << ' ' << x.second << '\n';}
void write(vpll x){rep(i,len(x)){cout << x[i].first << ' ' << x[i].second << '\n';}}
void write(vvpll x){rep(i,len(x))rep(j,len(x[i])){cout << x[i][j].first << ' ' << x[i][j].second;if(j!=len(x[i])-1){cout << " ";}else{cout << '\n';}}}

static ull random_seed_value = static_cast<ull>(std::chrono::steady_clock::now().time_since_epoch().count());
static std::mt19937_64 random_engine(random_seed_value);

ll randint(ll l, ll r) {
    assert(l < r);
    return std::uniform_int_distribution<ll>(l, r - 1)(random_engine);
}

template<class C>
void shuffle(C& c) {
    std::shuffle(std::begin(c), std::end(c), random_engine);
}

template<class C>
typename C::value_type choice(const C& c) {
    assert(!c.empty());
    auto index = std::uniform_int_distribution<size_t>(0, c.size() - 1)(random_engine);
    return *std::next(std::begin(c), index);
}

template <typename T>
T sum(const std::vector<T>& v) {
    return std::accumulate(v.begin(), v.end(), T(0));
}

template<class Set>
auto le(const Set &s, const typename Set::value_type &x,
        const typename Set::value_type &ngval = typename Set::value_type(-1)) {
    auto it = s.upper_bound(x);
    if (it == s.begin()) return ngval;
    return *prev(it);
}

template<class Set>
auto lt(const Set &s, const typename Set::value_type &x,
        const typename Set::value_type &ngval = typename Set::value_type(-1)) {
    auto it = s.lower_bound(x);
    if (it == s.begin()) return ngval;
    return *prev(it);
}

template<class Set>
auto ge(const Set &s, const typename Set::value_type &x,
        const typename Set::value_type &ngval = typename Set::value_type(-1)) {
    auto it = s.lower_bound(x);
    if (it == s.end()) return ngval;
    return *it;
}

template<class Set>
auto gt(const Set &s, const typename Set::value_type &x,
        const typename Set::value_type &ngval = typename Set::value_type(-1)) {
    auto it = s.upper_bound(x);
    if (it == s.end()) return ngval;
    return *it;
}

template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }



int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);



}