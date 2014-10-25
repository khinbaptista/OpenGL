#pragma once

#include <glm/glm.hpp>

class VertexUnit
{
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	
	VertexUnit(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoord);
	~VertexUnit(void);

	bool PositionEquals(VertexUnit other);
	bool NormalEquals(VertexUnit other);
	bool TexCoordEquals(VertexUnit other);
};

bool operator==(VertexUnit v1, VertexUnit v2);
bool operator!=(VertexUnit v1, VertexUnit v2);
