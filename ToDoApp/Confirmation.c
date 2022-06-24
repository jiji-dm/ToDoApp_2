#define _CRT_SECURE_NO_WARNINGS	
#include "Confirmation.h"

/*
* task_ptrはtask[num2]のポインタ変数
*/

void confirmation(Task* task_ptr, int num) {

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
			update(&task, &task[num]);
			continue;

		case 2:
			delete(&task, &task[num]);
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