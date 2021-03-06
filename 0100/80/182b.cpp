#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned d)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 0; i < n-1; ++i)
        k += d - a[i];

    answer(k);
}

int main()
{
    unsigned d;
    std::cin >> d;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, d);

    return 0;
}

