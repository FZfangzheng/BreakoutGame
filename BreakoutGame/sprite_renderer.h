#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"


class SpriteRenderer
{
public:
    // 构造函数（初始化shader）
    SpriteRenderer(Shader shader);
    // 析构函数
    ~SpriteRenderer();
    // 应用渲染精灵绘制指定纹理，位置大小旋转方向颜色的长方体
    void DrawSprite(Texture2D texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    // Shader
    Shader       shader;
    // 顶点数组对象，四边形方块
    unsigned int quadVAO;
    // 初始化并配置四边形的缓冲区和顶点属性
    void initRenderData();
};

#endif