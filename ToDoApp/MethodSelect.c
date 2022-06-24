#define _CRT_SECURE_NO_WARNINGS	
#include "MethodSelect.h"


void methodSelect(int selectNum, int taskNum) {

	//入力されたタスク番号(taskNum)があるかを判定し、編集か削除(selectNum)でメソッドの処理を実行する
	int num1;
	int num2 = taskNum - 1;

	for (num1 = 0; num1 < TASKMAX; num1++) {

		if (taskNum == task[num2].id) {

			switch (selectNum)
			{
			case 0:
				confirmation(&task[num2], num2);
				break;

			case 1:
				delete(&task, &task[num2]);
				break;

			default:
				break;
			}
			break;
		}
		else {
			printf("入力されたIDが見つかりません");
		}
	}

}