int menu()
{
	initgr();
	setbkmode(TRANSPARENT);
	settextstyle(23, 15, _T("黑体"));
	settextcolor(RED);
	outtextxy(200, 120, "Pingpong Game!!");
	settextcolor(GREEN);
	outtextxy(250, 160, "---FangMingxuan ");
	settextcolor(BLUE);
	outtextxy(200, 200, "1.Start Game");
	outtextxy(200, 240, "2.Exit  Game ");
	outtextxy(200, 280, "3.Rank  ");
	
	int sel;
	//printf("Please enter your selection:	");
	sel = _getch();
	//scanf_s("%d", &sel);

	while (sel < 49 || sel>51)//_getch()函数  的  1-->49   2-->50   3-->51    .. .. . .. . .. .
	{
		initgr();
		settextstyle(23, 15, _T("黑体"));
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		outtextxy(30, 120, "ERROR: Please enter correct selection!!!");
		settextcolor(GREEN);
		outtextxy(30, 160, "You should enter your selection again!!!");
		outtextxy(30, 200, "Please enter your selection:	");
		settextcolor(BLUE);
		outtextxy(200, 240, "1.Start Game");
		outtextxy(200, 280, "2.Exit  Game ");
		outtextxy(200, 320, "3.Rank  ");
		sel = _getch();
	}

	switch(sel)
	{
	case 49:initgr(); picture(); move(); menu(); break;
	case 50:closegr(); break;
	case 51:rank(); menu(); break;
	}




	return 0;
	system("pause");
}