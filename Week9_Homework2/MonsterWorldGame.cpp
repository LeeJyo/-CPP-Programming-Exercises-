#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("����������", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Siangshi("����", "SS", rand() % w, rand() % h, false));
	game.add(new Smombi("������", "MM", rand() % w, rand() % h));
	game.play(455, 10);
	printf("------���� ����-------------------\n");
}