#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned c = 0;
    for (size_t i = 0; i < n-1; ++i) {
        c += a[i];

        const unsigned k = 1 << (31 - __builtin_clz(n-1 - i));
        a[i+k] += a[i];

        std::cout << c << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

