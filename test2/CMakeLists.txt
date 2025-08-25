cmake_minimum_required(VERSION 3.10)
project(opengl_test)

set(PROJECT_NAME test2)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# --- FetchContent ---
include(FetchContent)

# spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)

# --- 실행 파일 생성 ---
add_executable(${PROJECT_NAME}
    src/main.cpp
    external/glad/src/glad.c   # zip에서 가져온 glad.c 추가
)

# glad 헤더 추가
target_include_directories(${PROJECT_NAME}
    PRIVATE
    external/glad/include
)

# --- 라이브러리 링크 ---
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${OPENGL_gl_LIBRARY}
    glfw
    spdlog::spdlog     # spdlog 라이브러리 추가
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

# --- 매크로 정의 ---
target_compile_definitions(${PROJECT_NAME} PRIVATE
    WINDOW_NAME="Hello, OpenGL!"
    WINDOW_WIDTH=960
    WINDOW_HEIGHT=540
)