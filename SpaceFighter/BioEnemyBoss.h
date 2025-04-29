
#pragma once

#include "EnemyShip.h"

class BioEnemyBoss : public EnemyShip
{

public:

	/** @brief Creates a new instance of BioEnemyShip. */
	BioEnemyBoss();
	virtual ~BioEnemyBoss() { }

	/** @brief Sets the texture that will be used to render the enemy ship.
		@param pTexture A pointer to the texture. */
	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	/** @brief Updates the enemy ship.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Draws the enemy ship.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);


private:

	Texture* m_pTexture = nullptr;
};