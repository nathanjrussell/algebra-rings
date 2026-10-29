#include <cstdint>
#include <stdexcept>
#include <gtest/gtest.h>
#include <algebra/rings/rings.hpp>

using namespace algebra;

using E = Residue<6>::Element;
static_assert(CommutativeRingElement<E>);
static_assert(!FieldElement<E>);
static_assert(!GroupElement<E, Multiplication>);

TEST(ResidueRings, ComputesUsingCanonicalResidues) {
    EXPECT_EQ(Residue<11>::element(7).multiply(Residue<11>::element(3)).representative(), 10u);
    EXPECT_EQ(Residue<11>::element(-1).representative(), 10u);
    using Wide = Residue<4294967295u>;
    EXPECT_EQ((Wide::element(4294967294LL) + Wide::element(4294967294LL)).representative(), 4294967293u);
}

TEST(ResidueRings, SatisfiesRingLawsWithZeroDivisors) {
    for (int a = 0; a < 6; ++a) {
        const auto x = E::from_integer(a);
        EXPECT_TRUE((identity_law<E, Addition>(x)));
        EXPECT_TRUE((identity_law<E, Multiplication>(x)));
        EXPECT_TRUE((x + -x).is_zero());
        for (int b = 0; b < 6; ++b) {
            const auto y = E::from_integer(b);
            EXPECT_EQ(x * y, y * x);
            for (int c = 0; c < 6; ++c) {
                const auto z = E::from_integer(c);
                EXPECT_TRUE((associative_law<E, Multiplication>(x, y, z)));
                EXPECT_TRUE(distributive_law(x, y, z));
            }
        }
    }
    EXPECT_TRUE((E::from_integer(2) * E::from_integer(3)).is_zero());
}

TEST(ResidueRings, ExposesTheCommutativeRingInterface) {
    Residue<6> ring;
    const interfaces::CommutativeRing<E>& view = ring;
    EXPECT_EQ(view.multiply(E::from_integer(2), E::from_integer(4)), E::from_integer(2));
    EXPECT_TRUE(view.add(E::one(), E::one().negate()).is_zero());
}

TEST(ResidueRings, SupportsTheZeroRing) {
    const auto value = Residue<1>::Element::zero();
    EXPECT_TRUE(value.is_zero());
    EXPECT_TRUE(value.is_one());
    EXPECT_TRUE(value.multiply(value).is_one());
}

TEST(Units, RejectsNonunitsAndPreservesReciprocals) {
    const auto five = E::from_integer(5);
    const Unit<E> unit(five, five);
    EXPECT_TRUE((unit * unit.reciprocal()).is_one());
    EXPECT_THROW((Unit<E>(E::from_integer(2), E::from_integer(3))), std::domain_error);
}
