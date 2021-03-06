/*
* IDENTIFIERING
*
* Filnamn:    TextureHandler.cpp
* Enhetsnamn: TextureHandler
* Typ:        Definitioner hörande till klass TextureHandler
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner för klassen TextureHandler.
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

#include "TextureHandler.h"

using namespace std;

/*
* KONSTRUKTOR TextureHandler()
*
* BESKRIVNING
*
* Denna konstruktor skapar en texturhanterare genom anrop av loadTexture.
*
* INDATA
*
* -
*
* UTDATA
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

TextureHandler::TextureHandler()
{
	loadTexture("void", "res/textures/voidtile.png");

	//Tiles
	loadTexture("grass", "res/textures/grass.png");
	loadTexture("grassTree", "res/textures/grassTree.png");
	loadTexture("bridge", "res/textures/bridge.png");
	loadTexture("mountainGrass", "res/textures/mountainGrass.png");
	loadTexture("water", "res/textures/water.png");
	loadTexture("snow", "res/textures/snow.png");
	loadTexture("snowTree", "res/textures/snowTree.png");
	loadTexture("snowChest", "res/textures/snowChest.png");
	loadTexture("grassStump", "res/textures/grassStump.png");
	loadTexture("sand", "res/textures/sand.png");
	loadTexture("palmtree", "res/textures/palmtree.png");
	loadTexture("cactus", "res/textures/cactus.png");
	loadTexture("lava", "res/textures/lava.png");
	loadTexture("burnedTree", "res/textures/burnedTree.png");
	loadTexture("lavastone", "res/textures/lavastone.png");
	loadTexture("grassBurnedTree", "res/textures/grassBurnedTree.png");
	loadTexture("burnedGround", "res/textures/burnedGround.png");
	loadTexture("fountain", "res/textures/fountain.png");
	loadTexture("grassStone", "res/textures/grassStone.png");
	loadTexture("noneWalkableSand", "res/textures/noneWalkableSand.png");

	//Items
	loadTexture("grassTreeChoppable", "res/textures/grassTreeChoppable.png");
	loadTexture("pickAxe", "res/textures/pickAxe.png");
	loadTexture("energyRing", "res/textures/energyRing.png");
	loadTexture("armour", "res/textures/armour.png");
	loadTexture("amulet", "res/textures/amulet.png");
	loadTexture("magicFireOrb", "res/textures/magicFireOrb.png");
	loadTexture("magicWaterCalice", "res/textures/magicWaterCalice.png");

	//Player
	loadTexture("player", "res/textures/player.png");

	//Enemies
	loadTexture("minotaur", "res/textures/minotaurEnemy.png");
	loadTexture("ghost", "res/textures/ghostEnemy.png");
	loadTexture("superGhost", "res/textures/SuperGhostEnemy.png");
	loadTexture("demon", "res/textures/woodEnemy.png");
	loadTexture("blueWind", "res/textures/blueWind.png");
	loadTexture("redWizard", "res/textures/redWizardEnemy.png");
	loadTexture("blueWizard", "res/textures/blueWizardEnemy.png");
	loadTexture("badAlloc", "res/textures/badAlloc.png");
	loadTexture("snowWolf", "res/textures/snowWolfEnemy.png");
	loadTexture("fire", "res/textures/fire.png");
	loadTexture("yourEx", "res/textures/girlEnemy.png");

	//NPC
	loadTexture("bridgeguard", "res/textures/NPC1.png");
	loadTexture("NPC1", "res/textures/NPC1.png");
	loadTexture("warrior", "res/textures/NPC2.png");
	loadTexture("citizenWoman3", "res/textures/NPC3.png");
	loadTexture("NPC4", "res/textures/NPC4.png");
	loadTexture("NPC5", "res/textures/NPC5.png");
	loadTexture("NPC6", "res/textures/NPC6.png");
	loadTexture("cityPriest", "res/textures/NPC7.png");
	loadTexture("saveNPC", "res/textures/saveNPC.png");
	loadTexture("Firimaniums", "res/textures/Firimaniums.png");
	loadTexture("brokenFountain", "res/textures/brokenFountain.png");
	loadTexture("citizenWoman1", "res/textures/citizenWoman1.png");
	loadTexture("citizenWoman2", "res/textures/citizenWoman2.png");
	loadTexture("citizenMan1", "res/textures/citizenMan1.png");
	loadTexture("citizenMan2", "res/textures/citizenMan2.png");
	loadTexture("citizenBoy1", "res/textures/citizenBoy1.png");
	loadTexture("citizenBoy2", "res/textures/citizenBoy2.png");
	loadTexture("citizenGirl1", "res/textures/citizenGirl1.png");
	loadTexture("citizenGirl2", "res/textures/citizenGirl2.png");

	//House
	loadTexture("house00", "res/textures/house00.png");
	loadTexture("house01", "res/textures/house01.png");
	loadTexture("house02", "res/textures/house02.png");
	loadTexture("house03", "res/textures/house03.png");
	loadTexture("house10", "res/textures/house10.png");
	loadTexture("house11", "res/textures/house11.png");
	loadTexture("house12", "res/textures/house12.png");
	loadTexture("house13", "res/textures/house13.png");
	loadTexture("house20", "res/textures/house20.png");
	loadTexture("house21", "res/textures/house21.png");
	loadTexture("house22", "res/textures/house22.png");
	loadTexture("house23", "res/textures/house23.png");
	loadTexture("house30", "res/textures/house30.png");
	loadTexture("house31", "res/textures/house31.png");
	loadTexture("house32", "res/textures/house32.png");
	loadTexture("house33", "res/textures/house33.png");
}

/*
* DESTRUKTOR ~TextureHandler()
*
* BESKRIVNING
*
* Denna destruktor tar bort texturhanteraren samt alla sparade texturer.
*
* INDATA
*
* -
*
* UTDATA
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

TextureHandler::~TextureHandler()
{
	while (!textures_.empty())
	{
		auto it = textures_.begin();
		delete it->second;
		textures_.erase(it);
	}
}

/*
* FUNKTION TextureHandler::getTextureRef(const std::string& ref)
*
* BESKRIVNING
*
* Uppdaterar NPC:n.
*
* INDATA
*
* ref: Sträng motsvarande texturen vi vill ha.
*
* UTDATA
*
* Texture&:	Referens till textur.
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/

sf::Texture & TextureHandler::getTextureRef(const std::string& ref)
{
	return (*textures_.find(ref)->second);
}

/*
* FUNKTION TextureHandler::loadTexture(const std::string& texName, const std::string& fileName)
*
* BESKRIVNING
*
* Laddar in texturer från fil och lagrar i TextureTablen.
*
* INDATA
*
* ref: Sträng motsvarande texturen vi vill ha.
*
* UTDATA
*
* Texture&:	Referens till texturen.
*
* REVISIONSBERÄTTELSE
*
* Revision             Datum           Förändringar
*
* 1                    151214          Ursprungsversion
*
*/

void TextureHandler::loadTexture(const std::string& texName, const std::string& fileName)
{
	sf::Texture* tex = new sf::Texture;
	if (!tex->loadFromFile(fileName))
	{
		throw TextureException("Kunde inte ladda in textur från fil:" + fileName);
	}
	textures_.emplace(texName, tex);
}

/*
* SLUT PÅ FILEN TextureHandler.cpp
*/