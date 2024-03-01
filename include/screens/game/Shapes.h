#pragma once
#include "Tetromino.h"

class LShape : public Tetromino
{
public:
	LShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class JShape : public Tetromino
{
public:
	JShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class OShape : public Tetromino
{
public:
	OShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class SShape : public Tetromino
{
public:
	SShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class TShape : public Tetromino
{
public:
	TShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class ZShape : public Tetromino
{
public:
	ZShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};

class IShape : public Tetromino
{
public:
	IShape(std::shared_ptr<Board> board);
	void RenderInFrame(glm::vec2 position) const override;
};
