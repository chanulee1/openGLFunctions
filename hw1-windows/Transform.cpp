// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
  // You will change this return call
	const float radians = degrees * pi / 180;
	const float x(axis.x), y(axis.y), z(axis.z);
	const mat3 rotationMatrix = cos(radians) * mat3(1.0) + (1 - cos(radians)) * mat3(x * x, x * y, x * z, x * y, y * y, y * z, x * z, y * z, z * z) + sin(radians) * mat3(0, z, -y, -z, 0, x, y, -x, 0);
  return rotationMatrix;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	//printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	//printf("Coordinates: %.2f, %.2f, %.2f; length: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
	eye = rotate(degrees, up) * eye;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	const vec3 axis = glm::normalize(glm::cross(eye, up));
	eye = rotate(degrees, axis) * eye;
	up = glm::normalize(glm::cross(axis, eye));
	printf("Eye Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	printf("Up Coordinates: %.2f, %.2f, %.2f; length: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
	printf("Axis Coordinates: %.2f, %.2f, %.2f; length: %.2f\n", axis.x, axis.y, axis.z, sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
	const vec3 w = glm::normalize(eye);
	const vec3 u = glm::normalize(glm::cross(up, w));
	const vec3 v = glm::cross(w, u);
	const vec3 translate = -eye+vec3(0.0, 0.0, -4.0);
	const mat4 finalResult = mat4(u.x, v.x, w.x, 0, u.y, v.y, w.y, 0, u.z, v.z, w.z, 0, glm::dot(u, translate), glm::dot(v, translate), glm::dot(w, translate), 1);
  // You will change this return call
  return finalResult;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}