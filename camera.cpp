#include "camera.h"

camera::camera(glm::vec3 pos)
{
    posicao = pos;
    direcao = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

camera::~camera()
{}
//PRIMEIRA PESSOA
void camera::ativarCamera(float aspecto)
{
    //Projeção - Perspectiva
    glMatrixMode(GL_PROJECTION);
    glm::mat4 projMatrix = glm::perspective(glm::radians(80.0f), aspecto, 1.0f, 100.0f);
    glLoadMatrixf(glm::value_ptr(projMatrix));

    look = posicao + direcao;
    gluLookAt(posicao.x, posicao.y, posicao.z,
              look.x, look.y, look.z,
              up.x, up.y, up.z);
}
//LATERAL
void camera::ativarCamera2(float aspecto)
{
    //Projeção - Perspectiva
    glMatrixMode(GL_PROJECTION);
    glm::mat4 projMatrix = glm::perspective(glm::radians(80.0f), aspecto, 1.0f, 100.0f);
    glLoadMatrixf(glm::value_ptr(projMatrix));

    gluLookAt(posicaoX, posicaoY, posicaoZ,
              0, 1, 0,
              0, 1, 0);
}


