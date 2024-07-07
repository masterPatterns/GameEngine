#pragma once
#include "geResource.h"
#include "geTexture.h"
#include "geTime.h"
#include "geTransform.h"
#include "geGameObject.h"
#include "geAnimator.h"
#include "geRenderer.h"

namespace ge
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		virtual ~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);
			
		void CreateAnimation(const std::wstring& name
			, graphcis::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animatior) { mAnimator = animatior; }

	private:
		class Animator* mAnimator;
		graphcis::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}
