#include "screens/game/Theme.h"
#include "rendering/Shader.h"

Theme::Theme()
{
    std::shared_ptr<Material> defaultBlockMaterial = std::make_shared<Material>("assets/themes/default/shaders/block/blue.vert", "assets/themes/default/shaders/block/blue.frag");
    defaultBlockMaterial->SetDiffuseTexture("assets/themes/default/textures/block/blue.png");
    
    std::shared_ptr<Material> defaultGridMaterial = std::make_shared<Material>("assets/themes/default/shaders/board.vert", "assets/themes/default/shaders/board.frag");
    defaultGridMaterial->SetDiffuseTexture("assets/themes/default/textures/board.jpg");

    std::shared_ptr<Material> ghostMaterial = std::make_shared<Material>("assets/themes/default/shaders/block/ghost.vert", "assets/themes/default/shaders/block/ghost.frag");

    SetMaterialLShape(defaultBlockMaterial);
    SetMaterialJShape(defaultBlockMaterial);
    SetMaterialIShape(defaultBlockMaterial);
    SetMaterialOShape(defaultBlockMaterial);
    SetMaterialTShape(defaultBlockMaterial);
    SetMaterialZShape(defaultBlockMaterial);
    SetMaterialSShape(defaultBlockMaterial);
    SetMaterialGhost(ghostMaterial);
    SetMaterialGrid(defaultGridMaterial);
    SetMaterialHold(defaultGridMaterial);
    SetMaterialTetrominoQueue(defaultGridMaterial);
}

void Theme::Load(std::string path)
{
    std::shared_ptr<Material> blockMat = std::make_shared<Material>(path + "shaders/block/block.vert", path + "/shaders/block/block.frag");
    blockMat->SetDiffuseTexture(path + "/textures/block/diffuse.jpg");
    blockMat->SetSpecularTexture(path + "/textures/block/specular.jpg");
    blockMat->SetNormalTexture(path + "/textures/block/normal.jpg");

    std::shared_ptr<Material> grid = std::make_shared<Material>(path + "shaders/board/board.vert", path + "shaders/board/board.frag");
    grid->SetDiffuseTexture(path + "textures/board/boardDiffuse.jpg");


    std::shared_ptr<Material> ghost = std::make_shared<Material>("assets/themes/default/shaders/block/ghost.vert", "assets/themes/default/shaders/block/ghost.frag");

    SetMaterialLShape(blockMat);
    SetMaterialJShape(blockMat);
    SetMaterialIShape(blockMat);
    SetMaterialOShape(blockMat);
    SetMaterialTShape(blockMat);
    SetMaterialZShape(blockMat);
    SetMaterialSShape(blockMat);
    SetMaterialGhost(ghost);
    SetMaterialGrid(grid);
    SetMaterialHold(grid);
    SetMaterialTetrominoQueue(grid);
}

void Theme::SetMaterials(std::vector<std::shared_ptr<Material>> materials)
{
    if (materials.size() < 11)
    {
        std::cerr << "Error: Not enough materials." << std::endl;
    }
    m_LShapeMaterial = materials[0];
    m_JShapeMaterial = materials[1];
    m_IShapeMaterial = materials[2];
    m_OShapeMaterial = materials[3];
    m_SShapeMaterial = materials[4];
    m_TShapeMaterial = materials[5];
    m_ZShapeMaterial = materials[6];
    m_BackgroundMaterial = materials[7];
    m_GridMaterial = materials[8];
    m_HoldMaterial = materials[9];
    m_TetrominoQueueMaterial = materials[10];
}

void Theme::SetMaterialLShape(std::shared_ptr<Material> material) {
    m_LShapeMaterial = material;
}

void Theme::SetMaterialJShape(std::shared_ptr<Material> material) {
    m_JShapeMaterial = material;
}

void Theme::SetMaterialIShape(std::shared_ptr<Material> material) {
    m_IShapeMaterial = material;
}

void Theme::SetMaterialOShape(std::shared_ptr<Material> material) {
    m_OShapeMaterial = material;
}

void Theme::SetMaterialSShape(std::shared_ptr<Material> material) {
    m_SShapeMaterial = material;
}

void Theme::SetMaterialTShape(std::shared_ptr<Material> material) {
    m_TShapeMaterial = material;
}

void Theme::SetMaterialZShape(std::shared_ptr<Material> material) {
    m_ZShapeMaterial = material;
}

void Theme::SetMaterialGhost(std::shared_ptr<Material> material)
{
    m_GhostMaterial = material;
}

void Theme::SetMaterialBackground(std::shared_ptr<Material> material) {
    m_BackgroundMaterial = material;
}

void Theme::SetMaterialGrid(std::shared_ptr<Material> material) {
    m_GridMaterial = material;
}

void Theme::SetMaterialHold(std::shared_ptr<Material> material) {
    m_HoldMaterial = material;
}

void Theme::SetMaterialTetrominoQueue(std::shared_ptr<Material> material) {
    m_TetrominoQueueMaterial = material;
}

std::shared_ptr<Material> Theme::GetMaterialLShape() {
    return m_LShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialJShape() {
    return m_JShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialIShape() {
    return m_IShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialOShape() {
    return m_OShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialSShape() {
    return m_SShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialTShape() {
    return m_TShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialZShape() {
    return m_ZShapeMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialGhost()
{
    return m_GhostMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialBackground() {
    return m_BackgroundMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialGrid() {
    return m_GridMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialHold() {
    return m_HoldMaterial;
}

std::shared_ptr<Material> Theme::GetMaterialTetrominoQueue() {
    return m_TetrominoQueueMaterial;
}