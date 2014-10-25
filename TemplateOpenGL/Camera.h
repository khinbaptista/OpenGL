#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

class Camera
{
protected:
	glm::mat4 projection;
	glm::mat4 view;

	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;

	glm::vec3 movementDirection;
	float angularSpeed;
	float movementSpeed;

public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);
	~Camera(void);

	static Camera* New2D(int width, int height, int layer = 5);

	glm::mat4 Projection(void);
	void Projection(glm::mat4 projection);

	glm::mat4 View(void);

	glm::vec3 Position(void);
	void Position(glm::vec3 position);

	glm::vec3 Direction(void);
	void Direction(glm::vec3 direction);

	glm::vec3 Target(void);
	void Target(glm::vec3 target);

	float DistanceToTarget(void);
	void DistanceToTarget(float distance);

	glm::vec3 Up(void);
	void Up(glm::vec3 up);

	glm::vec3 MovementDirecion(void);
	void MovementDirecion(glm::vec3 direction);

	float AngularSpeed(void);
	void AngularSpeed(float speed);

	float MovementSpeed(void);
	void MovementSpeed(float speed);

	glm::mat4 ModelViewProjection(glm::mat4 model);

	void RotateUp(float deltaTime = 1, bool clockwise = true);
	void RotateUp(float angularSpeed, float deltaTime = 1, bool clockwise = true);

	void RotateY(float deltaTime = 1, bool clockwise = true);
	void RotateY(float angularSpeed, float deltaTime = 1, bool clockwise = true);

	void RotateAroundTarget(float deltaTime = 1, bool clockwise = true);
	void RotateAroundTarget(float angularSpeed, float deltaTime = 1, bool clockwise = true);
};
