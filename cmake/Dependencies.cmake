include(FetchContent)
if(NOT TARGET njr::algebra_core)
    FetchContent_Declare(
        njr_algebra_core
        GIT_REPOSITORY git@github.com:nathanjrussell/algebra-core.git
        GIT_TAG 288e0f9279ca26925c79ece475d318dd100e76cb
    )
    FetchContent_MakeAvailable(njr_algebra_core)
endif()
if(NOT TARGET njr::algebra_groups)
    FetchContent_Declare(
        njr_algebra_groups
        GIT_REPOSITORY git@github.com:nathanjrussell/algebra-groups.git
        GIT_TAG 35465f6ee50c6bd481aa29d8d601058f9e6d6695
    )
    FetchContent_MakeAvailable(njr_algebra_groups)
endif()
