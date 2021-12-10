include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_ROOT}/include)

link_directories(${PROJECT_ROOT}/src)

add_executable(
  GA_test
  GA_test.cc
)

target_link_libraries(
  GA_test
  gtest_main
  GA
)

include(GoogleTest)
gtest_discover_tests(GA_test)