#include <cassert>
#include <cuchar>

template <typename T>
struct Rank {
    static constexpr size_t value = 0;
};

template <typename T>
struct Rank<T[]> {
    static constexpr size_t value = 1 + Rank<T>::value;
};  

template <typename T, size_t N>
struct Rank<T[N]> {
    static constexpr size_t value = 1 + Rank<T>::value;
};


int main() {
    static_assert(Rank<int>::value == 0);
    static_assert(Rank<float[]>::value == 1);
    static_assert(Rank<char*[2][3]>::value == 2);

    constexpr int x{};
    static_assert(Rank<decltype(x)>::value == 0);

    constexpr int a[2][2] = {
        {1, 2},
        {3, 4}
    };

    static_assert(Rank<decltype(a)>::value == 2);

    return 0;
}

