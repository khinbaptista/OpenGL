#pragma once

#include <vector>
#include "VertexUnit.h"

using namespace std;

class MeshData
{
public:
	vector<VertexUnit> data;
	vector<unsigned int> indices;

	MeshData(void);
	~MeshData(void);

	void AddVertexUnit(VertexUnit unit);
};
