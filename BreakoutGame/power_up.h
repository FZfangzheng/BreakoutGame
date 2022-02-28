#ifndef POWER_UP_H
#define POWER_UP_H
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"


// 道具大小
const glm::vec2 POWERUP_SIZE(60.0f, 20.0f);
// 道具掉落速度
const glm::vec2 VELOCITY(0.0f, 150.0f);


// 道具类
class PowerUp : public GameObject 
{
public:
    // 道具类型、持续时间、是否使用该道具
    std::string Type;
    float       Duration;	
    bool        Activated;

    PowerUp(std::string type, glm::vec3 color, float duration, glm::vec2 position, Texture2D texture) 
        : GameObject(position, POWERUP_SIZE, texture, color, VELOCITY), Type(type), Duration(duration), Activated() { }
};

#endif