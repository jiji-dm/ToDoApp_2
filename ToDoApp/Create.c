#define _CRT_SECURE_NO_WARNINGS	

#include "Create.h"

void create(Task *task_ptr) {
	printf("新規登録します\n表示された項目を入力してください\n");
	int num2;
	for (num2 = 0; num2 < TASKMAX; num2++) {

		//初期化されていない構造体の配列を探し、id = 0（int初期化値）の場所に初期化する
		if ((task_ptr + num2)->id == 0)
		{
			//idが設定されていない(id = 0)配列を使用し,かつidを配列番号によって決める
			(task_ptr + num2)->id = num2 + 1;
			
			while (1) {
				printf("タスクのタイトルを入力してください(必須)\n");
				fgets(line, sizeof(line), stdin);
				sscanf(line, "%s", (task_ptr + num2)->title);

				if ((task_ptr + num2)->title[0] == '\0') {
					printf("titleは必ず記入してください");
					continue;
				}else {
					break;
				}
			}

			printf("タスクの期限を入力してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->deadLine);

			printf("タスクの概要があれば記入してください\n");
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s", (task_ptr + num2)->mainSubject);

			//現在日時・時刻を取得
			t = time(NULL);
			struct tm* local = localtime(&t);

			strftime((task_ptr + num2)->date, sizeof((task_ptr + num2)->date), "%Y/%m/%d %a %H:%M:%S", local);

			#define C_TASK (task_ptr + num2)

			fopen_s(&fp, "tasklist.txt", "a");
			fprintf(fp, "%d, %s, %s, %s, %s\n",
				C_TASK->id, C_TASK->title, C_TASK->deadLine, C_TASK->mainSubject, C_TASK->date);
			fclose(fp);
			
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