#pragma once
#include "app/GameObject.h"
#include "screens/game/Tetromino.h"
#include <queue>


class TetrominoQueue : public GameObject
{
public:
	TetrominoQueue(std::shared_ptr<Board> board);

	void Render() override;
	void Update(float deltaTime) override;

	std::shared_ptr<Tetromino> PickNewTetrominoFromQueue();

private:
	void FillBag();

private:
	std::deque<std::shared_ptr<Tetromino>> m_Bag;
	std::shared_ptr<Board> m_Board;
};