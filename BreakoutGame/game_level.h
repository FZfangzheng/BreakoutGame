#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"


//�ؿ��࣬���ı��ж�ȡ�ؿ�
class GameLevel
{
public:
    // ש��
    std::vector<GameObject> Bricks;
    // ����
    GameLevel() { }
    // ���ļ��м��عؿ�
    void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
    // ��Ⱦ�ؿ�
    void Draw(SpriteRenderer& renderer);
    // ���ש���Ƿ�ȫ������
    bool IsCompleted();
private:
    // ��ʼ���ؿ�
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif