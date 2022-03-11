#ifndef TEXTURAS_H
#define TEXTURAS_H

#include <iostream>

class texturas
{
private:
    unsigned int id;
    int largura, altura, canais;

public:
    texturas();
    ~texturas();

    //Funções para carregar, fazer o bind e o unbind
    void load(std::string filePath);    //Carrega textura

    void bind();                        //Vincular

    void unBind();                      //Desvincular para não ocorrer problemas de cor
};

#endif // TEXTURAS_H
