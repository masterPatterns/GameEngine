#include "geSpriteRenderer.h"
#include "geEntity.h"
#include "geTransform.h"
#include "geGameObject.h"
#include "geComponent.h"
#include "geTexture.h"
#include "geRenderer.h"

namespace ge
{
	SpriteRenderer::SpriteRenderer()
		: mTexture(nullptr)
		, mSize(Vector2::One)
		, Component(enums::eComponentType::SpriteRenderer)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
		
	}
	void SpriteRenderer::Initialize()
	{

	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CaluatePosition(pos);
		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc()
				, 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphcis(hdc);

			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);

			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y)
				, 0, 0
				, mTexture->GetWidth()
				, mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr/*&imgAtt*/
			);
		}
	}
}