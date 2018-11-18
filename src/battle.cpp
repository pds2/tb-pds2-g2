#include "wizard.h"
#include "enemy.h"
#include "battle.h"
#include "spells.h"
#include "stats.h"
#include <iostream>
#include <string>

void myBattlePause(){
	{
	    std::cout << "Press any character followed by ENTER to continue" << std::endl ;
	    std::string hold ; 
	    std::cin >> hold ;
    }
}

Battle::Battle(Wizard * player , Enemy * enemy){
    this->_round = 1 ; //Numero do round
    this->_ended = 0 ;  //Booleano de acabou
    this->_player = player ;  //Pointer para a instancia de player
    this->_enemy = enemy; //Pointer para a instancia de enermy
    this->_originalStats = player->getBaseStats() ;
    if (player->getDexterity() > enemy->getDexterity()){ //Define quem vai ter o primeiro turno
        this->_playerturn = 1 ;
    } else {
        this->_playerturn = 0 ;
    }
    Stats filler = {0,0,0,0,0,0} ;
    for ( int i = 0 ; i < 20 ; i ++) {
        _playerDebuffs.push_back(filler);
        _enemyDebuffs.push_back(filler) ;
    }
    this->initializeBattle() ;
}

void Battle::initializeBattle(){
    this->introduction();

    while((this->_player->getHP() > 0) && (this->_enemy->getHP() > 0)){
        this->round() ;
    }
    _originalStats.level += 1 ;
    this->_player->setStats(this->_originalStats) ; 
    this->_player->incrementSkillPoints(1);
}


void Battle::spellMove(Spell* spell ){
    

}

void Battle::introduction(){
    this->_enemy->printIntro() ;
    std::cout << " " << std::endl; 
    myBattlePause();
    std::cout << "\033[2J\033[1;1H"; //This line clear the screen
    std::cout << "Get ready to battle!\nYour opponent is: " << this->_enemy->getName()  << std::endl ;
    std::cout << "They are of type " << this->_enemy->getType() << std::endl ; 
    std::cout << "Their stats are:\n" ;
    this->_enemy->printStats() ;
    myBattlePause();
}


void Battle::round(){
    if (this->_playerturn == 1){
        unsigned int menuIndex ;
        //int actionIndex; //essa variavel ainda nao foi usada, tire o comentario quando for usar
        unsigned int selectionIndex ;
        while(1){ //Deemed necessary, player might return to menu selection menu
            try {
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                std::cout << "Make a choice:" << std::endl << "[1] Spells" << std::endl << "[2] Inventory" << std::endl ;
                std::cin >> menuIndex ;
                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                if (menuIndex == 1 ){
                    //Print out spell options as well as option to return to menu. If a spell is selected, call the move function with it and terminate de round
                    while(1){ //Done
                        try {
                            std::cout << "[0] "<<  "Back to main menu" << std::endl ;
                            _player->printPlayerSpells() ;
                            std::cin >> selectionIndex ;
                            if ((selectionIndex > 0) && (selectionIndex <= _player->getSpellVector().size())){
                                spellMove(_player->getSpellVector()[selectionIndex-1]) ;
                                //move(_player->getSpellVector()[selectionIndex-1]) ;
                                this->_playerturn = 0 ;
                                return ;
                            } else if (selectionIndex == 0 ) {
                                std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                break ;
                            } else throw std::invalid_argument("Invalid spell index, try again ") ;
                        } catch (std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }
                    }
                } else if (menuIndex == 2 ){
                    unsigned int secondaryMenuIndex ;
                    while (1){
                        try{
                            std::cout << "Make a choice:" << std::endl << "[0] Back to main menu" << std::endl << "[1] Potions" << std::endl << "[2] Artifacts" << std::endl;
                            std::cin>> secondaryMenuIndex ;
                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                            if (secondaryMenuIndex == 0){
                                break ;
                            } else if (secondaryMenuIndex == 1){
                                unsigned int potionIndex ;
                                while(1){
                                    try{
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        _player->printPlayerPotions();
                                        std::cin >> potionIndex ;
                                        if ((potionIndex > 0) && (potionIndex <= _player->getPotionsVector().size())){
                                            //move(_player->getPotionsVector()[potionsIndex-1]) ;
                                            this->_playerturn = 0 ;
                                            return ;
                                        } else if (potionIndex == 0 ) {
                                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                            break ;
                                        } else throw std::invalid_argument("Invalid potion index, try again ") ;
                                    } catch (std::invalid_argument &t) {
                                        std::cout << t.what() << std::endl;
                                        }
                                }
                            } else if (secondaryMenuIndex == 2 ){
                                unsigned int artifactsIndex ;
                                while(1){
                                    try{
                                        _player->printPlayerArtifacts();
                                        std::cout << "[0] "<<  "Back to inventory menu" << std::endl ;
                                        std::cin >> artifactsIndex;
                                        if ((artifactsIndex > 0) && (artifactsIndex <= _player->getArtifactsVector().size())){
                                            //move(_player->getArtifactsVector()[artifactsIndex-1]) ;
                                            this->_playerturn = 0 ;
                                            return ;
                                        } else if (artifactsIndex == 0 ) {
                                            std::cout << "\033[2J\033[1;1H"; //This line clear the screen
                                            break ;
                                        } else throw std::invalid_argument("Invalid artifact index, try again ") ;
                                    } catch(std::invalid_argument &t){
                                        std::cout << t.what() << std::endl ;
                                    }
                                }
                            } else {
                                throw std::invalid_argument("Invalid secondary menu index, try again") ;
                            }
                        } catch(std::invalid_argument &t){
                            std::cout << t.what() << std::endl;
                        }

                    }
                } else {
                    throw std::invalid_argument("Invalid menu index, try again") ;
                }
            } catch(std::invalid_argument &t) {
                std::cout << t.what() << std::endl;
            }
        }


    } else {
        if (this->_enemy->getType() == "human"){
            int number_spell = rand() % this->_enemy->getSpellVector().size();
            std::cout << _enemy->getSpell(number_spell)->get_name() << std::endl; //imprimir o nome do feitico do inimigo na tela
        } else {
            std::cout << _enemy->getSpecialAttack()<< std::endl;
        }
        //Generate/select a random action given the enemy's level stat, call the Move() function with that action and modify the target character's stats according to _playerturn
    }

}
