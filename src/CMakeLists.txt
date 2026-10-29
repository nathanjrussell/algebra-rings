add_library(algebra_rings INTERFACE)
add_library(algebra::rings ALIAS algebra_rings)
target_compile_features(algebra_rings INTERFACE cxx_std_20)
target_include_directories(algebra_rings INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_link_libraries(algebra_rings INTERFACE
    algebra::core
    algebra::groups
)
