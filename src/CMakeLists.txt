find_package(glfw3 REQUIRED)

file(
  GLOB_RECURSE
  HEADER_LIST
  CONFIGURE_DEPENDS
  "*.hpp"
  )

file(
  GLOB_RECURSE
  SOURCE_LIST
  CONFIGURE_DEPENDS
  "*.cpp"
  )

add_executable(tnc ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(
  tnc
  PRIVATE
  ${CMAKE_DL_LIBS}
  glfw
  glad
  )

target_compile_features(tnc PUBLIC cxx_std_17)

target_compile_options(
  tnc
  PRIVATE
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
  )
