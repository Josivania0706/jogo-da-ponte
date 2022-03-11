#ifndef OBJOBJETOS_H
#define OBJOBJETOS_H

#include <iostream>
using namespace std;
#include "glm/glm.hpp"
#include<GL/gl.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include<stdlib.h>
#include <QString>
#include <fstream> //arquivo
#include <sstream>
#include "iluminacao.h"
#include "texturas.h"

class objobjetos
{
public:
    objobjetos();


private:
  class Face {
    public:
      int tam;
      int *vertices;
      //int *texcoords;
      int normall[3];


      Face(int tam, int *vertices, int *texcoords, int normal1, int normal2, int normal3);

  };
  std::vector<glm::vec3> vertices;                   //guardar os vertices das malha
  //std::vector<float *> texcoords;
  std::vector<glm::vec3> normals;                    //guardar as normais das malha
  std::vector<Face> faces;                           //guardar as faces das malha na mmatriz
  GLuint list;                                       //identificador do objeto

public:
  glm::vec3 posicao = glm::vec3(0, -0.4, 5.8);
  glm::vec3 escala  = glm::vec3(1.3, 1.3, 1.3);
  float angulo = 180;

  void load(const char *file);
  void loadPonte(const char *file);
  void atualizarObject(glm::vec3 poscam, glm::vec3 posluz, iluminacao luz, texturas *textura);
  void desenhar( glm::vec3 poscam, glm::vec3 posluz, iluminacao *luz, texturas *textura);
  void desenharPonte( glm::vec3 poscam, glm::vec3 posluz, iluminacao *luz, texturas *textura);
};

#endif // OBJOBJETOS_H
