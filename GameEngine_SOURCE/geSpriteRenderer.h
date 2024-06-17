#pragma once
#include "geEntity.h"
#include "geTransform.h"
#include "geGameObject.h"
#include "geComponent.h"

namespace ge
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize(float mLSize, float mRSize) override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
