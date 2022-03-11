#ifndef BONECO_H
#define BONECO_H
#include "GL/glu.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class boneco
{
public:
    boneco();
    float c1 = 0,c2 = 0,c3 =1;
    glm::vec3 posicao;
    int ang=0;
    void desenhaBoneco();

};

#endif // BONECO_H
