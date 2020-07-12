#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);  


int main()
{	
	float red = 0.0f, green = 1.0f, blue = 0.0f;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
	}
	glfwMakeContextCurrent(window); 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
}   
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);   
	while(!glfwWindowShouldClose(window))
	{	
		if (red + 0.01f > 1.0f) red = 0.0f;
		red += 0.001f;
			
		glClearColor(red, green, blue, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    	glfwSwapBuffers(window);
    	glfwPollEvents();    
	}	
	
	glfwTerminate();
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

