#include <imgui\imgui.h>
#include <imgui\imgui_impl_glfw_gl3.h>

bool show_test_window =true;
void GUI() {
	{	//FrameRate
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		//TODO
	}

	// ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

bool euler = true, font=true;

float actualPos[3], nextPos[3], pastPos[3], newSpeed[3],actualSpeed[3], totalForce[3];

float time = 0.0333;



void PhysicsInit() {
	//TODO
	//Hay que darle valores a la posicion y a la velocidad si ed font si no solo a la posicion
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
	if (euler) {
		for (int i = 0; i < 3; i++) {
			newSpeed[i] = actualSpeed[i] + time*totalForce[i];
			actualSpeed[i] = newSpeed[i];
			actualPos[i] = nextPos[i];
			nextPos[i] = actualPos[i] + time + actualSpeed[i];
		}
	}
}
void PhysicsCleanup() {
	//TODO
}