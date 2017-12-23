#include "Mesh.h"

Mesh::Mesh() {

}

Mesh::Mesh(std::vector<float> vertices) {
    this->vertices = vertices;
}

void Mesh::uploadToGPU() {
    glGenBuffers(1, &this->vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    
    float* arr = &this->vertices[0];
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size(), arr, GL_STATIC_DRAW);
}

void Mesh::draw() {
    //std::cout << "DRAWING MESH" << std::endl; 
    /*glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*) 0
    );*/
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDisableVertexAttribArray(0);
}

Mesh::~Mesh() {
    // TODO: add destructor
}
