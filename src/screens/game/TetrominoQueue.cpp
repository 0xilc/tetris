#include "screens/game/TetrominoQueue.h"
#include "model/Quad.h"
#include "app/config.h"
#include "screens/game/Board.h"
#include "screens/game/Shapes.h"
#include <memory>
#include <random>

TetrominoQueue::TetrominoQueue(std::shared_ptr<Board> board)
	:m_Board(board)
{
	m_Mesh = std::make_shared<Quad>();
	m_Material = std::make_shared<Material>("assets/shaders/board.vert", "assets/shaders/board.frag");
	m_Material->SetDiffuseTexture("assets/textures/board.jpg");
	m_ModelMatrix = glm::mat4(1.0f);
	m_Scale = glm::vec2(5, 16);
	m_Position = glm::vec2((BOARD_WIDTH / 2) + 3.5, (BOARD_HEIGHT / 2) - 7.5);
	UpdateModelMatrix();
	
	FillBag();
}

void TetrominoQueue::Render()
{
	m_Material->Use();
	m_Material->GetShader()->SetUniformMat4fv("modelMatrix", GetModelMatrix());
	m_Mesh->Render();

	glm::vec2 topPos = m_Position + glm::vec2(0, 9);
	glm::vec2 offset(0, -3);
	int cnt = 0;
	for (auto& element : m_Bag)
	{
		cnt++;
		if (cnt > 5) return;
		topPos += offset;
		element->RenderInFrame(topPos);
	}
}

void TetrominoQueue::Update(float deltaTime)
{

}

std::shared_ptr<Tetromino> TetrominoQueue::PickNewTetrominoFromQueue()
{
	if (m_Bag.size() <= 7) FillBag();
	std::shared_ptr<Tetromino> picked = m_Bag.front();
	m_Bag.pop_front();
	return picked;
}

void TetrominoQueue::FillBag()
{
	std::deque<std::shared_ptr<Tetromino>> tempBag;
	tempBag.push_back(std::make_shared<LShape>(m_Board));
	tempBag.push_back(std::make_shared<LShape>(m_Board));
	tempBag.push_back(std::make_shared<ZShape>(m_Board));
	tempBag.push_back(std::make_shared<SShape>(m_Board));
	tempBag.push_back(std::make_shared<TShape>(m_Board));
	tempBag.push_back(std::make_shared<OShape>(m_Board));
	tempBag.push_back(std::make_shared<JShape>(m_Board));
	tempBag.push_back(std::make_shared<IShape>(m_Board));
	std::random_shuffle(tempBag.begin(), tempBag.end());
	for (auto element : tempBag)
	{
		m_Bag.push_back(element);
	}
}
