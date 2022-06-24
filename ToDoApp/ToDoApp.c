#define _CRT_SECURE_NO_WARNINGS		//VSのC++コンパイラの警告を解放する

#include <stdio.h>
#include "Create.h"		
#include "Confirmation.h"
#include "Delete.h"
#include "MethodSelect.h"
#include "Update.h"

extern FILE* fp;				//ファイル呼び出すための変数

extern char line[LINEMAX];		//sscanfで読み込むための変数
extern char f_line[LINEMAX];

int main(void) {

	//抜けるには終了を選択で選ぶ
	while (1) {

		/*テキストファイルからデータを読み込み、
		構造体変数に格納してからidを１から順の番号にし、
		順番を並び替えるために更新する
		*/

		/*** ファイルの読み込み ***/	
		//ファイルを読み込みモードで開く
		fopen_s(&fp, "tasklist.txt", "r");

		int plus = 0;	//構造体配列の要素番号の初期化

		//ファイルの中身を一行ずつ構造体メンバ変数に代入していく
		while (fgets(f_line, LINEMAX, fp) != NULL){
			sscanf(f_line, "%d %[^,], %[^,], %[^,], %[^\n]",
				&task[plus].id, &task[plus].title, &task[plus].deadLine, &task[plus].mainSubject, &task[plus].date);
				
			//タスクIDを順番通りにする（配列の要素番号によってIDを変更する)
			task[plus].id = plus + 1;
				
			plus++;
		}
		fclose(fp);

		/*** ファイルの更新 ***/		
		fopen_s(&fp, "tasklist.txt", "w");
		int m;
		#define M_TASK ()
		for (m = 0; m < TASKMAX; m++) {
			if (task[m].id != 0) {
				fprintf(fp, "%d %s, %s, %s, %s\n",
					task[m].id, task[m].title, task[m].deadLine, task[m].mainSubject, task[m].date);
			}
		}
		fclose(fp);

		/***呼び出した構造体をタスク一覧に表示 (id + title + 期限) ***/
		int i;	//タスク要素番号の宣言
		printf("| TaskID | Title | 期限  \n");

		for (i = 0; i < 10; i++)
		{
			if (task[i].id != 0) {
				printf("・  %d  /  %s  /  %s   \n", task[i].id, task[i].title, task[i].deadLine);
			};
		};

		/***タスク操作の選択***/
		printf("タスク操作を操作、番号を入力してください\n");
		printf("[1:新規登録] [2:詳細] [3:削除] [4:終了] ");
		
		int select;			//最初の選択番号

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &select);

		//選択された番号(select)で条件分岐
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

