add_executable(algebra_rings_test residue_ring_test.cpp)
target_link_libraries(algebra_rings_test PRIVATE algebra::rings GTest::gtest_main)
gtest_discover_tests(algebra_rings_test TEST_PREFIX "algebra_rings.")
