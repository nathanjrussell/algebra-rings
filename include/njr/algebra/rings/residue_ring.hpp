#pragma once

#include <cstdint>
#include <ostream>
#include <njr/algebra/core/core.hpp>
#include <njr/algebra/groups/cyclic.hpp>

namespace njr::algebra {

template<class AdditiveGroup>
class ResidueRing;

template<std::uint32_t N>
class ResidueElement : public AdditiveOperators<ResidueElement<N>>,
                       public MultiplicativeOperators<ResidueElement<N>> {
    using AdditiveElement = typename Cyclic<N>::Element;
    AdditiveElement value_;

    explicit ResidueElement(AdditiveElement value) : value_(value) {}

public:
    using parent_type = ResidueRing<Cyclic<N>>;
    using algebra = CommutativeRingDescriptor;

    ResidueElement() = default;

    static ResidueElement from_integer(std::int64_t value) {
        return ResidueElement(Cyclic<N>::element(value));
    }

    static ResidueElement zero() {
        return ResidueElement{};
    }

    static ResidueElement one() {
        return from_integer(1);
    }

    ResidueElement add(const ResidueElement& other) const {
        return ResidueElement(value_.add(other.value_));
    }

    ResidueElement negate() const {
        return ResidueElement(value_.negate());
    }

    ResidueElement multiply(const ResidueElement& other) const {
        ResidueElement result = zero();
        for (std::uint64_t count = 0; count < other.representative(); ++count) {
            result = result.add(*this);
        }
        return result;
    }

    bool is_zero() const {
        return value_.is_zero();
    }

    bool is_one() const {
        return *this == one();
    }

    std::uint32_t representative() const {
        return value_.representative();
    }

    const parent_type& parent() const {
        static const parent_type instance;
        return instance;
    }

    bool operator==(const ResidueElement& other) const {
        return value_ == other.value_;
    }

    friend std::ostream& operator<<(std::ostream& out, const ResidueElement& value) {
        return out << value.representative();
    }
};

template<std::uint32_t N>
class ResidueRing<Cyclic<N>> : public CommutativeRingStructure<ResidueElement<N>> {
public:
    using Element = ResidueElement<N>;

    static Element element(std::int64_t value) {
        return Element::from_integer(value);
    }

    static constexpr std::uint64_t cardinality() {
        return N;
    }
};

template<std::uint32_t N>
using Residue = ResidueRing<Cyclic<N>>;

}
