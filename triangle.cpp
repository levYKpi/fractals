#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <deque>

sf::Vector2f mPosition, pos_1, pos_2, pos_3, pos_beg, tmp_pos;

sf::CircleShape tmp;

void add_point(int a){
	tmp.setRadius(1.f);
	switch(a){
		case 0:{tmp_pos.x = (pos_1.x + pos_beg.x)/2;tmp_pos.y = (pos_1.y + pos_beg.y)/2;break;}
		case 1:{tmp_pos.x = (pos_2.x + pos_beg.x)/2;tmp_pos.y = (pos_2.y + pos_beg.y)/2;break;}
		case 2:{tmp_pos.x = (pos_3.x + pos_beg.x)/2;tmp_pos.y = (pos_3.y + pos_beg.y)/2;break;}
	};
	pos_beg = tmp_pos;
	tmp.setPosition(pos_beg.x,pos_beg.y);
	//points.push_back(tmp);
}

int main()
{
	srand(time(0));
	// = sf::Mouse::getPosition();
    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML works!");
    sf::CircleShape point1, point2, point3, beg_point;
    //shape.setFillColor(sf::Color::Green);
	point1.setRadius(2.f);
	point2.setRadius(2.f);
	point3.setRadius(2.f);
	beg_point.setRadius(2.f);
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
				mPosition = (sf::Vector2f)sf::Mouse::getPosition(window);
				f++;
			}
			if (f == 1)
				{point1.setPosition(mPosition.x, mPosition.y); pos_1 = mPosition;}
			else if (f == 2)
				{point2.setPosition(mPosition.x, mPosition.y); pos_2 = mPosition;}
			else if (f == 3)
				{point3.setPosition(mPosition.x, mPosition.y); pos_3 = mPosition;}
			else if (f == 4)
				{beg_point.setPosition(mPosition.x, mPosition.y); pos_beg = mPosition; f++;}
			
        }
        window.draw(point1);
        window.draw(point2);
        window.draw(point3);
        window.draw(beg_point);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				break;
		}
		window.display();
		if(f > 4)
		{
				j++;
				add_point(rand()%3);
				usleep( (int)(1000000/j) );//!!!!!!!!!!!!!!!!!!!!!!
			window.draw(tmp);
		}
		else
			{window.clear();}
    }

    return 0;
}
