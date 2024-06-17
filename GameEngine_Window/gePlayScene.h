#pragma once
#include "..\\GameEngine_SOURCE\\geScene.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"

namespace ge
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
