#ifndef PDS2_WIZARD_H
#define PDS2_WIZARD_H

#include "character.h"
#include "spells.h"
#include "potions.h"
#include "artifacts.h"
#include <string>
#include <vector>

class Wizard : public Character{
 protected:
	std::string _house;
	std::string _wand;
	std::string _patronum;
	int _skillPoints ;
	std::vector<Potions *> _potionsVector;
	std::vector<Artifacts *> _artifactsVector;

 public:
  	Wizard(std::string name, int level, int hp, int mp, int str , int cons, int dex, std::string house, std::string wand, std::string patronum, std::vector<Spell *> _spells, std::vector<Potions *> _potions, std::vector<Artifacts *> _artifacts);
	~Wizard();

	std::vector<Potions *> instantiate_potions(std::vector<Potions *> _potions);
	std::vector<Artifacts *> instantiate_artifacts(std::vector<Artifacts *> _artifacts);

	std::string getHouse();
	std::string getWand();
	std::string getPatronum();
	std::vector<Spell *> getSpellVector();  
	std::vector<Potions *> getPotionsVector();
	std::vector<Artifacts *> getArtifactsVector();

	void printPlayerSpells();
	void printPlayerPotions();
	void printPlayerArtifacts();

	void set_quantPotions(std::vector<Potions *> potion, int i, int quant);
	void incrementSkill(int selection);
};
#endif
