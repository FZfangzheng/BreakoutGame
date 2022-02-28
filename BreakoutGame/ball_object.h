#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


// ����󣬼̳�GameObject���߱��뾶���Ƿ�̶�����
class BallObject : public GameObject
{
public:
    // �뾶
    float   Radius;
    // �Ƿ�̶�����	
    bool    Stuck;
    bool    Sticky, PassThrough;
    // ����
    BallObject();
    BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);
    // ����ƶ�
    glm::vec2 Move(float dt, unsigned int window_width);
    // ����״̬
    void    Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif