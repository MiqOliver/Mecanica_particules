#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw_gl3.h>

bool show_test_window = true;
void GUI() {
	{	//FrameRate
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		//TODO
	}

	// ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if (show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

enum Integration { EULER, VERLET };
Integration integration = VERLET;
bool font = true;

float previousPos[3], actualPos[3], nextPos[3], pastPos[3], newSpeed[3], actualSpeed[3], totalForce[3];

float time = 0.0333;
float acceleration = -9'81;
float mass = 1;


void PhysicsInit() {
	//TODO
	//Hay que darle valores a la posicion y a la velocidad si ed font si no solo a la posicion
	previousPos[0] = 0;
	previousPos[1] = 0;
	previousPos[2] = 0;
	actualPos[0] = 0;
	actualPos[1] = 0;
	actualPos[2] = 0;
	nextPos[0] = actualPos[0];
	nextPos[1] = actualPos[1];
	nextPos[2] = actualPos[2];


	actualSpeed[0] = 0;
	actualSpeed[1] = 0;
	actualSpeed[2] = 0;
	totalForce[0] = 0;
	totalForce[1] = -9.81;
	totalForce[2] = 0;
}
void PhysicsUpdate(float dt) {
	//TODO
	//ParticleSpawn

	//The way it calculates the position of the particles
	switch (integration)
	{
	case EULER:
		for (int i = 0; i < 3; i++) {
			newSpeed[i] = actualSpeed[i] + time*totalForce[i];
			actualSpeed[i] = newSpeed[i];
			actualPos[i] = nextPos[i];
			nextPos[i] = actualPos[i] + time + actualSpeed[i];
		}
		break;
	case VERLET:
		for (int i = 0; i < 3; i++)
		{
			//calculating new position
			nextPos[i] = 2 * actualPos[i] - previousPos[i] + (totalForce[i] / mass) * time * time;
			//calculating new speed
			newSpeed[i] = (nextPos[i] - actualPos[i]) / time;
			//setting values
			previousPos[i] = actualPos[i];
			actualPos[i] = nextPos[i];
			actualSpeed[i] = newSpeed[i];
		}
		break;
	default:
		break;
	}
}
void PhysicsCleanup() {
	//TODO
}