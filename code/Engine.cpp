#include "Engine.h"
#include <vector>

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

	int max = 50;
	int min = 25;

	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Window.close();
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				int numPoints = rand() % (max - min + 1) + min;

				/*How many do we want to construct*/
				for (int i = 0; i < 5; i++)
				{
					Particle goingIntoArray(m_Window, numPoints, Mouse::getPosition());
					m_particles.push_back(goingIntoArray);
				}
			}
		}
	}
	
}

void Engine::update(float dtAsSeconds)
{
	//Strugling with the iterator
	vector<Particle>::iterator it;
	int i = 0;
	for ( it = m_particles.begin(); it != m_particles.end();)
	{
		if (m_particles.at(i).getTTL() > 0)
		{
			m_particles.at(i).update(dtAsSeconds);
			it++;
			i++;
		}
		else
		{
			it = m_particles.erase(it);
		}
	}
}

void Engine::draw()
{
	m_Window.clear();
	
	for (Particle p : m_particles)
	{
		m_Window.draw(p);
	}
	
	m_Window.display();
}