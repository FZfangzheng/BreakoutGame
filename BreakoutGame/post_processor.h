#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"
#include "shader.h"


class PostProcessor
{
public:
    Shader PostProcessingShader;
    Texture2D Texture;
    unsigned int Width, Height;
    // ��Ч
    bool Confuse, Chaos, Shake;

    PostProcessor(Shader shader, unsigned int width, unsigned int height);
    // ׼��֡����
    void BeginRender();
    // ����֡���壬���䴦���浽һ������
    void EndRender();
    // ��������Ⱦ
    void Render(float time);
private:
    unsigned int MSFBO, FBO;
    unsigned int RBO;
    unsigned int VAO;
    // ��ʼ����������Ⱦ��������
    void initRenderData();
};

#endif