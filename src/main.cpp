#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1280, 720)), "SFML + ImGui Template");
    ImGui::SFML::Init(window);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_::ImGuiConfigFlags_DockingEnable;

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time deltaTime = deltaClock.restart();

        ImGui::SFML::Update(window, deltaTime);
		
        ImGui::ShowDemoWindow();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}