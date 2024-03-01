#include "app/Input.h"
#include "app/config.h"
#include "screens/game/GameState.h"
#include "screens/game/GameScreen.h"
#include "screens/game/Shapes.h"

GameScreen::GameScreen()
{
	Theme::GetInstance().Load("assets/themes/diamonds/");
	m_Board = std::make_shared<Board>();
	m_HoldBoard = std::make_shared<HoldBoard>();
	m_TetrominoQueue = std::make_shared<TetrominoQueue>(m_Board);

	m_CurrentTetromino = m_TetrominoQueue->PickNewTetrominoFromQueue();
}

void GameScreen::Render()
{
	m_Board->Render();
	m_CurrentTetromino->RenderGhost();
	m_CurrentTetromino->Render();
	m_HoldBoard->Render();
	m_TetrominoQueue->Render();
}

void GameScreen::Update(float deltaTime)
{
	GameState::GetInstance().Update(deltaTime);
	if (!GameState::GetInstance().GetGameContinues()) 
	{
		std::cout << "game ended" << std::endl;
		return;
	}
	HandleInput();	
	m_CurrentTetromino->Update(deltaTime);
	m_Board->Update(deltaTime);
	if (m_CurrentTetromino->IsPlaced())
	{
		std::shared_ptr<Tetromino> newTetromino = m_TetrominoQueue->PickNewTetrominoFromQueue();
		SetCurrentTetromino(newTetromino);
		m_ControllerState.canHold = true;
	}
}

void GameScreen::Enter()
{
}

void GameScreen::Exit()
{
}

void GameScreen::HandleInput()
{
	if (Input::IsKeyPressed(SWAP_HOLD_PIECE_KEY))
	{
		if (!m_ControllerState.canHold) return;
		SwapTetrominoWithHold();
		m_ControllerState.canHold = false;
	}
}

void GameScreen::SetCurrentTetromino(std::shared_ptr<Tetromino> other)
{
	m_CurrentTetromino = other;
	m_CurrentTetromino->Refactor();
}

void GameScreen::SwapTetrominoWithHold()
{
	if (!m_HoldBoard->IsEmpty())
	{
		std::shared_ptr<Tetromino> swappedTetromino = m_HoldBoard->SwapTetromino(m_CurrentTetromino);
		SetCurrentTetromino(swappedTetromino);
	}
	else
	{
		m_HoldBoard->SetTetromino(m_CurrentTetromino);
		std::shared_ptr<Tetromino> newTetromino = m_TetrominoQueue->PickNewTetrominoFromQueue();
		SetCurrentTetromino(newTetromino);
	}
}
