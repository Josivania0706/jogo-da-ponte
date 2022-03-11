#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GL/glu.h"

class camera
{
public:
    camera(glm::vec3 pos);
    ~camera();

    glm::vec3 posicao;
    glm::vec3 posicaoDaCamera;
    float posicaoX = 15;
    float posicaoZ = 10;
    float posicaoY = 7;
    glm::vec3 direcao;
    glm::vec3 up;
    glm::vec3 look;
    float posxTransladar = 0;

    void ativarCamera(float aspecto);    //Primeira pessoa
    void ativarCamera2(float aspecto);   //Câmera observa todo o cenário

};



#endif // CAMERA_H
