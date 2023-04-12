#include <iostream>
#include <GLFW/glfw3.h>



int main(int argc, char argv)
{
    // Initialize GLFW
    if (!glfwInit()) 
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Menu", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        fprintf(stderr, "Failed to create GLFW window\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Set up OpenGL
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    while (!glfwWindowShouldClose(window))
    {
        // Check for input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        {
            glfwSetWindowShouldClose(window, true);
        }
    }


    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the menu
    glColor3f(1.0f, 31.0f, 1.0f);  // Set the color to white

    // Draw the play button
    glBegin(GL_QUADS);
    glVertex2f(200, 400);
    glVertex2f(600, 400);
    glVertex2f(600, 500);
    glVertex2f(200, 500);
    glEnd();

    // Draw the options button
    glBegin(GL_QUADS);
    glVertex2f(200, 300);
    glVertex2f(600, 300);
    glVertex2f(600, 400);
    glVertex2f(200, 400);
    glEnd();

    // Draw the quit button
    glBegin(GL_QUADS);
    glVertex2f(200, 200);
    glVertex2f(600, 200);
    glVertex2f(600, 300);
    glVertex2f(200, 300);
    glEnd();

    // Swap the buffers
    glfwSwapBuffers(window);

    // Poll for events
    glfwPollEvents();




    // Check for mouse click
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) 
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if (xpos >= 200 && xpos <= 600 && ypos >= 400 && ypos <= 500) 
        {
            std::cout << "Play button clicked" << std::endl;
        }
        else if (xpos >= 200 && xpos <= 600 && ypos >= 300 && ypos <= 400) 
        {
            std::cout << "Options button clicked" << std::endl;
        }
        else if (xpos >= 200 && xpos <= 600 && ypos >= 200 && ypos <= 300) 
        {
            std::cout << "Quit button clicked" << std::endl;
            glfwSetWindowShouldClose(window, true);
        }
    }

 // Clean up GLFW
    glfwTerminate();
    return 0;


}
   
