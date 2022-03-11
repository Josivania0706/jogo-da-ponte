#include "texturas.h"
#include <Windows.h>
#include <gl/GL.h>
#include "stb_image.h"

texturas::texturas() : id(0), largura(0), altura(0), canais(0)
{

}

texturas::~texturas()
{
    glDeleteTextures(1, &id);
}

void texturas::load(std::string filePath)
{
    unsigned char* imgData;

    stbi_set_flip_vertically_on_load(true);
    //Receber a imagem que será aplicada aos objetos
    imgData = stbi_load(filePath.c_str(), &largura, &altura, &canais, 3);

    if(imgData) //Guardar a imagem carregada na memória
    {
        //Gerar a textura e associá-la ao id passado
        glGenTextures(1, &id);

        //Especificar o tipo de textura e seu identificador - vínculo
        glBindTexture(GL_TEXTURE_2D, id);

        //Seria guardar todas as informações da imagem na GPU
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, largura, altura, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);

        //Minificação (textura é reduzida de tamanho)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //Magnificação (textura tem seu tamanho ampliado)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        //Coordenadas S e T
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        std::cout << "SUCESSO: A textura foi carregada!" << filePath.c_str() << std::endl;
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(imgData);   //Caso não carregue, será liberada
    }
    else
    {
        std::cout << "ERRO: Nao foi possivel carregar a textura!" << filePath.c_str() << std::endl;
    }
}

void texturas::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void texturas::unBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
