#pragma once
#include "app/GameObject.h"
#include "Block.h"

class Tetromino;

class Board : public GameObject
{
public:
	Board();

	void Render() override;
	void Update(float deltaTime) override;

	void PlaceTetromino(Tetromino &tetromino);
	bool CheckCollision(int x, int y);

	static glm::vec2 ConvertToGridPosition(glm::vec2 position);
	static glm::vec2 ConvertToWorldPosition(glm::vec2 position);

private:
	std::vector<std::vector<Block>> m_Grid;

	void CheckGameEnded();
	void ClearLines();
	void ShiftLinesDown(int row);
};