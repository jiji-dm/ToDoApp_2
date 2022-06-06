#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

typedef struct {
	int id;					//プライマリーキー（必須）
	char title[100];		//題名（必須）
	char date[100];			//登録日（必須）
	char deadLine[100];		//期限
	char mainSubject[200];	//概要
}Task;

Task task[10];		//タスクの数１０件
//Task* task_ptr;		//task[0]のポインタ変数


void create(Task *task_ptr);									//新規登録
void confirmation(Task* task_ptr);				//内容確認(編集/削除)
void delete(Task* task_ptr);					//削除
void update(Task* task_ptr);			//編集時のUser入力をメンバ変数に格納するメソッド
void methodSelect(int selectNum, int taskNum);	//変更/削除をするタスクのidと、使用するメソッドを条件分岐により動く

time_t t;			//<time.h>のtime_t型から現在日時を取得する


char line[100];		//sscanfで読み込むための変数
int selectC;		//confirmation時の選択番号



int main(void) {
	
	

	//抜けるには終了を選択で選ぶ
	while (1) {

		//タスク一覧を表示させる(id + title)
		int i;

		printf("| TaskID | Title | 期限  \n");
		for (i = 0; i < 10; i++)
		{
			if (task[i].id != 0) {
				printf("・  %d  /  %s  /  %s   \n", task[i].id, task[i].title, task[i].deadLine);
			};
		};

		//選択フェーズ
		printf("タスク操作を操作、番号を入力してください\n");
		printf("[1:新規登録] [2:詳細] [3:削除] [4:終了] ");
		
		int select;			//最初の選択番号

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &select);

		//選択された番号(select)を条件分岐
		switch (select)
		{
		case 1:
			create(&task);
			continue;

		case 2:
			printf("詳細を表示するタスクIDを入力してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%d", &select);

			methodSelect(0, select);
			continue;

		case 3:
			printf("削除するタスクIDを入力してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%d", &select);

			methodSelect(1, select);
			continue;

		case 4:
			printf("終了します\n");
			break;

		default:
			printf("正しく数値が入力されていません\n");
			continue;
		};

		break;
	};

	return 0;
};




void methodSelect(int selectNum, int taskNum) {
	
	//入力されたタスク番号(taskNum)があるかを判定し、編集か削除(selectNum)でメソッドの処理を実行する
	int num1;
	
	for (num1 = 0; num1 < sizeof(task); num1++) {
		
		if (taskNum == task[taskNum - 1].id) {
			
			switch(selectNum)
			{
			case 0:
				confirmation(&task[taskNum - 1]);
				break;

			case 1:
				delete(&task[taskNum - 1]);
				break;

			default:
				break;
			}
			break;
		}else {
			printf("入力されたIDが見つかりません");
		}
	}
		
}

void create(Task *task_ptr) {
	printf("新規登録します\n表示された項目を入力してください\n");
	int num2;
	for (num2 = 0; num2 < sizeof(task_ptr); num2++) {
		if ((task_ptr + num2)->id == 0)
		{
			//idが設定されていない(id = 0)配列を使用し,かつidを配列番号によって決める
			(task_ptr + num2)->id = num2 + 1;
			
			printf("タスクのタイトルを入力してください(必須)\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->title);

			printf("タスクの期限を入力してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->deadLine);

			printf("タスクの概要があれば記入してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->mainSubject);

			//現在日時・時刻を取得
			t = time(NULL);
			struct tm* local = localtime(&t);

			strftime((task_ptr + num2)->date, sizeof((task_ptr + num2)->date), "%Y/%m/%d %a %H:%M:%S %A", local);
			
			break;
		}
		else 
		{	
			if (num2 == 9) {
				printf("タスクが最大件数であるため、新規登録するにはタスクを削除してください\n");
				break;
			}
			//idが設定されている場合は、スキップする
			continue;
		}
	}
};

void confirmation(Task *task_ptr) {
	
	while (1) {

		printf("ID = %d\nタイトル = %s\n登録日 = %s\n期限日 = %s\n概要 = %s\n",
			task_ptr->id, task_ptr->title, task_ptr->date, task_ptr->deadLine, task_ptr->mainSubject);

		printf("[1:編集] [2:削除] [3:戻る] \n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &selectC);

		switch (selectC)
		{
		case 1:
			printf("編集します\n");
			update(task_ptr);
			continue;

		case 2:
			delete(task_ptr);
			break;

		case 3:
			break;

		default:
			printf("正しく選択されていません\n");
			continue;
		}
		break;
	}
};

void delete(Task* task_ptr) {
	memset(task_ptr, 0, sizeof(task));
	printf("タスクを削除しました\n");
};

void update(Task* task_ptr) {

	printf("タスクのタイトルを入力してください(必須)\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> title);
	
	printf("タスクの期限を入力してください\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> deadLine);

	printf("タスクの概要があれば記入してください\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr -> mainSubject);

	//現在日時・時刻を取得
	t = time(NULL);
	struct tm* local = localtime(&t);

	strftime(task_ptr->date, sizeof(task_ptr ->date), "%Y/%m/%d %a %H:%M:%S %A", local);
}
