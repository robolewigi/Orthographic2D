//Dec 21 2023
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define pi 3.14159265359;


sf::RenderWindow window;
sf::Event event;
sf::Keyboard keyboard;
sf::View view;
struct Actor;
float Speed=0.1f;
clock_t current_ticks,delta;
clock_t frames = 0;
sf::VertexArray triangles(sf::TriangleStrip, 0);
int points;

struct vec3
{
float x,y,z;
    vec3 operator + (vec3 vecc)
    {
        vec3 new_vec;
        new_vec.x = x + vecc.x;
        new_vec.y = y + vecc.y;
		new_vec.z = z + vecc.z;
        return new_vec;
    }
   vec3 operator * (vec3 vecc)
    {
        vec3 new_vec;
        new_vec.x = x * vecc.x;
        new_vec.y = y * vecc.y;
		new_vec.z = z * vecc.z;
        return new_vec;
    }
};

vec3 Screen={512, 512, 0};
vec3 Camera={-1,-1,-1};

void fpsTick(int x){
    switch (x){// your main loop. could also be the idle() function in glut or whatever
    case 0:
    current_ticks = clock();
    break;
    case 1:

    delta = clock() - current_ticks; //the time, in ms, that took to render the scene
    if(delta > 0)
        frames = CLOCKS_PER_SEC / delta;
    std::cout << frames << "\n";
    break;}
}

struct Actor
{
		float size=188;
		int startVertex;//=triangles.getVertexCount();
		vec3 location;
	vec3 loc[8];
	vec3 sLoc[8];
	
	void Begin()
	{
		vec3 sizeVec={size,size*2,size/1000};
		//Starts on left top front rotates right 
		for(int i =0 ; i<8;i++)
	{	
			loc[i].x = (i % 2)*2-1;
			loc[i].y = (i / 2) % 2; ((i / 2)%2)*2-1;
		loc[i].z = (i>3)*2-1;
		loc[i] = loc[i] * sizeVec + location;
	}
	
	triangles.resize(startVertex+36);


	}
	
	void Update()
	{for(int i =0;i<8;i++){
		sLoc[i].z=Camera.z / (Camera.z+loc[i].z);
		
		
	sLoc[i].x = (loc[i].x * sLoc[i].z) + Screen.x + (-Camera.x * sLoc[i].z);
	sLoc[i].y = (loc[i].y * sLoc[i].z) + Screen.y+ (-Camera.y * sLoc[i].z);}
	//triangles[i+startVertex].color = sf::Color(255,255,255,-loc[i].z/Camera.z*255);
	//triangles[i+startVertex].position=sf::Vector2f(sLoc[i].x,sLoc[i].y);
	
	
/*		if(sLoc[i].z >=1  )
	{
		}
	}	 */   
	//left
	triangles[0].position = sf::Vector2f(sLoc[4].x, sLoc[4].y);
     triangles[1].position = sf::Vector2f(sLoc[0].x, sLoc[0].y);
     triangles[2].position = sf::Vector2f(sLoc[6].x, sLoc[6].y);
     triangles[3].position = sf::Vector2f(sLoc[6].x, sLoc[6].y);
     triangles[4].position = sf::Vector2f(sLoc[0].x, sLoc[0].y);
     triangles[5].position = sf::Vector2f(sLoc[2].x, sLoc[2].y);
	//right
		triangles[6].position = sf::Vector2f(sLoc[1].x, sLoc[1].y);
     triangles[7].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[8].position = sf::Vector2f(sLoc[3].x, sLoc[3].y);
     triangles[9].position = sf::Vector2f(sLoc[3].x, sLoc[3].y);
     triangles[10].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[11].position = sf::Vector2f(sLoc[7].x, sLoc[7].y);
	//top
		triangles[12].position = sf::Vector2f(sLoc[4].x, sLoc[4].y);
     triangles[13].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[14].position = sf::Vector2f(sLoc[0].x, sLoc[0].y);
     triangles[15].position = sf::Vector2f(sLoc[0].x, sLoc[0].y);
     triangles[16].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[17].position = sf::Vector2f(sLoc[1].x, sLoc[1].y);
	//bottom
		triangles[18].position = sf::Vector2f(sLoc[6].x, sLoc[6].y);
     triangles[19].position = sf::Vector2f(sLoc[7].x, sLoc[7].y);
     triangles[20].position = sf::Vector2f(sLoc[2].x, sLoc[2].y);
     triangles[21].position = sf::Vector2f(sLoc[2].x, sLoc[2].y);
     triangles[22].position = sf::Vector2f(sLoc[7].x, sLoc[7].y);
     triangles[23].position = sf::Vector2f(sLoc[3].x, sLoc[3].y);
	//front
	triangles[24].position = sf::Vector2f(sLoc[0].x, sLoc[0].y);
     triangles[25].position = sf::Vector2f(sLoc[1].x, sLoc[1].y);
     triangles[26].position = sf::Vector2f(sLoc[2].x, sLoc[2].y);
     triangles[27].position = sf::Vector2f(sLoc[2].x, sLoc[2].y);
     triangles[28].position = sf::Vector2f(sLoc[1].x, sLoc[1].y);
     triangles[29].position = sf::Vector2f(sLoc[3].x, sLoc[3].y);
	//back
		triangles[30].position = sf::Vector2f(sLoc[4].x, sLoc[4].y);
     triangles[31].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[32].position = sf::Vector2f(sLoc[6].x, sLoc[6].y);
     triangles[33].position = sf::Vector2f(sLoc[6].x, sLoc[6].y);
     triangles[34].position = sf::Vector2f(sLoc[5].x, sLoc[5].y);
     triangles[35].position = sf::Vector2f(sLoc[7].x, sLoc[7].y);
	 for (int i=0; i<36;i++){
		triangles[i].color = sf::Color(i/6*55,i/6*55,i/6*55,/*-loc[i].z/Camera.z**/255);
}
	}

};


Actor Actors[1];



struct map
{
int MapSize = 1024;
sf::Image image; sf::Texture texture; sf::Sprite sprite;
float Near=.01f,Far=0.1f;
float FovHalf = 3.14159f / 4;
float WorldX,WorldY,WorldA;

void Begin()
{
	image.create(MapSize,MapSize,sf::Color(0,0,0,255));
texture.loadFromImage(image);
	sprite.setTexture(texture,true);

for(int x=0; x < MapSize; x += 32){
	for(int y=0;y < MapSize; y++){
		if(x>=1 && y>=1 && x<=MapSize-1 && y){
		image.setPixel(x,y,sf::Color::Magenta);
		image.setPixel(x+1,y,sf::Color::Magenta);
		image.setPixel(x-1,y,sf::Color::Magenta);

		image.setPixel(y,x,sf::Color::Blue);
		image.setPixel(y,x+1,sf::Color::Blue);
		image.setPixel(y,x-1,sf::Color::Blue);
		}}}

}

void Update(){
	float FarX1 = WorldX + cosf(WorldA- FovHalf) * Far;
	float FarY1 = WorldY + sinf(WorldA - FovHalf) * Far;
														
	float FarX2 = WorldX + cosf(WorldA + FovHalf) * Far;
	float FarY2 = WorldY + sinf(WorldA + FovHalf) * Far;

		float NearX1 = WorldX + cosf(WorldA - FovHalf) * Near;
	float NearY1 = WorldY + sinf(WorldA - FovHalf) * Near;

		float NearX2 = WorldX + cosf(WorldA + FovHalf) * Near;
	float NearY2 = WorldY + sinf(WorldA + FovHalf) * Near;

	for (int y = 0; y< Screen.y / 2; y++){
	float SampleDepth = float(y)/ (float)(Screen.y / 2.f);
	
	float StartX = (FarX1 - NearX1) / (SampleDepth) + NearX1;
			float StartY = (FarX1 - NearX1) / (SampleDepth) + NearY1;
			float EndX = (FarX2 - NearX2) / (SampleDepth) + NearX2;
			float EndY = (FarY2 - NearY2) / (SampleDepth) + NearY2;

			// Linearly interpolate lines across the screen
			for (int x = 0; x < Screen.x; x++)
			{float SampleWidth = (float)x / (float)Screen.x;
			float SampleX = (EndX - StartX) * SampleWidth + StartX;
				float SampleY = (EndY - StartY) * SampleWidth + StartY;

			image.setPixel(x, y + (Screen.y / 2), sf::Color::Green);		


			}
	}
	sprite.setTextureRect(sf::IntRect(0,0,222,222));
	texture.update(image);
window.draw(sprite);}
};

void ButtonLive()
{
	if(delta >0){
	if(keyboard.isKeyPressed(sf::Keyboard::Key::LShift))
		{Speed=1*delta;
	}else{Speed=.1*delta;}
	}
		if(keyboard.isKeyPressed(sf::Keyboard::Key::A))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].x+=Speed;}
		}
		if (keyboard.isKeyPressed(sf::Keyboard::Key::D))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].x-=Speed;}
		}
		if (keyboard.isKeyPressed(sf::Keyboard::Key::W))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].z+=Speed/22;}
		}
		if (keyboard.isKeyPressed(sf::Keyboard::Key::S))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].z-=Speed/22;}
		}
				if(keyboard.isKeyPressed(sf::Keyboard::Key::Q))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].x+=Speed;}
		}
						if(keyboard.isKeyPressed(sf::Keyboard::Key::Q))
		{for(int i = 0;i<8;i++){
			Actors[0].loc[i].x+=Speed;}
		}
}

int main()
{
		srand((unsigned) time(NULL));
	window.create(sf::VideoMode(Screen.x, Screen.y), "SFML tutorial", sf::Style::Close | sf::Style::Resize);

	map Game; Game.Begin();

	//view.setCenter(0,0);
	
	for(int i =0; i<1; i++)
	{Actors[i].Begin();
	}

		sf::VertexArray lines(sf::LinesStrip, 2);


	while (window.isOpen())
	{
		fpsTick(0);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
			}}
		
	ButtonLive();


		window.setView(sf::View(view));
		window.clear();
			for(int i =0; i<1; i++)
	{Actors[i].Update();
	}

	//Game.Update();
			window.draw(triangles);
			window.draw(lines);
		window.display();
			fpsTick(1);
	}

	return 0;
}