#include "boneco.h"

boneco::boneco()
{
    posicao = glm::vec3(0,0,5.5);
}

void boneco::desenhaBoneco()
{
    glTranslatef(posicao.x, posicao.y, posicao.z);
    glRotatef(ang,0,1,0);
        glColor3f(c1,c2,c3);
        glBegin(GL_QUADS);
             glVertex3f(-0.4, 0, 0.4);
             glVertex3f(-0.2, 0, -0.4);
             glVertex3f(0.4, 0, -0.4);
             glVertex3f(0.4, 0, 0.4);
        glEnd();

        glColor3f(0,1,0);
        glBegin(GL_TRIANGLES);
             glVertex3f(-0.4, 0, 0.4);
             glVertex3f(-0.4, 0, -0.4);
             glVertex3f(0, 1.5, 0);
        glEnd();

        glColor3f(0,1,1);
        glBegin(GL_TRIANGLES);
             glVertex3f(-0.4, 0, -0.4);
             glVertex3f(0.4, 0, -0.4);
             glVertex3f(0,1.5,0);

        glEnd();

        glColor3f(0,0,1);
        glBegin(GL_TRIANGLES);
             glVertex3f(0.4, 0, -0.4);
             glVertex3f(0.4, 0, 0.4);
             glVertex3f(0,1.5,0);

        glEnd();

        glColor3f(1,0,1);
        glBegin(GL_TRIANGLES);
             glVertex3f(0.4, 0, 0.4);
             glVertex3f(-0.4, 0, 0.4);
             glVertex3f(0,1.5,0);

        glEnd();
    glRotatef(-ang,0,1,0);
    glTranslatef(-posicao.x,-posicao.y, -posicao.z);

}

