#include "objectobj.h"

ObjectOBJ::ObjectOBJ()
{

}

ObjectOBJ::Face::Face(int tam, int *vertices, int *texcoords, int normal1, int normal2, int normal3)
{
    this->tam = tam;
    this->vertices = vertices;
    //this->texcoords = texcoords;
    normall[0] = normal1;
    normall[1] = normal2;
    normall[2] = normal3;
}
void ObjectOBJ::load(const char *file)
{
    std::string line;
    std::vector<std::string> lines;

    std::ifstream in(file);//ler as linhas

    if (!in.is_open()){
        printf("Não foi possivel carregar o arquivo %s\n", file);
        return;
    }
    while (!in.eof()) {
        std::getline(in, line);//passar as linhas
        lines.push_back(line);//adicionar
    }
    in.close();//fechar
    float a, b, c,d,e,f;
    for (std::string &line : lines) {
        if (line[0] == 'v') {
            if (line[1] == ' ') {
                sscanf(line.c_str(), "v %f %f %f", &a, &b, &c);
                glm::vec3 vet = glm::vec3(a, b, c);
                vertices.push_back(vet);
            }
            else if (line[1] == 'n'){
                sscanf(line.c_str(), "vn %f %f %f", &d, &e, &f);
                glm::vec3 Normais = glm::vec3(d, e, f);
                normals.push_back(Normais);
            }
        } else if (line[0] == 'f') {
            int v0, v1, v2, t0, t1, t2, n1,n2,n3;
            sscanf(line.c_str(), "f %d//%d %d//%d %d//%d", &v0, &n1, &v1, &n2, &v2, &n3);
            int *v = new int[3]{v0 - 1, v1 - 1, v2 - 1};
            faces.push_back(Face(3, v, NULL, n1, n2, n3));
        }
    }
    printf("Modelo: %s\n", file);
    printf("Vertices: %d\n", vertices.size());
    //printf("Texcoords: %d\n", texcoords.size());
    printf("Normals: %d\n", normals.size());
    printf("Faces: %d\n", faces.size());
}

void ObjectOBJ::atualizarObject(glm::vec3 poscam, glm::vec3 posluz, iluminacao luz)
{
    list = glGenLists(1);        //armazena os dados obj
    glNewList(list, GL_COMPILE); //
    for(int i = 0; i < (int)faces.size(); i++){

        glBegin(GL_TRIANGLES);

            glColor3fv(glm::value_ptr(luz.aplicarLuz( posicao, normals[faces[i].normall[0]-1],
                                                   posluz,  poscam, cor)));
            glVertex3fv(glm::value_ptr(vertices[faces[i].vertices[0]]));


            glColor3fv(glm::value_ptr(luz.aplicarLuz(posicao, normals[faces[i].normall[1]-1],
                                                   posluz, poscam, cor)));
            glVertex3fv(glm::value_ptr(vertices[faces[i].vertices[1]]));


            glColor3fv(glm::value_ptr(luz.aplicarLuz(posicao, normals[faces[i].normall[2]-1],
                                                   posluz,  poscam, cor )));
            glVertex3fv(glm::value_ptr(vertices[faces[i].vertices[2]]));

        glEnd();
    }
    glEndList();
}

void ObjectOBJ::desenhar(glm::vec3 poscam, glm::vec3 posluz, iluminacao *luz)
{
    glm::mat4 R1 ,I1, T1, S1, M1;
    I1 = glm::mat4(1.0f);// inicializar identidade
    R1 = glm::rotate(I1, glm::radians(angulo), glm::vec3(0,1,0)); //inicializar matriz de rotacao
    S1 = glm::scale(I1, escala);//inicializar matriz de escala
    T1 = glm::translate(I1, posicao); // inicializar matriz de translacao
    M1 = T1 * R1 * S1; // multiplicar as matrizes

    glPushMatrix();
    glMultMatrixf(glm::value_ptr(M1));//habilitando a matriz de transformacao Rot

        atualizarObject( poscam,posluz, (*luz));

        glCallList(list);// a list que foi salvo
    glPopMatrix();
}


