#include "geTransform.h"

namespace ge
{
	Transform::Transform()
		: mX(0)
		, mY(0)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize(float mLSize, float mRSize)
	{
		setLSize(mLSize);
		setRSize(mRSize);
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}