#pragma once
#include <iostream>

class Base {
protected:
    virtual void SetHP(int hp);

    virtual void SetAtk(int atk);

    virtual void SetDef(int def);

    virtual void SetLevel(int lvl);

public:
    const std::string name;

    Base(std::string Name);

    ~Base();

    virtual int GetHP() const;

    virtual int GetAtk() const;

    virtual int GetDef() const;

    virtual int GetLevel() const;

    virtual bool IsDead() const;

    virtual void Victory();

    void Attack(Base &other);

    void Load(int hp, int atk, int def, int lvl);
};

////////////////////
// Ваш код //
///////////////////

class Character : public Base {
    int _hp;
    int _atk;
    int _def;
    int _lvl;

public:
    Character(std::string Name);

    ~Character();

    void SetHP(int hp) final;

    void SetAtk(int atk) final;

    void SetDef(int def) final;

    void SetLevel(int lvl) final;

    int GetHP() const final;

    int GetAtk() const final;

    int GetDef() const final;

    int GetLevel() const final;

    bool IsDead() const final;
};

class Player : public Character {
    int _xp;

    int _potentialXpReward = 0;
public:
    Player(std::string Name = "Player");

    void SetXP(int xp);

    int GetXP() const;

    void Attack(Base &other);

    void Victory() final;

    ~Player();
};

class Enemy : public Character {
    int _xpReward;

public:
    Enemy(std::string Name = "Enemy");

    ~Enemy();
};