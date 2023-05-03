#include "Engine.h"

Engine::Engine()
{
	float width = VideoMode::getDesktopMode().width;
	float height = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(width, height), "Particles", Style::Fullscreen);
}

void Engine::run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete. Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		Time dT = clock.restart();
		float secs = dT.asSeconds();

		input();
		update(secs);
		draw();

	}
}

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}

		/*if (event.type == Event::MouseButtonPressed)
		{
			mouseClick = window.mapPixelToCoords(Mouse::getPosition(), plane.getView());

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				plane.zoomIn();
				plane.setCenter(mouseClick);
			}
			if (Mouse::isButtonPressed(Mouse::Right))
			{
				plane.zoomOut();
				plane.setCenter(mouseClick);

			}
			state = State::CALCULATING;
		}
		if (event.type == Event::MouseMoved)
		{
			mousePosition = window.mapPixelToCoords(Mouse::getPosition(), plane.getView());
			plane.setMouseLocation(mousePosition);
		}*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Window.close();
		}
	}
	
}

void Engine::update(float dtAsSeconds)
{

}

void Engine::draw()
{
	m_Window.clear();
	
	m_Window.display();
}