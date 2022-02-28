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
    // 特效
    bool Confuse, Chaos, Shake;

    PostProcessor(Shader shader, unsigned int width, unsigned int height);
    // 准备帧缓冲
    void BeginRender();
    // 结束帧缓冲，将其处理后存到一个纹理
    void EndRender();
    // 将纹理渲染
    void Render(float time);
private:
    unsigned int MSFBO, FBO;
    unsigned int RBO;
    unsigned int VAO;
    // 初始化矩形以渲染后处理纹理
    void initRenderData();
};

#endif