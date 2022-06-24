#define _CRT_SECURE_NO_WARNINGS	
#include "Update.h"

void update(Task* p_task, Task* task_ptr) {

	while (1) {
		
		printf("タスクのタイトルを入力してください(必須)\n");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%s", task_ptr->title);

		if (task_ptr->title[0] == '\0') {
			printf("titleは必ず記入してください");
			continue;
		}
		else {
			break;
		}
	}

	printf("タスクの期限を入力してください\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr->deadLine);

	printf("タスクの概要があれば記入してください\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s", task_ptr->mainSubject);

	//現在日時・時刻を取得
	t = time(NULL);
	struct tm* local = localtime(&t);

	strftime(task_ptr->date, sizeof(task_ptr->date), "%Y/%m/%d %a %H:%M:%S %A", local);

	//編集前のtxtファイルに編集内容を上書きする

	fopen_s(&fp, "tasklist.txt", "w");
	int u;

	for (u = 0; u < TASKMAX; u++) {
		if ((p_task + u)->id != 0) {
			
			fprintf(fp, "%d %s, %s, %s, %s\n",
				(p_task + u)->id, (p_task + u)->title, (p_task + u)->deadLine, (p_task + u)->mainSubject, (p_task + u)->date);
		}
	}
	fclose(fp);
}


