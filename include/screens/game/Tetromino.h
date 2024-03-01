#pragma once
#include "app/GameObject.h"
#include "rendering/Material.h"
#include "Block.h"

class Board;

enum RotationType
{
	ROTATE_CLOCKWISE,
	ROTATE_CCLOCKWISE,
	ROTATE_180
};

class Tetromino : public GameObject
{
public:
	Tetromino(std::shared_ptr<Board> board);

	void Render() override;
	void RenderGhost() const;
	virtual void RenderInFrame(glm::vec2 pos) const = 0;

	void Update(float deltaTime) override;
	void Move(glm::vec2 direction);
	void Drop();
	void Rotate(RotationType type);
	bool IsPlaced() const;
	void Refactor();

	std::vector<glm::vec2> GetBlockGridPositions() const;
	std::shared_ptr<Material> GetMaterial() const;

protected:
	std::unique_ptr<Block> m_Block;
	std::vector<glm::vec2> m_RelativePositions;
	std::vector<glm::vec2> m_DefaultRelativePositions;
	glm::vec2 m_GhostTetrominoPosition;
	std::shared_ptr<Board> m_Board;
	std::shared_ptr<Material> m_GhostMaterial;

	float m_TimeSinceLastMove = 0;
	float m_MoveSpeed;
	float m_MoveDelay;
	float m_FallTimer = 0;
	float m_StayOnSurfaceTimer = 2.0f;

	bool m_CanRotate;
	bool m_CanDrop = false;
	bool m_IsPlaced;

private:
	glm::vec2 FindDropPosition();
	bool CheckCollision(glm::vec2 position);
	bool IsOnSurface() const;
	void PlaceToBoard();
	void HandleInput();
	void PrintPos();
};