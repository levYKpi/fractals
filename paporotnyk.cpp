#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <deque>

sf::Vector2f tmp_pos;

sf::CircleShape tmp;
std::deque<sf::CircleShape> points;

void add_point(int a){
	tmp.setRadius(1.f);
	tmp.setFillColor(sf::Color::Green);
	if(a<1){tmp_pos.x =100+ 0;
			tmp_pos.y =-100+ 0;}
	else if(a<8){tmp_pos.x =100+ 0.2*tmp_pos.x - 0.26*tmp_pos.y;
				 tmp_pos.y =-100+ 0.23*tmp_pos.x +0.22*tmp_pos.y +1.6;}
	else if(a<15){tmp_pos.x =100+ 0.15*tmp_pos.x + 0.28*tmp_pos.y;
				  tmp_pos.y =-100+ 0.26*tmp_pos.x +0.24*tmp_pos.y +0.44;}
	else{tmp_pos.x =100+ 0.85*tmp_pos.x + 0.04*tmp_pos.y;
		 tmp_pos.y =-100+ - 0.04*tmp_pos.x + 0.85*tmp_pos.y +1.6;}
	tmp.setPosition(-tmp_pos.y*1.5,200+tmp_pos.x/1.5);
	points.push_back(tmp);
}

int main()
{
	srand(time(0));
	// = sf::Mouse::getPosition();
    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
    sf::CircleShape point1;
    point1.setRadius(2.f);
    //shape.setFillColor(sf::Color::Green);
	int j = 0;
	int f = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				f++;
			}
			
        }
        if(f > 0)
			if(j <= 100000000){
				j++;
				add_point(rand()%100);
			}
		
        window.clear();
        int siz = points.size();
        for(int k = 0; k < siz; k++){
			window.draw(points[k]);
		}
        window.draw(point1);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				break;
		}
    }

    return 0;
}
