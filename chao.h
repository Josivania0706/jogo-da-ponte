#ifndef CHAO_H
#define CHAO_H
#include "GL/glu.h"
#include "iluminacao.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "texturas.h"

class chao
{
public:
    chao();
    iluminacao luz;
    void desenharChao(iluminacao *luz, glm::vec3 posluz, glm::vec3 posCam, texturas *textura);
    void desenharAgua(iluminacao *luz, glm::vec3 posluz, glm::vec3 posCam, texturas *textura);
};

#endif // CHAO_H
