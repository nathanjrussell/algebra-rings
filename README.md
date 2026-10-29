# Algebra rings

Residue rings built from cyclic additive groups.

```cmake
include(FetchContent)

FetchContent_Declare(
    algebra_rings
    GIT_REPOSITORY git@github.com:nathanjrussell/algebra-rings.git
    GIT_TAG v0.2.0
)

FetchContent_MakeAvailable(algebra_rings)

target_link_libraries(my_app PRIVATE algebra::rings)
```
