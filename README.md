# Algebra rings

Residue rings built from cyclic additive groups.

```cmake
include(FetchContent)

FetchContent_Declare(
    njr_algebra_rings
    GIT_REPOSITORY git@github.com:nathanjrussell/algebra-rings.git
    GIT_TAG v0.1.0
)

FetchContent_MakeAvailable(njr_algebra_rings)

target_link_libraries(my_app PRIVATE njr::algebra_rings)
```
