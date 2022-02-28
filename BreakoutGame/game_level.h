#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"


//关卡类，从文本中读取关卡
class GameLevel
{
public:
    // 砖块
    std::vector<GameObject> Bricks;
    // 构造
    GameLevel() { }
    // 从文件中加载关卡
    void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
    // 渲染关卡
    void Draw(SpriteRenderer& renderer);
    // 监控砖块是否全部打完
    bool IsCompleted();
private:
    // 初始化关卡
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif