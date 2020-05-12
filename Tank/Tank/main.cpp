
#include "Graph.h"
#include "mainTank.h"
#include "enemyTank.h"
#include "Shape.h"
#include "setting.h"
#include <iostream>
#include <conio.h>  //键盘交互
#include <ctime>  //随机函数
#include <list>
using namespace std;
#define MAX_TANKS 10


//多态的体现
list<Object *> lstBombs;
list<Object*> lstMainTankBullets;
list<Tank *> lstTanks;

list <Object*> lstBullets;

mainTank my_Tank;
void checkCrash(){
	//遍历mantank的炮弹和坦克list，进行碰撞检测
	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		for (list<Tank*>::iterator itt = lstTanks.begin(); itt != lstTanks.end(); itt++)
		{
			if (Shape::checkIntersect((*it)->getSphere(),(*itt)->getSphere()))
			{
				//碰撞检测，设置消失的标志位true
				(*itt)->setDisappear();
				(*it)->setDisappear();
			}
		}
	}

	//check mainTank life
	for (list<Object *>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++) {
		if (Shape::checkIntersect((*it)->getSphere(), my_Tank.getSphere()))
		{
			Setting::Die();

			if (Setting::GetLife() > 0)
			{
				(*it)->setDisappear();
			}
			else
			{
				my_Tank.setDisappear();
			}
		}
	}
}

int main() {
	srand((unsigned)time(NULL));  //随机数种子，以时间为随机数种子
	Graph::graphOpen();
	


	lstMainTankBullets.clear();
	lstBombs.clear();
	lstTanks.clear();
	lstBullets.clear();

	bool loop = true;
	bool skip = false;
	bool bGameOver = false;

	while (loop) {

		
		if (_kbhit()) {
			int key = _getch();
			switch (key)
			{
			case 'w':
			case 'W':
			case 72:
				my_Tank.setDir(direction::up);
				break;
			case 's':
			case 'S':
			case 80:
				my_Tank.setDir(direction::down);
				break;
			case 'a':
			case 'A':
			case 75:
				my_Tank.setDir(direction::left);
				break;
			case 'd':
			case 'D':
			case 77:
				my_Tank.setDir(direction::right);
				break;

			case 27:  //esc
				loop = false;
				break;
			case 32:  //space
				my_Tank.Shoot(lstMainTankBullets);
				break;

			case 13: //enter -> pause
				if (skip)
					skip = false;
				else
					skip = true;
				break;

			default:
				break;
			}
		}


		if (!skip) {
			if (bGameOver) {
				break;
			}
			cleardevice();
			Graph::drawBattleGround();
			checkCrash();

			Graph::showScore();
			if (Setting::m_bNewLevel)
			{
				Setting::m_bNewLevel = false;

				Setting::NewGameLevel();

				Graph::ShowGameLevel(Setting::GetGameLevel());

				for (int i = 0; i < Setting::GetTankNum(); i++)
				{
					enemyTank* p = new enemyTank();
					lstTanks.push_back(p);
				}

				// 设置暂停，按Enter开始
				skip = true;
				continue;
			}
			if (my_Tank.IsDisappear()) {
				skip = true;
				bGameOver = true;
				Graph::ShowGameOver();
				continue;
			}
			
			my_Tank.tankMove();
			my_Tank.tankDisplay();


			//draw tanks
			for (list<Tank* >::iterator it = lstTanks.begin(); it != lstTanks.end();)  //这里值得注意问题it++
			{
				(*it)->tankMove();

				if ((*it)->IsDisappear()) { 
					Setting::TankGamaged();
					(*it)->Boom(lstBombs);
					delete *it;
					it = lstTanks.erase(it);
					continue;
				}
				(*it)->tankDisplay();
				if ((*it)->NeedShoot()) {
					enemyTank *p = (enemyTank*)*it;
					p->Shoot(lstBullets);
				}
				it++;
			}

			//draw bullets
			for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end();)
			{
				(*it)->tankMove();
				if ((*it)->IsDisappear())
				{
					(*it)->Boom(lstBombs);
					delete *it;
					it = lstMainTankBullets.erase(it);
					continue;
				}

				(*it)->tankDisplay();
				it++;
			}
			for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();)
			{
				(*it)->tankMove();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete *it;
					it = lstBullets.erase(it);
					continue;
				}

				(*it)->tankDisplay();
				it++;
			}
			//draw booms
			for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end();)
			{
				(*it)->tankMove();

				if ((*it)->IsDisappear())
				{
					delete *it;
					it = lstBombs.erase(it);
					continue;
				}

				(*it)->tankDisplay();
				it++;
			}
			Graph::showScore();
		}
		Sleep(200);
	}
	
	// Destroy
	for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete *it;
	}
	lstTanks.clear();

	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		delete *it;
	}
	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete *it;
	}
	lstBullets.clear();
	for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete *it;
	}
	lstBombs.clear();
	
	Graph::graphClose();
	system("pause");
	return EXIT_SUCCESS;
}