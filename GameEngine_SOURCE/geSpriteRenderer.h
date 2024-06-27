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

		//void ImageLoad(const std::wstring& path);

	private:
		//Gdiplus::Image* mImage;
		//UINT mWidth;
		//UINT mHeight;
	};
}
