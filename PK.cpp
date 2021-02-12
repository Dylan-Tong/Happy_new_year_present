#include"PK.h"

bool Weapon::isTrigger(int rate) {
	int num = rand() % 100 + 1;
	if (num <= rate)return true;
	return false;
}

GodSword::GodSword() {
	this->m_BaseDamage =60;
	this->m_WeaponName = "����";
}

int GodSword::get_m_baseDamage(){
	return m_BaseDamage;
}

int GodSword::get_SuckBlood() {
	if (isTrigger(SuckRate))
	{
		return m_BaseDamage; //��Ѫ�ٷ�֮25
	}
	return 0;
}

bool GodSword::get_Hold() {
	if (isTrigger(HoldRate)) { 
		return true; 
	}
	return false;
}

bool GodSword::get_Crit() {
	if (isTrigger(CritRate)) {
		return true;
	}
	return false;
}
int GodSword::Crit() { return CritRate; }
int GodSword::Suck() { return SuckRate; }

Knife::Knife() {
	this->m_BaseDamage = 50;
	this->m_WeaponName = "����";
}
int Knife::get_m_baseDamage(){
	return m_BaseDamage;
}

int Knife::get_SuckBlood() {
	return 0;
}
bool Knife::get_Hold() {
	if (isTrigger(HoldRate)) {
    //std::cout << "����ѣ�Σ��Է�ѣ��һ�غϣ�\n";
		return true;
	}
	return false;
}

bool Knife::get_Crit() {
	if (isTrigger(CritRate)) {
		//std::cout << "������\n";
		return true;
	}
	return false;
}

int Knife::Crit() { return CritRate; }
int Knife::Suck() { return SuckRate; }

MagicStick::MagicStick() {
	this->m_BaseDamage = 80;
	this->m_WeaponName = "�޾�";
}
int MagicStick::get_m_baseDamage() {
	return m_BaseDamage;
}

int MagicStick::get_SuckBlood() {
	if (isTrigger(SuckRate))
	{
		return m_BaseDamage ; 
	}
	return 0;
}

bool MagicStick::get_Hold() {
	return isTrigger(HoldRate);
}

bool MagicStick::get_Crit() {
	return false;//�ޱ���
}

int MagicStick::Crit() { return CritRate; }
int MagicStick::Suck() { return SuckRate; }

Hero::Hero() {
	m_Hp = 450;
	m_Atk = 50;
	m_Def = 30;
	weapon = nullptr;
	is_energy = true;
}
void Hero::EquipWeapon(Weapon* weapon) {
	this->weapon = weapon;
}
void Hero::Attack(Monster* monster) {
	int ComsumeHp=this->m_Atk - monster->get_m_Def();
	ComsumeHp = ComsumeHp > 0 ? ComsumeHp : 1;
	if (weapon == nullptr) {//���֣���Ȼ�������һ�㲻�ᷢ��
		monster->set_m_Hp(monster->get_m_Hp()-ComsumeHp);
		return;
	}
	ComsumeHp += weapon->get_m_baseDamage();

	//����
	if (weapon->get_Crit()) {
		ComsumeHp += weapon->get_m_baseDamage()*2;
		std::cout << "Ӣ�۵���������" << weapon->m_WeaponName << "�������˱�����\n";
	}


	//������Ѫ�˺�
	int tmp = m_Hp + weapon->get_SuckBlood();
	if (tmp != m_Hp) {
		std::cout << "Ӣ�۵���������" << weapon->m_WeaponName << "����ѪЧ����\n";
		if (tmp > 450)m_Hp = 450;
		else m_Hp = tmp;
	}
	//ѣ��
	if (weapon->get_Hold()){
		std::cout << "Ӣ�۵���������" << weapon->m_WeaponName << "����������Ч������ʹ�з�ֹͣ����һ�غϣ�\n";
		monster->m_Hold = true;
	}
	if (ComsumeHp != 1) {
		monster->set_m_Hp(monster->get_m_Hp() - ComsumeHp);
		std::cout << "Ӣ��" << m_Name << "�����˵��ˡ�" << monster->get_m_Name() << "���������"
			<< ComsumeHp << "���˺�ֵ\n";
	}
	else {
		monster->set_m_Hp(monster->get_m_Hp() - ComsumeHp);
		std::cout << "Ӣ��" << m_Name << "�����˵��ˡ�" << monster->get_m_Name() << "��û������˺�ֵ\n";
	}
}

void Hero::out() {
	std::cout << "Ӣ��" << m_Name << ":\n" << " Hp:" << m_Hp << " ������Def��:" << m_Def << "\n";
	std::cout << "����:\n��������:" << weapon->get_m_baseDamage()<< " ����(Cruit)��" << weapon->Crit()<<" ��Ѫ(Suck):"<<weapon->Suck()<<"\n\n";
}

Monster::Monster() {
	std::string m_Name = "���ޡ�����������";
	m_Atk = 225;
	m_Def = 75;
	m_Hp = 1000;
	m_Hold = false;
}

void Monster::Attack(Hero* hero)
{

	if (m_Hold) {
		std::cout << "������������������\n";
		m_Hold = false;
		return;
	}

	int damage = m_Atk - hero->m_Def;
	damage = (damage > 0) ? damage : 1;
	if (damage != 1) {
		hero->m_Hp = hero->m_Hp - damage;
		std::cout << "��" << this->get_m_Name() << "'������Ӣ�ۡ�" << hero->m_Name << "���������"
			<< damage<< "���˺�ֵ\n";
	}
	else {	
		std::cout << "��" << this->get_m_Name()<< "'������Ӣ�ۡ�" << hero->m_Name << "����û������˺�ֵ\n";
	}

}

int Monster::get_m_Def()
{
	return m_Def;
}

std::string Monster::get_m_Name() {
	return  "���ޡ�����������";
}

int Monster::get_m_Hp() {
	return m_Hp;
}

void Monster::set_m_Hp(int a) {
	m_Hp = a;
}
