#pragma once
#include "rendering/Material.h"

class Theme
{
public:

    Theme(const Theme&) = delete;
    Theme& operator=(const Theme&) = delete;

    static Theme& GetInstance()
    {
        static Theme instance;
        return instance;
    }

    void Load(std::string path);
    void SetMaterials(std::vector<std::shared_ptr<Material>> materials);

    void SetMaterialLShape(std::shared_ptr<Material> material);
    void SetMaterialJShape(std::shared_ptr<Material> material);
    void SetMaterialIShape(std::shared_ptr<Material> material);
    void SetMaterialOShape(std::shared_ptr<Material> material);
    void SetMaterialSShape(std::shared_ptr<Material> material);
    void SetMaterialTShape(std::shared_ptr<Material> material);
    void SetMaterialZShape(std::shared_ptr<Material> material);
    void SetMaterialGhost(std::shared_ptr<Material> material);
    void SetMaterialBackground(std::shared_ptr<Material> material);
    void SetMaterialGrid(std::shared_ptr<Material> material);
    void SetMaterialHold(std::shared_ptr<Material> material);
    void SetMaterialTetrominoQueue(std::shared_ptr<Material> material);

    std::shared_ptr<Material> GetMaterialLShape();
    std::shared_ptr<Material> GetMaterialJShape();
    std::shared_ptr<Material> GetMaterialIShape();
    std::shared_ptr<Material> GetMaterialOShape();
    std::shared_ptr<Material> GetMaterialSShape();
    std::shared_ptr<Material> GetMaterialTShape();
    std::shared_ptr<Material> GetMaterialZShape();
    std::shared_ptr<Material> GetMaterialGhost();
    std::shared_ptr<Material> GetMaterialBackground();
    std::shared_ptr<Material> GetMaterialGrid();
    std::shared_ptr<Material> GetMaterialHold();
    std::shared_ptr<Material> GetMaterialTetrominoQueue();

private:
    Theme();
    std::shared_ptr<Material> m_LShapeMaterial;
    std::shared_ptr<Material> m_JShapeMaterial;
    std::shared_ptr<Material> m_IShapeMaterial;
    std::shared_ptr<Material> m_OShapeMaterial;
    std::shared_ptr<Material> m_SShapeMaterial;
    std::shared_ptr<Material> m_TShapeMaterial;
    std::shared_ptr<Material> m_ZShapeMaterial;
    std::shared_ptr<Material> m_GhostMaterial;
    std::shared_ptr<Material> m_BackgroundMaterial;
    std::shared_ptr<Material> m_GridMaterial;
    std::shared_ptr<Material> m_HoldMaterial;
    std::shared_ptr<Material> m_TetrominoQueueMaterial;
};
