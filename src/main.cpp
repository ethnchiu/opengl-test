#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fmt/base.h>

int windowWidth = 800;
int windowHeight = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fmt::println("Failed to initialize GLFW");
        return -1;
    }

    fmt::println("GLFW initialized successfully");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create windowed mode window
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL Test", NULL, NULL);

    if (window == NULL) {
        fmt::println("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fmt::println("Failed to initialize GLAD");
        return -1;
    }

    // Set rendering window size
    glViewport(0, 0, windowWidth, windowHeight);

    // Register resize window callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Continuously redraw window
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up GLFW resources
    glfwTerminate();
    return 0;
}



