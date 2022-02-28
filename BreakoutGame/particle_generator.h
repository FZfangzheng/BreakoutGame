#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "texture.h"
#include "game_object.h"


// 粒子
struct Particle {
    // 粒子位置速度
    glm::vec2 Position, Velocity;
    // 粒子颜色
    glm::vec4 Color;
    // 粒子生存周期
    float     Life;

    Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) { }
};


// 粒子生成器，用于渲染大量粒子，消灭达到指定生存周期的粒子
class ParticleGenerator
{
public:
    ParticleGenerator(Shader shader, Texture2D texture, unsigned int amount);
    // 更新粒子
    void Update(float dt, GameObject& object, unsigned int newParticles, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
    // 绘制粒子
    void Draw();
private:
    std::vector<Particle> particles;
    unsigned int amount;
    // 渲染相关
    Shader shader;
    Texture2D texture;
    unsigned int VAO;
    // 初始化缓冲区和顶点属性
    void init();
    // 返回第一个未使用的粒子
    unsigned int firstUnusedParticle();
    // 重新生成粒子
    void respawnParticle(Particle& particle, GameObject& object, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
};

#endif