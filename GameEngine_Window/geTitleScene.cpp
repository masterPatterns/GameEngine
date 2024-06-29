#include "geTitleScene.h"

namespace ge
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPos(Vector2(100.0f, 100.0f));
		//tr->SetName(L"TRTitle");

		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SRTitle");
		//sr->ImageLoad(L"K:\\workspace\\test\\GameEngine\\Resources\\title.bmp");

		//AddGameObject(bg, enums::eLayerType::Background);

		bg = object::Instantiate<Player>(enums::eLayerType::Background, L"TitleScene");
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SRTitle");

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"TITLE");
		sr->SetTexture(bg);
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 30, str, 11);
	}

	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
		/*bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}