#include "Class_description.h"
#include <iostream>
#include <utility>

void Base::SetHP(int hp) {}

void Base::SetAtk(int atk) {}

void Base::SetDef(int def) {}

void Base::SetLevel(int lvl) {}

Base::Base(std::string Name)
        : name(std::move(Name)) {}

Base::~Base() {}

int Base::GetHP() const { return 0; }

int Base::GetAtk() const { return 0; }

int Base::GetDef() const { return 0; }

int Base::GetLevel() const { return 0; }

bool Base::IsDead() const { return true; }

void Base::Victory() {}

void Base::Attack(Base &other) {
    if (IsDead())
        return;
    int dmg = std::max(1, GetAtk() - other.GetDef());
    other.SetHP(other.GetHP() - dmg);
    std::cout << name << " attacked " << other.name << " and dealt " << dmg << " damage!" << std::endl;
    if (other.IsDead()) {
        std::cout << name << " won!" << std::endl;
        Victory();
    }
}

void Base::Load(int hp, int atk, int def, int lvl) {
    SetHP(hp);
    SetAtk(atk);
    SetDef(def);
    SetLevel(lvl);
    std::cout << "hp: " << GetHP() << std::endl;
    std::cout << "atk: " << GetAtk() << std::endl;
    std::cout << "def: " << GetDef() << std::endl;
    std::cout << "lvl: " << GetLevel() << std::endl;
}

Player::Player(std::string Name) : Character(Name) {}

Player::~Player() {}

void Player::SetXP(int xp) {
    Character::SetLevel(Character::GetLevel() + xp / 100);
    _xp = xp % 100;
}

int Player::GetXP() const {
    return _xp;
}

void Player::Attack(Base &other) {
    _potentialXpReward = 5*other.GetLevel() + other.GetDef()/4 + other.GetAtk()/4;
    Base::Attack(other);
}

void Player::Victory() {
    Base::Victory();
    SetXP(GetXP() + _potentialXpReward);
    _potentialXpReward = 0;
}

Enemy::Enemy(std::string Name) : Character(Name) {}

Enemy::~Enemy() {}

Character::Character(std::string Name) : Base(Name) {}

Character::~Character() {}

void Character::SetHP(int hp) {
    Base::SetHP(hp);
    _hp = hp;
}

void Character::SetAtk(int atk) {
    Base::SetAtk(atk);
    _atk = atk;
}

void Character::SetDef(int def) {
    Base::SetDef(def);
    _def = def;
}

void Character::SetLevel(int lvl) {
    Base::SetLevel(lvl);
    _lvl = lvl;
}

int Character::GetHP() const {
    return _hp;
}

int Character::GetAtk() const {
    return _atk;
}

int Character::GetDef() const {
    return _def;
}

int Character::GetLevel() const {
    return _lvl;
}

bool Character::IsDead() const {
    return GetHP() <= 0;
}