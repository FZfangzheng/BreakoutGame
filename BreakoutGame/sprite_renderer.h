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
    // ���캯������ʼ��shader��
    SpriteRenderer(Shader shader);
    // ��������
    ~SpriteRenderer();
    // Ӧ����Ⱦ�������ָ������λ�ô�С��ת������ɫ�ĳ�����
    void DrawSprite(Texture2D texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    // Shader
    Shader       shader;
    // ������������ı��η���
    unsigned int quadVAO;
    // ��ʼ���������ı��εĻ������Ͷ�������
    void initRenderData();
};

#endif