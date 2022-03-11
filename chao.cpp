#include "chao.h"


chao::chao()
{

}

void chao::desenharChao(iluminacao *luz, glm::vec3 posluz, glm::vec3 posCam, texturas *textura)
{
    float size = 1;

    textura->bind();
    glTranslatef(-1.5,0, -4);
        glBegin(GL_QUADS);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                glm::vec3 posQuadrado = glm::vec3(size * i, 0, size * j)           +
                                        glm::vec3(size * (1 + i), 0, size * j)     +
                                        glm::vec3(size * (1 + i), 0, size * (1+j)) +
                                        glm::vec3(size * i, 0, size * (j+1));

                posQuadrado = glm::vec3 (posQuadrado.x/4,posQuadrado.y/4, posQuadrado.z/4);

                glColor3fv(glm::value_ptr(luz->aplicarLuz(posQuadrado, glm::vec3(0, 1, 0),
                                                          posluz, posCam,
                                                          glm::vec3(1, 1, 1))));
                //Primeiro vértice
                glTexCoord2f(0.0, 0.0);
                glVertex3f(size * i, 0, size * j);

                //Segundo vértice
                glTexCoord2f(1.0, 0.0);
                glVertex3f(size * (1 + i), 0, size * j);

                //Terceiro vértice
                glTexCoord2f(1.0, 1.0);
                glVertex3f(size * (1 + i), 0, size * (1+j));

                //Quarto vértice
                glTexCoord2f(0.0, 1.0);
                glVertex3f(size * i, 0, size * (j+1));
            }
        }
        glEnd();
    glTranslatef(1.5,0, 4);
    textura->unBind();
}

void chao::desenharAgua(iluminacao *luz, glm::vec3 posluz, glm::vec3 posCam, texturas *textura)
{
    float size = 2;
    textura->bind();
    glTranslatef(-15, -1, -15);
        glBegin(GL_QUADS);
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                glm::vec3 posQuadrado = glm::vec3(size * i, 0, size * j)           +
                                        glm::vec3(size * (1 + i), 0, size * j)     +
                                        glm::vec3(size * (1 + i), 0, size * (1+j)) +
                                        glm::vec3(size * i, 0, size * (j+1));

                posQuadrado = glm::vec3 (posQuadrado.x/4,posQuadrado.y/4, posQuadrado.z/4);

                glColor3fv(glm::value_ptr(luz->aplicarLuz(posQuadrado, glm::vec3(0, 1, 0),
                                                          posluz, posCam,
                                                          glm::vec3(1, 1, 1))));
                //Primeiro vértice
                glTexCoord2f(0.0, 0.0);
                glVertex3f(size * i, 0, size * j);

                //Segundo vértice
                glTexCoord2f(1.0, 0.0);
                glVertex3f(size * (1 + i), 0, size * j);

                //Terceiro vértice
                glTexCoord2f(1.0, 1.0);
                glVertex3f(size * (1 + i), 0, size * (1+j));

                //Quarto vértice
                glTexCoord2f(0.0, 1.0);
                glVertex3f(size * i, 0, size * (j+1));
            }
        }
        glEnd();
    glTranslatef(15, 1, 15);
    textura->unBind();
}

