#pragma once
#include "app/Screen.h"
#include "Board.h"
#include "HoldBoard.h"
#include "TetrominoQueue.h"
#include "Tetromino.h"
#include "Theme.h"
#include <memory>
#include <queue>

struct ControllerState
{
    bool canHold = true;
};

class GameScreen : public Screen
{
public:
    GameScreen();
    void Render() override;
    void Update(float deltaTime) override;
    void Enter() override;
    void Exit() override;

    void HandleInput();

private:
    std::shared_ptr<Tetromino> m_CurrentTetromino;
    std::shared_ptr<Board> m_Board;
    std::shared_ptr<HoldBoard> m_HoldBoard;
    std::shared_ptr<TetrominoQueue> m_TetrominoQueue;

    ControllerState m_ControllerState;

    void SetCurrentTetromino(std::shared_ptr<Tetromino> other);
    void SwapTetrominoWithHold();
};