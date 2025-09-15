#include "Object.hpp"
#include "glm/glm.hpp"

class Transform : public Component {
public:
	using Component::Component;

	Transform(const unsigned int obj_id);
	Transform(const unsigned int obj_id, glm::vec3 pos);

    void start() {};
    void update() {};

	void setPosition(glm::vec3 new_pos);
	void setPosition(float x, float y, float z);

	glm::vec3& position();

protected:
	glm::vec3 m_position;
};
