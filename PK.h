#ifndef _PK_h
#define _PK_h
#include<iostream>
#include<string>
#include<time.h>
class Weapon {
public:
	virtual int get_m_baseDamage() = 0;//�����˺�
	virtual int get_SuckBlood() = 0;//��Ѫ
	virtual bool get_Hold() = 0;//ѣ��
	virtual bool get_Crit() = 0;//����
	
	virtual int Crit()=0;
	virtual int Suck()=0;

	bool isTrigger(int rate);


private:

public:
	std::string m_WeaponName;
	int m_BaseDamage;
};
/*
���ص㣺
���������ֽϾ���
*/
class GodSword :public Weapon
{
public:
	GodSword();
	virtual int get_m_baseDamage();//�����˺�
	virtual int get_SuckBlood();//��Ѫ
	virtual bool get_Hold();//ѣ��
	virtual bool get_Crit();//����
	virtual int Crit();
	virtual int Suck();
private:
	int SuckRate = 20;
	int HoldRate = 35;
	int CritRate = 5;
};
/*
�����ص㣺
ѣ�������ͱ��������ߣ�������Ѫ
�����˺���
*/
class Knife :public Weapon
{
public:
	Knife();
	virtual int get_m_baseDamage();//�����˺�
	virtual int get_SuckBlood();//��Ѫ
	virtual bool get_Hold();//ѣ��
	virtual bool get_Crit();//����
	virtual int Crit();
	virtual int Suck();
private:
	int SuckRate = 0;
	int HoldRate = 25;
	int CritRate = 70;
};
/*
�����ص㣺
����Ѫ��ѣ�Σ������ޱ���
�����˺���
*/
class MagicStick :public Weapon
{
public:
	MagicStick();
	virtual int get_m_baseDamage();//�����˺�
	virtual int get_SuckBlood();//��Ѫ
	virtual bool get_Hold();//ѣ��
	virtual bool get_Crit();//����
	virtual int Crit();
	virtual int Suck();
private:
	int SuckRate = 60;
	int HoldRate = 30;
	int CritRate = 0;
};

class Monster;
class Hero {
public:
	Hero();
	void EquipWeapon(Weapon* weapon);
	void Attack(Monster* monster);
	void out();

	std::string m_Name;
	int m_Atk;
	int m_Def;
	int m_Hp;
	Weapon* weapon;
	bool is_energy;
};

class Monster {
public:
	Monster();
	void Attack(Hero* hero);
	int get_m_Def();
	std::string get_m_Name();
	int get_m_Hp();
	void set_m_Hp(int a);
private:
	std::string m_Name;
	int m_Atk;
	int m_Def;
	int m_Hp;
public:
	bool m_Hold;

};
#endif
