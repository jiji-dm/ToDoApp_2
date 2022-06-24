#pragma once			//複数のファイルからincludeされても二重定義を阻止できる
#ifndef _CREATE_H		//ifndef → _METHOD_Hの定義がなければendifまでを定義する
#define _CREATE_H		//_METHOD_Hを定義したので次にMethod.hが呼ばれた際にスキップする。

/* 【Create.h】をincludeしたファイルは以下の宣言を宣言せずに使用できる */

#include <stdio.h>
#include <time.h>

#define TITLEMAX 100				//構造体メンバ title文字列の配列数
#define DATEMAX 100					//構造体メンバ date文字列の配列数
#define SUBJECTMAX 200				//構造体メンバ subObject文字列の配列数
#define TASKMAX 10					//Task型 task変数の配列数
#define LINEMAX 100					//ユーザ入力の際の入力容量

typedef struct {
	int id;							//プライマリーキー（必須）
	char title[TITLEMAX];			//題名
	char date[DATEMAX];				//登録日
	char deadLine[DATEMAX];			//期限
	char mainSubject[SUBJECTMAX];	//概要
}Task;

Task task[TASKMAX];					//タスクの要素数 10件


time_t t;			//<time.h>のtime_t型から現在日時を取得する
FILE* fp;			//ファイル呼び出すための変数

char line[LINEMAX];		//sscanfで読み込むための変数
int selectC;		//confirmation時の選択番号

char f_line[LINEMAX];

void create(Task*);					//このファイルをincludeした際にメソッドを参照できるようにする


#endif // !_CREATE_H