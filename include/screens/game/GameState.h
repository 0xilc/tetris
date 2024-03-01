#pragma once
class GameState
{
public:
	GameState(const GameState &) = delete;
	GameState &operator=(const GameState &) = delete;

	static GameState &GetInstance()
	{
		static GameState instance;
		return instance;
	}

	void Update(float deltaTime);
	void Restart();

	void SetGameContinues(bool value);
	void IncrementScore(int amount);

	int GetScore() const;
	bool GetGameContinues() const;
	double GetGameSpeed() const;

private:
	GameState();

	double m_GameSpeed = 1.0f;
	double m_GameTime = 0.0f;
	int m_Score = 0;
	bool m_GameContinues = true;
};