#define _CRT_SECURE_NO_WARNINGS	
#include "Delete.h"

/*
* p_taskはtask[0]のポインタ変数
* task_ptrはtask[num2]のポインタ変数
*/

void delete(Task* p_task, Task* task_ptr) {
	
	//選ばれた配列番号の構造体を初期化
	memset(task_ptr, 0, sizeof(task_ptr));
	printf("タスクを削除しました");

	//上書きモードを使用し、ファイルを書き換える。（前のファイルはなくなる）
	fopen_s(&fp, "tasklist.txt", "w");
	int d;

	for (d = 0; d < TASKMAX; d++) {
		if ((p_task + d)->id != 0) {
			fprintf(fp, "%d %s, %s, %s, %s\n",
				(p_task + d)->id, (p_task + d)->title, (p_task + d)->deadLine, (p_task + d)->mainSubject, (p_task + d)->date);
		}
	}
	fclose(fp);

	//構造体の配列全体の初期化
	memset(p_task, 0, sizeof(task));

};