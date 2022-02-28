#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


// 球对象，继承GameObject，具备半径，是否固定属性
class BallObject : public GameObject
{
public:
    // 半径
    float   Radius;
    // 是否固定板子	
    bool    Stuck;
    bool    Sticky, PassThrough;
    // 构造
    BallObject();
    BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);
    // 球的移动
    glm::vec2 Move(float dt, unsigned int window_width);
    // 重置状态
    void    Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif