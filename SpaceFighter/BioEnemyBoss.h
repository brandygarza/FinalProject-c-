
#pragma once

#include "EnemyShip.h"

/** @brief Represents the boss of the biological ships. */
class BioEnemyBoss : public EnemyShip
{

public:

	/** @brief Creates a new instance of BioEnemyBoss. */
	BioEnemyBoss();
	virtual ~BioEnemyBoss() { }

	/** @brief Sets the texture that will be used to render the boss ship.
		@param pTexture A pointer to the texture. */
	virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	/** @brief Updates the boss ship.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Draws the boss ship.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Gets the current hit points of the ship.
		@return Returns the current hit points of the ship. */
	virtual float GetHitPoints() const { return m_hitPoints; }

	/** @brief Applies damage to the ship.
		@param damage The amount of damage to apply. */
	virtual void Hit(const float damage);

private:

	Texture* m_pTexture = nullptr;
};