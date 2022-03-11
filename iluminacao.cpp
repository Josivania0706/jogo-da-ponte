#include "iluminacao.h"

iluminacao::iluminacao()
{

}

glm::vec3 iluminacao::aplicarLuz(glm::vec3 posObj, glm::vec3 Nxyz, glm::vec3 posicaoLuz, glm::vec3 posicaoCamera, glm::vec3 cor)
{
    glm::vec3 n = glm::vec3(Nxyz);
    n = glm::normalize(n);
    glm::vec3 l = posicaoLuz - posObj;
    l = glm::normalize(l);
    glm::vec3 v = posicaoCamera - posObj;
    v = glm::normalize(v);
    glm::vec3 r = 2 * (glm::dot(n,l)) * n - l;
    r = glm::normalize(r);

    glm::vec3 matDiff = cor;
    glm::vec3 matSpec = glm::vec3(1, 1, 1);
    glm::vec3 matAmb = 0.2f * matDiff;

    glm::vec3 luzAmb= glm::vec3(0.1,0.1,0.1);
    glm::vec3 luzDiff = glm::vec3(0.8,0.8,0.8);
    glm::vec3 luzSpec = glm::vec3(0.8,0.8,0.8);
    float     matExp = 16;

    return (luzAmb*matAmb)+
           (luzDiff * matDiff * (glm::max(glm::dot(l,n),0.0f))) +
           luzSpec * matSpec * pow(glm::max(glm::dot(v,r), 0.0f), matExp);
}

void iluminacao::pontoLuz(glm::vec3 posluz)
{
    glBegin( GL_POINTS );
        glColor3f(1,1,1);
        glVertex3fv(glm::value_ptr(posluz));
    glEnd();
}
