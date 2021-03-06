#include "canvas.h"

canvas::canvas(QWidget *parent) : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    objetoPersonagem.load("C:/Qt/fusca.obj");
    objetoPonte.loadPonte("C:/Qt/ponte.obj");
    this->objetoPonte.escala = glm::vec3(-0.34,-0.4, -0.41);
    this->objetoPonte.posicao = glm::vec3(0,-0.170, 0.3);
    this->objetoPonte.angulo = 180;
}

//Posição inicial da câmera, antes do usuário realizar alguma operação
camera CriarCamera(glm::vec3(0.0f, 2.5f, 10.0f));

//Resposável por chamar função para carregar a textura
texturas text1, text2, text3, text4;

//Aramzena o aspct ratio
float aspecto;

void canvas::initializeGL()
{
    glClearColor(0.25,0.25,0.25,1);
    glEnable(GL_DEPTH_TEST);                // habilitar o teste de profundidade
    glCullFace(GL_BACK);                    //remove as faces de costas para câmera
    glEnable(GL_POINT_SMOOTH);              //suavizar o ponto
    glPointSize(10.0);                      //aumentar tamanho do ponto

    glEnable(GL_TEXTURE_2D);
    //Como a textura irá se combinar com a superfície
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
    text1.load("C:/Qt/piso.jpg");           //Carregar a textura
    text2.load("C:/Qt/img.jpeg");          //Carregar a textura
    text3.load("C:/Qt/img1.jpg");          //Carregar a textura
    text4.load("C:/Qt/mar.jpg");          //Carregar a textura
}

void canvas::paintGL()
{
    aspecto = (float) width() / (float) height(); //Calcular o apect ratio

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    mudarVisualizacao(MudarCamera);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    luz.pontoLuz(posicaoLuz);

    //Desenhar o chão do cenário
    texturas* tex1;
    tex1 = &text1;
    this->piso.desenharChao(&luz,posicaoLuz, CriarCamera.posicaoDaCamera, tex1);

    //Carregar a ponte
    texturas* tex2;
    tex2 = &text2;
    objetoPonte.desenharPonte(CriarCamera.posicaoDaCamera, posicaoLuz, &luz, tex2);

    //Carregar o carro
    texturas* tex3;
    tex3 = &text3;
    objetoPersonagem.desenhar(CriarCamera.posicaoDaCamera, posicaoLuz, &luz, tex3);

    //Carregar água
    texturas* tex4;
    tex4 = &text4;
    this->piso.desenharAgua(&luz,posicaoLuz, CriarCamera.posicaoDaCamera, tex4);
}

void canvas::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){//pressionado o up da seta
        if(matrizChao[posMatrizX][posMatrizZ + 1] != 2 ){
            direcao = 1;
        }
    }
    if(event->key() == Qt::Key_Right){//pressionado o direito da seta
        if(matrizChao[posMatrizX + 1][posMatrizZ] != 2){
            direcao = 2;
        }
    }
    if(event->key() == Qt::Key_Left){//pressionado o esquerdo da seta
        if(matrizChao[posMatrizX - 1][posMatrizZ] != 2){
            direcao = 3;
        }
    }
    if(event->key() == Qt::Key_Q){  //Quando o usuário apertar 'q', a câmera será mudada
        MudarCamera = !MudarCamera;
        CriarCamera.posicaoX = 5.0f;
        CriarCamera.posicaoY = 4.0f;
        CriarCamera.posicaoZ = 5.0f;
        mudarVisualizacao(MudarCamera);
    }
    if(event->key() == Qt::Key_A){  //A câmera se move no eixo x negativo
        CriarCamera.posicaoX -= 0.1;
        CriarCamera.posicaoZ -= 0.001;
    }
    if(event->key() == Qt::Key_S){ //A câmera se move no eixo x positivo
         CriarCamera.posicaoX += 0.1;
         CriarCamera.posicaoZ += 0.001;
    }
    if(event->key() == Qt::Key_I){ //A LUZ se move no eixo z
         posicaoLuz.z -= 0.4;

    }
    if(event->key() == Qt::Key_M){ //A LUZ se move
         posicaoLuz.z += 0.4;

    }
    if(event->key() == Qt::Key_L){ //A LUZ se move
         posicaoLuz.y -= 0.4;

    }
    if(event->key() == Qt::Key_O){ //A LUZ se move
         posicaoLuz.y += 0.4;

    }
    if(event->key() == Qt::Key_K){ //A LUZ se move
         posicaoLuz.x += 0.4;

    }
    if(event->key() == Qt::Key_J){ //A LUZ se move
        posicaoLuz.x -= 0.4;

   }

    update();
}

void canvas::direcionamento()
{
    switch(direcao)
    {
        case 1: // subir, up
            if(passosUP < 1){
                CriarCamera.posicao.z -= 0.1;
                this->objetoPersonagem.posicao.z -= 0.1;
                passosUP = passosUP + 0.1;
            }else{
                posMatrizZ += 1;
                passosUP = 0.0;
                direcao = 0;
            }
            break;
        case 2:// direito rigth
            if(passosRight < 1){
                this->objetoPersonagem.posicao.x += 0.1;
                passosRight = passosRight + 0.1;
            }else{
                this->objetoPersonagem.angulo = 180;
                posMatrizX += 1;
                passosRight = 0.0;
                direcao = 0;
            }
            break;
        case 3: //esquerdo left
            if(passosLeft < 1){
                this->objetoPersonagem.posicao.x -= 0.1;
                passosLeft = passosLeft + 0.1;
            }else{
                this->objetoPersonagem.angulo = 180;
                posMatrizX -= 1;
                passosLeft = 0.0;
                direcao = 0;
            }
            break;
        }

    if(matrizChao[posMatrizX][posMatrizZ] == 1){
        posMatrizX = 2;
        posMatrizZ = 1;
        this->objetoPersonagem.posicao.x = 0;
        this->objetoPersonagem.posicao.y = -0.4;
        this->objetoPersonagem.posicao.z = 5.5;
        CriarCamera.posicao.z = 10.0;
    }
       update();
}

void canvas::rotacao()
{
    switch(direcao)
    {
        case 2://esquerdo left
            if(passoAnguloEsq > 89){
                this->objetoPersonagem.angulo -= 10;
                passoAnguloEsq -= 10;
            }else{
                this->objetoPersonagem.angulo += 90;
                passoAnguloEsq = 180;
            }
            break;
        case 3: // direito rigth
            if(passoAnguloDir < 271){
                this->objetoPersonagem.angulo += 10;
                passoAnguloDir += 10;
            }else{
                this->objetoPersonagem.angulo -= 90;
                passoAnguloDir =180;
            }
            break;
        }
        update();
}

void canvas::mudarVisualizacao(bool MC)
{
    if(MC == true)
    {
        CriarCamera.ativarCamera2(aspecto);
    }
    else
    {
        CriarCamera.ativarCamera(aspecto);
    }
}
