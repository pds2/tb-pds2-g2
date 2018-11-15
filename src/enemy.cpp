#include "character.h"
#include "enemy.h"

Enemy::Enemy(std::string name, std::string type, int level, int hp, int mp, int str, int cons, int dex) :
 Character(name, type, level, hp, mp, str, cons, dex){};

Enemy::~Enemy(){}

void Enemy::decrementSkill(int i){
	switch(i){
		case 1:
			this->_baseStats.hp -= 10;
			break;
		case 2:
			this->_baseStats.mp -=10;
			break;	
	}
}

