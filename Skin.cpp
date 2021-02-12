#ifndef Skin_h
#define Skin_h
#include<string>
#include<list>
#include<iostream>

struct Block{
	int x, y;
	std::string Name;
	Block(int _y,std::string s="��") :x(20), y(_y),Name(s){};
};

BOOL inline SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

void inline put(std::string c)
{
	for (int i = 0; i < c.size(); ++i) {
		std::cout << c[i];
		Sleep(10);
	}
	Sleep(500);
}

class SkinRoad {
private:
	std::list<Block>Blocks;

	int location=3;

public:
	int Memory = 0;

	//sign��ʾy
	void add(int sign,std::string s="��") {
		Block a(sign,s);
		Blocks.push_back(a);
	}

	void popBlock() {
		if (Blocks.empty())return;
		Blocks.pop_front();
	}

	bool Find(int _x, int _y) {
		for (auto i = Blocks.begin(); i!= Blocks.end(); ++i) {
			if (i->x == _x && i->y == _y)
			{
				std::cout << i->Name;
				return true;
			}
		}
		return false;
	}
	bool check(){
		auto i = Blocks.begin();
		for (;i!=Blocks.end(); ++i)--(i->x);
		i = Blocks.begin();
		if (i->x <= 0) {
			if (i->y == location)
			{
				if(i->Name=="��")
				   return false;
				else if(i->Name=="*")
				{
					++Memory;
					if (Memory == 1) {
						SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						put("���ƺ���һ���鼮�������ҳ����ƺ���һ���С���ʷ�ĳ��������鼮\n");
						put("                      ��ҳ\n");
						put("    �ȵ۴�ҵδ����е����㣬������ƣ�ף��˳�Σ������֮��Ҳ��\n");
						put("����Ϧ�£���Ԩ��ĩ��Robert֮��Ҳ�������ȵۼ����������\n........\n");
						put("����������ƺ������ڱʸ�������\n");
						put("�Ȿ���ƺ��õ��ǹ������Ϊʲô����������ֻ�������������\n");
						put("��Robert���ƺ����������÷�Χ��������֮һ��������һ���ƽ�����ʧ��������ʲô��˼��\n");
						SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
					}
					else if (Memory == 2) {
						SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						put("���ƺ���һҳ���Ƶ��ռ�\n");
						put("    ά������԰��ʵ����̫���ˣ���˵����ƺ�����֣ˬ�й�\n");
						put("�����̣������ǹ¶����������̣���������֣ˬ��\n");
						put("д���ˣ���˵����԰������������ָ��������֡������ܸо�������Щ���װ�\n");
						put("���ˣ���Щ����������Ĵ��������ȥ��\n");
						put("�������ĵ����������������������...�������������\n");
						put("world war III��������ģ���Ȼ������Ҫ�����������ռ���\n");
						put("��үү˵�������Ǹ�ʱ����һ�ֶ�����ɫƤ�������ɽУ���ר�ųԺ���ģ���˵����ҲԽ��Խ�ټ��˰�\n");
						//put("�����������������ֵ�һֻС���ܣ�lululululululu\n��");
						put("����˵������ɫ�ģ����Ҳ����ɫ�ģ�������������\n");
						SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
					}
					else if (Memory == 3) {
						put("���� ���̶ܳȣ�III ǩ���ˣ�����ͯ \n");
						put("�����һϵ��������ʾ���������硰�������ƺ������쳣��������ȡ����������ʩ����\n");
						put("����������ƺ���ָ��������ƫ�������֤�ݲ��㣬���д��۲�\n");
						put("�ݡ��й�����Ĺ���취���������涨������ҳ�ʵ��ǡ�����������������ס������Լ�Ŀ��\n");
						put("��ʵ�����������������\n");
						put("...........\n");
						put(".....................\n");
						put("�����Ķ��ߣ�����������>~<\n�����������\n");
						_getch();
					}
				}
				
			}
			popBlock();
		}

		return true;
	}

	bool is_empty() { return Blocks.empty(); }

	int role() { return location; }

	void Draw(double last){
		auto iter=Blocks.begin();
		std::cout << "_____________________\n";
		std::cout <<"time: "<< last<< "s\n";
		std::cout << "_____________________\n";
		for (int j = 5; j > 0; --j) {
			//�������˹�
			if (j == location)std::cout << "@";
			else std::cout <<" ";

			//�����ϰ���
			for (int i = 1; i <= 20; ++i){
				if (!Find(i, j))std::cout << " ";
			}
			std::cout << "\n";
		}
		std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	}

	void SetLocation(int _y) {
		location = _y;
	}
};
#endif
