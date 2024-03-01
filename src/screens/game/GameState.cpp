#include "screens/game/GameState.h"
#include <iostream>
GameState::GameState()
{
}

void GameState::Update(float deltaTime)
{
	m_GameSpeed = 0.5 + 0.3 * (m_Score / 1000);
	std::cout << m_Score << std::endl;
}

void GameState::Restart()
{
}

void GameState::SetGameContinues(bool value)
{
	m_GameContinues = value;
}

double GameState::GetGameSpeed() const
{
	return m_GameSpeed;
}


int GameState::GetScore() const
{
	return m_Score;
}

bool GameState::GetGameContinues() const
{
	return m_GameContinues;
}

void GameState::IncrementScore(int amount)
{
	m_Score += amount;
}
