#include "Camera.h"

using namespace glm;

// Creates a new camera
Camera::Camera(vec3 position, vec3 target, vec3 up){
	this->position = position;
	this->target = target;
	this->up = up;

	movementDirection = target - position;
	movementSpeed = 0;
	angularSpeed = 0;

	projection = perspective(radians(45.0f), float(16 / 9), 0.1f, 100.0f);
	view = lookAt(position, target, up);
}

Camera::~Camera(void){
}

// Camera 2D (suitable for sprites and GUI)
Camera* Camera::New2D(int width, int height, int layer){
	Camera &camera2d = *new Camera(vec3(0, 0, layer), vec3(0, 0, -1), vec3(0, 1, 0));
	camera2d.Position(vec3(width / 2, height / 2, layer));
	camera2d.projection = ortho(0.0f, float(width), 0.0f, float(height));

	return &camera2d;
}

// Gets the projection matrix of this camera
mat4 Camera::Projection(void){
	return projection;
}

// Sets the projection matrix of this camera
void Camera::Projection(mat4 projection){
	this->projection = projection;
}

// Gets the view matrix of this camera
mat4 Camera::View(void){
	return view;
}

// Gets the position of this camera
vec3 Camera::Position(void){
	return position;
}

// Sets the position of this camera
void Camera::Position(vec3 position){
	this->position = position;
	view = lookAt(position, target, up);
}

// Gets the direction of this camera (note: direction is a unit vector pointing towards the target of the camera)
vec3 Camera::Direction(void){
	return normalize(target - position);
}

// Sets the direction of this camera (note: direction is a unit vector pointing towards the target of the camera)
void Camera::Direction(vec3 direction){
	target = position + direction;
	view = lookAt(position, target, up);
}

// Gets the target of this camera (the point in the world where the camera points towards)
vec3 Camera::Target(void){
	return target;
}

// Sets the target of this camera (the point in the world where the camera points towards)
void Camera::Target(vec3 target){
	this->target = target;
	view = lookAt(position, target, up);
}

// Gets the distance between the camera and its target
float Camera::DistanceToTarget(void){
	return float((target - position).length());
}

// Sets the distance between the camera and its target
void Camera::DistanceToTarget(float distance){
	this->Target(distance * (position + this->Direction()));
}

// Gets the up vector of this camera
vec3 Camera::Up(void){
	return up;
}

// Sets the up vector of this camera
void Camera::Up(vec3 up){
	this->up = up;
	view = lookAt(position, target, up);
}

// Gets the movement direction of this camera (does not affect the image rendered)
vec3 Camera::MovementDirecion(void){
	return movementDirection;
}

// Sets the movement direction of this camera (does not affect the image rendered)
void Camera::MovementDirecion(vec3 direction){
	this->movementDirection = direction;
}

// Gets the angular speed of this camera (speed with which this camera rotates)
float Camera::AngularSpeed(void){
	return angularSpeed;
}

// Sets the angular speed of this camera (speed with which this camera rotates)
void Camera::AngularSpeed(float speed){
	this->angularSpeed = speed;
}

// Gets the movement speed of this camera (speed with which this camera moves)
float Camera::MovementSpeed(void){
	return movementSpeed;
}

// Sets the movement speed of this camera (speed with which this camera moves)
void Camera::MovementSpeed(float speed){
	this->movementSpeed = speed;
}


// Methods

// Given a model matrix, returns the MVP matrix
mat4 Camera::ModelViewProjection(mat4 model){
	return projection * view * model;
}

//Rotate this camera around itself in the axis defined by the up vector
void Camera::RotateUp(float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	Direction(glm::rotate(this->Direction(), angularSpeed * deltaTime * direction, up));
}

//Rotate this camera around itself in the axis defined by the up vector using the specified angular speed
void Camera::RotateUp(float andgularSpeed, float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	Direction(glm::rotate(this->Direction(), angularSpeed * deltaTime * direction, up));
}

// Rotate this camera around itself in the Y-axis
void Camera::RotateY(float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	Direction(glm::rotate(this->Direction(), angularSpeed * deltaTime * direction, vec3(0, 1, 0)));
}

// Rotate this camera around itself in the Y-axis using the specified angular speed
void Camera::RotateY(float angularSpeed, float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	Direction(glm::rotate(this->Direction(), angularSpeed * deltaTime * direction, vec3(0, 1, 0)));
}

// Rotate this camera around its target in the Y-axis
void Camera::RotateAroundTarget(float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	vec3 buffer = position - target;

	position = position + glm::rotate(buffer, angularSpeed * deltaTime * direction, vec3(0, 1, 0));
	Direction(target - position);
}

// Rotate this camera around its target in the Y-axis with the specified angular speed
void Camera::RotateAroundTarget(float angularSpeed, float deltaTime, bool clockwise){
	int direction = clockwise ? -1 : 1;
	vec3 buffer = position - target;

	position = position + glm::rotate(buffer, angularSpeed * deltaTime * direction, vec3(0, 1, 0));
	Direction(target - position);
}