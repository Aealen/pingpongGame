void move()
{
	int key = 0;//key     0:��û�б����й�   1:�б����й�
	int ballX, ballY, dX = 1, dY = 1; // �ֱ���������� �� �� ��XY������ٶ�
	int barX = 300, barY = 400, x, y;//���ӵĳ�ʼ����   �Ͱ����ƶ��������

	FILE* p,*q;   //�ļ�ָ��
	int i, j;  //������
	
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
				if (num < 50)//�ж������޸�С��������ٶ�:X����
					dX = dX * (-1);
				else if ((num >= 50) || (num <= 100))
					dX = dX * (-2);
				else if (num >= 100)
					dX = dX * (-3);
			}
			if ((ballY <= 15) || (ballY >= 415))
			{
				if (num < 50)//�ж������޸�С��������ٶ�:Y����
					dY = dY * (-1);
				else if ((num >= 50) || (num <= 100))
					dY = dY * (-2);
				else if (num >= 100)
					dY = dY * (-3);
			}
			
		}
		
		setcolor(BLACK);//����
		fillcircle(ballX += dX, ballY -= dY, 5);
		setfillcolor(WHITE);
		fillcircle(ballX, ballY, 5);
		Sleep(5);
		//���º�������ʵ������ƶ�
		setcolor(BLACK);//���ǵ���һ�����λ��
		setfillcolor(BLACK);
		fillcircle(ballX, ballY, 5);

		//�жϷ��������
		if ((ballX >= barX) && (ballX <= barX + 48) && (ballY >= barY-5))//ײ�����ӵ���ȥ    //����Ӽ��һ����������ֹ���ӱ����
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
		if (ballY <= 36)//�ϱ߽�           /      /����һ����������ֹ�ϱ߽类���
			dY = dY * (-1);
		if ((ballX <= 10) || (ballX >= 630))//���ұ߽�
			dX = dX * (-1);
		if (((ballX < barX) || (ballX > barX + 48)) && (ballY > barY))   //����
		{
			setbkcolor(BLACK);
			settextcolor(RED);
			settextstyle(50, 30, _T("����"));
			outtextxy(150, 130, "GAME OVER !!");
			itoa(num, strnum, 10);
			settextcolor(WHITE);
			outtextxy(180, 230, "SCORE��");
			outtextxy(380, 230, strnum);


			time(&nowtime);
			thistm = localtime(&nowtime);
			//time(&nowtime);
			//	thistm = localtime(&nowtime);


			gamer[10].score = num;							//���浱ǰ������ʱ�䵽gamer[10]
			gamer[10].year = thistm->tm_year + 1900;
			gamer[10].mon = thistm->tm_mon;
			gamer[10].day = thistm->tm_mday;
			gamer[10].hour = thistm->tm_hour;
			gamer[10].min = thistm->tm_min;
			gamer[10].sec = thistm->tm_sec;

			num = 0;//��ǰ�������,��������һ����Ϸ�ļƷ�
			settextstyle(25, 15, _T("����"));
			outtextxy(170, 350, "Enter any key . . . . . .");
			getch();
			
			return;



		}
											 //����//�������,������������,����ð������  ����һ��temp�������ʱ�ṹ������
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


		if (barX <= 0)//���ư���ֻ������Ұ��
			barX = 0;
		if (barX >= 613)
			barX = 613;

		//���ĵ��˶�    ÿ���ƶ�ʮ������

		int kb;
		x = barX;
		y = barY;

		if (_kbhit()) //�ж��м�����ʱ��ִ������Ĳ���

		{
			kb = _getch();   //��kb����ȡ��ֵ
			if (kb == 224)
			{
				kb = _getch();//ֵΪ224ʱ��ʾ�����˷������Ҫ�ٴλ�ȡ����
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


	

		/*	while ((kb = _getch()) != 0x1B)//��������    ������¹�  ���޼���������������,���޽���취
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

