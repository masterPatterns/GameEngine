#pragma once
#include "geEntity.h"
#include "geTransform.h"
#include "geGameObject.h"
#include "geComponent.h"
#include "geTexture.h"

namespace ge
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphcis::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphcis::Texture* mTexture;
		math::Vector2 mSize;
	};
}
