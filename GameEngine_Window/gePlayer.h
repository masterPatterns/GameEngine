#pragma once
#include "..\\GameEngine_SOURCE\\geGameObject.h"

namespace ge
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}
