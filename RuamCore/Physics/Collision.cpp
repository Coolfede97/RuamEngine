#include "Collision.h"
#include "Transform.h"

namespace RuamEngine
{
    bool CheckAABBOverlap(BoxCollider* boxA, BoxCollider* boxB, glm::vec3& outNormal, float& outPenetration)
    {
        if (!boxA) {std::cerr << "Error: boxA is nullptr in a call to function CheckAABBOverlap\n"; return false;}
        if (!boxB) {std::cerr << "Error: boxB is nullptr in a call to function CheckAABBOverlap\n"; return false;}

        glm::vec3 posA = boxA->transform()->position() + boxA->m_center;
        glm::vec3 posB = boxB->transform()->position() + boxB->m_center;
        glm::vec3 delta = posB - posA;

        glm::vec3 scaleA = boxA->transform()->scale();
        glm::vec3 halfSizeA = boxA->m_halfSize * scaleA;
        glm::vec3 scaleB = boxB->transform()->scale();
        glm::vec3 halfSizeB = boxB->m_halfSize * scaleB;

        float overlapX = (halfSizeA.x + halfSizeB.x) - abs(delta.x);
        float overlapY = (halfSizeA.y + halfSizeB.y) - abs(delta.y);
        float overlapZ = (halfSizeA.z + halfSizeB.z) - abs(delta.z);

        if (overlapX<=0 || overlapY<=0 || overlapZ <= 0) return false;

        if (overlapX < overlapY && overlapX < overlapZ)
        {
            outPenetration = overlapX;
            outNormal = glm::vec3(delta.x >= 0 ? 1 : -1, 0, 0);
        }
        else if (overlapY < overlapZ)
        {
            outPenetration = overlapY;
            outNormal = glm::vec3(0, delta.y >= 0 ? 1 : -1, 0);
        }
        else
        {
            outPenetration = overlapZ;
            outNormal = glm::vec3(0, 0, delta.z >= 0 ? 1 : -1);
        }

        return true;
    }
}
