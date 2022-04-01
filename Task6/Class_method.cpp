#include "Class_description.h"

void Base::SetHP(int hp) {}
void Base::SetAtk(int atk) {}
void Base::SetDef(int def) {}
void Base::SetLevel(int lvl) {}
Base::Base(std::string Name)
    : name(Name) {}
Base::~Base() {}
int Base::GetHP() const { return 0; }
int Base::GetAtk() const { return 0; }
int Base::GetDef() const { return 0; }
int Base::GetLevel() const { return 0; }
bool Base::IsDead() const { return true; }
void Base::Victory() {}
void Base::Attack(Base &other)
{
  if (IsDead())
    return;
  int dmg = std::max(1, GetAtk() - other.GetDef());
  other.SetHP(other.GetHP() - dmg);
  std::cout << name << " attacked " << other.name << " and dealt " << dmg << " damage!" << std::endl;
  if (other.IsDead())
  {
    std::cout << name << " won!" << std::endl;
    Victory();
  }
}
void Base::Load(int hp, int atk, int def, int lvl)
{
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
Enemy::Enemy(std::string Name) : Character(Name) {}
Enemy::~Enemy() {}
Character::Character(std::string Name) : Base(Name) {}
Character::~Character() {}
