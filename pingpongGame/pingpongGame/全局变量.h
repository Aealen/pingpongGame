int num = 0;//����ͳ�Ƶ�ǰ����
char strnum[5];//����ͳ�Ƶ�ǰ�������ڵ��ַ���
int k;

struct rank
{
	//int rank;						//�������ڽṹ����������� ,ֱ����������ȷ������
	int score;    
								   //	2020/6/20__17:00      //     ��  ��  ��  ʱ  ��  /0
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};

struct rank gamer[11] = {0};  //��¼rank10   ���� gamer[10]Ϊ��ʱ���� ��¼��ǰ��Ϸ����  ��������һ������������ 
struct rank temp = { 0 };


time_t nowtime;			  //�˲�����ȡ��ǰϵͳʱ��������������¼   �����ǵ���,������ʱ���������û���
struct tm* thistm;;

//time(&nowtime);
//thistm = localtime(&nowtime);
//printf("%02d:%02d:%02d\n", thistm->tm_hour, thistm->tm_min, thistm->tm_sec);
