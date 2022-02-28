#ifndef GAME_H
#define GAME_H
#include <vector>
#include <tuple>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_level.h"
#include "power_up.h"

//��Ϸ״̬-���˵�ѡ��ʤ��
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// ��ײ����
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// ��ײ���ݣ�������ײ��������λ��
typedef std::tuple<bool, Direction, glm::vec2> Collision; 

// ��ʼ������С
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// ��ʼ������ٶ�
const float PLAYER_VELOCITY(500.0f);
// ��ʼ���ٶ�
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// ������뾶
const float BALL_RADIUS = 12.5f;


class Game
{
public:
    // ��Ϸ״̬
    GameState               State;
    bool                    Keys[1024];
    bool                    KeysProcessed[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    std::vector<PowerUp>    PowerUps;
    unsigned int            Level;
    unsigned int            Lives;
    // ����/����
    Game(unsigned int width, unsigned int height);
    ~Game();
    // ��ʼ����Ϸ״̬���������е���ɫ��/����/�ؿ���
    void Init();
    // ��Ϸѭ�����֣�������ƣ����£���Ⱦ����ײ���ʹ���
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void DoCollisions();
    // ���ùؿ������
    void ResetLevel();
    void ResetPlayer();
    // powerups
    void SpawnPowerUps(GameObject& block);
    void UpdatePowerUps(float dt);
};

#endif