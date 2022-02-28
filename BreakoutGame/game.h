#ifndef GAME_H
#define GAME_H
#include <vector>
#include <tuple>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_level.h"
#include "power_up.h"

//游戏状态-存活，菜单选择，胜利
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// 碰撞方向
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// 碰撞数据，包括碰撞方向和最近位置
typedef std::tuple<bool, Direction, glm::vec2> Collision; 

// 初始弹射板大小
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// 初始弹射板速度
const float PLAYER_VELOCITY(500.0f);
// 初始球速度
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// 弹射球半径
const float BALL_RADIUS = 12.5f;


class Game
{
public:
    // 游戏状态
    GameState               State;
    bool                    Keys[1024];
    bool                    KeysProcessed[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    std::vector<PowerUp>    PowerUps;
    unsigned int            Level;
    unsigned int            Lives;
    // 构造/析构
    Game(unsigned int width, unsigned int height);
    ~Game();
    // 初始化游戏状态（加载所有的着色器/纹理/关卡）
    void Init();
    // 游戏循环部分（输入控制，更新，渲染及碰撞检测和处理）
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void DoCollisions();
    // 重置关卡及玩家
    void ResetLevel();
    void ResetPlayer();
    // powerups
    void SpawnPowerUps(GameObject& block);
    void UpdatePowerUps(float dt);
};

#endif