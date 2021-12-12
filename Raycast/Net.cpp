
#include "Net.h" 



int main()
{
	
	srand(time(NULL)); 
	initNet();
	initGrid(); 
	
	sf::RenderWindow window(sf::VideoMode(width	, height ), "NNVisulization"); 
	sf::Event ev; 
	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{

			switch (ev.type)
			{
			case sf::Event::Closed: 
				window.close(); 

				break; 
			case sf::Event::KeyPressed: 
				switch (ev.key.code)
				{
				case sf::Keyboard::Escape: 
					window.close(); 
					return 0; 
					//ends program
					break; 
				}

				break; 
			}
		}


		//updates 
		update(); 


		//render 
		window.clear(sf::Color::White); 
		draw(&window); 
		window.display(); 

	}
	return 0; 
}