void initgr()
{
	IMAGE bg;
	loadimage(&bg,"src\\BG1.jpg" );
	initgraph(640, 480);//��ʼ������
	putimage(0,0,&bg);
	mciSendString("open src\\BGM.mp3", NULL, 0, NULL);
	mciSendString("play src\\BGM.mp3", NULL, 0, NULL);
}

void picture()
{
	int x, y, i, color;//����ʼͼ
	setcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(23, 15, _T("����"));
	outtextxy(150, 350, "Enter Any Key .. .. ..");

	while (!kbhit())
	{
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		outtextxy(190, 100, "Pingpong Game");
		settextcolor(RED);
		outtextxy(100, 200, "Rules:");
		settextcolor(BLUE);
		outtextxy(190, 200, "Use Right and Left key to ");
		outtextxy(100, 250, "move the bat to catch the ball !!");//����
		getch();
		break;
	}

	cleardevice();
	setbkmode(TRANSPARENT);
	setbkcolor(BLUE);
	setfillstyle(SOLID_FILL, RED);
	bar(300, 400, 348, 404);//��һ���ޱ߿�������,bar(left,top,right,bottom)     ����

	settextcolor(WHITE);
	outtextxy(250, 420, "SCORE: ");//��ʾ����
	outtextxy(350, 420, "0");




	//��ʼ����Ļ�϶˵ķ���
	srand((unsigned)time(NULL));
	for (y = 15; y <= 15; y = y + 15)
	{
		if ((y / 15) % 2 == 0)
			i = 1;
		else
			i = 0;

		for (x = 0; x <= 640; x = x + 32)
		{
			if ((y / 32) % 2 == 0 && i == 1)
				color = 5;
			else if (i == 1 && (x / 32) % 2 == 1)
				color = 15;
			else if (i == 0 && (x / 32) % 2 == 0)
				color = 15;
			else
				color = 5;
			//color=((rand()%5)+2)
			setfillstyle(SOLID_FILL, color);
			bar(x, y, x + 30, y + 13);
		}
	}
	Sleep(1);

}

void closegr()//�ر�ͼ��
{
	cleardevice();
	closegraph();
}

void end()
{
	cleardevice();
	setbkcolor(0);
	switch (k)//kΪ   1 : �����˳�     0 : ��ESC�˳�
	{
	case 1:
		setcolor(RED);
		settextstyle(23, 15, _T("����"));
		outtextxy(200, 150, "emmm...I think you lost just now !!");
		itoa(num, strnum, 10);//��num���ְ�ʮ���Ʒ�ʽת��Ϊ���ڵ��ַ��� 
		outtextxy(400,420, strnum);//���뵱ǰ����
		Sleep(2);
		break;
	case 0:
		cleardevice();
		settextstyle(23, 15, _T("����"));
		outtextxy(250, 240, "GAME��OVER������");
		Sleep(2);
		break;
	}
}


void bomb(int x, int y)
{
	int r1, i;
	int pointX, pointY, point_color;

	setcolor(YELLOW);
	for(r1=1;r1<=4;r1++)
	{
		circle(x + 18, y + 7, r1);
		Sleep(1);
	}
	Sleep(3);
	setcolor(BLUE);
	for (r1 = 6; r1 >= 1; r1--)
	{
		circle(x + 16, y + 7, r1);
		Sleep(1);
	}
	for (i = 1; i <= 50; i++)
	{
		point_color = rand() % 15;
		pointX = (rand()%32 + x);
		pointY = (rand() % 15 + y);
		putpixel(pointX, pointY, point_color);
		Sleep(1);
	}
	setfillstyle(1, BLUE);
}