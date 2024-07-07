#pragma once
#include "..\\GameEngine_SOURCE\\geScript.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"
#include "..\\GameEngine_SOURCE\\geInput.h"
#include "..\\GameEngine_SOURCE\\geTransform.h"
#include "..\\GameEngine_SOURCE\\geTime.h"

namespace ge
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void PositionMove(int posiAndDire, float mSpeed);
	private:
		
	};
}
