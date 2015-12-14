/* IDENTIFIERING
*
* Filnamn:    Sensor.cpp
* Enhetsnamn: Sensor
* Typ:        Definitioner hörande till klass Sensor
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner för klassen Sensor.
*
* REVISIONSBERÄTTELSE
*
* Revision     Datum   Förändringar
*
* 1            151214  Ursprungsversion
*/

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include "Sensor.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"
#include <iostream>

using namespace std;

/*
* KONSTRUKTOR Sensor(int ID, std::string name, sf::Vector2f position, World * worldPtr, std::function<void(World*)> callbackFunc, sf::Texture& tex)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en sensor.
*
* INDATA
*
* ID:			Sensorns ID.
* name:			Sensorns namn.
* position:		Sensorns position.
* worldPtr:		Pekare till sensorns värld.
* callbackFunc:	Sensorns callbackfunktion.
* tex:			Sensorns textur.
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* -
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/

Sensor::Sensor(int ID, std::string name, sf::Vector2f position, World * worldPtr, std::function<void(World*)> callbackFunc, sf::Texture& tex)
	: Entity(0, 0, 0, ID, name, position, worldPtr, tex), 
	callback_{ callbackFunc }
{
}

/*
* FUNKTION Sensor::update()
*
* BESKRIVNING
*
* Uppdaterar Sensorn.
*
* INDATA
*
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* -
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/

void Sensor::update()
{
}

/*
* FUNKTION NPC::render()
*
* BESKRIVNING
*
* render-funktionen är tom, sensorer ritas inte upp.
*
* INDATA
*
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* -
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/
void Sensor::render(GameWindow & window)
{
}

/*
* FUNKTION NPC::trigger()
*
* BESKRIVNING
*
* Triggar igång callbackfunktionen.
*
* INDATA
*
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* -
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/
void Sensor::trigger()
{
	callback_(worldPointer_);
}

/*
* FUNKTION NPC::update()
*
* BESKRIVNING
*
* Die-funktionen är tom, sensorer skall inte gå att döda.
*
* INDATA
*
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* -
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/

void Sensor::die()
{
}

/*
* SLUT PÅ FILEN Sensor.cpp
*/
