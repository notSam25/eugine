#include "eugine/platform/OpenGL/wrapper/GLAPI.h"
#include "error.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace eg::GLWrapper {
    OGLAPI::OGLAPI(Window& window) : m_window(window){
        glfwMakeContextCurrent((GLFWwindow*)window.getNativeWindow());

        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        EG_CORE_ASSERT(status, "Failed to initialize Glad");

        int OGL_MINOR_VERSION;
        int OGL_MAJOR_VERSION;
        GLCall(glGetIntegerv(GL_MAJOR_VERSION, &OGL_MAJOR_VERSION));
        GLCall(glGetIntegerv(GL_MINOR_VERSION, &OGL_MINOR_VERSION));

        info("up and running with OpenGL {}.{}", OGL_MAJOR_VERSION, OGL_MINOR_VERSION);
        GLCall(info("RENDERER: {}", glGetString(GL_RENDERER)));
        GLCall(info("VENDOR: {}", glGetString(GL_VENDOR)));
        

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void OGLAPI::swapBuffers() {
        glfwSwapBuffers((GLFWwindow*)m_window.getNativeWindow());
    }

    void OGLAPI::setClearColor(glm::vec3 color) {
       GLCall(glClearColor(color.x, color.y, color.z, 1.0));
    }

    void OGLAPI::clear() {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    i32 OGLAPI::getMaxTexturesPerShader() const {
        i32 count;
        GLCall(glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &count));
        return count;
    }
}