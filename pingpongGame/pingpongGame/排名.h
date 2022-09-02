void rank()
{
	FILE *p;

	int i, j;
	char stri[5];

	p = fopen("rank.txt", "r+");
	for(i=0;i<=10;i++)
	fread(&gamer[i], sizeof(struct rank), 1, p);

	

	//排名界面
	cleardevice();
	settextcolor(RED);
	settextstyle(50, 30, _T("Arial"));
	outtextxy(225,40, "RANK");
	settextstyle(15, 10, _T("Arial"));
	settextcolor(WHITE);
	outtextxy(180, 80, "----------------------------------------");
	outtextxy(159, 90, "----------------------------------------------");
	
	outtextxy(180, 105, "|");
	outtextxy(190, 105, "  SCORE   |       TIME ");

	for (i = 0; i <= 9; i++)
	{
		itoa(i+1,stri,10);
		outtextxy(160, 120 + 20 * i, stri);
		outtextxy(180, 120+20* i, "|");

		itoa(gamer[i].score, stri, 10);
		outtextxy(230, 120 + 20 * i, stri);
		outtextxy(292, 120 + 20 * i, "|");

	
		itoa(gamer[i].year, stri, 10);
		outtextxy(300, 120 + 20 * i, stri);
		outtextxy(345, 120 + 20 * i, "-");
		itoa(gamer[i].mon, stri, 10);
		outtextxy(350, 120 + 20 * i, stri);
		outtextxy(375, 120 + 20 * i, "-");
		itoa(gamer[i].day, stri, 10);
		outtextxy(380, 120 + 20 * i, stri);
		itoa(gamer[i].hour, stri, 10);
		outtextxy(410, 120 + 20 * i, stri);
		outtextxy(435, 120 + 20 * i, ":");
		itoa(gamer[i].min, stri, 10);
		outtextxy(440, 120 + 20 * i, stri);

		Sleep(500);                       //动态
	}








	fclose(p);
	getch();//阻滞 防止直接跳转闪退
}