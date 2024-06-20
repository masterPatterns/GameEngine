#include "geEndScene.h"

namespace ge
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TREnd");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SREnd");
		sr->ImageLoad(L"K:\\workspace\\test\\GameEngine\\Resources\\event.bmp");

		AddGameObject(bg);
	}
	void EndScene::Update()
	{
		Scene::Update();
	}
	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"End Scene";
		TextOut(hdc, 0, 30, str, 9);
	}
}