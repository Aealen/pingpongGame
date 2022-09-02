int num = 0;//用来统计当前分数
char strnum[5];//用来统计当前分数对于的字符串
int k;

struct rank
{
	//int rank;						//决定不在结构体内添加排名 ,直接用数组来确定排名
	int score;    
								   //	2020/6/20__17:00      //     年  月  日  时  分  /0
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};

struct rank gamer[11] = {0};  //记录rank10   其中 gamer[10]为临时参数 记录当前游戏分数  来进行下一步的排名操作 
struct rank temp = { 0 };


time_t nowtime;			  //此操作获取当前系统时间来进行排名记录   由于是单机,所以用时间来代替用户名
struct tm* thistm;;

//time(&nowtime);
//thistm = localtime(&nowtime);
//printf("%02d:%02d:%02d\n", thistm->tm_hour, thistm->tm_min, thistm->tm_sec);
