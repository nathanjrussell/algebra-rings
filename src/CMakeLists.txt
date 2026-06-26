add_library(njr_algebra_rings INTERFACE)
add_library(njr::algebra_rings ALIAS njr_algebra_rings)
target_compile_features(njr_algebra_rings INTERFACE cxx_std_20)
target_include_directories(njr_algebra_rings INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_link_libraries(njr_algebra_rings INTERFACE
    njr::algebra_core
    njr::algebra_groups
)
