// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

int main(/*int argc, char *argv[]*/)
{
  GLFWwindow *window;

  if (!glfwInit())
  {
    return -1;
  }

  window = glfwCreateWindow(640, 480, "Nix is great!", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGL())
  {
    return -1;
  }

  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
