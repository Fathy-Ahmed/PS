#include <bits/stdc++.h>
#define ll long long
#define Fathy_Ahmed ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
#define endl '\n'
// printf("%.9f\n", 9.0);
//  __builtin_popcount(s)
// accumulate(all(a),0ll)
#define all(a) (a).begin(), (a).end()
const int N = 1000000007;
using namespace std;
/*     LOWER_BOUND AND UPER_BOUND
 * LOWER_BOUND => تاخد عنصر و تبعت الاندكس بتاع اول عنصر اكبرمن العنصر او يساويه
 * UPER_BOUND => تاخد عنصر و تبعت الاندكس بتاع اول عنصر اكبرمن العنصر
 * */
const int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const char di[] = {'R', 'L', 'D', 'U'};
//--------------------------

ll Fast_Power(ll a, ll b)
{
    // BASE CASE
    if (!b)
        return 1;
    // TRANSITION
    ll ret = Fast_Power(a, b / 2);

    if (b % 2 == 0)
    {
        return ((ret * ret) % N);
    }

    return (((ret * ret) % N) * a % N);
}

//--------------------------

void Prime_Fac(ll n, unordered_map<ll, ll> mp)
{
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ll c = 0;
            while (n % i == 0)
                n /= i, c++;
            mp[i] += c;
        }
    }
    if (n > 1)
        mp[n]++;
}

//--------------------------

bool fastprime(ll x)
{
    bool y = 1;
    if (x == 2 || x == 3)
        y = 1;
    else if (x <= 1 || x % 2 == 0 || x % 3 == 0)
        y = 0;
    else
    {
        for (ll i = 5; i * i <= x; i += 6)
        {
            if (x % i == 0 || x % (i + 2) == 0)
            {
                y = 0;
                break;
            }
        }
    }
    return y;
}

//--------------------------

vector<ll> divisors(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    return ret;
}

//--------------------------

vector<pair<ll, ll>> PrimeFactorze(ll n)
{
    vector<pair<ll, ll>> ret;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ll c = 0;
            while (n % i == 0)
                n /= i, c++;
            ret.push_back({i, c});
        }
    }
    if (n > 1)
        ret.push_back({n, 1});
    return ret;
}

//--------------------------

string addBigNumbers(string number1, string number2)
{
    if (number1.length() > number2.length())
        swap(number1, number2);
    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    for (int i = len1 - 1; i >= 0; i--)
    {
        intSum = ((number1[i] - '0') + (number2[i + digitDiff] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }
    for (int i = digitDiff - 1; i >= 0; i--)
    {
        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }
    if (carry)
        sum.push_back(carry + '0');
    reverse(sum.begin(), sum.end());
    return sum;
}

//--------------------------

bool prime(ll x)
{
    if (x <= 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}

//--------------------------

void Sieve()
{
    bool IsPrime[10001];
    ::memset(IsPrime, true, sizeof IsPrime);
    IsPrime[0] = IsPrime[1] = false;
    for (int i = 2; i * i <= 10000; ++i)
    {
        if (IsPrime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                IsPrime[j] = false;
            }
        }
    }

    cout << IsPrime[5] << ' ' << IsPrime[6];
}

//--------------------------

int countDivisors(int num)
{
    int c = 0;
    for (int i = 1; i <= num / 2; ++i)
    {
        if (num % i == 0)
            c++;
    }
    return c;
}

//--------------------------

bool palindrome(int num)
{
    int temp = num;
    int sum = 0;
    while (temp)
    {
        sum = (sum * 10) + (temp % 10);
        temp /= 10;
    }
    if (sum == num)
        return true;
    else
        return false;
}

//--------------------------
ll ncr(ll n, ll m)
{
    if (m == 0)
        return 1;
    return n * ncr(n - 1, m - 1) / m;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
//-----------------------------------------

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//---------------------------------

void Merge(int arr[], int l, int r, int mid)
{
    int i, j, k;
    int size1 = mid - l + 1, size2 = r - mid;
    int L[size1], R[size2];
    for (i = 0; i < size1; ++i)
        L[i] = arr[i + l];
    for (j = 0; j < size2; ++j)
        R[j] = arr[mid + j + 1];
    i = j = 0;
    k = l;
    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while (i < size1)
        arr[k++] = L[i++];
    while (j < size2)
        arr[k++] = R[j++];
}
void Merge_Sort(int arr[], int l, int r)
{
    // BASE CASE
    if (l >= r)
        return;
    // TRANSITION
    int mid = (l + r) / 2;
    Merge_Sort(arr, l, mid);
    Merge_Sort(arr, mid + 1, r);
    Merge(arr, l, r, mid);
}

//-----------------------------------------
//--------------------------

int main()
{
    Fathy_Ahmed

        return 0;
}
