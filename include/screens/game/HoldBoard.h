#pragma once
#include "app/GameObject.h"
#include "Tetromino.h"

class HoldBoard : public GameObject
{
public:
	HoldBoard();

	void Render() override;
	void Update(float deltaTime) override;

	bool IsEmpty() const;
	void SetTetromino(std::shared_ptr<Tetromino> tetromino);
	std::shared_ptr<Tetromino> SwapTetromino(std::shared_ptr<Tetromino> tetromino);

private:
	std::shared_ptr<Tetromino> m_HoldTetromino;
};