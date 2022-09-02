void move()
{
	int key = 0;//key     0:球没有被击中过   1:有被击中过
	int ballX, ballY, dX = 1, dY = 1; // 分别是球的坐标 和 球 在XY方向的速度
	int barX = 300, barY = 400, x, y;//板子的初始坐标   和板子移动后的坐标

	FILE* p,*q;   //文件指针
	int i, j;  //计数用
	
	//IMAGE bg;
	//loadimage(&bg,"bgm\\BG1.jpg" );
	//putimage(0, 0, &bg);

	srand((unsigned)(time(NULL)));
	ballX = rand() % 400 + 160;
	ballY = rand() % 300 + 50;
	


	while (TRUE)//GAMING
	{
		p = fopen("rank.txt", "w");
		q=fopen("rank.txt","r");
		
		while (!_kbhit)
		{
			if ((ballX <= 0) || (ballX >= 640))
			{
				if (num < 50)//判断用于修改小球的运行速度:X方向
					dX = dX * (-1);
				else if ((num >= 50) || (num <= 100))
					dX = dX * (-2);
				else if (num >= 100)
					dX = dX * (-3);
			}
			if ((ballY <= 15) || (ballY >= 415))
			{
				if (num < 50)//判断用于修改小球的运行速度:Y方向
					dY = dY * (-1);
				else if ((num >= 50) || (num <= 100))
					dY = dY * (-2);
				else if (num >= 100)
					dY = dY * (-3);
			}
			
		}
		
		setcolor(BLACK);//画球
		fillcircle(ballX += dX, ballY -= dY, 5);
		setfillcolor(WHITE);
		fillcircle(ballX, ballY, 5);
		Sleep(5);
		//上下合起来用实现球的移动
		setcolor(BLACK);//覆盖掉上一个球的位置
		setfillcolor(BLACK);
		fillcircle(ballX, ballY, 5);

		//判断反弹或出界
		if ((ballX >= barX) && (ballX <= barX + 48) && (ballY >= barY-5))//撞到板子弹回去    //与板子间隔一个像素来防止板子被填充
		{
			mciSendString("open src\\biu.mp3", NULL, 0, NULL);
			mciSendString("play src\\biu.mp3", NULL, 0, NULL);
			dY = dY * (-1);
			num = num + 1;
			itoa(num, strnum, 10);
			settextcolor(WHITE);
			setbkmode(OPAQUE);
			setbkcolor(BLACK);
			outtextxy(350, 420, strnum);
		}
		if (ballY <= 36)//上边界           /      /与间隔一个像素来防止上边界被填充
			dY = dY * (-1);
		if ((ballX <= 10) || (ballX >= 630))//左右边界
			dX = dX * (-1);
		if (((ballX < barX) || (ballX > barX + 48)) && (ballY > barY))   //出界
		{
			setbkcolor(BLACK);
			settextcolor(RED);
			settextstyle(50, 30, _T("黑体"));
			outtextxy(150, 130, "GAME OVER !!");
			itoa(num, strnum, 10);
			settextcolor(WHITE);
			outtextxy(180, 230, "SCORE：");
			outtextxy(380, 230, strnum);


			time(&nowtime);
			thistm = localtime(&nowtime);
			//time(&nowtime);
			//	thistm = localtime(&nowtime);


			gamer[10].score = num;							//保存当前分数和时间到gamer[10]
			gamer[10].year = thistm->tm_year + 1900;
			gamer[10].mon = thistm->tm_mon;
			gamer[10].day = thistm->tm_mday;
			gamer[10].hour = thistm->tm_hour;
			gamer[10].min = thistm->tm_min;
			gamer[10].sec = thistm->tm_sec;

			num = 0;//当前分数清空,来进行下一局游戏的计分
			settextstyle(25, 15, _T("黑体"));
			outtextxy(170, 350, "Enter any key . . . . . .");
			getch();
			
			return;



		}
											 //排序//排序操作,由于数量不大,采用冒泡排序  定义一个temp来存放临时结构体数据
		for (i = 0; i <= 9; i++)
			fread(&gamer[i], sizeof(struct rank), 1, q);
		fclose(q);
		for (i = 0; i <= 9; i++)
			for (j = 0; j <= 9; j++)
			{
				if (gamer[i].score <= gamer[i + 1].score)
				{
					temp = gamer[i];
					gamer[i] = gamer[i + 1];
					gamer[i + 1] = temp;
				}
			}
		for(i=0;i<=9;i++)
		fwrite(&gamer[i], sizeof(struct rank), 1, p);

		fclose(p);


		if (barX <= 0)//控制板子只能在视野内
			barX = 0;
		if (barX >= 613)
			barX = 613;

		//球拍的运动    每次移动十个像素

		int kb;
		x = barX;
		y = barY;

		if (_kbhit()) //判断有键按下时才执行下面的操作

		{
			kb = _getch();   //用kb来获取键值
			if (kb == 224)
			{
				kb = _getch();//值为224时表示按下了方向键，要再次获取才行
				if (kb == 75) 
				{
					barX -= 10;
					setfillcolor(BLACK);
					bar(x = barX + 10, y, x + 48, y + 4);
					setfillcolor(WHITE);
					bar(barX, barY, barX + 48, barY + 4);
				}

				if (kb == 77) 
				{
					barX += 10;
					setfillcolor(BLACK);
					bar(x = barX - 10, y, x + 48, y + 4);
					setfillcolor(WHITE);
					bar(barX, barY, barX + 48, barY + 4);
				}
			}
			
		}


	

		/*	while ((kb = _getch()) != 0x1B)//阻塞函数    必须提奥果  在无键盘输入的情况跳出,现无解决办法
			{
				switch (kb)
				{
				case 0xE0:
					switch (kb = _getch())
					{
					case 75:
						barX -= 10;
						setfillcolor(BLACK);
						bar(x = barX + 10, y, x + 48, y + 4);
						setfillcolor(WHITE);
						bar(barX, barY, barX + 48, barY + 4);
						break;
					case 77:
						barX += 10;
						setfillcolor(BLACK);
						bar(x = barX - 10, y, x + 48, y + 4);
						setfillcolor(WHITE);
						bar(barX, barY, barX + 48, barY + 4);
						break;

					}
					break;
				}
				break;

			}*/
		

	}



	

	
}

