#include "DataManager.h"
#include "Player.h"
#include "GameManager.h"
#include <iostream>
int isSave = 0;//�Ƿ��д浵
void writeData() {
	//�����������
	FILE* fp;//��Ϸ�浵�ļ����
	fopen_s(&fp, "save.txt", "wb");
	if (fp == NULL) {
		fprintf(stderr, "Can't open save.txt!\n");
		exit(1);
	}

	//�������
	else {
		fwrite(&OBJ_Player, sizeof(OBJ_Player), 1, fp);
		fscanf(fp, "%d", &OBJ_Player.health);
		fclose(fp);
	}
}
void loadData(Player& OBJ_Player) {
	FILE* fpp;
	fopen_s(&fpp, "save.txt", "rb");
	if (fpp == NULL) {
		fprintf(stderr, "Can't open save.txt!\n");
		exit(2);
	}
	else {
		fread(&OBJ_Player, sizeof(Player), 1, fpp);//��ȡ��ҵ�״̬
		fclose(fpp);//�ر�
	}
}