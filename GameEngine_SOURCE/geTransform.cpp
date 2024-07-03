#include "geTransform.h"

namespace ge
{
	Transform::Transform()
		: mPosition(0, 0)
		, Component(enums::eComponentType::Transform)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{

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