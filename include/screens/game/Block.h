#pragma once
#include "rendering/Camera.h"
#include "app/GameObject.h"
#include "model/Quad.h"
#include <memory>

class Block : public GameObject
{
public:
	Block();
	Block(std::shared_ptr<Material> material);

	void Render() override;
	void Update(float deltaTime) override;

	void Swap(Block &other);
	void Clear();
	bool IsEmpty() const;
	void SetEmpty(bool isEmpty);
	void SetMaterial(std::shared_ptr<Material> material);

private:
	bool m_IsEmpty;
};