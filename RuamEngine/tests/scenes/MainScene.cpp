#include "../../RuamEngine.h"

class Manager : public Component {
public:
	void ImGuiRender()
	{
		for (auto& test : SceneManager::sceneList())
		{
			if (ImGui::Button(test.name().c_str()))
			{
			}
		}
	}
};

static Scene mainScene;

Scene& MainScene() {
	return mainScene;
}
