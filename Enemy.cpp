#include "Enemy.h"
#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59
#define WDITH_ENEMY1 43
#define HEIGT_ENEMY1 58
EnemyNode* createEnemy(int x0, int y0, double angle, int vx, int vy, EnemyName name)
{
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->x = x0;
		pNew->y = y0;
		pNew->vx = vx;
		pNew->vy = vy;

	}

	pNew->weaponLevel = 0;
	pNew->isExist = 1;
	pNew->pnext = nullptr;


	return pNew;
}
void update_EnemyPosition(EnemyName name) {

}