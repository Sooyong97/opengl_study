cmake_minimum_required(VERSION 3.13)
project(opengl_test)

set(PROJECT_NAME test2)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable(${PROJECT_NAME} src/main.cpp)

set(WINDOW_NAME "Hello, OpenGL!")
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

# --- FetchContent로 spdlog 불러오기 ---
include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)

# --- 라이브러리 링크 ---
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${OPENGL_gl_LIBRARY}
    glfw
    GLEW
    spdlog::spdlog           # 여기서 spdlog 연결!
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
)