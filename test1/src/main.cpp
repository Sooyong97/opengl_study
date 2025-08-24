#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv) {
    SPDLOG_INFO("Start program");

    // glfw 초기화
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfw 윈도우 생성
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,  WINDOW_NAME,
     nullptr, nullptr);
    if (!window) {
       SPDLOG_ERROR("failed to create glfw window");
       glfwTerminate();
       return -1;
    }


    // glfw 루프, 창이 바로 꺼지지 않게
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); 
    }

    return 0;
}