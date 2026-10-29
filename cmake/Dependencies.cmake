include(FetchContent)
if(NOT TARGET algebra::core)
    FetchContent_Declare(
        algebra_core
        GIT_REPOSITORY git@github.com:nathanjrussell/algebra-core.git
        GIT_TAG df491678e274372fb0a08914c61a4d504414a739
    )
    FetchContent_MakeAvailable(algebra_core)
endif()
if(NOT TARGET algebra::groups)
    FetchContent_Declare(
        algebra_groups
        GIT_REPOSITORY git@github.com:nathanjrussell/algebra-groups.git
        GIT_TAG 3fb89f9178d775518d731a56bfebe7c3f2f84e52
    )
    FetchContent_MakeAvailable(algebra_groups)
endif()
