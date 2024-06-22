#pragma once
#include "..\\GameEngine_SOURCE\\geScene.h"
#include "..\\GameEngine_SOURCE\\geGameObject.h"
#include "..\\GameEngine_SOURCE\\geSceneManager.h"
#include "gePlayer.h"

namespace ge
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;
	};
}
