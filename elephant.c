#include "elephant.h"

void elephant() {
    glBegin(GL_TRIANGLES); // início triângulo
        glColor3f(0.8f,0.4f,0.0f);
        glVertex3f( 0.0f, 1.0f, 0.0f); // Topo
        glVertex3f(-1.0f,-1.0f, 0.0f); // Esquerda embaixo
        glVertex3f( 1.0f,-1.0f, 0.0f); // Direita embaixo
    glEnd(); // fim triângulo
}
