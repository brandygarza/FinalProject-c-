
#include "BioEnemyBoss.h"
#include "Level.h"

BioEnemyBoss::BioEnemyBoss()
{
	SetSpeed(120);
	SetMaxHitPoints(11);
	SetCollisionRadius(140);
}

void BioEnemyBoss::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = cos(gameTime.GetTotalTime() /** Math::PI*/ + GetIndex());

		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;

		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		if (!IsOnScreen())
		{
			Deactivate();
		}
	}

	EnemyShip::Update(gameTime);
}

void BioEnemyBoss::Hit(const float damage, ResourceManager& resourceManager, SpriteBatch& spriteBatch)
{
	m_hitPoints -= damage;

	if (m_hitPoints > 0)
	{
		// Doesn't work, not sure why. I locked in for 15-20 minutes, and I thought I had it. (No, it's not because it's commented)

		if (m_hitPoints <= 7 && m_hitPoints > 3)
		{
			m_pTexture = resourceManager.Load<Texture>("Textures\\DamagedBoss.png");
			BioEnemyBoss::SetTexture(m_pTexture);
			const float alpha = GetCurrentLevel()->GetAlpha();
			spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
		}
		if (m_hitPoints < 3)
		{
			m_pTexture = resourceManager.Load<Texture>("Textures\\BossHeavilyDamaged.png");
			BioEnemyBoss::SetTexture(m_pTexture);
			const float alpha = GetCurrentLevel()->GetAlpha();
			spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
		}

		// End of doesn't work. it doesn't harm anything, so I'll leave it as is. 

		return;
	}

	GameObject::Deactivate();
	GetCurrentLevel()->SpawnExplosion(this);
}

void BioEnemyBoss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
	}
}