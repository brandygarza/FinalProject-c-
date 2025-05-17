

#include "Level02.h"
#include "BioEnemyBoss.h"


void Level02::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy boss
	Texture *pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png");
	
	const int COUNT = 1;

	double xPosition = 0.5;

	float delay = 3.0; // start delay
	Vector2 position;

	position.Set(xPosition * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

	BioEnemyBoss *pBoss = new BioEnemyBoss();
	pBoss->SetTexture(pTexture);
	pBoss->SetCurrentLevel(this);
	pBoss->Initialize(position, (float)delay);
	AddGameObject(pBoss);

	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground03.png"));

	Level::LoadContent(resourceManager);
}

//void Level02::BossChange1(ResourceManager& resourceManager)
//{
//	// Setup enemy boss's second texture
//	Texture *pTexture = resourceManager.Load<Texture>("Textures\\DamagedBoss.png");
//
//	BioEnemyBoss *pBoss = new BioEnemyBoss();
//}

