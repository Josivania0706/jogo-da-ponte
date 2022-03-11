#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include<GL/gl.h>
#include<QKeyEvent>
#include "GL/glu.h"
#include "chao.h"
#include "camera.h"
#include "iluminacao.h"
#include <iostream>
#include "objobjetos.h"
#include "texturas.h"


class canvas: public QOpenGLWidget
{
public:
    canvas(QWidget *parent);

    glm::vec3 posicaoLuz = glm::vec3(2,10,-3.6);
    iluminacao luz;

    objobjetos objetoPersonagem;             //guarda os obj criados
    objobjetos objetoPonte;             //guarda os obj criados

    vector<objobjetos*> objetos;
    chao piso;
    int direcao = 0;

    bool MudarCamera = false; //Mudará o tipo de câmera, com base nesse estado - True ou False

    float passosUP = 0.0;
    float passosLeft = 0.0;
    float passosRight = 0.0;
    float passoAnguloEsq = 180.0;
    float passoAnguloDir = 180.0;
 void plano();


    int posMatrizX = 2, posMatrizZ = 1;
    double matrizChao[5][12] = {
                                   {2, 2, 2, 2 ,2 ,2 ,2 ,2 ,2, 2, 2, 2},
                                   {2, 0, 0, 0 ,0 ,0 ,1 ,0 ,1, 0, 0, 2},
                                   {2, 0, 0, 1 ,1 ,0 ,0 ,0 ,0, 0, 1, 2},
                                   {2, 0, 1, 1 ,0 ,1 ,0 ,1 ,0, 0, 0, 2},
                                   {2, 2, 2, 2 ,2 ,2 ,2 ,2 ,2, 2, 2, 2},
                               };

    void initializeGL();
    void paintGL();


    void keyPressEvent(QKeyEvent *event);
    void direcionamento();
    void rotacao();
    void move();
    void mudarVisualizacao(bool MC);    //Receberá o status de MudarCamera, para alterá-la

};


#endif // CANVAS_H
