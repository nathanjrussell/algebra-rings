#include <iostream>
#include <njr/algebra/rings/rings.hpp>

using namespace njr::algebra;

int main() {
    using R = Residue<11>;
    const auto a = R::element(7);
    const auto b = R::element(3);
    std::cout << a.add(b) << '\n';
    std::cout << a.multiply(b) << '\n';
}
