#include "game.h"
#include "battle.h"
#include "character.h"
#include "wizard.h"
#include <iostream>
#include <stdlib.h>
#include <cctype>

bool StringValidation(std::string myString){
	for(unsigned int i = 0; i < myString.size(); i++){
		if(!isalpha(myString[i])){
			throw InvalidStringException();
			return false;
		}
	}
	return true;
}

void myPause(){
	do{
    	std::cout << "Press ENTER  to continue!" << std::endl;
    	std::cin.get();
  	}while(std::cin.get() != '\n');
}

std::vector<Spell *> instantiate_spell(){
    std::vector<Spell *> spell;
	Spell *Expelliarmus = new Spell(2, "Expelliarmus", 1, -30, -40, -2, -1, 0);
	Spell *ExpectroPatronum = new Spell(2, "Expectro Patronum", 3, -50, -20, -20, -30, -40);
	Spell *Lumus = new Spell(2, "Lumus", 1, 0, 10, 0, -1, 0);
	Spell *Nox = new Spell(2, "Nox", 1, 0, 10, 0, -1, 0);
	Spell *Protego = new Spell(2, "Protego", 1, 0, 40, 0, -1, 0);
	Spell *WingardiumLeviosa = new Spell(2, "Wingardium Leviosa", 1, 0, 20, 0, -1, 0);
	Spell *Incendio = new Spell(2, "Incendio", 2, 0, -40, -20, -1, 0);
	Spell *Rictusempra = new Spell(2, "Rictusempra", 2, -50, 0, 0, -1, 0);	
	Spell *Imobbilius = new Spell(2, "Imobbilius", 4, -30, -50, 0, -1, 0);
	Spell *Estupefaca = new Spell(2, "Estupefaca", 4, -50, -40, 0, -1, 0);
	Spell *PetrificusTotalus = new Spell(2, "Petrificus Totalus", 4, 0, -50, -40, -1, 0);
	Spell *Sectusempra = new Spell(2, "Sectusempra", 4, -60, -60, 0, -1, 0);
	Spell *Obscuro = new Spell(2, "Obscuro", 4, -30, -30, 0, -1, 0);
	Spell *Crucio = new Spell(2, "Crucio", 5, -70, -70, 0, -1, 0);
	Spell *AvadaKedavra = new Spell(2, "Avada Kedavra", 5, -100, -100, 0, -1, 0);


	spell.push_back(Expelliarmus);
	spell.push_back(ExpectroPatronum);
	spell.push_back(Lumus);
	spell.push_back(Nox);
	spell.push_back(Protego);
	spell.push_back(WingardiumLeviosa);
	spell.push_back(Incendio);
	spell.push_back(Rictusempra);
	spell.push_back(Imobbilius);
	spell.push_back(Estupefaca);
	spell.push_back(PetrificusTotalus);
	spell.push_back(Sectusempra);
	spell.push_back(Obscuro);
	spell.push_back(Crucio);
	spell.push_back(AvadaKedavra);

    return spell;
}

std::vector<Artifacts *> instantiate_artifacts(){
	std::vector<Artifacts *> object;

	Artifacts *TimeTurner = new Artifacts(1, "Time-Turner", 2, 0, 0, 0, 0, 0, 1, true, "return");
	Artifacts *Cloak = new Artifacts(2, "Invisibility Cloak", 1, 0, 0, 0, 10, 0, 1, true ,"cloak");
	Artifacts *ElderWand = new Artifacts(3, "Elder Wand", 3, 0, 0, 10, 0, 10, 2, true, "damage");
	Artifacts *ResurrectionStone = new Artifacts(1, "Resurrection Stone", 4, 30, 10, 0, 0, 0, 1, 1, "life");

	object.push_back(TimeTurner);
	object.push_back(Cloak);
	object.push_back(ElderWand);
	object.push_back(ResurrectionStone);

    return object;
}

std::vector<Potions *> instantiate_potions(){
	std::vector<Potions *> object;

	Potions *Invigorate = new Potions(1, "Invigorating Potion", 1, 10, 0, 0, 0, 0, 3);
	Potions *SpiderAntidote = new Potions(1, "Antidote to spider poison", 1, 10, 0, 0, 0, 0, 1);
	Potions *SerpentAntidote = new Potions(1, "Antidote to serpent poison", 1, 10, 0, 0, 0, 0, 1);
	Potions *Strength = new Potions(1, "Strength Potion", 2, 0, 0, 10, 0, 0, 1);
	Potions *Restoration = new Potions (1, "Restoration Potion", 4, 10, 0, 0, 0, 0, 1);
	Potions *Death = new Potions(1, "Death Potion", 5, 0, 0, 0, 0, 0, 1);

	object.push_back(Invigorate);
	object.push_back(SpiderAntidote);
	object.push_back(SerpentAntidote);
	object.push_back(Strength);
	object.push_back(Restoration);
	object.push_back(Death);

    return object;
}

std::vector<specialAttack > instantiate_attack(){
	std::vector<specialAttack > attack;

	specialAttack None = {"NONE", 0, 0, 0, 0, 0, 0};
	specialAttack Sting = {"Sting", 1, -30, -40, -2, -1, 0};
	specialAttack Poison = {"Poison", 1, -30, -40, -2, -1, 0};
	specialAttack DementorsKiss = {"Dementors Kiss",1, -50, -40, -5, -1, 0};
	specialAttack ViolentNature = {"Violent Nature", 1, -30, -40, -2, -1, 0 };

	attack.push_back(None);
	attack.push_back(Sting);
	attack.push_back(Poison);
	attack.push_back(DementorsKiss);
	attack.push_back(ViolentNature);

	return attack;
}

std::string texts1(){
	std::string name ;
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	while (1){
		try{
			std::cout << "Please, enter your wizard/witch's name " << std::endl;
			std::cin >> name;
			if (StringValidation(name) == true)
				break;
		} catch (std::exception &t) {
			std::cout << t.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	std::cout << "Hogwarts School of Witchcraft and Wizardry" << std::endl;
	std::cout << "  ->Headmaster: Albus Dumbledore" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Dear " << name << ", " << std::endl << " " <<std::endl ;
	std::cout << "It is with great pleasure that we're hereby informing that you've been officially admitted in the great Hogwarts School of Witchcraft and Wizardry." << std::endl;
	std::cout << "First things first, you must acquire the necessary books and equipments." << std::endl << " " << std::endl ;
	std::cout << "Yours sincerely, " << std::endl;
	std::cout << "Minerva McGonagall" << std::endl;
	std::cout << std::endl;
	myPause();
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	std::cout << std::endl;
	return name;
}
std::string choice_of_wand(){
	std::cout << "Welcome to Olivanders, here, you shall acquire your very first wand." << std::endl;
	std::vector<std::string> woods;
	woods.push_back("Acacia wood");
	woods.push_back("Alder wood");
	woods.push_back("Apple wood");
	woods.push_back("Aspen wood");
	woods.push_back("Beech wood");
	woods.push_back("Blackthorn wood");
	woods.push_back("Black Walnut wood");
	woods.push_back("Cedar wood");
	woods.push_back("Cherry wood");
	woods.push_back("Chestnut wood");
	woods.push_back("Cypress wood");
	woods.push_back("Dogwood wood");
	woods.push_back("Ebony wood");
	woods.push_back("Elder wood");
	woods.push_back("Elm wood");
	woods.push_back("English Oak wood");
	woods.push_back("Fir wood");
	woods.push_back("Hawthorn wood");
	woods.push_back("Hazel wood");
	woods.push_back("Holly wood");
	woods.push_back("Hornbeam wood");
	woods.push_back("Larch wood");
	woods.push_back("Laurel wood");
	woods.push_back("Maple wood");
	woods.push_back("Pear wood");
	woods.push_back("Pine wood");
	woods.push_back("Poplar wood");
	woods.push_back("Red Oak wood");
	woods.push_back("Redwood wood");
	woods.push_back("Rowan wood");
	woods.push_back("Silver Lime wood");
	woods.push_back("Spruce wood");
	woods.push_back("Sycamore wood");
	woods.push_back("Vine wood");
	woods.push_back("Walnut wood");
	woods.push_back("Willow wood");
	woods.push_back("Yew wood");
	
	std::vector<std::string> cores;
	cores.push_back("Phoenix feathers");
	cores.push_back("Unicorn tail hair");
	cores.push_back("Dragon heartstrings");
	cores.push_back("Thestral tail hair");
	cores.push_back("Chifre de Basilisco");
	cores.push_back("Veela hair");
	cores.push_back("Troll whisker");
	cores.push_back("Basilisk horn");
	cores.push_back("Bone");
	cores.push_back("Shell");
	int number_wood =  rand() % woods.size();
	int number_core =  rand() % cores.size();
	std::string wand = woods[number_wood] + " and " + cores[number_core];
	std::cout << "Your wand is made out of " << wand << std::endl;
	std::cout << std::endl;
	myPause();
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	std::cout << std::endl;
	return wand;

}
std::string choice_of_house(){
	std::cout << "Welcome to Hogwarts. The sorting hat shall decide what house is best suited for you" << std::endl;
	std::vector<std::string> houses;
	houses.push_back("Gryffindor");
	houses.push_back("Slytherin");
	houses.push_back("Ravenclaw");
	houses.push_back("Hufflepuff");
	int number_house = rand() % houses.size();
	std::string house = houses[number_house];
	std::cout << "Your house is: " << house << std::endl;
	std::cout << std::endl;
	myPause();
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	std::cout << std::endl;
	return house;

}

std::string choice_of_patronum(){
	std::vector<std::string> patronuns;
	patronuns.push_back("Rat");
	patronuns.push_back("Phoenix");
	patronuns.push_back("Fox");
	patronuns.push_back("Otter");
	patronuns.push_back("Deer");
	patronuns.push_back("Hare");
	patronuns.push_back("Boar");
	patronuns.push_back("Cat");
	patronuns.push_back("Wolf");
	patronuns.push_back("Horse");
	int number_patronum = rand() % patronuns.size();
	std::string patronum = patronuns[number_patronum];
	std::cout << "Every witch and wizard has their very own patronus, yours shall take the form of a: " << patronum << std::endl;
	std::cout << std::endl;
	myPause();
	std::cout << "\033[2J\033[1;1H"; //This line clear the screen
	std::cout << std::endl;
	return patronum;
}

Wizard* initialize_player(std::vector<Spell *> _spells, std::vector<Potions *> _potions, std::vector<Artifacts *> _artifacts){
	std::string name = texts1();
	std::string wand = choice_of_wand();
	std::string house = choice_of_house();
	std::string patronum = choice_of_patronum();
	Wizard *player = new Wizard(name, 1, 100, 0, 1, 1, 1, house, wand, patronum, _spells, _potions, _artifacts);

	return player;
}

std::vector<Enemy *> initialize_enemy(std::vector<Spell *> _spells, std::vector<specialAttack> attack){
	std::vector<Enemy *> enemies;
	std::vector<Spell *> empty;

	Enemy *Spider = new Enemy("Aragog", "spider", attack[1], 1, 100, 0, 0, 0, 0, empty, "Giant spider who lives in the Forbidden Forest and is only loyal to Rubeus Hagrid");
	Enemy *Bellatrix = new Enemy("Bellatrix Lestrange", "human", attack[0], 4, 100, 0, 4, 4, 0, _spells , "Notorious Azkaban fugitive and Death eater, the assassin of Sirius Black, the dark figure of Bellaxtrix Lestrange presents itself with the sole intention of murdering you, for your involvement with Dumbledore's Army");
	Enemy *Dementor = new Enemy ("Dementor", "wraith", attack[3], 3, 100, 0, 4, 4, 0, empty, "Dementors are among the foulest creatures that walk this earth. They infest the darkest, filthiest places, they glory in decay and despair, they drain peace, hope, and happiness out of the air around them... Get too near a Dementor and every good feeling, every happy memory will be sucked out of you. The guards of Azkaban, they feed on human happiness and can extract souls with their Dementor's Kiss");
	Enemy *Basilisk = new Enemy ("Basilisk", "serpent", attack[2], 2, 100, 0, 4, 4, 0, empty, "The Secret Chamber has been opened. Enemies of the heir, beware! The Basilisk is a giant serpent that can instantly kill anyone who looks into their eyes");
	Enemy *Lucius = new Enemy("Lucius Malfoy", "human", attack[0], 4, 100, 0, 4, 4, 0, _spells, "Draco's father who serves Lord Voldemort as a Death Eater in both Wizarding Wars.");
	Enemy *Draco = new Enemy("Draco Malfoy", "human", attack[0], 1, 100, 0, 1, 1, 1, _spells, "A pure-blood wizard, proud Slytherin and Harry Potter’s arch rival at Hogwarts");
	Enemy *Peter = new Enemy("Peter Pettigrew","human", attack[0], 4, 100, 0, 4, 4, 0, _spells, "Loyal follower of Voldemort who betrayed Harry's parents");
	Enemy *Giant = new Enemy("Giant", "giant", attack[4], 2, 100, 0, 2, 2, 0, empty, "Colossal creatures which can be extremely dangerous");
	Enemy *MountainTrolls = new Enemy("Mountain Trolls", "trolls", attack[4], 1, 100, 0, 1, 1, 0, empty, "The largest and most vicious breed of troll - best avoided");
	Enemy *Nagini = new Enemy("Nagini", "serpent", attack[2], 4, 100, 0, 4, 4, 0, empty, "Lord Voldemort's pet snake and loyal servant.");
	Enemy *LordVoldemort = new Enemy("Lord Voldemort", "human", attack[0], 5, 100, 0, 7, 8, 0, _spells, "Formerly known as Tom Marvolo Riddle and commonly referred to as He-Who-Must-Not-Be-Named. The most powerful Dark wizard of all time.");

	enemies.push_back(Spider);
	enemies.push_back(Bellatrix);
	enemies.push_back(Dementor);
	enemies.push_back(Basilisk);
	enemies.push_back(Lucius);
	enemies.push_back(Draco);
	enemies.push_back(Peter);
	enemies.push_back(Giant);
	enemies.push_back(MountainTrolls);
	enemies.push_back(Nagini);
	enemies.push_back(LordVoldemort);
	
	return enemies;
}
void printMainMenu(){
	std::cout << "[1] Next battle" << std::endl << "[2] Distribute skillpoints" << std::endl << "[3] Display current character stats" << std::endl;
}

void initialize_game(){
	std::vector<Spell *> spell = instantiate_spell();
	std::vector<Potions *> potion = instantiate_potions();
	std::vector<Artifacts *> artifact = instantiate_artifacts();
	Wizard *player = initialize_player(spell, potion, artifact);
	std::vector<specialAttack> attack = instantiate_attack();
	std::vector<Enemy *> enemies = initialize_enemy(spell, attack); 
	

	while(1){ 
		char menuIndex;
		char selectionIndex;
		std::cout << "\033[2J\033[1;1H"; //This line clear the screen
		while(1){
            try {
				printMainMenu();
                std::cin >> menuIndex ;
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
				if ((menuIndex == '1')||(menuIndex == '2')||(menuIndex == '3'))
					break;
				else throw std::invalid_argument("Invalid menu index, try again ") ;
            } catch (std::invalid_argument &t){
                std::cout << t.what() << std::endl;
            }
		}     
		if (menuIndex == '1'){
			int number_enemy;
			do{
				number_enemy= rand() % enemies.size();
			} while(enemies[number_enemy]->getLevel() != player->getLevel());   
				Battle(player , enemies[number_enemy]);
        } else if (menuIndex == '2' ){
			bool ind;
			std::cout << "\033[2J\033[1;1H"; //This line clear the screen
            while(player->getSkillPoints() > 0){
        	    try {
					ind = 0;
					std::cout << "Available points: " << player->getSkillPoints()  << std::endl ;
                    std::cout <<"Pick an attribute to increase it:\n"<<  "[0]Return to main menu\n[1]Health\n[2]Magic Points\n[3]Strenght\n[4]Constitution\n[5]Dexterity" << std::endl ;
                    std::cin >> selectionIndex ;
					std::cout << "\033[2J\033[1;1H"; //This line clear the screen
					for (int i = 1; i < 6; i++)
						if (selectionIndex == (char)(i+48)){
							player->incrementSkill(i);
							ind = 1;
						}
                    if (selectionIndex == '0' ) {
                        std::cout << "\033[2J\033[1;1H"; //This line clear the screen
						ind = 1;
                        break;
                    } else if (ind == 0)
						throw std::invalid_argument("Invalid skill index, try again ") ;
                } catch (std::invalid_argument &t){
                    std::cout << t.what() << std::endl;
                }
            }
			std::cout << "\033[2J\033[1;1H"; //This line clear the screen
			if (player->getSkillPoints() == 0){
				std::cout << "You have no skillpoints available!\n" ;
				myPause();
			}
        } else if(menuIndex == '3'){
			while(1){
                try {
                    std::cout <<"[0]Return to main menu\nPlayer attributes:" << std::endl ;
					player->printStats() ;
                    std::cin >> selectionIndex ;
					std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                    if ((selectionIndex == '0')){
        	           	break ;
                    } else throw std::invalid_argument("Invalid selection index, try again ") ;
                } catch (std::invalid_argument &t){
                    std::cout << t.what() << std::endl;
            	}
            }
		}
		player->setSpellVector(spell);
		artifact = instantiate_artifacts();
		player->setArtifactsVector(artifact);
		potion = instantiate_potions();
		player->setPotionsVector(potion);
		if(player->getLevel() == 6){
			std::cout << "The game is over. You won." << std::endl;
			break;
		}
			
    }
}



