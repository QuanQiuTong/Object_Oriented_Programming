#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

inline void restriction(vi &v) //"restrict" is a keyword.
{
    vi::size_type i = 0;
    for (; i < v.size() - 1; ++i)
        v[i + 1] += v[i] / 10, v[i] %= 10;
    for (; v[i] > 9; ++i)
        v.push_back(v[i] / 10), v[i] %= 10;
}
void operator_meq(vi &x, int y) // operator*=
{
    for (auto &i : x)
        i *= y;
    restriction(x);
}
void operator_peq(vi &x, const vi &y) // operator+=
{
    if (x.size() < y.size())
        x.resize(y.size());
    for (vi::size_type i = 0; i < y.size(); ++i)
        x[i] += y[i];
    restriction(x);
}

int main()
{
    cout << "Enter n(1<=n<=50): ";
    int n;
    cin >> n;
    vi fac{1}, ans{0};
    for (int i = 1; i <= n; i++)
    {
        cout << i << '!' << (i < n ? '+' : '=');
        operator_meq(fac, i);
        operator_peq(ans, fac);
    }
    for (auto i = ans.rbegin(); i != ans.rend(); ++i)
        cout << *i;
    return 0;
}
