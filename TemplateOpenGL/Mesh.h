#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <fstream>

#include <fstream>

#include "MeshData.h"
#include "ShaderProgram.h"

using namespace std;

class Mesh
{
private:
	bool hasNormals;
	bool hasUVs;
	bool hasColor;
	bool isIndexed;

	GLint normalBuffer;
	GLint UVbuffer;
	GLint colorBuffer;
	GLint indexBuffer;

	GLint indexCounter;
	GLint vertexCounter;

	GLuint *buffers;
	GLuint meshID;

protected:
	vector<glm::vec3> vertices;
	vector<glm::vec3> normals;
	vector<glm::vec4> colors;
	vector<glm::vec2> texUVs;
	vector<GLuint> indices;

	ShaderProgram shader;
	MeshData data;
	glm::vec3 position;
	GLfloat scale;
	glm::mat4 rotationMatrix;

	void SetUp(void);
	void LoadData(void);
	void LoadArrayBuffer(GLint buffer, vector<glm::vec2> data);
	void LoadArrayBuffer(GLint buffer, vector<glm::vec3> data);
	void LoadArrayBuffer(GLint buffer, vector<glm::vec4> data);
	void LoadIndexer(GLint buffer, vector<GLuint> indexer);
	void BindAllBuffers(void);

public:
	Mesh(ShaderProgram *shader);
	Mesh(ShaderProgram *shader, MeshData *data);
	~Mesh(void);

	static Mesh* FromFile(ShaderProgram *shader, string filepath);

	void AddVertex(glm::vec3 vertex);
	void AddNormal(glm::vec3 normal);
	void AddTexCoord(glm::vec2 texCoord);
	void AddColor(glm::vec4 color);
	void AddIndex(GLuint index);
	void AddIndexes(int count, GLuint *index);

	glm::vec3 Position(void);
	void Position(glm::vec3 position);

	GLfloat Scale(void);
	void Scale(GLfloat);

	glm::mat4 ModelMatrix(void);
	ShaderProgram Shader(void);

	void Update(GLfloat deltaTime);
	void Draw(void);

	void RotateX(GLfloat angle);
	void RotateY(GLfloat angle);
	void RotateZ(GLfloat angle);
};