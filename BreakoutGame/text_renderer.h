#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <map>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"


struct Character {
    unsigned int TextureID; // ID
    glm::ivec2   Size;      // �����С
    glm::ivec2   Bearing;   // ���/����ƫ��
    unsigned int Advance;   // ˮƽ����
};


class TextRenderer
{
public:
    // ����Ԥ��������
    std::map<char, Character> Characters; 
    Shader TextShader;

    TextRenderer(unsigned int width, unsigned int height);
    // ��������
    void Load(std::string font, unsigned int fontSize);
    // ��Ⱦ�ı�
    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color = glm::vec3(1.0f));
private:
    unsigned int VAO, VBO;
};

#endif 