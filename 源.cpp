#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<cstring>
#include<stdio.h>
#include <conio.h>
#include"Characters.h"
#include"PK.h"
#include"Skin.cpp"
#include<conio.h>
#include<time.h>
using namespace std;
/*
version2.0 Ŀ����£�
1��������ͼ���͵�#��3��
2���������߼���--��֮��������һ�����ǣ�ѣ������1�غ�
3����Ϸ���ܿ����ټ�һ�� ���ո���Ϣһ�غ�
4�����������Թ�
5�����������֣�Ϧ�£���Ԩ��ĩ��  ���߽�������
*/
//�������߼��ܽ���


void display();
void Creat_stars();
bool is_legal(COORDINATE& node);
bool get_key();
bool check(int&);
void put(string c);

void pk_play();
void scene();
void skin_play();

struct Send {
	COORDINATE c;
	Send* o;
	Send(int x, int y) :c(x, y),o(NULL){};
	//void SetConnect(Send& a) { o = &a; };
};


Character monster(5, 5);
Voidwalker player(1, 1);

Send one(1, 6),another(6, 6);
int stars_in_map = 0;
int has_stars = 0;
int use_send = 0;
bool notes = false;
extern const int column , row;
int init_map[row][column] = { 
	                     {1,1,1,1,1,1,1},
                         {1,1,1,1,0,1,3},
					     {1,1,0,1,1,1,1},
                         {1,1,0,1,0,1,0},
                         {1,1,1,1,0,1,1},
						 {1,0,1,1,1,1,1},
                         {1,1,1,0,1,0,3} };
int map[row][column];
bool passed = false;

int Creat_random() {
	return rand() % 5+1;
}
/*
0����ǽ��
1����ͨ·,
2��������,
3�����͵㣬
4�����Ӷ����ϡ�
*/

void init(){
	monster.alter_id(COORDINATE(6, 6));
	player.alter_id(COORDINATE(1, 1));
	stars_in_map = 0;
	has_stars = 0;
	use_send = 0;
	for (int i = 0; i < row; ++i)memcpy(map[i], init_map[i], sizeof(int)*column);
	map[5][6] = 2;
	++stars_in_map;
	notes =false;
	passed = false;

	//�������͵�
	one.o = &another;
	another.o = &one;
}
bool is_eq(const COORDINATE& a,const COORDINATE &b)
{
	if (a.x == b.x && a.y == b.y)return true;
	return false;
}

bool elect() {
	cout <<"   �ڴ�ģʽ�£������ѡ��ͬ���½ڣ���Ծ�ԵĽ��벻ͬ�Ĺؿ����Ӷ�����������ѡ���֧��ʱ��\n";
	cout << "ֱ�����鲻ͬѡ���µĽ�ֻ������򣬵��������һ�����ʱ��ֱ��ѡ���������ܻ���ɾ�������ƫ��\n";
	cout << "����,��ģʽ�²�������Ծ�����еľ��顣\n";
	SetConsoleColor(FOREGROUND_BLUE);
	for (int i = 0; i < 25; ++i)cout << "__"; cout << "\n";
	SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|��֮�ż�̽����1��|��������ࣨ2��|���ѡ��3��|\n";
	//for (int i = 0; i < 25; ++i)cout << "__"; cout << "\n";
	SetConsoleColor(FOREGROUND_RED);
	cout << "�������Ӧ�����ֽ����½�\n";
	L1:switch (_getch()) {
	case '1':
		try {
			skin_play();
		}
		catch (...) {
			skin_play();
		}
		break;
	case '2':
		try {
			pk_play();
		}
		catch (...) {
			put("���¼����С�������");
			Sleep(1000);
			system("cls");
			pk_play();
		}
		break;
	case '3':
		return true;//����true˵��Ҫ��������ѡ��
	default:
		cout << "�������\n";
		goto L1;
	}
	return false;
}
void play();
int main()
{
	srand((int)time(NULL));
	//pk_play();
	cout<<"    \\\\\\|///        ����\n  ";
	cout<<"\\\\��.-.-��//    ����ս\n";
	SetConsoleColor(FOREGROUND_BLUE);
	for (int i = 0; i < 20; ++i)cout << "__"; cout << "\n";
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
	cout << "|   ��ͷ��ʼ��s��|| ѡ��ؿ����У�k��  |\n";
	//for (int i = 0; i < 20; ++i)cout << "__"; cout << "\n";
	SetConsoleColor(FOREGROUND_RED);

L3:	switch (_getch()) {
	case's':break;
	case'k':
		if (!elect())exit(0);
		else goto L2;
		break;
	default:
		cout << "�������\n";
		goto L3;
	}

	put("��k���������飨skip�����ո����������\n");
	if (_getch() == 'k')goto L1;
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED);
	put("��ɸ�   �ռ�˵�һ��\n");
	put("�������ӣ������߷ܡ�\n");
	put("����������ߣ���ն����\n");
	put("���������˲����Ϊ���ߣ�����Ϊ�ҵ��𹱣���\n");
	put("���·����Ľ�ʿ��������ǻ������ǰ�������Ѿõĵ�20��������̣��ⲻ֪������ڷ����������Ĵ��¡�\n");
	put("���ֵܣ���������ô���飿��\n");
	put("���ȣ��ϸ����ǴӶ�Զ���⽮���İ�����û�������ǹ�任������룬��������ÿҹ���ⲻ������Ϯ���������ػ�������Υ������ּ�⣬��ʱ����ִ��ͷն����\n");
	put("��ʿ�󾪣�Ѹ�ٸ��������������Խ����ƽ�������������������˹��ڷ���ǰ�ĵ�20�����ߡ�\n");
	put("���ʳ�������ն�����������������߷���\n");
	put("�����ߣ������ҵĽ����ƣ������ȥһֱ�����ߣ����ϳ����ŷ�������������������ƣ��������ȥ����ȫ�ĵط������������Ҫ�㣡��\n");
	put("���ҿ��ǣ��������������֮�ˣ�Ϊ���ڴ����ֻ�֮�ˣ���֪��������ʲô�𣿡�\n");
	put("���ǹ���룬���޳�û�����Ͳ�����Ĵ�������֮�ޱ䣬������Ҫ���������Ȱ��������Ҵ������̣������ˣ���Ҫ������������ϵ����ǰ�����\n");
	put("����̧ͷ����λ��ʿ�ƺ�֪���������ʽ���Ǳ���ɺ�����������\n");
	put("�������ˣ����߲������ػ���ְ�𣬻��а������ĵ�ְ������������������֮Ϊ��������֮��ɣ�����������˻֣̿���������������ȣ���\n");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY);
	put("˵�գ�����ˬ�ʴ�Ц�����ָ��ߣ�������һ��Ѹ�ٽ����ƻ��ڽ�ʿ���ദ��\n");
	put("�����ǣ�������������\n");
	SetConsoleColor(FOREGROUND_INTENSITY| FOREGROUND_RED);
	put("�����ģ����������������磬���������ȣ���ȥ�ռ���7��ɢ���˼�����ǣ��ٻ���������\n");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED);
	put("һ������ӿ���ڽ�ʿ���������21�����ߣ������ˡ�\n");
	put("��������ʱ������Ϊ�����̰ɣ���һ�ε����߰�����\n");

	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
	put("��ʱ  ��¸���\n");
	put("����̨�¼��������ڣ���ŭ���ֻţ����š�\n");
	put("������ǿ�������ᣬ���𱦽���������µ���һ�̣�������\n");
	put("���������������΢Ц������˵��\n");
	put("����ʼ������̰ɣ����ߣ���\n");

	put("����һ���������ߣ�@����������ޣ����������ռ����ǣ�*������Ϸ����#�������ͷ���\n");
	put("��$���Ǵ���������Ů�������֮�Ƶı��Ӷ�����\n");
	put("�������ܣ�\n���߲�����1��wsad�����������ң�ע���Сдsensitive��2������\n");
	put("  ������ߣ���cdΪ0ʱ�ɴ���������j������wasd�����Դ�Խǽ�ڣ����޲��ܴ�Խǽ�ڣ�\n");
	put("  ����֮��������������Ϣ������ӵ�е����ǣ�����k��������һ�����ǲ�������ֹͣһ�غϣ������ܰ�wsad����\n");
	put("���ޣ��ݴ����ǹ���������������ޣ����о޴����������һ��ʱ�䣨cd==0�����ܽ��г�̣������н�һ�غ϶������н����غ�\n");

L1:  try 
	{ 
		play();
}
catch (...) {
	put("�˳��밴q��(quit)�����������\n");
	if (_getch() == 'q')exit(0);
	goto L1;//PLAY AGAGIN
	}

	if (passed)
	{
L2:     put("��ϲ�㣡��������ޣ���ѡ��ɣ���ѡ������һ�У����ǻص���ʵ��(����q,ѡ�����ǣ�����w��ѡ��ص���ʵ)\n");
		char c = _getch();
		while (c != 'q' && c != 'w')c = _getch();
		if (c == 'q') {
			SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			put("��04.24����Sakuraȥ�������������������ů�͵ĵط���������Ķ��ϡ���\n");
			put("��04.25����Sakuraȥ�����񹬣�����������ٰ���񡣡�\n");
			put("��04.26����Sakuraȥ��ʿ�ᣬ���ݺܿ��£�������Sakura�ڣ����Բ����¡���\n");
			put("��Sakura����ˡ���...\n");
			put("���ߵ��Ժ��ȫ�����޳���ǰ�ͻ����µĹ��£������ҹ�Ȼ���ǷŲ��£����߷�������ɫҩ��\n");
			put("������ת�����������ϵ����飬���������۾�ǰ���Ĺ�â\n........\n");
			put("��ɵ���ӣ���ʲô���أ�������ҹ����������һ������������һ�������к���ͷ\n��");
			put("�衪���Ҷ������..........\n�ⲻ֪�������ı�ʯ������������Ĺ�\n");
			put("��Ϸ����");
			_getch();
		}
		else {
			SetConsoleColor(FOREGROUND_INTENSITY|FOREGROUND_RED);
			put("�������̲�ס�������������е�ҹ��\n");
			put("�ƻ�ȼ�ɵ�����\n");
			put("��������̨��\n");
			put("ʱ��̴�������\n");
			put("����ҵĶ������������������������\n����\n");
			put("���˵��� �����赸 �����మ\n");
			put("�����������������ɢ���ںڰ������ʢ��\n");
			put("��ɫ��̫������ѹ�Ӣ\n");
			put("��׹����ɫ����\n");
			put("��ɫ�ͽ�ɫ��֯�ɵ�õ��\n");
			put("��ɫ�Ĵ����ա���\n");
			put("����������ʢ�����������ػ���\n");
			put("���������˺�ɫҩ��\n");
			put("�����������е��Լ��������Լ����֣����ߴ������ӣ�������\n");
			system("color F8");
			put("������Һ����������Χ��һ����һ���Ĳ�Ӽ��������˶�����ϣ������ף������ޣ���԰�\n");
			put("���Ź�������Ų���ţ�Ӱ������ڰ�\n");
			put("��Ϸ����");
			_getch();
		}
	}
	return 0;
}

void display()
{
    system("cls");

	cout << "Monster:\n" <<" cd: "<<monster.get_cd() << endl;
	cout << "player:\n" << " cd: " << player.get_cd() << endl;
	cout << "stars you have:\n" <<has_stars<< endl;
	const string orstr = "|";
	const string line = "__";
	const string space = " ";

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	for (int j = 1; j <column; j++) { cout << space << line; }
	cout << endl;
	
	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < column; ++j)
		{

			cout << orstr;
			SetConsoleColor(FOREGROUND_BLUE);
			if (i == 6 && j == 1) {
				cout << "$ ";
			}
			else if (player.is_coordinate(i, j))
			{
				cout << "@ ";
			}
			else if (monster.is_coordinate(i, j))
			{
				cout << "! ";
			}
			else if (map[i][j] == 0)cout << "��";
			else if (map[i][j] == 2)cout << "* ";
			else if (map[i][j] == 3)cout << "# ";
			else cout << "  ";
			SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		}
		cout << orstr<<endl;
		for (int j = 1; j < column; j++) { cout << space << "--"; }
		cout << endl;
	}
}

bool is_legal(COORDINATE& node)
{
	if (node.x > column || node.x < 1 || node.y>row || node.y < 1)return false;//������ͼ��Χ
	if (map[node.x][node.y] == 0)return false;//λ����ǽ��
	return true;
}

void Creat_stars()
{
	int stars_x,stars_y;
	while (true)
	{
		stars_x = Creat_random();stars_y = Creat_random();
		COORDINATE tmp(stars_x, stars_y);
		if (is_legal(tmp))break;
	}
	++stars_in_map;
	map[stars_x][stars_y] = 2;
}


bool get_key()
{
	char c = _getch();
	player.alter_cd(-1);//ʱ������
	if (c == 'j')
	{
		cout << "�ٻ���������ߣ���";
		c = _getch();
		if (player.get_cd() != 0)
		{
			//system("color 01");
			put("��....ħ�����㲻��ʩ��\n");
			goto L1;//CD�������ܴ������ܣ�
		}
		//system("color 01");
		put("�񰡣������������ɣ�������ߣ�������\n�䣡����\n");
		switch (c)
		{
		case 'w':player.cross_wall(map, -1, 0); break;
		case 's':player.cross_wall(map, 1, 0); break;
		case 'a':player.cross_wall(map, 0, -1); break;
		case 'd':player.cross_wall(map, 0, 1); break;
		}
	}
	else if (c == 'k')
	{
		cout << "����֮��������";
		if(player.swimmy(has_stars))//��������
		{
		get_key();
		return false;//����ѣ�μ���
		}
	}
	else
	{
	L1:
		switch (c)
		{
		case 'w':player.March(map, -1, 0); break;
		case 's':player.March(map, 1, 0); break;
		case 'a':player.March(map, 0, -1); break;
		case 'd':player.March(map, 0, 1); break;
		}
	}
	return true;//û�з���ѣ�μ���
}


void play() {
	
	SetConsoleColor(FOREGROUND_RED);
	
	put("��������:\n1�����ƺú����޵ľ��룬���ô����š���������Լ��������Ʋ��ܶ������,���պ�cdʱ����\n2�����³���wsadjk������ļ����߲����߶�\n");
	put("��ʼ�ɣ��������������.....");
	_getch();
	init();
	display();
	//Creat_stars();
	while (has_stars < 7)
	{
		//cin
		if(get_key())//����false˵�������������޲���
		//bfs the line
		monster.bfs(map,player.get_coordinate());
		//update the map
		if (!check(has_stars))throw("lose game");
		//��������֧
		if(player.is_coordinate(6,1))
		{
			if (has_stars != 3) 
			{
				put("��������\nɳ����������Ѫ��\n�׹�ǧ��¶��Ұ\n......");
				put("���߸����ſ��ڱ��Ӷ����ϵ�ʯͷ�ϵ�ʫ�䣬̾�˿���\n");
				put("��������̫ƽȮ��Ī�������ˣ�\n�ǹ�ߵ������������´��ҡ��ַ�󺵣������ԡ������Ϊ�ţ��Ĵ�����\n");
				put("�һ��ǿ�Щȥ�ռ����ǰ�\n");
			}
		    else
			{
				SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
			L2:			put("�������ϵ��������Ǵ���ɳ�����������޴�Ĳ��ˣ�һ�����¹������ֳ���\n");
				try {
					skin_play();
				}
				catch (...) {
					cout << "��q����quit���˳�,���������\n";
					if (_getch() == 'q')exit(0);
					else goto L2;
				}

			L1:	try {
				pk_play();
			}
			catch (...) {
				goto L1;
			}
			break;
			}
		}
		//dispaly
		display();
	}
	if (has_stars == 7)
	{
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
		put("���߿�����*����ǰ���������⣬��������������������Ҳ��֮�ɳ�\n");
		put("   *   \n *   * \n   *   \n *   * \n   *\n");
		system("color 70"); system("cls");
		SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED|BACKGROUND_BLUE| BACKGROUND_RED| BACKGROUND_GREEN);
		put("���߱�������һ������Ŀռ䡭������һƬ����\n");
		put("���ߣ����ǡ����ģ��ǡ����ģ��ģ�������\n");
		put("Hello������ello����llo����lo����o�����졭���������̫����ɣ�\n");
		put("����˧����������󡭡���󡭡����������ĳ����͵͵�Լ���İ�ι����\n");
		put("����������ˣ� ��|&|��    ��|&|��    ��|&|�� \n");
		put("����Ϧ��(^_^)�����ߣ�����ʲôԸ������ʲôԸ����ʲôԸ����Ը������....\n");
		//put("���ߣ����������������ЧҲ̫������\n");
		put("���ߣ���.......��ϣ���ܽ�������Σ���������Σ����Σ������\n");
		put("����\n");
		put("������Ԩ�������Σ���Ѿ�������������....\n");
		put("���ߣ������������ϣ���ô�򵥾Ϳ��Խ���������ƺ���ʲô���ԣ���������ǰ��һ�������Ŀ�˰�\n");
		put("������ʧ�ˣ��������ڶ̶̵������º�ħ������,�����ٶ�����Σ����������һ��̤���������������;����\n");
		put("��Ϸ���������B��֡��������硷\n");
		_getch();
		exit(0);
	}
	passed = true;
}

bool check(int& has_stars){
	COORDINATE tmp = player.get_coordinate();
	if (map[tmp.x][tmp.y] == 2)
	{
		++has_stars;
		map[tmp.x][tmp.y]=1;//delete stars
		--stars_in_map;
	}
	else if (is_eq(tmp, monster.get_coordinate()))
	{
		system("cls");
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		put("����....�����𽥱ƽ������ޣ���������Ϣ��Ȼ�������������������ı������۾�\n");
		put("��Ȼ....�һ���ʲô��������.....\n");
		put("ǰ��...�Բ����ҹ���������ڴ�.....\n");
		put("���ˣ������뿪����ʷ����̨�������������....");
		return false;
	}
	if (stars_in_map != 1)Creat_stars();
	
	//ʹ�ô�����
	if (map[tmp.x][tmp.y] == 3) {
		if (is_eq(tmp,one.c))tmp = (one.o)->c;
		else tmp = (another.o)->c;
		++use_send;
		put("��������׹⣬���ݡ����ݡ���ħ�����پۼ��ڴ˵�\n");
		player.alter_id(tmp);
	}

	if (use_send == 3&&!notes) {
		notes = true;
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		put("�ڴ��͵Ĺ����У�������һ�����Ƶ��ռ�\n");
		put("1��19�� �¿��Ȿ�ռǣ�ϣ���ܼ�¼����Ѱ����֮�ż������̡�\n");
		put("����\n");
		put("2��1�� ���ơ�\n");
		put("2��2�� ���ơ�\n");
		put("2��3�� ���齫�������ƺ�Ӯ�˺ܶ�Ǯ��\n");
		put("2��5�� ��ʯ֮����ʯ֮������ô����˶��䣡���������Ѱ����֮�ż�����������������ȥ�ˡ�\n");
		put("2��6�� ���ơ�u1s1���������㡣\n");
		put("����\n");
		put("5��12�� ���ڷ������λ�����˼�ˡ��籩��۴������Ǽ���ʱ����֮�ż��֡����籩��۴����ģ�������ʲô��\n");
		put("5��19�� ��lacrimae�� ����籩��۴�ָ�ľ�������Ů������ ֮�Ƶı��Ӷ����ϣ�\n");
		put("6��20�� �����ڵִﱴ�Ӷ�������,��ô�ܸо��Һ����Ӱ�����ֲ���flag��С��ɫ��Ϊ�����ҵ���Ϣ��ͻ���ȥ?\n");
		put("6��21�� ���ƺ������˾�������ܣ��ɣ��о�����ˡ���\n");
		put("�����ƺ��м�ҳ�Ѿ���˺��\n");
		put("���籩��۴������Ǽ���ʱ����֮�ż��֡���\n");
		put("�����������\n");
		_getch();
	}
	return true;
}



void pk_play() {
	//�½�ѡ��
	system("cls");
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
	put("���������߳��ڰ����Թ��������˾�ͷ\n");
	put("�����ƺ�����һ������ͶӰ���ݡ���һ�����ϵ���Ӱ������\n");
	put("���ܿ������ͶӰ����Ե�ˣ�������������Ӧ���Ѿ������������������ࡱ\n");
	put("��û���Դӵ����������ս�Ժ󣬵��򻷾���䣬����ֻ��ת�Ƶ��������\n");
	put("�����������ϣ�������磬���Ǵ����ˡ���԰�����������硱\n");
	put("�����������������������ȴ�սǰ������������á�\n");
	put("��ֱ�����������˵�Ŀ���ƺ���͸��ʱ�⣬�ֺ����ڻ����ȥ���龰\n");
	put("�˹������ն˵����������Ť��������ָ��������֡����󲿷��˵ļ��䱻ɾ��\n");
	put("��������ɵ����෴�������ⳡ������˵�ս�������\n");
	put("��񣬼�Ȼ��������ң����������һ���������˸��ӻҰ���δ��\n");
	put("����������ҩ�裬��ɫ�Ŀ�������������һ�У����»ص����������\n��ɫ�����ܹ�����ӻ��������ѣ��ص���ʵ����\n");
	put("�Աߵ�Ӣ���ٻ�ϵͳ��������԰�����սʤ����\n");
	put("����������ԥ֮ʱ����¡������������䶸��\n");
	put("�㾪�ŵ���witch�� ps:��������֮·\n");
	put("�ޣ����޾�Ȼ�ҵ������\n");
	put("���棬���������⵽�ƻ������棬���������⵽�ƻ�\n");
	put("��������Ӣ���ٻ�ϵͳ\n");
	put("��������ˣ����ٻ����������ɣ�Ƥ���� ps:�˴�Ӧ��bgm,��ϧ�Ҳ���,����ʹ����������ɫ������\n");
	system("color 36");
	put("��������ҵ�master�����˷���������ѧ��Cauchy !��\n");
	put("��С�ܵܣ���ס�ˣ��ҵ������ǡ���Alice !��\n������������̫���ɣ��������ø������������������������Ϻͷ��ӣ���\n");
	cout << "`\\' `._.' '/'    `-...-'      \\ o o /\n";
	cout << "(��)   (��)\n";
	cout << "    <~~>   \n";
	cout << "   |____|  \n ";
	put("����,Alice �� Cauchy �������Ӵ�������γ������ĶԱ�\n");

	Monster* boss = new Monster;
	Hero* hero_Cauchy = new Hero;
	Hero* hero_Alice = new Hero;
	Hero* hero_Trump = new Hero;
	hero_Cauchy->m_Name = "Cauchy"; hero_Cauchy->EquipWeapon(new Knife);
	hero_Alice->m_Name = "Alice"; hero_Alice->EquipWeapon(new MagicStick);
	hero_Trump->m_Name = "����"; hero_Trump->EquipWeapon(new GodSword);
	system("color 70");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	put("�������������վ�ս��\n����i��o��p֮һ������ѡ��Ӣ�����ս��");
	put("�����Ǹ�����ɫ���ص㣺\n ���� ʥ�����ģ���������ֵ��Ϊƽ�⣬�ɱ�������Ѫ��ѣ�Σ����������ʲ���\n");
	put("Cauchy ʥ�������������˺��ߣ����չ�Ѫ���ϵͣ�������Ѫ\n");
	put("Alice ʯ�н��޾����չ��˺��ߣ����ܱ�������������Ѫ\n");
	put("һ�����ߵ�Ѫ��Ϊ0����Ϸ��������Cauchy��AliceΪ0�Կɼ�������Ҫ�ۺϸ����ŵ���ܻ������ޣ���Ȼ����Ҫһ������\n");
	put("׼�������𣿰����������\n");
	_getch();

	system("cls");
	cout << "ս����ʽ��ʼ��\n";
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	while (true) {
		system("cls");
		cout << "*****************************************************\n";
		cout << "Monster:\n Hp:" << boss->get_m_Hp() << "  ������Def��:" << boss->get_m_Def() << "\n";

		if (hero_Trump->m_Hp <= 0) {
			cout << "����������������\n";
			cout << "�Ƿ�������\n";
			cout << "����������c\n";
			if (_getch() == 'c') {
				throw("try again");
			}
			else exit(0);
		}
		else hero_Trump->out();

		if (hero_Cauchy->m_Hp <= 0) {
			cout << "Cauchyʧȥ��ʶ\n";
			hero_Cauchy->is_energy = false;
		}
		else hero_Cauchy->out();

		if (hero_Alice->m_Hp <= 0) {
			cout << "Aliceʧȥ��ʶ\n";
			hero_Alice->is_energy = false;
		}
		else hero_Alice->out();

		cout << "��ѡ�����Ӣ�ۣ�i:���ߣ�o:Cauchy,p:Alice��\n";
		cout << "*****************************************************\n";
		char c = _getch();

		switch (c)
		{
		case 'i':
			if (hero_Trump->is_energy)
			{
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				put("star burst stream! �Ǳ�����ն��\n");
				scene();
				hero_Trump->Attack(boss);
			}
			break;
		case'o':
			if (hero_Cauchy->is_energy) {
				SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				put("��������׼��!��ү������\n");
				scene();
				hero_Cauchy->Attack(boss);
			}
			break;
		case'p':
			if (hero_Alice->is_energy) {
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				put("Excalibur������������\n");
				scene();
				hero_Alice->Attack(boss);
			}
			break;
		}
		if (boss->get_m_Hp() <= 0) {
			put(boss->get_m_Name()); put("���һ������ʥ����شﰡ���������������̩��չ����������\n");
			put("��¡һ�����죬���޾޴������׹������\n");
			break;
		}
		//�ҳ����ߵ����ֵ
		Hero* hero = nullptr;
		hero = (hero_Trump->m_Hp > hero_Cauchy->m_Hp) ? hero_Trump : hero_Cauchy;
		hero = (hero->m_Hp > hero_Alice->m_Hp) ? hero : hero_Alice;

		boss->Attack(hero);
		Sleep(2000);
	}
  
}

void scene() {
	SetConsoleColor(FOREGROUND_RED);
	system("cls");
	cout << "`-...-'                    ������_������";//20���ո�
	int cnt = 1;
	string space = " ";
	string skill = ">>";
	while (cnt < 20) {
		system("cls");
		cout << "`-...-'";
		for (int i = 1; i < cnt; ++i) {
			cout << space;
		}
		cout << skill;
		for (int i = 1; i < 20 - cnt; ++i) {
			cout << space;
		}
		cout << "������_������";
		++cnt;
		Sleep(10);
	}
	system("cls");
	cout << "`-...-'                   ������_������* * *";
	cout << endl;
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void skin_play() {
	SkinRoad skinroad;
	int round = 0;
	bool is_win = false;
	char c;
	int location;
	put("����ơ��������������ס�����̣�ʳ�续������Ȫ�������乡��������ˡ�\n");
	put("�������װ���ŵ����Ļ��䣬�����ף��Ǵ���������͸���Ĺ��󣬻��궥����һȦ��ǳ��һ�ĵ���ɫ����Ⱦ����ɡ�\n");
	put("�������ĵ�������������������������������������ѹ�ơ�\n");
	put("���߸�������������ϵ����֣�������˼\n");
	put("һ���â���������߱����͵�һ���Թ�\n");
	put("��ʱ�˿̣�����ʯǽͻȻ��ʼ�ƽ������ã������ܣ���\n");
	put("............\n");
	put("ע��˹���ʱ�����ƣ���w����s���������˹������ƶ������ʯ�����*����������·�Ϸ��ֵ�����\n");
	put("�������ƽ����飬����Ҫ��ÿһ��*������\n");
	put("ע�⣡���˹���ʱ�����ƣ�һ��ʱ����û���ܳ�һ��������Ϸ�ͻ�ʧ��\n");
	put("ÿ��һ�Ρ�w��'s'���˹���ǰ��һ�㣬���ٰ������ʯ�飬�������ž����߳��Թ���\n");
	put("���������ʼ��Ϸ\n");
	double start = (double)clock();
	double last = (double)clock() - start;
	while(!is_win){
		++round;
		if (round % 10 == 2) {
		    last = (double)clock() - start;
			last /= CLOCKS_PER_SEC;
			
			if (last > 36)break;
		}
		if (round%10==1&&Creat_random() % 100 < 10)
			skinroad.add(Creat_random()%5+1, "*");

		if(round%3==1)skinroad.add(Creat_random() % 5 + 1);
		//��ջ�����
		//cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
		c = _getch();
		location = skinroad.role();
		if (location < 5 && c == 'w')skinroad.SetLocation(++location);
		else if (location > 1 && c == 's')skinroad.SetLocation(--location);

		system("cls"); skinroad.Draw(last);
		//��������
		if (!skinroad.check())break;
		//���blocks�Ƿ�������
		if (skinroad.Memory==3)is_win = true;
	}
	if (is_win) {
		cout << "�䣡����ʯ���ڱ����Ȼ��ֹ\n";
	}
	else {
		cout << "�������������������ܲ�����\n";
		cout << "ž�����߱�ʯǽ�̴���г������\n";
		Sleep(2000);
		throw("you lose");
	};
}