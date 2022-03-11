#ifndef ILUMINACAO_H
#define ILUMINACAO_H
#include <math.h>
#include<glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<GL/gl.h>
#include <QString>


class iluminacao
{
public:
    iluminacao();
    //retorna o tipo de luz escolhido
    glm::vec3 aplicarLuz(glm::vec3 posObj,glm::vec3 Nxyz, glm::vec3 posicaoLuz,glm::vec3 posicaoCamera,glm::vec3 cor);
    void pontoLuz(glm::vec3 posluz);
};

#endif // ILUMINACAO_H
