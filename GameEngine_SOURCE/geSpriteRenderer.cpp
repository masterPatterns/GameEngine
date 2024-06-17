#include "geSpriteRenderer.h"

namespace ge
{
	SpriteRenderer::SpriteRenderer()
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize(float mLSize, float mRSize)
	{
		setLSize(mLSize);
		setRSize(mRSize);
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rectangle(hdc, tr->GetX(), tr->GetY(), getLSize() + tr->GetX(), getRSize() + tr->GetY());

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);

		/*if (isShoot[0] == 1) {
			mMissile[0].Render(hdc);
		}*/
	}
}