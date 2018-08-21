#include "window.h"
#include "maths.h"

int main() 
{
    sparky::Window window("Sparky!", 960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    
    GLuint vao;
    //glGenVertexArrays(1, &vao);
    //glBindVertexArray(vao);
    
    sparky::mat4 a = sparky::mat4::translation(sparky::vec3(2, 3, 4));
    sparky::mat4 b = sparky::mat4::identity();
    a *= b;
    for (int i = 0; i < 4; i++) 
        std::cout << a.columns[i] << std::endl;
    
    
    while (!window.closed())
    {
        window.clear();
#if 1        
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#else        
       glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
       window.update();
    }
    
    return 0;
}
