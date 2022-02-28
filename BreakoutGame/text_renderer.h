#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <map>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"


struct Character {
    unsigned int TextureID; // ID
    glm::ivec2   Size;      // 字体大小
    glm::ivec2   Bearing;   // 左侧/顶部偏移
    unsigned int Advance;   // 水平距离
};


class TextRenderer
{
public:
    // 载入预编译字体
    std::map<char, Character> Characters; 
    Shader TextShader;

    TextRenderer(unsigned int width, unsigned int height);
    // 载入字体
    void Load(std::string font, unsigned int fontSize);
    // 渲染文本
    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color = glm::vec3(1.0f));
private:
    unsigned int VAO, VBO;
};

#endif 